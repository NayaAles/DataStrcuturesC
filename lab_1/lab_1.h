//
// Created by Mikhail Tatarenko on 24.04.2024.
//

#ifndef DATASTRCUTURESC_LAB_1_H
#define DATASTRCUTURESC_LAB_1_H

typedef struct Slice {
    int* arr;
    int capacity;
    int size;
} Slice;

Slice create();
void delete(Slice slice);

Slice append(Slice slice, int item);

Slice insert(Slice slice, int item, int position);

Slice removeItem(Slice slice, int position);

void print(Slice slice);
void lab_1();

#endif //DATASTRCUTURESC_LAB_1_H
