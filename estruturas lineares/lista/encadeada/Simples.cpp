#include "Simples.h"
#include <stdio.h>
#include <stdlib.h>

Simples::Simples(){
    list_size = 0;
    head = tail = nullptr;
}

Simples::Simples(int n){
    list_size = n;
    head = new No;
    No *prev = head;

    for (int i = 1; i < n; i++) {
        No *aux = new No;
        prev->next = aux;
        prev = aux;
    }

    tail = prev;
}

Simples::Simples(int n, int value){
    list_size = n;
    head = new No(value);
    No *prev = head;

    for (int i = 1; i < n; i++) {
        No *aux = new No(value);
        prev->next = aux;
        prev = aux;
    }

    tail = prev;
}

Simples::~Simples(){
    No* current = head;
    No* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    // redundante pois o objeto será destruido
    // contudo, é uma boa prática
    head = tail = nullptr;
    list_size = 0;
    //////////////////////
}

No* Simples::begin() const {
    return head;
}

No* Simples::end() const {
    return nullptr;
}

// capacity 
size_t Simples::size() const {
    return list_size;
}

bool Simples::empty() const {
    return (list_size == 0); 
}

// element acess
int Simples::front() const {
    if (empty()) {
        fprintf(stderr, "Lista vazia:\n");
        exit(EXIT_FAILURE);
    }
    return head->data;
}

int Simples::back() const {
    if (empty()) {
        fprintf(stderr, "Lista vazia:\n");
        exit(EXIT_FAILURE);
    }
    return tail->data;
}

// modifiers
void Simples::push_back(int value) {
    No *aux = new No(value);

    if (tail) tail->next = aux;
    else head = aux;
    
    tail = aux;
    list_size++;
}

void Simples::pop_back() {
    if (empty()) {
        fprintf(stderr, "Lista vazia:\n");
        exit(EXIT_FAILURE);
    }

    No *it = head;
    No *prev = nullptr;
    
    while (it->next != nullptr) {
        prev = it;
        it = it->next;
    }

    delete tail;
    if (prev) {
        prev->next = nullptr;
        tail = prev;
    } else {
        head = tail = nullptr;
    }

    list_size--;
}

void Simples::insert(size_t pos, int value) {
    if (pos < 1 || pos > list_size + 1) {
        fprintf(stderr, "Posicao invalida:\n");
        exit(EXIT_FAILURE);
    }

    No *aux = new No(value);
    if (pos == 1) {
        aux->next = head;
        head = aux;
        if (list_size == 0) tail = aux;
    } else {
        No *it = head;
        for (size_t i = 1; i < pos - 1; i++) it = it->next;
        
        aux->next = it->next;
        it->next = aux;
        if (aux->next == nullptr) tail = aux;
    }

    list_size++;
}

void Simples::erase(size_t pos) {
    if (empty()) {
        fprintf(stderr, "Lista vazia:\n");
        exit(EXIT_FAILURE);
    }

    if (pos < 1 || pos > list_size) {
        fprintf(stderr, "pos - 1icao invalida:\n");
        exit(EXIT_FAILURE);
    }

    No *it = head;
    No *prev = nullptr;
    for (size_t i = 1; i < pos; i++) {
        prev = it;
        it = it->next;
    }

    if (prev) {
        prev->next = it->next;
    } else {
        head = it->next;
    }

    if (it == tail) {
        tail = prev;
    }

    delete it;
    list_size--;
}

void Simples::assign(size_t pos, int value) {
    if (empty()) {
        fprintf(stderr, "Lista vazia:\n");
        exit(EXIT_FAILURE);
    }

    if (pos < 1 || pos > list_size) {
        fprintf(stderr, "Posicao invalida:\n");
        exit(EXIT_FAILURE);
    }

    No *it = head;
    for (size_t i = 1; i < pos; i++) it = it->next;
    it->data = value;
}
