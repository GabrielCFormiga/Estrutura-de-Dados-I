// Counting Sort

// Comparações: não é um algoritmo comparativo
// Time Complexity: O(n + m)
// Auxiliary Space: O(n + m)

// Não adaptativo: sempre O(n + m)
// Estável

// Bom quando m é pequeno
// Não trata números decimais ou negativos

void countingSort(int *ar, int n) {
    int mx = ar[0];
    for (int i = 1; i < n; i++) if (ar[i] > mx) mx = ar[i];
    
    int cpy[n];
    int cnt[mx + 1];
    for (int i = 0; i < n; i++) {
        cpy[i] = ar[i];
        cnt[ar[i]]++;
    }

    // prefix sum
    for (int i = 1; i <= mx; i++) cnt[i] += cnt[i - 1]; 

    // itera a partir do final para manter o algoritmo estável
    for (int i = n - 1; i >= 0; i--) {
        ar[cnt[cpy[i]] - 1] = cpy[i];
        cnt[cpy[i]]--;
    }
}