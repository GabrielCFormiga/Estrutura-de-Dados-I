#include <stdio.h>
#include "vector.h"

int main() {
    Vector vec;
    
    // Inicialização do vetor com capacidade inicial de 5
    init(&vec, 5);

    // Teste da função push_back
    push_back(&vec, 1);
    push_back(&vec, 2);
    push_back(&vec, 3);
    push_back(&vec, 4);
    push_back(&vec, 5);

    // Impressão do vetor
    printf("Vetor após push_back:\n");
    vec_print(&vec);

    // Teste da função pop_back
    pop_back(&vec);
    printf("Vetor após pop_back:\n");
    vec_print(&vec);

    // Teste da função insert
    insert(&vec, 2, 99); // Insere 99 na posição 2
    printf("Vetor após insert na posição 2:\n");
    vec_print(&vec);

    // Teste da função erase
    erase(&vec, 2); // Remove o elemento na posição 2
    printf("Vetor após erase na posição 2:\n");
    vec_print(&vec);

    // Teste da função assign
    assign(&vec, 1, 42); // Atribui 42 na posição 1
    printf("Vetor após assign na posição 1:\n");
    vec_print(&vec);

    // Teste da função get
    int value = get(&vec, 1);
    printf("Elemento na posição 1: %d\n", value);

    // Teste da função shrink_to_fit
    shrink_to_fit(&vec);
    printf("Vetor após shrink_to_fit:\n");
    vec_print(&vec);

    // Liberação da memória do vetor
    vec_free(&vec);

    return 0;
}
