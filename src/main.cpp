#include "lexer.hpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string input = "val = val1 + 1";

    std::vector<Token> token_vec = tokenize(input);

    for(const auto& token_output : token_vec)
    {
        std::cout << token_output.value << ' ';
    }
}
