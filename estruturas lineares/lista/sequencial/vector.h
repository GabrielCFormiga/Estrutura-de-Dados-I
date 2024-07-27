#pragma once

#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;

} Vector;

void init(Vector *vec, size_t n);
void vec_free(Vector *vec);
void vec_print(Vector *vec);

// capacity
void resize(Vector *vec, size_t n);
int empty(Vector *vec);
int full(Vector *vec);
size_t capacity(Vector *vec);
size_t size(Vector *vec);
void shrink_to_fit(Vector *vec);

// Element access
int get(Vector *vec, int index);

// modifiers
void push_back(Vector *vec, int value);
void pop_back(Vector *vec);
void insert(Vector *vec, int index, int value);
void erase(Vector *vec, int index);
void assign(Vector *vec, int index, int value);
