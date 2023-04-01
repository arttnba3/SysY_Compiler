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
    struct FuncRParamAST;

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
    struct PrimaryExprAST;
    struct UnaryExprAST;
    struct MulExprAST;
    struct AddExprAST;
    struct RelExprAST;
    struct EqExprAST;
    struct LAndExprAST;
    struct LOrExprAST;
    struct ConstExprAST;
    
    typedef struct BaseAST BaseAST;
    typedef struct CompUnitAST CompUnitAST;
    typedef struct DeclAST DeclAST;
    typedef struct ConstDeclAST ConstDeclAST;
    typedef struct BTypeAST BTypeAST;
    typedef struct ConstDefAST ConstDefAST;
    typedef struct ConstInitValAST ConstInitValAST;
    typedef struct VarDeclAST VarDeclAST;
    typedef struct VarDefAST VarDefAST;
    typedef struct InitValAST InitValAST;

    /* function definition */
    typedef struct FuncDefAST FuncDefAST;
    typedef struct FuncTypeAST FuncTypeAST;
    typedef struct FuncFParamsAST FuncFParamsAST;
    typedef struct FuncFParamAST FuncFParamAST;
    typedef struct FuncRParamAST FuncRParamAST;

    /* block and statements */
    typedef struct BlockAST BlockAST;
    typedef struct BlockItemAST BlockItemAST;
    typedef struct StmtAST StmtAST;
    typedef struct AssignStmtAST AssignStmtAST;
    typedef struct IfStmtAST IfStmtAST;
    typedef struct WhileStmtAST WhileStmtAST;
    typedef struct BreakStmtAST BreakStmtAST;

    /* expression */
    typedef struct ExprAST ExprAST;
    typedef struct CondExprAST CondExprAST;
    typedef struct LValExprAST LValExprAST;
    typedef struct PrimaryExprAST PrimaryExprAST;
    typedef struct UnaryExprAST UnaryExprAST;
    typedef struct MulExprAST MulExprAST;
    typedef struct AddExprAST AddExprAST;
    typedef struct RelExprAST RelExprAST;
    typedef struct EqExprAST EqExprAST;
    typedef struct LAndExprAST LAndExprAST;
    typedef struct LOrExprAST LOrExprAST;
    typedef struct ConstExprAST ConstExprAST;

    struct BaseAST {
        enum node_type type;
    };

    /* CompUnit -> [CompUnit](Decl|FuncDef) */
    struct CompUnitAST : BaseAST {
        bool is_func;
        DeclAST *decl;
        FuncDefAST *func_def;
    };

    /**
     * Decl -> ConstDecl|VarDecl
     * ConstDecl -> 'const' BType ConstDef {',' ConstDef } ';'
     * VarDecl -> BType VarDef {',' VarDef } ';'
    */
    struct DeclAST : BaseAST {
        bool is_const;
        BTypeAST *btype;
        vector<BaseAST*> defs;
    };

    enum btype {
        INT,
    };

    struct BTypeAST : BaseAST {
        btype type;
    };

    /* ConstDef -> Ident { '[' ConstExp ']' } '=' ConstInitVal */
    struct ConstDefAST : BaseAST {

    };

    
};

#endif