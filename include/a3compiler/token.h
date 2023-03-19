#ifndef _A3COMPILER_TOKEN_H_
#define _A3COMPILER_TOKEN_H_

#include <cstring>
#include <iostream>

namespace a3compiler {
    using std::string, std::ostream;

    enum TokenType {
        /* identifier and integer */
        IDENTIFIER, INTEGER,
        /* miniSysY key words */
        IF, ELSE, WHILE, BREAK, CONTINUE, RETURN, 
        /* seperator ; () {} */
        SEMICON, LPAR, RPAR, LBRACE, RBRACE,
        /* operator = + - * / < > == */
        ASSIGN, PLUS, MINUS, MULT, DIV, LT, GT, EQ,
        /* error token */
        ERR,
        /* end of token flow */
        END,
    };

    struct Token {
        TokenType type;
        string lexeme;
        uint64_t val;
        friend ostream &operator<<(ostream &output, const Token &token)
        {
            switch (token.type) {
            case IDENTIFIER:
                output << "Ident(" << token.lexeme << ")";
                break;
            default:
                output << "Unrecognized token type";
                break;
            }
            return output;
        }
    };
    typedef struct Token Token;
};

#endif