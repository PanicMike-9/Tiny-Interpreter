#include "parser.hpp"
#include <iostream>
#include <string>
#include <optional>

void parser(const std::vector<Token> &tokens)
{
    int i = 0;

    std::string variable;
    std::string num_str;

    std::optional<int> left;
    std::optional<int> right;

    TokenType current_op;

    while(i < tokens.size())
    {
        Token current_token = tokens[i];

        if(current_token.token == TokenType::IDENT) 
        {
            variable = current_token.value;
        }

        else if(current_token.token == TokenType::NUMBER)
        {
            num_str = current_token.value;

            if(!left) left = std::stoi(num_str);
            else right = std::stoi(num_str);
        }

        else if(current_token.token == TokenType::PLUS)
        {
            current_op = TokenType::PLUS;
        }

        if(left && right && current_op == TokenType::PLUS)
        {
            *left += *right;
            right = std::nullopt; // reset right for next values
        }

        else if(current_token.token == TokenType::ASSIGN) {}

        //std::cout << " " << current_token.value << " ";
        i++;
    }

    std::cout << variable << '=' << *left;
    std::cout << '\n';
}


