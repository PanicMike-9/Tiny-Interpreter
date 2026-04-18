#include "parser.hpp"
#include <iostream>

void parser(const std::vector<Token> &tokens)
{
    int i = 0;

    while(i < tokens.size())
    {
        Token current_token = tokens[i];

        if(current_token.token == TokenType::IDENT) {}
        else if(current_token.token == TokenType::ASSIGN) {}
        else if(current_token.token == TokenType::NUMBER) {}
        else if(current_token.token == TokenType::PLUS) {}

        std::cout << " " << current_token.value << " ";

        i++;
    }

    std::cout << '\n';
}


