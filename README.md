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
        std::cout << i.value << " type: " << static_cast<int>(i.token) << '\n';
    }

    parse(token1);

```
```bash
    --- Token 1 ---

      x type: 0
      = type: 10
      ( type: 6
      10.0 type: 1
      + type: 2
      10.0 type: 1
      ) type: 7
      * type: 4
      2.5 type: 1
      + type: 2
      5 type: 1
      / type: 5
      6 type: 1/ 

      output:
      x = 50.8333
```
