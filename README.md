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
            case TokenType::IDENT:       std::cout  << "IDENT\n"; break;
            case TokenType::NUMBER:      std::cout  << "number\n"; break;
            case TokenType::ASSIGN:      std::cout  << "ASSIGN\n"; break;
            case TokenType::PLUS:        std::cout  << "PLUS\n"; break;
            case TokenType::MINUS:       std::cout  << "MINUS\n"; break;
            case TokenType::STAR:        std::cout  << "STAR\n"; break;
            case TokenType::SLASH:       std::cout  << "SLASH\n"; break;
            case TokenType::RIGHT_PAREN: std::cout  << "RIGHT_PAREN\n"; break;
            case TokenType::LEFT_PAREN:  std::cout  << "LEFT_PAREN\n"; break;

            default: std::cout << " \n"; break;
    }

    parse(token1);
```
```--- Token 1 ---
   x type: IDENT
   = type: ASSIGN
   ( type: LEFT_PAREN
   10.0 type: number
   + type: PLUS
   10.0 type: number
   ) type: RIGHT_PAREN
   * type: STAR
   2.5 type: number
   + type: PLUS
   5 type: number
   / type: SLASH
   6 type: numberbash

   output: 
   x = 50.8333
```
