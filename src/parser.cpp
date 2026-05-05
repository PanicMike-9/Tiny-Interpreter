#include "parser.hpp"
#include <iostream>
#include <string>

// global i, used for all functions
int i = 0; 

// return NUMBER 
int factor(const std::vector<Token>& tokens)
{
    // size mismatch error
    if(i >= tokens.size()) throw std::runtime_error("Error: end of input in factor()\n");

    const Token& current_token = tokens[i];

    // check for NUMBER token
    if(current_token.token == TokenType::NUMBER)
    {
        int number = std::stoi(current_token.value);
        //std::cout << "Factor sees: " << current_token.value << '\n'; // check each value for debugging
        i++; // move to the next number
        return number;
    }

    // check unary operator()
    if(current_token.token == TokenType::MINUS)
    {
        i++;
        return -factor(tokens); // return negated value
    }

    // TODO: add parenthesis check

    // error message with the token value
    throw std::runtime_error("Expected a NUMBER but got a " + current_token.value + " instead");
}

// calculate multiplication and division logic
int term(const std::vector<Token>& tokens)
{
    if(i >= tokens.size()) throw std::runtime_error("Unexpected end of input\n");

    int left = factor(tokens);

    while(i < tokens.size() && (tokens[i].token == TokenType::MULTIPLY || tokens[i].token == TokenType::DIVIDE))
    {
        TokenType current_op = tokens[i].token;
        i++; // move to next token

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

// calculate addition and subtraction logic
int expression(const std::vector<Token>& tokens)
{
    if(i >= tokens.size()) throw std::runtime_error("Unexpected end of input\n");

    int left = term(tokens);

    while(i < tokens.size() && (tokens[i].token == TokenType::PLUS || tokens[i].token == TokenType::MINUS))
    {
        TokenType current_op = tokens[i].token;
        i++; // move to next token

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

void parse(const std::vector<Token> &tokens)
{
    i = 0; // reset i

    if(tokens[i].token != TokenType::IDENT) 
        throw std::runtime_error("Expected variable");

    // set variable
    std::string variable = tokens[i].value;
    i++;

    if(tokens[i].token != TokenType::ASSIGN) 
        throw std::runtime_error("Expected =");

    i++; // after assign move to next token

    int value = expression(tokens);

    // output variable token and final value
    std::cout << variable << " = " << value << " ";
}


