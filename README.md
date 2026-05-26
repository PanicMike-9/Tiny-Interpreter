# Tiny Interpreter

A tiny interpreter written in **C++** to explore **tokenization**, **lexer design**, **recursive descent parsing**, **expression evaluation** and **interpreter architecture**.

## Features
- Lexer for tokenizing source input
- Recursive descent parser for expression evaluation
- Arithmetic operations with operator precedence
- Parentheses support for grouped expressions
- Variable assignment and storage
- Comparison operators:
  * `<`  
  * `>`  
  * `<=`  
  * `>=`  
  * `!=`  
- Multi-character token handling
- Token stream debugging output

## Structure
- `token.hpp` - Defines token types and token metadata 
- `lexer.cpp/hpp` - Handles lexical analysis and token generation 
- `parser.cpp/hpp` - Handles recursive descent parsing and expression evaluation

## Project Goals
- Build a small interpreted language from scratch in C++
- Explore:
  * Lexer 
  * Parser
  * Runtime architecture

- Experiment with features:
  * Abstract Syntax Trees (AST)
  * Functions
  * Logical operators

## Working Example

```C++

    std::string input1 = "x = (10.0 + 10.0) * 2.5 + 5 / 6";
    std::vector<Token> token1 = tokenize(input1);
    
    // debugging to check correct token values and correct tokenization
    std::cout << "--- Token 1 ---\n";
    for(const Token& i : token1)
    {
        std::cout << i.value << " type: ";
        switch(i.token)
        {
            case TokenType::IDENT: std::cout << "ident\n"; break;
            case TokenType::NUMBER: std::cout << "num\n"; break;
            case TokenType::ASSIGN: std::cout << "assign\n"; break;
            case TokenType::PLUS: std::cout << "plus\n"; break;
            case TokenType::MINUS: std::cout << "minus\n"; break;
            case TokenType::STAR: std::cout << "star\n"; break;
            case TokenType::SLASH: std::cout << "slash\n"; break;
            case TokenType::RIGHT_PAREN: std::cout << "right_paren\n"; break;
            case TokenType::LEFT_PAREN: std::cout << "left_paren\n"; break;

            default: std::cout << " \n"; break;
        }
    }

    parse(token1);
```
```bash
        --- Token 1 ---
        x type: ident
        = type: assign
        ( type: left_paren
        10.0 type: num
        + type: plus
        10.0 type: num
        ) type: right_paren
        * type: star
        2.5 type: num
        + type: plus
        5 type: num
        / type: slash
        6 type: num

        output:
        x = 50.8333
```
