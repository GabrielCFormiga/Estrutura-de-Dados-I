#include "queue.h"

template <typename T>
queue<T>::queue() noexcept : data(nullptr), ft(0), bk(0), capacity(0), queue_size (0) {}

template <typename T>
queue<T>::~queue() noexcept {
    delete[] data;
}

template <typename T>
bool queue<T>::empty() const noexcept {
    return queue_size == 0;
}

template <typename T>
std::size_t queue<T>::size() const noexcept {
    return queue_size;
}

template <typename T>
T& queue<T>::front() {
    if (empty()) {
        fprintf(stderr, "Queue vazia:\n");
        exit(EXIT_FAILURE);
    }         

    return data[ft];           
}

template <typename T>
T& queue<T>::back() {
    if (empty()) {
        fprintf(stderr, "Queue vazia:\n");
        exit(EXIT_FAILURE);
    }         

    return data[bk];    
}

template <typename T>
void queue<T>::push(const T& value) {
    if (queue_size == capacity) {
        resize(2 * capacity + 1);
    }

    bk = (bk + 1) % capacity;
    data[bk] = value;
    queue_size++;
}

template <typename T>
void queue<T>::pop() {
    if (empty()) return;

    ft = (ft + 1) % capacity;
    queue_size--;
}

template <typename T>
void queue<T>::resize(std::size_t new_capacity) {
    T* tmp = new T[new_capacity];

    for (std::size_t i = 0; i < queue_size; i++) {
        tmp[i] = data[(ft + i) % capacity];
    }

    delete[] data;
    data = tmp;
    ft = 0;
    bk = queue_size - 1;
    capacity = new_capacity;
}
