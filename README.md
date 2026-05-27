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
    display_token(token1);

    parse(token1);
```
```bash
        --- Token ---
        x : IDENT
        = : ASSIGN
        ( : LEFT_PAREN
        10.0 : NUMBER
        + : PLUS
        10.0 : NUMBER
        ) : RIGHT_PAREN
        * : STAR
        2.5 : NUMBER
        + : PLUS
        5 : NUMBER
        / : SLASH
        6 : NUMBER

        output:
        x = 50.8333
```
