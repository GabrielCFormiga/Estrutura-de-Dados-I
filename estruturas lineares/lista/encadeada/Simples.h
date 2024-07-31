#pragma once

#include <stddef.h>

struct No {
    int data;
    No *next;

    No() : data(0), next(nullptr) {}
    No(int value) : data(value), next(nullptr) {}
};

class Simples {
    private:
        No *head;
        No *tail;
        size_t list_size;

    public:
        Simples();
        Simples(int n);
        Simples(int n, int value);
        ~Simples();

        // iterators
        No* begin() const;
        No* end() const;

        // capacity
        size_t size() const;
        bool empty() const;

        // element acess
        int front() const;
        int back() const;
        int get(size_t pos) const;

        // modifiers
        // pos = {1, 2, 3, ...}
        void push_back(int value);
        void pop_back();
        void insert(size_t pos, int value);
        void erase(size_t pos);
        void assign(size_t pos, int value);
};
