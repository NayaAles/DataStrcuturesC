//
// Created by Anastasia Aleskovskaya on 24.04.2024.
//

#ifndef DATASTRCUTURESC_LAB_2_H
#define DATASTRCUTURESC_LAB_2_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createList(int count);
Node* insertItemFront(struct Node** head, int newData);
Node* insertItemTail(struct Node** head, int newData);
Node* insertAfter(struct Node **head, int newData, int item);
Node* insertBefore(struct Node **head, int newData, int item);

void printList(struct Node *listHead);
void deleteList(struct Node *listHead);

void lab_2();

#endif //DATASTRCUTURESC_LAB_2_H