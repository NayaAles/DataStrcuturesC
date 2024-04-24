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
    if (position > slice.capacity) {
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

        if (position > slice.size) {
            slice.size = position + 1;
        }
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
    Slice slice = create();
    slice = append(slice, 24);

//    slice = insert(slice, 26, 10);
    slice = insert(slice, 24, 0);
    print(slice);

    delete(slice);
}


