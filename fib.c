#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag { ADD, SUB, MUL, DIV } TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *makeFunc(TypeTag type, int leftValue, int rightValue) {
    Node *node = malloc(sizeof(Node));
    node->type = type;
    node->value = 0;
    node->left = malloc(sizeof(Node));
    node->left->type = type;
    node->left->value = leftValue;
    node->left->left = NULL;
    node->left->right = NULL;
    node->right = malloc(sizeof(Node));
    node->right->type = type;
    node->right->value = rightValue;
    node->right->left = NULL;
    node->right->right = NULL;
    return node;
}

int calc(Node *node) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        return node->value;
    }
    int leftValue = calc(node->left);
    int rightValue = calc(node->right);
    switch (node->type) {
        case ADD:
            node->value = leftValue + rightValue;
            break;
        case SUB:
            node->value = leftValue - rightValue;
            break;
        case MUL:
            node->value = leftValue * rightValue;
            break;
        case DIV:
            node->value = leftValue / rightValue;
            break;
        default:
            break;
    }
    return node->value;
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    
    int f[n+1];
    
    f[0] = 0; 
    f[1] = 1; 
    
    for (int i=2; i<=n; i++) {
        Node *addNode = makeFunc(ADD, f[i-1], f[i-2]);
        f[i] = calc(addNode);
        free(addNode);
    }
    
    return f[n];
}

void freeNode(Node *node) {
  if (node == NULL) {
      return;
  }
  freeNode(node->left);
  freeNode(node->right);
  free(node);
}

int main() {
  Node *addNode = makeFunc(ADD, 10, 6);
  Node *mulNode = makeFunc(MUL, 5, 4);
  Node *subNode = makeFunc(SUB, calc(mulNode), calc(addNode));
  Node *fiboNode = makeFunc(SUB, calc(subNode), 0);

  printf("add: %d\n", calc(addNode));
  printf("mul: %d\n", calc(mulNode));
  printf("sub: %d\n", calc(subNode));
  printf("fibo: %d\n", fib(calc(fiboNode)));

  freeNode(addNode);
  freeNode(mulNode);
  freeNode(subNode);
  free(fiboNode);

  return 0;
}