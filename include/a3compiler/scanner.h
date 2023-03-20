#ifndef _A3COMPILER_SCANNER_H_
#define _A3COMPILER_SCANNER_H_

#include <iostream>
#include <fstream>
#include "a3compiler/token.h"

namespace a3compiler {
    using std::ifstream, std::string, std::ios;

    class A3Scanner {
    private:
        ifstream *input;
        uint64_t token_nr;
        uint64_t line_nr;
        char next_char(void);
        void char_back(char ch);
    public:
        A3Scanner(ifstream *input);
        Token* get_token(void);
        void token_println(Token *t);
    };
};

#endif