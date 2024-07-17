// Quick Sort

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

int particao(int *ar, int l, int r) {
    int pivot = ar[r];
    int posMn = l - 1;

    for (int i = l; i < r; i++) {
        if (ar[i] < pivot) {
            posMn++;
            troca(ar, i, posMn);
        }
    } 
    
    troca(ar, posMn + 1, r);
    return posMn + 1;
}

void quickSort(int *ar, int l, int r) {
    if (l >= r) return;

    int i = particao(ar, l, r);
    quickSort(ar, l, i - 1);
    quickSort(ar, i + 1, r);
}