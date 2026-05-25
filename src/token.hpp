#pragma once

#include <string>

enum class TokenType
{
   // literals
   IDENT, NUMBER,

   // single character tokens
   PLUS, MINUS, STAR, 
   SLASH, LEFT_PAREN, 
   RIGHT_PAREN, GREATER, 
   LESS, ASSIGN, BANG,

   // multi-character tokens
   GREATER_EQUAL, LESS_EQUAL,
   BANG_EQUAL,

   // keywords
   AND, OR,
};

struct Token
{
    TokenType token;
    std::string value;
};
