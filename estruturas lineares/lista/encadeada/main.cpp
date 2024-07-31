#include "Simples.h"
#include <iostream>

using namespace std;

int main() {
    // Testa o construtor padrão
    Simples list1;
    cout << "Lista 1 (construtor padrão) - Tamanho: " << list1.size() << ", Vazia: " << (list1.empty() ? "Sim" : "Não") << endl;

    // Testa o construtor com n elementos
    Simples list2(5); // Cria uma lista com 5 elementos, todos com valor 0
    cout << "Lista 2 (construtor com n elementos) - Tamanho: " << list2.size() << ", Vazia: " << (list2.empty() ? "Sim" : "Não") << endl;
    
    // Testa o construtor com n elementos e valor inicial
    Simples list3(3, 10); // Cria uma lista com 3 elementos, todos com valor 10
    cout << "Lista 3 (construtor com n elementos e valor inicial) - Tamanho: " << list3.size() << endl;
    
    // Exibe elementos da lista 3
    cout << "Elementos da Lista 3: ";
    for (No* it = list3.begin(); it != list3.end(); it = it->next) {
        cout << it->data << " ";
    }
    cout << endl;

    // Testa push_back e exibe a lista
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);
    cout << "Lista 1 após push_back: ";
    for (No* it = list1.begin(); it != list1.end(); it = it->next) {
        cout << it->data << " ";
    }
    cout << endl;

    // Testa insert e exibe a lista
    list1.insert(2, 99); // Insere 99 na posição 2
    cout << "Lista 1 após insert(2, 99): ";
    for (No* it = list1.begin(); it != list1.end(); it = it->next) {
        cout << it->data << " ";
    }
    cout << endl;

    // Testa assign e exibe a lista
    list1.assign(3, 88); // Atribui 88 à posição 3
    cout << "Lista 1 após assign(3, 88): ";
    for (No* it = list1.begin(); it != list1.end(); it = it->next) {
        cout << it->data << " ";
    }
    cout << endl;

    // Testa pop_back e exibe a lista
    list1.pop_back();
    cout << "Lista 1 após pop_back: ";
    for (No* it = list1.begin(); it != list1.end(); it = it->next) {
        cout << it->data << " ";
    }
    cout << endl;

    // Testa erase e exibe a lista
    list1.erase(2); // Remove o elemento da posição 2
    cout << "Lista 1 após erase(2): ";
    for (No* it = list1.begin(); it != list1.end(); it = it->next) {
        cout << it->data << " ";
    }
    cout << endl;

    // Testa acesso front e back
    cout << "Elemento na frente de list1: " << list1.front() << endl;
    cout << "Elemento no final de list1: " << list1.back() << endl;

    return 0;
}
