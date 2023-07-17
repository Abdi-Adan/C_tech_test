#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    MUL,
    SUB,
    FIBO
} TypeTag;

typedef struct Node
{
    TypeTag type;
    int value1;
    int value2;
} Node;

Node* makeFunc(TypeTag type, int val1, int val2)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    new_node->type = type;
    new_node->value1 = val1;
    new_node->value2 = val2;
    
    return new_node;
}

unsigned int fibo(unsigned int n) {
    unsigned int fib[n+1]; 
    fib[0] = 0;
    fib[1] = 1;

    for( unsigned int i = 2; i <= n; i++)
        fib[i] = fib[i-1] + fib[i-2];

    return fib[n];
}

int calc(Node* node) {
    switch(node->type) {
        case ADD:
            return node->value1 + node->value2;
        case MUL:
            return node->value1 * node->value2;
        case SUB:
            return node->value1 - node->value2;
        case FIBO:
            return fibo(node->value1);
    }
    return 0;
}

int main()
{
    Node *add = makeFunc(ADD, 10, 6);
    Node *mul = makeFunc(MUL, 5, 4);
    Node *sub = makeFunc(SUB, calc(mul), calc(add));
    Node *fibo = makeFunc(FIBO, calc(sub), 0);

    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}
