#ifndef STACK_H
#define STACK_H

#include <cstddef> 

template <typename T>
class Stack {
    public:
        Stack() noexcept;
        ~Stack() noexcept;

        bool empty() const noexcept;
        std::size_t size() const noexcept;
        T& top();
        const T& top() const;
        void push(const T& value);
        void push(T&& value);
        void pop();

    private:
        T *data;
        std::size_t top_index;
        std::size_t capacity;
        void resize(std::size_t new_capacity);

};

#include "stack.tpp"

#endif