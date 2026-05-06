#pragma once

#include <string>

enum class TokenType
{
   IDENT,
   ASSIGN,
   NUMBER,
   PLUS,
   MINUS,
   MULTIPLY,
   DIVIDE,
   LEFT_PAREN,
   RIGHT_PAREN,
};

struct Token
{
    TokenType token;
    std::string value;
};
