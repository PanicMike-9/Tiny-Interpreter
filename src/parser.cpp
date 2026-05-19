#include "parser.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

// global access to unordered_map
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

        // undeclared variables or undefined variables check
        if(variables.find(var_name) == variables.end())
        {
            throw std::runtime_error("Error: undefined variable: " + var_name);
        }
        
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

        i++; 

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
    if(i >= tokens.size()) throw std::runtime_error("Unexpected end of input term()\n");

    double left = factor(tokens);

    while(i < tokens.size() && (tokens[i].token == TokenType::STAR || tokens[i].token == TokenType::SLASH))
    {
        TokenType current_op = tokens[i].token;
        i++; // move to next token

        double right = factor(tokens);

        if(current_op == TokenType::STAR)
        {
            left *= right;
        }
        else if(current_op == TokenType::SLASH)
        {
            left /= right;
        }
    }

    return left;
}

// compare and true 1 or 0 for true or false
double comparison(const std::vector<Token>& tokens)
{
    if(i >= tokens.size()) throw std::runtime_error("Error: Unexpected end of input comparison()\n");
    
    double left = expression(tokens);

    double compare_val = 0;
    TokenType current_op = tokens[i].token;

    double right = 0;

    // check and assign >= and <=
    if(tokens[i].token == TokenType::GREATER_EQUAL)
    {
        current_op = TokenType::GREATER_EQUAL;
        i++;
        right = expression(tokens);
    }
    else if(tokens[i].token == TokenType::LESS_EQUAL)
    {
        current_op = TokenType::LESS_EQUAL;
        i++;
        right = expression(tokens);
    }

    // check and assign current operator and parse right after
    if(tokens[i].token == TokenType::GREATER)
    {
        current_op = TokenType::GREATER;
        i++;
        right = expression(tokens);
    }
    else if(tokens[i].token == TokenType::LESS)
    {
        current_op = TokenType::LESS;
        i++;
        right = expression(tokens);
    }

    // compare values and return true, if they don't compare, compare_val returns 0
    if(current_op == TokenType::GREATER_EQUAL && left >= right)
    {
        compare_val = 1;
    }
    else if(current_op == TokenType::LESS_EQUAL && left <= right)
    {
        compare_val = 1;
    }
     
    // compare values and return true, if they don't compare, compare_val returns 0
    if(current_op == TokenType::GREATER && left > right)
    {
        compare_val = 1;
    }
    else if(current_op == TokenType::LESS && left < right)
    {
        compare_val = 1;
    }

    // return value if > & < aren't detected
    if(current_op != TokenType::GREATER && current_op != TokenType::LESS && 
       current_op != TokenType::GREATER_EQUAL && current_op != TokenType::LESS_EQUAL)
    {
        return left;
    }
    else
    {
        if(compare_val == 1) std::cout << " true ";
        else std::cout << " false ";
        return compare_val;
    }

}

// calculate addition and subtraction logic
double expression(const std::vector<Token>& tokens)
{
    if(i >= tokens.size()) throw std::runtime_error("Unexpected end of input expression()\n");

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

// parse tokens
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

    double value = comparison(tokens);

    variables[variable] = value;

    // output variable token and final value
    std::cout << variable << " = " << value << " ";
}
