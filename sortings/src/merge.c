#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LEN 256

// Merge Sort

// Time Complexity:
    // Pior caso: O(nlogn) aray ordenado de forma reversa
    // Caso médio: O(nlogn)  
    // Melhor caso: O(nlogn) aray ordenado

// Estável 

void merge(int *ar, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = ar[l + i];
    for (int i = 0; i < n2; i++) R[i] = ar[m + 1 + i];

    int i = 0, j = 0;
    int k = l;

    while (k <= r) {
        // copia o elemento de L para ar
        while ((i < n1 && j < n2 && L[i] <= R[j]) || (i < n1 && j == n2)) {
            ar[k] = L[i];
            i++;
            k++;
        }
        // copia o elemento de R para ar
        while ((j < n2 && i < n1 && R[j] < L[i]) || (j < n2 && i == n1)) {
            ar[k] = R[j];
            j++;
            k++;
        }
    }
}

void mergeSort(int *ar, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l) / 2;
    mergeSort(ar, l, m);
    mergeSort(ar, m + 1, r);
    merge(ar, l, m, r);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    const char *intancesFolder = "/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/instancias-num/";
    const char *resultsFolder = "/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/resultados-num/merge/";

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

        cpu_time_used = 0;

        for (int j = 0; j < 10; j++) {
            int arCopy[i];
            for (int k = 0; k < i; k++) arCopy[k] = ar[k];

            start = clock();
            if (j != 9) mergeSort(arCopy, 0, i - 1);
            else mergeSort(ar, 0, i - 1);
            end = clock();
            
            cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
        }

        cpu_time_used /= 10;
        fprintf(outputFile, "Merge Sort:\n");
        fprintf(outputFile, "Tempo de CPU usado: %f segundos\n", cpu_time_used);
        for (int j = 0; j < i; j++) {
            fprintf(outputFile, "%d\n", ar[j]);
        }

        fclose(inputFile);
        fclose(outputFile);
    }

    return 0;
}
