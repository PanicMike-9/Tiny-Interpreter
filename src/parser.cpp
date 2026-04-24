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

        // detect identifier(IDENT)
        if(current_token.token == TokenType::IDENT) 
        {
            variable = current_token.value;
        }

        // detect digit(NUMBER)
        else if(current_token.token == TokenType::NUMBER)
        {
            num_str = current_token.value;

            if(!left) left = std::stoi(num_str);
            else right = std::stoi(num_str);
        }

        // apply plus(+) operator logic
        else if(current_token.token == TokenType::PLUS)
        {
            current_op = TokenType::PLUS;
        }

        // check operator and compute logic
        if(left && right && current_op == TokenType::PLUS)
        {
            *left += *right;
            right = std::nullopt; // reset right for next values
        }

        // apply minus(-) operator logic
        else if(current_token.token == TokenType::MINUS)
        {
            current_op = TokenType::MINUS;
        }

        if(left && right && current_op == TokenType::MINUS)
        {
            *left -= *right;
            right = std::nullopt; 
        }

        // apply multiply(*) operator logic
        else if(current_token.token == TokenType::MULTIPLY)
        {
            current_op = TokenType::MULTIPLY;
        }

        if(left && right && current_op == TokenType::MULTIPLY)
        {
            *left *= *right;
            right = std::nullopt; 
        }

        // apply division(/) operator logic
        else if(current_token.token == TokenType::DIVIDE)
        {
            current_op = TokenType::DIVIDE;
        }

        if(left && right && current_op == TokenType::DIVIDE)
        {
            *left /= *right;
            right = std::nullopt; 
        }

        // apply assign(=) operator
        else if(current_token.token == TokenType::ASSIGN) {}

        std::cout << current_token.value << " ";

        i++;
    }

    std::cout << variable << " = " << *left;
    std::cout << '\n';
}

