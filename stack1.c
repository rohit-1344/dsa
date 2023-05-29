#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct {
    int items[STACK_SIZE];
    int top;
} Stack;

void push(Stack* s, int item)
 {
    if (s->top < STACK_SIZE)
        {
        s->items[s->top++] = item;
    }
    else
        {
        printf("Stack is full\n");
    }
}

int pop(Stack* s)
 {
    if (s->top > 0)
        {
        return s->items[--s->top];
    }
    else
        {
        printf("Stack is empty\n");
        return -1;
    }
}

int main()
 {
    Stack s = { .top = 0 };
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s)); // prints 3
    printf("%d\n", pop(&s)); // prints 2
    printf("%d\n", pop(&s)); // prints 1
    printf("%d\n", pop(&s)); // prints "Stack is empty" and returns -1
    return 0;
}
