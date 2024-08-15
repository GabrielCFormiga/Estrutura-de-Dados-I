#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

template <typename T>
class queue {
    public:
        queue() noexcept;
        ~queue() noexcept;

        bool empty() const noexcept;
        std::size_t size() const noexcept;
        T& front();
        T& back();
        void push(const T& value);
        void pop();

    private:
        T *data;
        std::size_t ft;
        std::size_t bk;
        std::size_t queue_size;
        std::size_t capacity;
        void resize(std::size_t new_capacity);

};

#include "queue.tpp"

#endif

