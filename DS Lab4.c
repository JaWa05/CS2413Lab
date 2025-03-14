#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct StackNode{
    int val;
    struct StackNode *next;
};

struct Stack{
    struct StackNode *top;
};

typedef struct{
    struct Stack in;
    struct Stack out;
}Queue;



int main(){
    Queue qq;
    myQueueCreate(&qq);

    printf("push 1, 2, 3, 4, 5, 6\n");
    myQueuePush(&qq, 1);
    myQueuePush(&qq, 2);
    myQueuePush(&qq, 3);
    myQueuePush(&qq, 4);
    myQueuePush(&qq, 5);
    myQueuePush(&qq, 6);

    printf("peek queue (1,2,3,4):\n");
    printf("%d ", myQueuePeek(&qq));
    myQueuePop(&qq);
    printf("%d ", myQueuePeek(&qq));
    myQueuePop(&qq);
    printf("%d ", myQueuePeek(&qq));
    myQueuePop(&qq);
    printf("%d ", myQueuePeek(&qq));
    myQueuePop(&qq);


}


void push(struct Stack *stack, int val) {
    if (stack == NULL) return;

    struct StackNode *new_node
        = (struct StackNode *)malloc(sizeof(struct StackNode));

    new_node->val = val;
    new_node->next = stack->top;

    stack->top = new_node;
}

int pop(struct Stack *stack) {
    if (stack == NULL || stack->top == NULL) return 0;

    struct StackNode *t = stack->top;
    int ans = t->val;

    stack->top = stack->top->next;

    free(t);

    return ans;
}


bool isEmpty(struct Stack *stack) {
    if (stack == NULL){
        return true;
    }
    else{
        if(stack->top == NULL){
            return true;
        }
        else{
            return false;
        }
    }
}

void myQueueCreate(Queue *queue, int maxSize) {
    if (queue == NULL) return;

    /* I'm a queue implemented using linked stack, so I don't need maxSize */
    queue->in.top = queue->out.top = NULL;
}


void myQueuePush(Queue * queue, int val){
    if(queue == NULL){
        return;
    }

    while(!isEmpty(&queue->out)){
        int value = pop(&queue->out);
        push(&queue->in, value);
    }
    push(&queue->in, val);
}

void myQueuePop(Queue* queue){
    if(queue == NULL){
        return;
    }

    if(isEmpty(&queue->out)){
        while(!isEmpty(&queue->in)){
            int value = pop(&queue->in);
            push(&queue->out, value);
        }
    }
    pop(&queue->out);
}

int myQueuePeek(Queue *queue){
    if(isEmpty(&queue->out)){
        while(!isEmpty(&queue->in)){
            int value = pop(&queue->in);
            push(&queue->out,value);
        }
    }
    if(!isEmpty(&queue->out) && queue->out.top){
        return queue->out.top->val;
    }
    else{
        return false;
    }
}

void myQueueFree(Queue *queue){
    while(!isEmpty(&queue->out)){
        pop(&queue->out);
    }
    while(!isEmpty(&queue->in)){
        pop(&queue->in);
    }
}



