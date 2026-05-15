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
   GREATER,
   LESSER,
   GREATER_EQUAL,
   LESSER_EQUAL,
};

struct Token
{
    TokenType token;
    std::string value;
};
