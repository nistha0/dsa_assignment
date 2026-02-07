# Program 1: Balanced Parentheses Checker

## Data Structures Used

Stack structure with array implementation:
```c
struct Stack {
    char arr[MAX];
    int top;
};
```

## Functions Implemented

**init()** - Initializes empty stack by setting top to -1

**isEmpty()** - Returns 1 if stack is empty, 0 otherwise

**push()** - Adds character to top of stack after checking overflow

**pop()** - Removes and returns top character from stack

**isMatchingPair()** - Checks if opening and closing brackets match

**checkBalance()** - Main function that uses stack to verify balanced parentheses

## How main() Works

The main function tests three different expressions by calling checkBalance() for each and printing whether the parentheses are balanced or not.

## Sample Output
```
Testing expression: a + (b - c) * (d
Result: Not Balanced

Testing expression: m + [a - b * (c + d * {m)]
Result: Not Balanced

Testing expression: a + (b - c)
Result: Balanced
```