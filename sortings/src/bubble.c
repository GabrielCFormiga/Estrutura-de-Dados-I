#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LEN 256

// Bubble Sort

// Comparações: C(n) = O(n²)
// Trocas: T(n) = O(n²)

// Não adaptativo
// Estável

// É simples, contudo tem muitas trocas

void bubbleSort(int *ar, int n) {
    int i, aux;
    int troca = 1; // true

    while (1) {
        troca = 0; // false

        for (i = 1; i < n; i++) {
            if (ar[i] < ar[i - 1]) {
                aux = ar[i];
                ar[i] = ar[i - 1];
                ar[i - 1] = aux;
                troca = 1;
            }
        }

        if (troca == 0) break;
    }
}

int main() {
    DIR *dir;
    struct dirent *entry;
    const char *intancesFolder = "/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/instancias-num/";
    const char *resultsFolder = "/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/resultados-num/bubble/";

    FILE *inputFile, *outputFile;
    char inputPath[MAX_PATH_LEN], outputPath[MAX_PATH_LEN];

    clock_t start, end;
    double cpu_time_used;

    dir = opendir(intancesFolder);
    if (dir == NULL) {
        perror("Erro ao abrir o diretório");
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        int ar[100000];
        int x, i = 0;

        // constrói o caminho completo do arquivo
        snprintf(inputPath, MAX_PATH_LEN, "%s/%s", intancesFolder, entry->d_name);
        snprintf(outputPath, MAX_PATH_LEN, "%s/%st", resultsFolder, entry->d_name);
        outputPath[strlen(outputPath) - 3] = 'o';
        outputPath[strlen(outputPath) - 2] = 'u';

        inputFile = fopen(inputPath, "r");
        if (inputFile == NULL) {
            perror("Erro ao abrir o arquivo de entrada");
            return EXIT_FAILURE;
        }

        outputFile = fopen(outputPath, "w");
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
        bubbleSort(ar, i);
        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        fprintf(outputFile, "Bubble Sort:\n");
        fprintf(outputFile, "Tempo de CPU usado: %f segundos\n", cpu_time_used);
        for (int j = 0; j < i; j++) {
            fprintf(outputFile, "%d\n", ar[j]);
        }

        fclose(inputFile);
        fclose(outputFile);
    }

    return 0;
}