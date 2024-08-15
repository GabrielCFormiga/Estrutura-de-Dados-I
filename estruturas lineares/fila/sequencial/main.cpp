#include <iostream>
#include "queue.h"

int main() {
    queue<int> q;

    // Testa se a fila está inicialmente vazia
    std::cout << "A fila está vazia? " << (q.empty() ? "Sim" : "Não") << std::endl;

    // Testa inserção de elementos na fila
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Tamanho da fila após inserir 3 elementos: " << q.size() << std::endl;

    // Testa acesso ao primeiro e último elemento
    std::cout << "Primeiro elemento (front): " << q.front() << std::endl;
    std::cout << "Último elemento (back): " << q.back() << std::endl;

    // Testa remoção de elementos
    q.pop();
    std::cout << "Tamanho da fila após remover um elemento: " << q.size() << std::endl;
    std::cout << "Primeiro elemento (front) após pop: " << q.front() << std::endl;

    // Testa o comportamento com mais inserções e remoções
    q.push(40);
    q.push(50);
    std::cout << "Último elemento (back) após mais inserções: " << q.back() << std::endl;

    q.pop();
    q.pop();
    std::cout << "Tamanho da fila após remover mais dois elementos: " << q.size() << std::endl;
    std::cout << "Primeiro elemento (front) após mais pop: " << q.front() << std::endl;

    // Testa remoção até a fila ficar vazia
    q.pop();
    q.pop();
    std::cout << "A fila está vazia após remover todos os elementos? " << (q.empty() ? "Sim" : "Não") << std::endl;

    return 0;
}
