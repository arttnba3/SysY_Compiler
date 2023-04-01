#include "a3compiler/syntactic.h"
#include "a3compiler/ast.h"

using namespace a3compiler;

A3SyntacticParser::A3SyntacticParser(A3Scanner *scanner)
{
    this->scanner = scanner;
}

struct BaseAST* parse_stmt(void)
{
    
}