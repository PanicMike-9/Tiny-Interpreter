#include "parser.hpp"
#include <iostream>
#include <string>
#include <optional>

// global i, used for all functions
int i = 0; 

int factor(const std::vector<Token>& tokens)
{
    // size mismatch error
    if(i >= tokens.size()) throw std::runtime_error("Unexpected end of input in factor()\n");

    const Token& current_token = tokens[i];

    // check for NUMBER token
    if(current_token.token == TokenType::NUMBER)
    {
        int number = std::stoi(current_token.value);
        i++; // move to the next number
        return number;
    }

    // error if the value is wrong
    throw std::runtime_error("Unxpected value is not a NUMBER in factor()\n");
}

int term(const std::vector<Token>& tokens)
{
    if(i >= tokens.size()) throw std::runtime_error("Unexpected end of input\n");

    int left = factor(tokens);

    while(i < tokens.size() && (tokens[i].token == TokenType::MULTIPLY || tokens[i].token == TokenType::DIVIDE))
    {
        TokenType current_op = tokens[i].token;
        i++;

        int right = factor(tokens);

        if(current_op == TokenType::MULTIPLY)
        {
            left *= right;
        }
        else if(current_op == TokenType::DIVIDE)
        {
            left /= right;
        }
    }

    return left;
}

int expression(const std::vector<Token>& tokens)
{
    if(i >= tokens.size()) throw std::runtime_error("Unexpected end of input\n");

    int left = term(tokens);

    while(i < tokens.size() && (tokens[i].token == TokenType::PLUS || tokens[i].token == TokenType::MINUS))
    {
        TokenType current_op = tokens[i].token;
        i++;

        int right = term(tokens);

        if(current_op == TokenType::PLUS)
        {
            left += right;
        }
        else if(current_op == TokenType::MINUS)
        {
            left -= right;
        }
    }

    return left;
}

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
        const Token& current_token = tokens[i];

        // detect identifier(IDENT)
        if(current_token.token == TokenType::IDENT) 
        {
            variable = current_token.value;
        }

        // detect digit(NUMBER)
        else if(current_token.token == TokenType::NUMBER)
        {
            num_str = current_token.value;

            if(!left.has_value()) left = std::stoi(num_str);
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

        // output each token
        std::cout << current_token.value << " ";

        i++;
    }

    std::cout << '\n';
    std::cout << variable << " = " << *left;
    std::cout << '\n';
}


