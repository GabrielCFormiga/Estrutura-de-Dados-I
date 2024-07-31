#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

void init(Vector *vec, size_t n) {
    vec->data = (int *) calloc(n, sizeof(int));

    if (vec->data == NULL) {
        fprintf(stderr, "Erro ao alocar memória:\n");
        exit(EXIT_FAILURE);
    }

    vec->size = 0;
    vec->capacity = n;
}

void vec_free(Vector *vec) {
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

void vec_print(Vector *vec) {
    if (empty(vec)) {
        printf("Vetor vazio\n");
        return;
    }

    for (int i = 0; i < vec->size; i++) {
        printf("%d%c", vec->data[i], (i == vec->size - 1 ? '\n' : ' '));
    }
}

// capacity
void resize(Vector *vec, size_t n) {
    int *tmp = (int *) realloc(vec->data, n * sizeof(int));

    if (tmp == NULL) {
        fprintf(stderr, "Erro ao alocar memória:\n");
        exit(EXIT_FAILURE);
    }

    vec->data = tmp;
    vec->capacity = n;
};

int empty(Vector *vec) {
    return (vec->size == 0);
}

int full(Vector *vec) {   
    return (vec->size == vec->capacity);
}

size_t capacity(Vector *vec) {
    return vec->capacity;
}

size_t size(Vector *vec) {
    return vec->size;
}

void shrink_to_fit(Vector *vec) {
    if (vec->size == vec->capacity) return;
    resize(vec, vec->size);
}

// Element access
int get(Vector *vec, int index) {
    if (index < 0 || index >= vec->size) {
        fprintf(stderr, "Índice fora dos limites:\n");
        exit(EXIT_FAILURE);
    }

    return vec->data[index];
}

// modifiers
void push_back(Vector *vec, int value) {
    if (vec->capacity == vec->size) resize(vec, 2 * vec->capacity);

    vec->data[vec->size] = value;
    vec->size++;  
};

void pop_back(Vector *vec) {
    if (vec->size == 0) {
        fprintf(stderr, "Vetor vazio:\n");
        exit(EXIT_FAILURE);
    }

    vec->data[vec->size - 1] = 0;
    vec->size--;
}

void insert(Vector *vec, int index, int value) {
    if (index < 0 || index >= vec->size) {
        fprintf(stderr, "Índice fora dos limites:\n");
        exit(EXIT_FAILURE);
    }
    
    if (vec->size == vec->capacity) resize(vec, 2 * vec->capacity);

    for (int i = vec->size; i > index; i--) {
        vec->data[i] = vec->data[i - 1];
    }

    vec->data[index] = value;
    vec->size++;
}

void erase(Vector *vec, int index) {
    if (index < 0 || index >= vec->size) {
        fprintf(stderr, "Índice fora dos limites:\n");
        exit(EXIT_FAILURE);
    }

    for (int i = index; i < vec->size - 1; i++) {
        vec->data[i] = vec->data[i + 1];
    }

    vec->data[vec->size - 1] = 0;
    vec->size--;
}

void assign(Vector *vec, int index, int value) {
    if (index < 0 || index >= vec->size) {
        fprintf(stderr, "Índice fora dos limites:\n");
        exit(EXIT_FAILURE);
    }

    vec->data[index] = value;
}