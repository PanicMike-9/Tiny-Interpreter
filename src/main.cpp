#include "parser.hpp"
#include "lexer.hpp"
#include <vector>
#include <string>
#include <iostream>

void display_token(const std::vector<Token>& input_token)
{
    std::cout << "--- Token ---\n";
    for(const Token& i : input_token)
    {
        std::cout << i.value << " : ";
        switch(i.token)
        {
            case TokenType::IDENT:                
                std::cout  << "IDENT\n"; break;

            case TokenType::NUMBER:               
                std::cout  << "NUMBER\n"; break;

            case TokenType::ASSIGN:               
                std::cout  << "ASSIGN\n"; break;

            case TokenType::PLUS:                 
                std::cout  << "PLUS\n"; break;

            case TokenType::MINUS:                
                std::cout  << "MINUS\n"; break;

            case TokenType::STAR:                 
                std::cout  << "STAR\n"; break;

            case TokenType::SLASH:                
                std::cout  << "SLASH\n"; break;

            case TokenType::RIGHT_PAREN:          
                std::cout  << "RIGHT_PAREN\n"; break;

            case TokenType::LEFT_PAREN:           
                std::cout  << "LEFT_PAREN\n"; break;

            case TokenType::GREATER:              
                std::cout  << "GREATER\n"; break;

            case TokenType::LESS:                 
                std::cout  << "LESS\n"; break;

            case TokenType::GREATER_EQUAL:        
                std::cout  << "GREATER_EQUAL\n"; break;

            case TokenType::LESS_EQUAL:           
                std::cout  << "LESS_EQUAL\n"; break;

            case TokenType::BANG_EQUAL:           
                std::cout  << "BANG_EQUAL\n"; break;

            default: 
                std::cout << " \n"; break;
        }
    }
}

int main()
{
    std::string input1 = "x = (10.0 + 10.0) * 2.5 + 5 / 6";
    std::vector<Token> token1 = tokenize(input1);
    display_token(token1);

    std::string input2 = "y = x * (3 + 5) * 3 / 2";
    std::vector<Token> token2 = tokenize(input2);
    display_token(token2);

    std::string input3 = "z = (2.2 * 5.2) / x + y / 2";
    std::vector<Token> token3 = tokenize(input3);
    display_token(token3);

    std::string input4 = "a = 3 * 5 < 5 * 5";
    std::vector<Token> token4 = tokenize(input4);
    display_token(token4);

    std::string input5 = "b = 4 * 4 <= 4 * 4";
    std::vector<Token> token5 = tokenize(input5);
    display_token(token5);

    std::string input6 = "c = 4 * 5 != 2 * 2";
    std::vector<Token> token6 = tokenize(input6);
    display_token(token6);

    parse(token1); // 50.8333
    parse(token2); // 610
    parse(token3); // 305.255
    parse(token4); // false
    parse(token5); // true
    parse(token6); // true
}

