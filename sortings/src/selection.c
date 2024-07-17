#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Selection Sort

// Comparações: C(n) = O(n²)
// Trocas: T(n) = O(n)

// Não adaptativo: sempre faz O(n²) comparações
// Não estável

// Bom quando o custo da troca é muito caro

void selectionSort(int *ar, int n) {
    int i, j;
    int menor, indexMenor;

    for (i = 0; i < n; i++) {
        menor = ar[i];
        indexMenor = i;

        for (j = i + 1; j < n; j++) {
            if (ar[j] < menor) {
                menor = ar[j];
                indexMenor = j;
            }
        }

        ar[indexMenor] = ar[i];
        ar[i] = menor;
    }
}

int main() {
    FILE *inputFile, *outputFile;
    clock_t start, end;
    double cpu_time_used;
    int ar[100000];
    int x, i = 0;

    inputFile = fopen("/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/instancias-num/num.100000.4.in", "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return EXIT_FAILURE;
    }

    outputFile = fopen("/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/resultados-num/selection/num.100000.4.in", "w");
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
    selectionSort(ar, i);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(outputFile, "Selection Sort:\n");
    fprintf(outputFile, "Tempo de CPU usado: %f segundos\n", cpu_time_used);
    for (int j = 0; j < i; j++) {
        fprintf(outputFile, "%d\n", ar[j]);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}