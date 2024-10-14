#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH_LEN 256

// Quick Sort Três Vias (Três Partições)

// Time Complexity:
    // Pior caso: O(n²) quando sempre se escolhe o pior pivô
    // Caso médio: O(nlogn)
    // Melhor caso: Ω(nlogn)

// Adaptativo: depende da boa escolha do pivô
// Não estável 

// Ruim com n pequenos
// Eficiente com n grandes e gasta pouca memória

void troca(int *ar, int i, int j) {
    int aux = ar[i];
    ar[i] = ar[j];
    ar[j] = aux;
}

void particao(int *ar, int l, int r, int *i, int *j) {
    int pivot = ar[r];
    int posMn = l - 1;

    for (int k = l; k < r; k++) {
        if (ar[k] < pivot) {
            posMn++;
            troca(ar, k, posMn);
        }
    } 
    
    troca(ar, posMn + 1, r);
    
    *i = posMn; // posicao anterior ao pivô
    
    while (posMn < r && ar[posMn + 1] == pivot) posMn++;
    // agora posMn é a última ocorrência do pivô
    *j = posMn + 1;
}

void quickTresVias(int *ar, int l, int r) {
    if (l >= r) return;

    int i, j;

    particao(ar, l, r, &i, &j);
    
    quickTresVias(ar, l, i);
    quickTresVias(ar, j, r);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    const char *intancesFolder = "/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/instancias-num/";
    const char *resultsFolder = "/home/campfor/Área de Trabalho/Estrutura de Dados I/sortings/resultados-num/quickTresVias/";

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
            if (j != 9) quickTresVias(arCopy, 0, i - 1);
            else quickTresVias(ar, 0, i - 1);
            end = clock();
            
            cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
        }

        cpu_time_used /= 10;
        fprintf(outputFile, "Quick Sort Tres Vias:\n");
        fprintf(outputFile, "Tempo de CPU usado: %f segundos\n", cpu_time_used);
        for (int j = 0; j < i; j++) {
            fprintf(outputFile, "%d\n", ar[j]);
        }

        fclose(inputFile);
        fclose(outputFile);
    }

    return 0;
}