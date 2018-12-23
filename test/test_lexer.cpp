#include <stdlib.h>
#include <iostream>
#include "lexer.h"

using std::cout;
using std::endl;

int main() {

    Token tok;

    while (1) {
        tok.Get_Token();
        tok.Print_Token();
        if (tok_eof == tok.type) {
            break;
        }
    }

    cout << "Finish lexer..." << endl;
    return 0;
}