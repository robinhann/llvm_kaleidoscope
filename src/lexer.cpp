#include <cctype>
#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

using std::string;

Token* Token::Get_Token() {
    char   last_char = ' ';
    string tmp_str   = "";
    bool   tmp_flag  = 0;

    // skip space
    while (isspace(last_char)) {
        last_char = getchar();
    }

    // case string
    if (isalpha(last_char)) {
        tmp_str = last_char;
        while (isalnum(last_char = getchar())) {
            tmp_str += last_char;
        }

        if ("def" == tmp_str) {
            type = tok_def;
        }
        else if ("extern" == tmp_str) {
            type = tok_extern;
        }
        else {
            type = tok_identifier;
            identifier_str = tmp_str;
        }
        return this;
    }

    // case number
    if (isdigit(last_char) || '.' == last_char) {
        tmp_flag = ('.' == last_char) ? 1 : 0;
        tmp_str = last_char;
        last_char = getchar();
        while (isdigit(last_char) || '.' == last_char) {
            if ('.' == last_char) {
                if (1 == tmp_flag) {
                    // TODO: got one more '.'
                }
                else {
                    tmp_flag = 1;
                }
            }
            tmp_str += last_char;
            last_char = getchar();
        }

        type = tok_number;
        number_val = strtod(tmp_str.c_str(), nullptr);
        return this;
    }

    // case comment
    if ('#' == last_char) {
        while (last_char != EOF && last_char != '\n' && last_char != '\r') {
            last_char = getchar();
        }
        if (last_char != EOF) {
            return Get_Token();
        }
    }

    // case EOF
    if (EOF == last_char) {
        type = tok_eof;
        return this;
    }

    // otherwise
    type = tok_undefined;
    undefined_ascii = (int) last_char;

    return this;
}

void Token::Print_Token() {
    switch (type) {

        case tok_undefined: {
            printf("tok_undefined = %i\n", undefined_ascii);
            break;
        }
        case tok_eof: {
            printf("tok_eof\n");
            break;
        }
        case tok_def: {
            printf("tok_def\n");
            break;
        }
        case tok_extern: {
            printf("tok_extern\n");
            break;
        }

        case tok_identifier: {
            printf("tok_identifier = %s\n", identifier_str.c_str());
            break;
        }
        case tok_number: {
            printf("tok_number = %f\n", number_val);
            break;
        }
        default: {
            break;
        }
    }
}