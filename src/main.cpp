#include "parser.hpp"
#include "lexer.hpp"
#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::string input1 = "val1 = 5 + 10 * 2 / 5";
    std::vector<Token> token1 = tokenize(input1);
    
    // debugging to check correct token values and correct tokenization
    for(const Token& i : token1)
    {
        std::cout << i.value << ' ';
        std::cout << "type: " << static_cast<int>(i.token) << '\n';
    }

    std::string input2 = "val2 = 3 + 5 * 3 / 2";
    std::vector<Token> token2 = tokenize(input2);

    parse(token1);
    parse(token2); // the answer is actually 10.5, but we get 10, because it's integer division, the decimal value gets truncated
}
