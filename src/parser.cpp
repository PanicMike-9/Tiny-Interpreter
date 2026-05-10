#include "parser.hpp"
#include <iostream>
#include <string>
#include <unordered_map>


std::unordered_map<std::string, double> variables;

// global i, used for all functions
int i = 0; 

// return NUMBER 
double factor(const std::vector<Token>& tokens)
{
    // size mismatch error
    if(i >= tokens.size()) throw std::runtime_error("Error: end of input in factor()\n");

    const Token& current_token = tokens[i];

    // check and store variable name
    if(current_token.token == TokenType::IDENT)
    {
        std::string var_name = tokens[i].value;
        i++;

        return variables[var_name];
    }

    // parenthesis check 
    if(current_token.token == TokenType::LEFT_PAREN)
    {
        i++; // move ahead

        double value = expression(tokens);

        if(i >= tokens.size() || tokens[i].token != TokenType::RIGHT_PAREN)
        {
            throw std::runtime_error("Error: expected ')'");
        }

        i++; // move ahead

        return value;
    }

    // check for NUMBER token
    if(current_token.token == TokenType::NUMBER)
    {
        double number = std::stod(current_token.value);
        i++; // move to the next number
        return number;
    }

    // check unary operator()
    if(current_token.token == TokenType::MINUS)
    {
        i++;
        return -factor(tokens); // return negated value
    }
    
    // error message with the token value
    throw std::runtime_error("Expected a NUMBER but got a " + current_token.value + " instead");
}

// calculate multiplication and division logic
double term(const std::vector<Token>& tokens)
{
    if(i >= tokens.size()) throw std::runtime_error("Unexpected end of input\n");

    double left = factor(tokens);

    while(i < tokens.size() && (tokens[i].token == TokenType::MULTIPLY || tokens[i].token == TokenType::DIVIDE))
    {
        TokenType current_op = tokens[i].token;
        i++; // move to next token

        double right = factor(tokens);

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
double expression(const std::vector<Token>& tokens)
{
    if(i >= tokens.size()) throw std::runtime_error("Unexpected end of input\n");

    double left = term(tokens);

    while(i < tokens.size() && (tokens[i].token == TokenType::PLUS || tokens[i].token == TokenType::MINUS))
    {
        TokenType current_op = tokens[i].token;
        i++; // move to next token

        double right = term(tokens);

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

    double value = expression(tokens);

    variables[variable] = value;

    // output variable token and final value
    std::cout << variable << " = " << value << " ";
}


