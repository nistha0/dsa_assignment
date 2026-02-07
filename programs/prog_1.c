#include <stdio.h>
#include <string.h>

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void init(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return (s->top == -1);
}

void push(struct Stack* s, char ch) {
    if(s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = ch;
}

char pop(struct Stack* s) {
    if(isEmpty(s)) {
        return '\0';
    }
    char ch = s->arr[s->top];
    s->top--;
    return ch;
}

int isMatchingPair(char open, char close) {
    if(open == '(' && close == ')') return 1;
    if(open == '[' && close == ']') return 1;
    if(open == '{' && close == '}') return 1;
    return 0;
}

int checkBalance(char* expr) {
    struct Stack s;
    init(&s);
    
    for(int i = 0; i < strlen(expr); i++) {
        char current = expr[i];
        
        if(current == '(' || current == '[' || current == '{') {
            push(&s, current);
        }
        else if(current == ')' || current == ']' || current == '}') {
            if(isEmpty(&s)) {
                return 0;
            }
            char top = pop(&s);
            if(!isMatchingPair(top, current)) {
                return 0;
            }
        }
    }
    
    return isEmpty(&s);
}

int main() {
    char expr1[] = "a + (b - c) * (d";
    char expr2[] = "m + [a - b * (c + d * {m)]";
    char expr3[] = "a + (b - c)";
    
    printf("Testing expression: %s\n", expr1);
    if(checkBalance(expr1))
        printf("Result: Balanced\n\n");
    else
        printf("Result: Not Balanced\n\n");
    
    printf("Testing expression: %s\n", expr2);
    if(checkBalance(expr2))
        printf("Result: Balanced\n\n");
    else
        printf("Result: Not Balanced\n\n");
    
    printf("Testing expression: %s\n", expr3);
    if(checkBalance(expr3))
        printf("Result: Balanced\n\n");
    else
        printf("Result: Not Balanced\n\n");
    
    return 0;
}
