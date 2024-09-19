#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

void insertNode(Node **head, int val) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->val = val;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    } else{
        Node *curr = *head;
        while (curr->next != NULL) {
            if (val == curr->val) {
                return;
            }
            curr = curr->next;
        }

        if (val == curr->val) {
            return;
        }
        
        curr->next = temp;
    }
}
int main() {
    Node *head = NULL;
    
    int inputVal = 99;

    while (inputVal != 0) {
        scanf("%d", &inputVal);
        if (inputVal == 0) {
            break;
        }
        insertNode(&head, inputVal);
    }

    Node *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
}