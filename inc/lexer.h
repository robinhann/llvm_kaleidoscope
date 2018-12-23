#ifndef _LEXER_H
#define _LEXER_H

#include <string>

enum TokenType {
    // error type
    tok_error     = 1,

    // undefined
    tok_undefined = 0,

    // eof
    tok_eof = -1,

    // keywords
    tok_def    = -2,
    tok_extern = -3,

    //primary
    tok_identifier = -4,
    tok_number     = -5,

};

class Token {
    public:
    TokenType type;

    // additional info
    std::string identifier_str;  // for tok_identifier
    double      number_val;      // for tok_number
    int         undefined_ascii; // for tok_undefined

    // get next token
    Token* Get_Token();
    void   Print_Token();
};

#endif	// _LEXER_H

