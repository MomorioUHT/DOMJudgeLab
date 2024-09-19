#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void insertNode(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

bool isInList(Node* head, int data) {
    Node* iterator = head;
    while (iterator != NULL) {
        if (iterator->data == data) {
            return true;
        }
        iterator = iterator->next;
    }
    return false;
}

void concatTheNode(Node **key, Node **tempList) {
    if (*tempList == NULL) return;

    Node *keyIterator = *key;
    Node *tempListIterator = *tempList;

    bool isInKey = isInList(*key, tempListIterator->data);

    if (!isInKey) return;

    int firstTempData = tempListIterator->data;
    while (keyIterator != NULL && keyIterator->data != firstTempData) {
        keyIterator = keyIterator->next;
    }

    Node *insertionPoint = keyIterator;

    tempListIterator = tempListIterator->next; 
    while (tempListIterator != NULL) {
        if (!isInList(*key, tempListIterator->data)) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = tempListIterator->data;
            newNode->next = insertionPoint->next;
            insertionPoint->next = newNode;
            insertionPoint = newNode;
        }
        tempListIterator = tempListIterator->next;
    }
}

void printNode(Node **head) {
    Node *curr = *head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    Node *Key = NULL;

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int val;

        if (i == 0) {
            while (1) {
                scanf("%d", &val);
                if (val == 0) break;
                insertNode(&Key, val);
            }
        } else {
            Node *Temp = NULL;
            while (1) {
                scanf("%d", &val);
                if (val == 0) break;
                insertNode(&Temp, val);
            }
            concatTheNode(&Key, &Temp);
        }
    }

    printNode(&Key);

    return 0;
}
