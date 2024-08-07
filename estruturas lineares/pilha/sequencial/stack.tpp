#include "stack.h"

template <typename T>
Stack<T>::Stack() noexcept : data(nullptr), top_index(0), capacity(0) {}

template <typename T>
Stack<T>::~Stack() noexcept {
    delete[] data;
}

template <typename T>
bool Stack<T>::empty() const noexcept {
    return top_index == 0;
} 

template <typename T>
std::size_t Stack<T>::size() const noexcept {
    return top_index;
}

template <typename T>
T& Stack<T>::top() {
    if (empty()) {
        fprintf(stderr, "Stack vazia:\n");
        exit(EXIT_FAILURE);
    }

    return data[top_index - 1];
}

template <typename T>
const T& Stack<T>::top() const {
    if (empty()) {
        fprintf(stderr, "Stack vazia:\n");
        exit(EXIT_FAILURE);
    }

    return data[top_index - 1];
}

template <typename T>
void Stack<T>::push(const T& value) {
    if (top_index == capacity) {
        resize(capacity == 0 ? 1 : 2 * capacity);
    }
    data[top_index++] = value; // Copiando o valor
}

template <typename T>
void Stack<T>::push(T&& value) {
    if (top_index == capacity) {
        resize(capacity == 0 ? 1 : 2 * capacity);
    }
    data[top_index++] = std::move(value); // Movendo o valor
}

template <typename T>
void Stack<T>::pop() {
    if (empty()) {
        fprintf(stderr, "Stack vazia:\n");
        exit(EXIT_FAILURE);
    }
    top_index--;
}

template <typename T>
void Stack<T>::resize(std::size_t new_capacity) {
    T *new_data = new T[new_capacity];
    for (std::size_t i = 0; i < top_index; i++) {
        new_data[i] = std::move(data[i]);
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}