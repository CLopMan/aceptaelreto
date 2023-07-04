#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    /*Node structure. Stores an int element and the pointer to the next element*/
    int element;
    struct Node* next;
} Node;

typedef struct __Stack {
    /*private Stack*/
    Node* centinela;
    int size;
} __Stack;

// Public Stack
typedef __Stack* Stack;

Node Node_init(int elem, Node* next) {
    /*Creates a new Node given 2 parameters*/
    Node node;
    node.element = elem;
    node.next = next; 
    return node;
}

/*__Stack Methods*/

__Stack __Stack_init() {
    /*Creates a private Stack. Not visible to the programer*/
    __Stack stack; 
    stack.centinela = NULL;
    stack.size = 0;
    return stack;
}

/*Stack Methods*/

Stack Stack_init() {
    /*Creates the public Stack. Pointer to a __Stack*/
    __Stack stack = __Stack_init();
    Stack stackp = (Stack) malloc(sizeof(__Stack));
    *stackp = stack;
    return stackp;
}

void Stack_push(int elem, Stack self) {
    /*Push a new element into the stack*/
    Node* new_node = (Node*) malloc(sizeof(Node));
    *new_node = Node_init(elem, self->centinela);
    self->centinela = new_node;
    ++self->size;
}

int Stack_pop(Stack self) {
    /*deletes and return the last element included in the stack (LIFO)*/
    if (self->size == 0) {
        return -1; // case of error
    }
    Node* aux = self->centinela;
    self->centinela = aux->next;
    --self->size;
    int out = aux->element;
    free(aux);
    return out;
}

int Stack_empty(Stack self) {
    if (self->size > 0) return 1;
    return 0;
}

void Stack_print(Stack self) {
    /*Print the Stack*/

    if (self->size <= 0) { 
        printf("[]");
        return;
    }

    Node* aux = self->centinela;
    printf("[");
    for (int i = 0; i < self->size -1; ++i) {
        printf("%i -> ", aux->element);
        aux = aux->next;
    }
    printf("%i]", aux->element);
}

int main() {
    /*Test the Stack */
    Stack Stack = Stack_init();
    
    Stack_pop(Stack); // pop from an empty stack
    Stack_print(Stack);printf("\n");

    for (int i = 0; i < 20; ++i) {
        /*Insertion test*/
        //printf("hi%i\n", i);
        Stack_push(i, Stack);
    }

    printf("size: %i\n", Stack->size);
    Stack_print(Stack);printf("\n");
    
    //printf("prueba: %i %i %i %i\n", Stack.centinela->element, Stack.centinela->next->element, Stack.centinela->next->next->element, Stack.centinela->next->next->next->element);

    printf("pop: %i\n", Stack_pop(Stack)); // pop of some element
    printf("size: %i\n", Stack->size);
    printf("pop: %i\n", Stack_pop(Stack)); // pop of an element
    printf("size: %i\n", Stack->size);
    printf("pop: %i\n", Stack_pop(Stack)); // pop of an element
    printf("size: %i\n", Stack->size);
    Stack_print(Stack);printf("\n");

    while(Stack_empty(Stack)) {
        printf("%i\n", Stack_pop(Stack));
    }
    Stack_print(Stack);printf("\n");
    return 0;
}
