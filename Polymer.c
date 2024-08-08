#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[11];
    unsigned long long value;
    struct Node* next;
} Node;

Node* createNode(char* name, unsigned long long value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, char* name, unsigned long long value) {
    Node* newNode = createNode(name, value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node* current = *head;
    Node* index = NULL;
    char tempName[11];
    unsigned long long tempValue;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->value > index->value) {
                strcpy(tempName, current->name);
                strcpy(current->name, index->name);
                strcpy(index->name, tempName);

                tempValue = current->value;
                current->value = index->value;
                index->value = tempValue;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void printList(Node* head, unsigned long long sum) {
    printf("Polymer Chain:\n");
    Node* current = head;
    while (current != NULL) {
        printf("%s (%llu) -> ", current->name, current->value);
        current = current->next;
    }
    printf("None\n");
    printf("Total Bond Strength: %llu + x,\n", sum);
    printf("when x is total bond strength in each monomers\n");
    printf("connected bonds");
}

int main() {
    Node* head = NULL;
    char name[11];
    unsigned long long value;    
    unsigned long long sum = 0;

    while (scanf("%s %llu", name, &value) != EOF) {
        insertEnd(&head, name, value);
        sum += value;
    }

    sortList(&head);
    printList(head, sum);

    return 0;
}
