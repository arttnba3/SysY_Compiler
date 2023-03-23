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

    /* basis of all AST type */
    struct BaseAST;

    /* entry point for a file */
    struct CompUnitAST;

    /* variable declaration */
    struct DeclAST;
    struct ConstDeclAST;
    struct BTypeAST;
    struct ConstDefAST;
    struct ConstInitValAST;
    struct VarDeclAST;
    struct VarDefAST;
    struct InitValAST;

    /* function definition */
    struct FuncDefAST;
    struct FuncTypeAST;
    struct FuncFParamsAST;
    struct FuncFParamAST;

    /* block and statements */
    struct BlockAST;
    struct BlockItemAST;
    struct StmtAST;
    struct AssignStmtAST;
    struct IfStmtAST;
    struct WhileStmtAST;
    struct BreakStmtAST;

    /* expression */
    struct ExprAST;
    struct CondExprAST;
    struct LValExprAST;

    typedef struct BaseAST BaseAST;
    typedef struct CompUnitAST CompUnitAST;
    typedef struct DeclAST DeclAST;

    struct BaseAST {
        enum node_type type;
    };

    

    struct CompUnitAST : BaseAST {

    };

};

#endif