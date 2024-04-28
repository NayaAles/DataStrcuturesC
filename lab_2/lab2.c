//
// Created by Anastasia Aleskovskaya on 24.04.2024.
//

#include "lab_2.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//struct Node {
//    int data;
//    struct Node *next;
//};

Node* createList(int count) {
    struct Node *head = NULL;
    struct Node *current = NULL;

    for (int i = 0; i < count; i++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            fprintf(stderr, "Ошибка выделения памяти\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = rand() % 100;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            current->next = newNode;
        }
        current = newNode;
    }

    return head;
}

Node* insertItemFront(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    if (newNode == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = newData;
    newNode->next = (*head);

    (*head) = newNode;

    return *head;
}

Node* insertItemTail(struct Node** head, int newData) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head;

    if (new_node == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = newData;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;

        return *head;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;

    return *head;
}

void printList(struct Node *listHead){
    struct Node *temp = listHead;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteList(struct Node *listHead){
    struct Node *temp = listHead;

    temp = listHead;
    while (temp != NULL) {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }
}

Node* insertBefore(struct Node **head, int newData, int item) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = newData;

    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == item) {
        new_node->next = temp;
        *head = new_node;

        return *head;
    }

    while (temp != NULL && temp->data != item) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Узел с данными %d не найден.\n", item);
        free(new_node);

        return *head;
    }

    new_node->next = temp;
    prev->next = new_node;

    return *head;
}

Node* insertAfter(struct Node **head, int newData, int item) {
    struct Node *current = *head;

    while (current != NULL && current->data != item) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Узел с данными %d не найден.\n", item);

        return *head;
    }

    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = newData;
    new_node->next = current->next;
    current->next = new_node;

    return *head;
}

void lab_2() {
    srand(time(NULL));

    struct Node *listHead = createList(5);
    printList(listHead);

    listHead = insertItemFront(&listHead, 1);
    printList(listHead);

    listHead = insertItemTail(&listHead, 7);
    printList(listHead);

    listHead = insertBefore(&listHead, 0, 1);
    printList(listHead);

    listHead = insertAfter(&listHead, 8, 7);
    printList(listHead);

    deleteList(listHead);
}