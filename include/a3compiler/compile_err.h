#ifndef _A3COMPILER_COMPILE_ERR_H_
#define _A3COMPILER_COMPILE_ERR_H_

#include <iostream>
#include <string>

namespace a3compiler {
    using std::string, std::exception, std::to_string;
    class A3CompilerError : exception {
    private:
        string error_msg;
    public:
        A3CompilerError(const string &msg, const string &filename, size_t line)
        {
            this->error_msg = filename +":"+ to_string(line) + ": error: "+msg; 
        }
        const char* what(void) const throw()
        {
            return this->error_msg.c_str();
        }
    };
};

#endif