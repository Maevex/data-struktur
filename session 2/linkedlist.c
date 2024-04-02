#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int data) {
 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Alokasi Memori gagal.\n");
        exit(1);
    }


    newNode->data = data;
    newNode->next = head;

    
    return newNode;
}

void insertAtEnd(struct Node* head, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head == newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    
    
}

struct Node* deleteAtBeginning(struct Node* head){
    if (head == NULL)
    {
        printf("Linked List Kosong\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
    
}

void deleteAtEnd(struct Node* head){
    if(head == NULL){
        printf("Linked list kosong");
        return;
    }

    struct Node* temp = head;
    struct Node* prevNode = NULL;
    while (temp->next != NULL)
    {
        prevNode = temp;
        temp = temp-> next;
    }

    if (prevNode != NULL)
    {
        prevNode->next = NULL;
        free(temp);
    } else
    {
        free(head);
        head = NULL;
    }
    
    
    
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
