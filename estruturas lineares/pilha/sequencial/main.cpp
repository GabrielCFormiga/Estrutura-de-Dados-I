#include <iostream>
#include "stack.h"

int main() {
    Stack<int> stack;

    // Testando se a pilha está inicialmente vazia
    std::cout << "A pilha está vazia? " << (stack.empty() ? "Sim" : "Não") << std::endl;

    // Adicionando elementos na pilha
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Verificando o tamanho da pilha
    std::cout << "Tamanho da pilha após três push: " << stack.size() << std::endl;

    // Acessando o elemento do topo
    std::cout << "Elemento no topo: " << stack.top() << std::endl;

    // Removendo o elemento do topo
    stack.pop();

    // Verificando o novo elemento do topo e o tamanho da pilha
    std::cout << "Elemento no topo após um pop: " << stack.top() << std::endl;
    std::cout << "Tamanho da pilha após um pop: " << stack.size() << std::endl;

    // Adicionando mais um elemento com push usando move semantics
    stack.push(40);

    // Verificando o elemento do topo e o tamanho da pilha novamente
    std::cout << "Elemento no topo após adicionar 40: " << stack.top() << std::endl;
    std::cout << "Tamanho da pilha após adicionar 40: " << stack.size() << std::endl;

    // Esvaziando a pilha
    stack.pop();
    stack.pop();
    stack.pop();

    // Verificando se a pilha está vazia novamente
    std::cout << "A pilha está vazia após esvaziar? " << (stack.empty() ? "Sim" : "Não") << std::endl;

    return 0;
}
