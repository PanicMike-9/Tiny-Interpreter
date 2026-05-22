#include "parser.hpp"
#include <iostream>
#include <string>
#include <unordered_map>

// global access to unordered_map
std::unordered_map<std::string, double> variables;

// global i, used for all functions
int token_pos = 0; 

// return NUMBER 
double factor(const std::vector<Token>& tokens)
{
    // size mismatch error
    if(token_pos >= tokens.size()) throw std::runtime_error("Error: end of input in factor()\n");

    const Token& current_token = tokens[token_pos];

    // check and store variable name
    if(current_token.token == TokenType::IDENT)
    {
        std::string var_name = tokens[token_pos].value;
        token_pos++;

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
        token_pos++; // move ahead

        double value = expression(tokens);

        if(token_pos >= tokens.size() || tokens[token_pos].token != TokenType::RIGHT_PAREN)
        {
            throw std::runtime_error("Error: expected ')'");
        }

        token_pos++; 

        return value;
    }

    // check for NUMBER token
    if(current_token.token == TokenType::NUMBER)
    {
        double number = std::stod(current_token.value);
        token_pos++; // move to the next number
        return number;
    }

    // check unary operator()
    if(current_token.token == TokenType::MINUS)
    {
        token_pos++;
        return -factor(tokens); // return negated value
    }
    
    // error message with the token value
    throw std::runtime_error("Expected a NUMBER but got a " + current_token.value + " instead");
}

// calculate multiplication and division logic
double term(const std::vector<Token>& tokens)
{
    if(token_pos >= tokens.size()) throw std::runtime_error("Unexpected end of input term()\n");

    double left = factor(tokens);

    while(token_pos < tokens.size() && (tokens[token_pos].token == TokenType::STAR || tokens[token_pos].token == TokenType::SLASH))
    {
        TokenType current_op = tokens[token_pos].token;
        token_pos++; // move to next token

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
    if(token_pos >= tokens.size()) throw std::runtime_error("Error: Unexpected end of input comparison()\n");
    
    double left = expression(tokens);

    double compare_val = 0;
    TokenType current_op = tokens[token_pos].token;

    double right = 0;

    // check and assign !=
    if(tokens[token_pos].token == TokenType::BANG_EQUAL)
    {
        current_op = TokenType::BANG_EQUAL;
        token_pos++;
        right = expression(tokens);
    }

    // output true when values aren't equal
    if(current_op == TokenType::BANG_EQUAL && left != right)
    {
        compare_val = 1;
    }

    // check and assign >= and <=
    if(tokens[token_pos].token == TokenType::GREATER_EQUAL)
    {
        current_op = TokenType::GREATER_EQUAL;
        token_pos++;
        right = expression(tokens);
    }
    else if(tokens[token_pos].token == TokenType::LESS_EQUAL)
    {
        current_op = TokenType::LESS_EQUAL;
        token_pos++;
        right = expression(tokens);
    }

    // check and assign current operator and parse right after
    if(tokens[token_pos].token == TokenType::GREATER)
    {
        current_op = TokenType::GREATER;
        token_pos++;
        right = expression(tokens);
    }
    else if(tokens[token_pos].token == TokenType::LESS)
    {
        current_op = TokenType::LESS;
        token_pos++;
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
    if(current_op != TokenType::GREATER && 
       current_op != TokenType::LESS && 
       current_op != TokenType::GREATER_EQUAL && 
       current_op != TokenType::LESS_EQUAL &&
       current_op != TokenType::BANG_EQUAL)
    {
        return left;
    }
    else
    {
        return compare_val;
    }

}

// calculate addition and subtraction logic
double expression(const std::vector<Token>& tokens)
{
    if(token_pos >= tokens.size()) throw std::runtime_error("Unexpected end of input expression()\n");

    double left = term(tokens);

    while(token_pos < tokens.size() && (tokens[token_pos].token == TokenType::PLUS || tokens[token_pos].token == TokenType::MINUS))
    {
        TokenType current_op = tokens[token_pos].token;
        token_pos++; // move to next token

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
    token_pos = 0; // reset i

    if(tokens[token_pos].token != TokenType::IDENT) 
        throw std::runtime_error("Expected variable");

    // set variable
    std::string variable = tokens[token_pos].value;
    token_pos++;

    if(tokens[token_pos].token != TokenType::ASSIGN) 
        throw std::runtime_error("Expected =");

    token_pos++; // after assign move to next token

    double value = comparison(tokens);

    variables[variable] = value;

    // output variable token and final value
    std::cout << variable << " = " << value << " ";
}
