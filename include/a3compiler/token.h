#ifndef _A3COMPILER_TOKEN_H_
#define _A3COMPILER_TOKEN_H_

#include <cstring>
#include <iostream>

namespace a3compiler {
    using std::string, std::ostream;

    enum TokenType {
        /* identifier and integer */
        IDENTIFIER = 0, NUMBER,
        /* SysY key words */
        IF, ELSE, DO, WHILE, BREAK, CONTINUE, RETURN, 
        /* seperator ; () [] {} */
        SEMICOLON, LPAR, RPAR, LBRACKET, RBRACKET, LBRACE, RBRACE,
        /* operator = + - * / ++ -- */
        ASSIGN, PLUS, MINUS, MULT, DIV, INC, DEC, 
        /* logical operator && || ! < > <= >= == != */
        AND, OR, NOT, LT, GT, LTEQ, GTEQ, EQ, NEQ,
        /* bit operator & | ~ << >> */
        BITAND, BITOR, BITNOT, LSHIFT, RSHIFT,
        /* error token */
        ERR,
        /* end of token flow */
        END,
        /* num of types */
        TOKEN_TYPES,
    };

    static string token_type_str[TOKEN_TYPES] = {
        /* in fact we don't use these two str, but print the original value */
        "Ident()", "Number()",
        /* print by default */
        "If", "Else", "Do", "While", "Break", "Continue", "Return",
        "Semicolon", "LPar", "RPar", "LBracket", "RBracket", "LBrace", "RBrace",
        "Assign", "Plus", "Minus", "Mult", "Div", "Inc", "Dec",
        "And", "Or", "Not", "Lt", "Gt", "LtEq", "GtEq", "Eq", "Neq",
        "BitAnd", "BitOr", "BitNot", "LShift", "RShift",
        "Err", "End",
    };

    static string key_words_str[TOKEN_TYPES] = {
        "", "",
        "if", "else", "do", "while", "break", "continue", "return",
        "", "", "", "", "", "", "",
        "", "", "", "", "", "", "", 
        "", "", "", "", "", "", "", "", "",
        "", "", "", "", "",
        "",
        "",
    };

    struct Token {
        TokenType type;
        string lexeme;
        uint64_t val;
        uint64_t no;    /* numero of tokens */
        uint64_t line;  /* where the token is */

        friend ostream &operator<<(ostream &output, const Token &token)
        {
            switch (token.type) {
            case IDENTIFIER:
                output << "Ident(" << token.lexeme << ")";
                break;
            case NUMBER:
                output << "Number(" << token.lexeme << ")";
                break;
            default:
                output << token_type_str[token.type];
                break;
            }
            return output;
        }
    };
    typedef struct Token Token;
};

#endif