#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int val;
    struct Node *next;
};

struct Queue{
    int size;
    struct Node *front;
    struct Node *back;
};

void push(struct Queue *queue, int value){
    if(queue==NULL){
        return;
    }
    struct Node *nNode = (struct Node *)malloc(sizeof(struct Node));
    nNode->val = value;
    nNode->next = NULL;

    if(queue->back!=NULL){
        queue->back->next = nNode;
    }

    queue->back =nNode;

    if(queue->front == NULL){
        queue->front = nNode;
        queue->size = 1;
    }
    else{
        queue->size++;
    }
}

void pop(struct Queue *queue){
    if(queue == NULL){
        return;
    }
    else{
        struct Node * temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        queue->size--;
        if(queue->front==NULL){
            queue->back = NULL;
            queue->size = 0;
        }
    }
}

int size(struct Queue *queue){
    if(queue ==NULL){
        return 0;
    }
    else{
        return queue->size;
    }
}

bool isEmpty(struct Queue *queue){
    if(queue==NULL){
        return true;
    }
    else{
        return false;
    }
}

typedef struct{
    struct Queue queue;
}Stack;

void StackCreate(Stack *stack){
    if(stack==NULL){
        return;
    }
    stack->queue.front = 0;
    stack->queue.back = 0;
    stack->queue.size = 0;
}

void Stackpush(Stack *stack, int value){
    if(stack == NULL){
        return;
    }
    else{
        push(&stack->queue,value);
    }
}

void stackPop(Stack *stack) {
    if (stack == NULL) return;

    int fSize = size(&stack->queue);
    for (int i = 0; i < fSize - 1; i++) {
        if (stack->queue.front == NULL) {
            return;
        }
        int tmp = stack->queue.front->val;
        pop(&stack->queue);
        push(&stack->queue, tmp);
    }

    pop(&stack->queue);
}

int stackTop(Stack *stack){
    if(stack==NULL || stack->queue.back == NULL){
        return 0;
    }
    else{
        return stack->queue.back->val;
    }
}

void stackDestroy(Stack *stack){
    if(stack==NULL){
        return;
    }
    while(size(&stack->queue)>0){
        pop(&stack->queue);
    }
}

int main(){
    Stack stacc;
    StackCreate(&stacc);

    printf("push 1,2,3,4\n");
    Stackpush(&stacc, 1);
    Stackpush(&stacc, 2);
    Stackpush(&stacc, 3);
    Stackpush(&stacc, 4);

    printf("top of stack:\n");
    printf("%d ", stackTop(&stacc));
    stackPop(&stacc);
    printf("%d ", stackTop(&stacc));
    stackPop(&stacc);
}
