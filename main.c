#include <stdio.h>
#include <stdlib.h>
#include "lab_1/lab_1.h"
#include "lab_2/lab_2.h"

//typedef struct Node {
//    int data;
//    struct Node *next;
//} Node;
//
//typedef Node *PNode;
//
//PNode Head = NULL;

//const int MAXSIZE = 100;
//
//typedef struct Stack {
//    char data[MAXSIZE];
//    int size;
//} Stack;
//
//void InitStack(Stack *S) {
//    S->size = 0;
//}
//
//void Push(Stack *S, char x) {
//    if (S->size == MAXSIZE) {
//        printf("Стек переполнен\n");
//        return;
//    }
//    S->data[S->size] = x;
//    S->size++;
//}
//
//char Pop(Stack *S) {
//    if (S->size == 0) {
//        printf("Стек пуст\n");
//        return (char)255;
//    }
//    S->size--;
//    return S->data[S->size];
//}
//
//// Стек на списке
//typedef struct Node {
//    int data;
//    struct Node *next, *prev;
//} Node;

//typedef Node *Pointer;
//
//typedef struct {
//    Pointer Head, Tail;
//} Stack;
//
//void Push(Stack *S, int x) {
//    Node* NewNode = (Node*)malloc(sizeof(Node));
//
//    NewNode->data = x;
//    NewNode->next = S->Head;
//    NewNode->prev = NULL;
//
//    if (S->Head) {
//        S->Head->prev = NewNode;
//    }
//    S->Head = NewNode;
//
//    if (!S->Tail) {
//        S->Tail = NewNode;
//    }
//}
//
//char Pop(Stack *S) {
//    Node *TopNode = S->Head;
//    int x;
//
//    if (!TopNode)
//        return (char)255;
//
//    x = TopNode->data;
//    S->Head = TopNode->next;
//
//    if (S->Head) S->Head->prev = NULL;
//    else S->Tail = NULL;
//
//    free(TopNode);
//
//    return x;
//}

int main() {
//    lab_1();
    lab_2();
}
//int main(void) {
//    lab_1();
//    Stack S;
//    InitStack(&S);
//
//    Push(&S, 'a');
//    Push(&S, 'b');
//    Push(&S, 'c');
//
//    printf("Pop: %c\n", Pop(&S)); // c
//    printf("Pop: %c\n", Pop(&S)); // b
//    printf("Pop: %c\n", Pop(&S)); // a
//    printf("Pop: %c\n", Pop(&S)); // Стек пуст

//    Stack S = {NULL, NULL};
//    Push(&S, 10);
//    Push(&S, 20);
//    Push(&S, 30);
//
//    // Вывод списка для проверки
//    Node* current = S.Head;
//    while (current != NULL) {
//        printf("%d ", current->data);
//        current = current->next;
//    }
//    printf("\n");
//
//    printf("Pop: %d\n", Pop(&S)); // 30
//    printf("Pop: %d\n", Pop(&S)); // 20
//    printf("Pop: %d\n", Pop(&S)); // 10
//    printf("Pop: %c\n", Pop(&S)); // Стек пуст
//
//    return 0;
//}

