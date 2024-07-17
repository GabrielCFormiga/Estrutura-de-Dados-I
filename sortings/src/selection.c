#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LEN 256

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
    DIR *dir;
    struct dirent *entry;
    const char *intancesFolder = "/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/instancias-num/";
    const char *resultsFolder = "/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/resultados-num/selection/";

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
    }

    return 0;
}