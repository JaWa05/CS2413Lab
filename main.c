#include <stdio.h>
#include <stdlib.h>


//function definirion
struct ListNode* reverseList(struct ListNode* head);

//defines the listnode structure
struct ListNode{
    int val;
    struct Node *next;
};

int main()
{
    struct ListNode *head = NULL;

    push(&head,1);
    push(&head, 2);
    push(&head, 3);



    printf("linked list before reversing:\n");
    print(head);


    struct ListNode* newNode = reverseList(head);
    printf("linked list after reversing:\n");

    print(newNode);








}

//push function - adds new nodes to the front
void push(struct ListNode** head_ref, int val){
    //allocate memory for tha node
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    //put data in new node
    new_node->val = val;
    //make new node piont to head
    new_node->next = (*head_ref);
    //make new node = head
    (*head_ref) = new_node;
}


//print function
void print(struct ListNode* n){
    //runs through the linked list and prints every value holded in the nodes
    while(n!=NULL){
        printf("%d ",n->val);
        n = n->next;
    }
    printf("\n");
}




//function reverses the linkedlist
struct ListNode* reverseList(struct ListNode* head) {


    struct ListNode* temp = head;
    struct ListNode* prev = NULL;
    struct ListNode* ahead = NULL;

    // loop runs through the linked list
    while (temp != NULL) {

        // stores the next after temp
        ahead = temp->next;

        // switches the positions of ahead and prev
        temp->next = prev;

        // pointers move through linked list
        prev = temp;
        temp = ahead;
    }

    //returns prev which is the new head
    return prev;
}
