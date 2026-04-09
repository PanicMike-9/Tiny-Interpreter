#include <iostream>
#include <string>
#include <vector>

enum TokenType { VARIABLE, ASSIGN, NUMBER, PLUS, MINUS };

struct Token
{
    TokenType type;
    std::string value;
};

void parse(std::vector<Token> tokens)
{
    for(auto t : tokens)
    {
        if(t.type == VARIABLE)
        {
            std::cout << " " << t.value << " ";
        }

        if(t.type == ASSIGN)
        {
            std::cout << ' ' << t.value << ' ';
        }

        if(t.type == NUMBER)
        {
            std::cout << " " << t.value << " ";
        }

        if(t.type == PLUS)
        {
            std::cout << " " << t.value << " ";
        }

        if(t.type == MINUS)
        {
            std::cout << " " << t.value << " ";
        }
    }

    std::cout << '\n';
}

int main()
{
    std::vector<Token> tokens{ {VARIABLE, "a"}, {ASSIGN, "="}, {NUMBER, "10"}, {PLUS, "+"}, {NUMBER, "50"}, {MINUS, "-"}, {NUMBER, "20"} };

    parse(tokens);
    return 0;
}
