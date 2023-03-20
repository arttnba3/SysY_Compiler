/*
 * A3Compiler - Abstract Syntax Tree definition
 * 
 * Copyright (c) 2023 arttnba3
 * Author: arttnba3 <arttnba@gmail.com>
 *
 */
#ifndef _A3COMPILER_AST_H_
#define _A3COMPILER_AST_H_

#include <cstring>
#include <vector>

namespace a3compiler {
    using std::string, std::vector;

    enum node_type {
        IF_STMT = 0, 
    };

    struct ASTNode {
        vector<struct ASTNode*> child;
    };

    typedef struct ASTNode ASTNode;
};

#endif