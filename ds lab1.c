
#include <stdio.h>
#include <stdlib.h>


struct ListNode* removeElements(struct ListNode* head, int value);

struct ListNode{
    int val;
    struct Node *next;
};



int main()
{
    struct ListNode *head = NULL;

    push(&head,2);
    push(&head,3);
    push(&head,6);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    push(&head,7);
    push(&head,8);

    printf("before removing elements: \n");

    print(head);

    removeElements(head, 6);

    printf("after removing elements: \n");

    print(head);


}

//adds new nodes to the front of the linked list
void push(struct ListNode** head_ref, int val){
    struct ListNode *new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}


//runs through the linked list and prints every node
void print(struct ListNode* n){
    while(n!=NULL){
        printf("%d ",n->val);
        n = n->next;
    }
    printf("\n");
}

struct ListNode* removeElements(struct ListNode* head, int value) {
    struct ListNode* temp = head;
    struct ListNode* prev = NULL;

   //runs through the linked list
    while(temp != NULL){

            //if the current node needs to be deleted and its not the first node
            if(temp->val == value && prev != NULL){

                prev->next = temp->next;
                free(temp);
                temp = prev-> next;
            }
            //if the current node needs to be deleted and its the first node
            else if(temp->val == value && prev == NULL){
                head = temp->next;
                free(temp);
                temp = head;
            }
            //moves through the linked list
            else{
                prev = temp;
                temp = temp->next;
            }
    }

    return head;
}




