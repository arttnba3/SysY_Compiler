#ifndef _A3COMPILER_SYNTACTIC_H_
#define _A3COMPILER_SYNTACTIC_H_

#include "a3compiler/scanner.h"

namespace a3compiler {
    class A3SyntacticParser {
    private:
        A3Scanner *scanner;
    public:
        A3SyntacticParser(A3Scanner *scanner);
    };
};

#endif