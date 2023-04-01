#include <iostream>
#include <fstream>
#include <cstring>

#include "a3compiler/scanner.h"
#include "a3compiler/token.h"
#include "a3compiler/compile_err.h"
#include "tools/tools.h"

using namespace a3compiler;

using std::ifstream, std::string, std::ios, std::cout, std::endl, std::stoull;

A3Scanner::A3Scanner(string filename, ifstream *input)
{
    this->input = input;
    this->filename = filename;
    this->token_nr = 0;
    this->line_nr = 1;
}

char A3Scanner::next_char(void)
{
    if (!*(this->input) || this->input->eof()) {
        return EOF;
    }

    return this->input->get();
}

void A3Scanner::char_back(char ch)
{
    if (ch != EOF) {
        this->input->seekg(-1, ios::cur);
    }
}

static inline TokenType identifier_type(const string &lexeme)
{
    for (int i = IF; i < SEMICOLON; i++) {
        if (lexeme == key_words_str[i]) {
            return TokenType(i);
        }
    }
    return IDENTIFIER;
}

Token* A3Scanner::get_token(void)
{
    Token *token;

    if (this->token_queue.empty()) {
        token = this->get_new_token();
    } else {
        token = this->token_queue.front();
        this->token_queue.pop();
    }

    return token;
}

void A3Scanner::put_token(Token *token)
{
    this->token_queue.push(token);
}

Token* A3Scanner::get_new_token(void)
{
    Token *token;
    char ch;

    token = new Token;
    token->no = this->token_nr++;

reget_token:
    token->lexeme = "";
    ch = this->next_char();

    /* clear the space */
    while (isspace(ch)) {
        if (ch == '\n') {
            this->line_nr++;
        }
        ch = this->next_char();
    }

    token->line = this->line_nr;

    if (ch == EOF) {
        token->type = END;
        return token;
    }

    /* identifier or key words */
    if (isalpha(ch) || ch == '_') {
        do {
            token->lexeme += ch;
            ch = this->next_char();
        } while (isalnum(ch) || ch == '_');

        this->char_back(ch);

        token->type = identifier_type(token->lexeme);

        return token;
    }

    /* const integer */
    if (is_digit(ch)) {
        int num_base = 10;

        token->type = NUMBER;
        token->lexeme += ch;

        if (ch == '0') {
            ch = this->next_char();

            if (ch == 'x' || ch == 'X') { /* hex */
                num_base = 16;
                token->lexeme += ch;

                ch = this->next_char();
                while (is_hex_digit(ch)) {
                    token->lexeme += ch;
                    ch = this->next_char();
                }
            } else if (is_oct_digit(ch)) { /* octal */
                num_base = 8;
                token->lexeme += ch;

                ch = this->next_char();
                while (is_digit(ch)) {
                    if (!is_oct_digit(ch)) {
                        throw A3CompilerError(string("invalid digit \"") + ch
                                              + "\" in octal constant",
                                              this->filename,
                                              this->line_nr);
                    }
                    token->lexeme += ch;
                    ch = this->next_char();
                }
            } else if (ch == 'b' || ch == 'B') { /* binary */
                num_base = 2;
                token->lexeme += ch;

                ch = this->next_char();
                while (is_digit(ch)) {
                    if (!(is_bin_digit(ch))) {
                        throw A3CompilerError(string("invalid digit \"") + ch
                                              + "\" in binary constant",
                                              this->filename,
                                              this->line_nr);
                    }
                    token->lexeme += ch;
                    ch = this->next_char();
                }
            }

            goto num_token_out;
        }

        ch = this->next_char();

        while (is_digit(ch)) {
            token->lexeme += ch;
            ch = this->next_char();
        }

    num_token_out:
        this->char_back(ch);
        token->val = stoull(token->lexeme, 0, num_base);

        return token;
    }

    /* other types */
    token->lexeme += ch;

    switch (ch) {
    /* seperator ; () [] {} */
    case ';':
        token->type = SEMICOLON;
        break;
    case '(':
        token->type = LPAR;
        break;
    case ')':
        token->type = RPAR;
        break;
    case '[':
        token->type = LBRACKET;
        break;
    case ']':
        token->type = RBRACKET;
        break;
    case '{':
        token->type = LBRACE;
        break;
    case '}':
        token->type = RBRACE;
        break;
    /* operator = + - * / ++ -- and comment */
    case '=':
        ch = this->next_char();
        if (ch == '=') {
            token->lexeme += ch;
            token->type = EQ;
        } else {
            this->char_back(ch);
            token->type = ASSIGN;
        }
        break;
    case '+':
        ch = this->next_char();
        if (ch == '+') {
            token->lexeme += ch;
            token->type = INC;
        } else {
            this->char_back(ch);
            token->type = PLUS;
        }
        break;
    case '-':
        ch = this->next_char();
        if (ch == '-') {
            token->lexeme += ch;
            token->type = DEC;
        } else {
            this->char_back(ch);
            token->type = MINUS;
        }
        break;
    case '*':
        token->type = MULT;
        break;
    case '/':
        ch = this->next_char();
        if (ch == '/') { /* comment in line */
            do {
                ch = this->next_char();
            } while (ch != '\n' && ch != EOF);

            if (ch == '\n') {
                this->line_nr++;
            }

            goto reget_token;
        } else if (ch == '*') { /* comment cross lines */
            do {
                ch = this->next_char();
                if (ch == '*') {
                    ch = this->next_char();
                    if (ch == '/') {
                        break;
                    }
                }

                if (ch == '\n') {
                    this->line_nr++;
                }
            } while (ch != EOF);

            goto reget_token;
        } else {
            this->char_back(ch);
            token->type = DIV;
        }
        break;
    /* logical operator && || ! < > <= >= == != and bit operator & | ~ */
    case '&':
        ch = this->next_char();
        if (ch == '&') {
            token->lexeme += ch;
            token->type = AND;
        } else {
            this->char_back(ch);
            token->type = BITAND;
        }
        break;
    case '|':
        ch = this->next_char();
        if (ch == '|') {
            token->lexeme += ch;
            token->type = OR;
        } else {
            this->char_back(ch);
            token->type = BITOR;
        }
        break;
    case '!':
        ch = this->next_char();
        if (ch == '=') {
            token->lexeme += ch;
            token->type = NEQ;
        } else {
            this->char_back(ch);
            token->type = NOT;
        }
        break;
    case '<':
        ch = this->next_char();
        if (ch == '=') {
            token->lexeme += ch;
            token->type = LTEQ;
        } else if (ch == '<') {
            token->lexeme += ch;
            token->type = LSHIFT;
        } else {
            this->char_back(ch);
            token->type = LT;
        }
        break;
    case '>':
        ch = this->next_char();
        if (ch == '=') {
            token->lexeme += ch;
            token->type = GTEQ;
        } else if (ch == '>') {
            token->lexeme += ch;
            token->type = RSHIFT;
        } else {
            this->char_back(ch);
            token->type = GT;
        }
        break;
    default:
        token->type = ERR;
        break;
    }

    return token;
}

void A3Scanner::token_println(Token *t)
{
    cout << *t << endl;
}
