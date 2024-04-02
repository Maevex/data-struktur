#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("alokasi memori gagal");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
    
}


struct Node* insertEnd(struct Node* head, int data){
    struct Node* newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
        
    }else{
        struct Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }

        return head;
    
}

struct Node* insertFirst(struct Node* head, int data){
    struct Node* newNode = createNode(data);

    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }else{
        struct Node* last = head->prev;
        newNode->next =head;
        head->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
        newNode = head;
    }

    return head;
    
}

struct Node* deleteFirst(struct Node* head){
    if (head == NULL)
    {
        return NULL;
    }

    struct Node* temp = head;
    struct Node* last = head->prev;

    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);

    return head;
    
}

struct Node* deleteEnd(struct Node* head){
    if ( head == NULL){
        return NULL;
    }

    struct Node* last = head->prev;
    struct Node* temp = last;

    if (head->next = head)
    {
        free(head);
        return(NULL);
    }
    
    head->prev = last->prev;
    last->prev->next = head;
    free(temp);

    return head;
}

void displayList(struct Node* head){
    if (head == NULL)
    {
        return;
    }

    struct Node* current = head;
    do
    {
        printf("%d", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
    
    
}
