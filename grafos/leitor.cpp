#include <bits/stdc++.h>
using namespace std;

#define MAX_E 1000000
#define MAX_V 1000

// Grafo G(V, E)
int V; // |V|

// matriz de adjacência de G
int matrizAdj[MAX_V][MAX_V];

// lista de adjacência de G
vector<vector<int>> listaAdj(MAX_V);

int main() {
    cin >> V;

    if (V > MAX_V) {
        cout << "V maior que MAX_V!" << endl;
        cout << "Encerrando o programa..." << endl;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> matrizAdj[i][j];
            
            // atualização da lista de adjacência
            if (matrizAdj[i][j] > 0) {
                listaAdj[i].push_back(j);
            }
        }
    }

    // exibe lista de adjacência
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < listaAdj[i].size(); j++) {
            cout << listaAdj[i][j];
            if (j < listaAdj[i].size() - 1) cout << " ";
        }
        cout << endl;
    }
}