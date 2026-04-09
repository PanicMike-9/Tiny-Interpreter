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
};

struct Token
{
    TokenType token;
    std::string value;
};
