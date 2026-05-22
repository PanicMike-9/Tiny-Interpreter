#include "parser.hpp"
#include "lexer.hpp"
#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::string input1 = "x = (10.0 + 10.0) * 2.5 + 5 / 6";
    std::vector<Token> token1 = tokenize(input1);
    
    // debugging to check correct token values and correct tokenization
    std::cout << "--- Token 1 ---\n";
    for(const Token& i : token1)
    {
        std::cout << i.value << " type: " << static_cast<int>(i.token) << '\n';
    }

    std::string input2 = "y = x * (3 + 5) * 3 / 2";
    std::vector<Token> token2 = tokenize(input2);

    std::cout << "--- Token 2 ---\n";
    for(const Token& i : token2)
    {
        std::cout << i.value << " type: " << static_cast<int>(i.token) << '\n';
    }

    std::string input3 = "z = (2.2 * 5.2) / x + y / 2";
    std::vector<Token> token3 = tokenize(input3);

    std::cout << "--- Token 3 ---\n";
    for(const Token& i : token3)
    {
        std::cout << i.value << " type: " << static_cast<int>(i.token) << '\n';
    }

    std::string input4 = "a = 3 * 5 < 5 * 5";
    std::vector<Token> token4 = tokenize(input4);

    std::cout << "--- Token 4 ---\n";
    for(const Token& i : token4)
    {
        std::cout << i.value << " type: " << static_cast<int>(i.token) << '\n';
    }

    std::string input5 = "b = 4 * 4 <= 4 * 4";
    std::vector<Token> token5 = tokenize(input5);

    std::cout << "--- Token 5 ---\n";
    for(const Token& i : token5)
    {
        std::cout << i.value << " type: " << static_cast<int>(i.token) << '\n';
    }

    std::string input6 = "c = 4 * 5 != 2 * 2";
    std::vector<Token> token6 = tokenize(input6);

    std::cout << "--- Token 6 ---\n";
    for(const Token& i : token6)
    {
        std::cout << i.value << " type: " << static_cast<int>(i.token) << '\n';
    }

    parse(token1); // 50.8333
    parse(token2); // 610
    parse(token3); // 305.255
    parse(token4); // false
    parse(token5); // true
    parse(token6); // true
}

