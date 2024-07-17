#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Insertion Sort

// Comparações: C(n) = O(n²)
// Trocas: T(n) = O(n²)

// Adaptativo: O(n) comparações quando o vetor está parcialmente ordenado
// Estável

// Bom quando o vetor está parcialmente ordenado

void insertionSort(int *ar, int n) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
        aux = ar[i];
        j = i - 1;

        while (j >= 0 && ar[j] > aux) {
            ar[j + 1] = ar[j];
            j--;
        }

        ar[j + 1] = aux;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    clock_t start, end;
    double cpu_time_used;
    int ar[100000];
    int x, i = 0;

    inputFile = fopen("/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/instancias-num/num.100000.1.in", "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return EXIT_FAILURE;
    }

    outputFile = fopen("/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/resultados-num/insertion/num.100000.1.out", "w");
    if (outputFile == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    while (fscanf(inputFile, "%d", &x) != EOF) {
        ar[i] = x;
        i++;
    }

    start = clock();
    insertionSort(ar, i);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(outputFile, "Insertion Sort:\n");
    fprintf(outputFile, "Tempo de CPU usado: %f segundos\n", cpu_time_used);
    for (int j = 0; j < i; j++) {
        fprintf(outputFile, "%d\n", ar[j]);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}