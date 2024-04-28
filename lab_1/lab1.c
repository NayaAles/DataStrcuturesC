//
// Created by Mikhail Tatarenko on 24.04.2024.
//

#include <printf.h>
#include <stdlib.h>
#include "lab_1.h"

const int SLICE_CAPACITY = 5;

Slice create() {
    Slice slice;
    slice.size = 0;
    slice.capacity = SLICE_CAPACITY;

    slice.arr = malloc(SLICE_CAPACITY * sizeof(int));

    return slice;
}

void delete(Slice slice) {
    free(slice.arr);
    slice.arr = NULL;
}

Slice append(Slice slice, int item) {
    if (slice.size == slice.capacity) {
        int* newArr = malloc(slice.capacity * 2 * sizeof(int));

        for (int i = 0; i < slice.size; i++) {
            newArr[i] = slice.arr[i];
        }

        free(slice.arr);
        slice.arr = NULL;

        slice.arr = newArr;
        slice.capacity = slice.capacity * 2;
    }

    if (slice.size < slice.capacity) {
        slice.arr[slice.size] = item;
        slice.size += 1;
    }

    return slice;
}

Slice insert(Slice slice, int item, int position) {
    if (position + 1 > slice.capacity) {
        int* newArr = malloc((position + 1) * sizeof(int));

        for (int i = 0; i < slice.size; i++) {
            newArr[i] = slice.arr[i];
        }

        free(slice.arr);
        slice.arr = NULL;

        slice.arr = newArr;
        slice.capacity = slice.size = position + 1;

        slice.arr[position] = item;
    } else {
        slice.arr[position] = item;
        slice.size = position + 1;
    }

    return slice;
}

Slice removeItem(Slice slice, int position){
    if (position < slice.size) {

        for (int i = position; i < slice.size; i++) {
            slice.arr[i] = slice.arr[i+1];
        }

        slice.arr[slice.size] = 0;
        slice.size = slice.size - 1;
    }

    return slice;
}

void print(Slice slice) {
    for (int i = 0; i < slice.size; i++) {
        printf("%d ", slice.arr[i]);
    }
}

// leaks --atExit -- ./cmake-build-debug/DataStrcuturesC
void lab_1() {
    Slice slice = create(); // malloc 5
    printf("Capacity:%d\n", slice.capacity);

    // Добавление
    printf("\n%s\n", "Добавление:");
    slice = append(slice, 1);
    slice = append(slice, 2);
    slice = append(slice, 3);
    slice = append(slice, 4);
    slice = append(slice, 5);
    slice = append(slice, 6);
    print(slice);
    printf("\nCapacity:%d; size:%d\n", slice.capacity, slice.size);

    // Вставка
    printf("\n%s\n", "Вставка:");
    slice = insert(slice, 7, 6);
    print(slice);
    printf("\nCapacity:%d; size:%d\n", slice.capacity, slice.size);
    slice = insert(slice, 11, 10);
    print(slice);
    printf("\nCapacity:%d; size:%d\n", slice.capacity, slice.size);
    slice = insert(slice, 21, 20);
    print(slice);
    printf("\nCapacity:%d; size:%d\n", slice.capacity, slice.size);

    // Удаление
    printf("\n%s\n", "Удаление:");
    slice = removeItem(slice, 20);
    print(slice);
    printf("\nCapacity:%d; size:%d\n", slice.capacity, slice.size);
    slice = removeItem(slice, 5);
    print(slice);
    printf("\nCapacity:%d; size:%d\n", slice.capacity, slice.size);

    delete(slice);
}


