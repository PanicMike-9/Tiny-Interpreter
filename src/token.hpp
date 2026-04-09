#pragma once
#include <string>

enum class TokenType
{
   VARIABLE,
   IDENT,
   ASSIGN,
   NUMBER,
   PLUS,
   MINUS,
};

struct Token
{
    TokenType token;
    std::string value;
};
