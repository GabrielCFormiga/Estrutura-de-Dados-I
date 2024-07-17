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