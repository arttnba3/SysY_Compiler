#ifndef _A3COMPILER_SCANNER_H_
#define _A3COMPILER_SCANNER_H_

#include <iostream>
#include <fstream>
#include <queue>
#include "a3compiler/token.h"

namespace a3compiler {
    using std::ifstream, std::string, std::ios, std::queue;

    class A3Scanner {
    private:
        string filename;
        ifstream *input;
        uint64_t token_nr;
        uint64_t line_nr;
        queue<Token*> token_queue;

        char next_char(void);
        void char_back(char ch);
        Token* get_new_token(void);
    public:
        A3Scanner(string filename, ifstream *input);
        Token* get_token(void);
        void put_token(Token *token);
        void token_println(Token *t);
    };
};

#endif