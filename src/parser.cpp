#include "parser.hpp"
#include <iostream>
#include <string>
#include <optional>

void parser(const std::vector<Token> &tokens)
{
    int i = 0;

    std::string variable;
    std::string num_str;

    int number = 0;
    std::optional<int> left;
    std::optional<int> right;

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

            if(!left) left = number;
            else right = number;
        }

        else if(current_token.token == TokenType::PLUS)
        {
            *left += *right;
        }

        //std::cout << " " << current_token.value << " ";

        i++;
    }

    std::cout << *left << ' ' << *right << '\n';
    std::cout << variable << '=' << *left;

    std::cout << '\n';
}


