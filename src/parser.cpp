#include "parser.hpp"
#include <iostream>
#include <string>

void parser(const std::vector<Token> &tokens)
{
    int i = 0;

    std::string variable;
    std::string num_str;

    int number = 0;
    int left   = 0;
    int right  = 0;

    while(i < tokens.size())
    {
        Token current_token = tokens[i];

        if(current_token.token == TokenType::IDENT) 
        {
            variable = current_token.value;
        }

        else if(current_token.token == TokenType::ASSIGN) {}

        else if(current_token.token == TokenType::NUMBER) 
        {
            num_str = current_token.value;
            number = std::stoi(num_str);
        }

        else if(current_token.token == TokenType::PLUS) {}

        //std::cout << " " << current_token.value << " ";

        i++;
    }

    std::cout << variable << '=' << number;

    std::cout << '\n';
}


