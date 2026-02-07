# Program 2: Infix to Postfix Conversion and Evaluation

## Data Structures Used

### Character Stack
```c
struct Stack {
    int top;
    char arr[MAX];
};
```
Used for storing operators during conversion.

### Integer Stack
```c
struct IntStack {
    int top;
    int arr[MAX];
};
```
Used for evaluating postfix expression.

## Functions Implemented

### Conversion Functions

**getPrecedence(char op)** - Returns precedence value of operators (1 for +/-, 2 for */,  3 for ^)

**isOperator(char c)** - Checks if character is an operator

**infixToPostfix(char* infix, char* postfix)** - Main conversion function
- Scans infix expression left to right
- Operands are added directly to output
- Operators are pushed to stack based on precedence
- Parentheses control the order

### Evaluation Functions

**evaluatePostfix(char* postfix)** - Evaluates postfix expression
- Uses integer stack
- Scans expression left to right
- Pushes operands to stack
- For operators, pops two values, computes result, pushes back

### Stack Operations

**push/pop/peek** - Standard stack operations for char stack

**pushInt/popInt** - Stack operations for integer stack

## How main() Works

1. Takes infix expression as input from user
2. Converts it to postfix using infixToPostfix()
3. Displays the postfix expression
4. Demonstrates evaluation with a test case (2+3*4)
5. Shows both conversion and evaluation result

## Sample Output
```
Enter infix expression: a+b*c
Postfix expression: abc*+

Test: 2+3*4 converted to 234*+
Evaluation result: 14
```

## Algorithm Explanation

**Infix to Postfix:** Uses operator precedence and stack. Higher precedence operators are output first. Parentheses override normal precedence.

**Evaluation:** Scans postfix expression, uses stack to store operands. When operator found, pops two operands, performs operation, pushes result back.