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

// vetor de visitados que indica se o vértice i foi visitado na dfs
vector<bool> vis(MAX_V); 

void dfs(int raiz) {
    stack<int> s;
    s.push(raiz);

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (!vis[v]) {
            vis[v] = true;

            for (int u : listaAdj[v]) {
                if (!vis[u]) s.push(u);
            }
        }
    }
}

int main() {
    srand(time(0));

    cin >> V;

    if (V > MAX_V) {
        cout << "V maior que MAX_V!" << endl;
        cout << "Encerrando o programa..." << endl;
        return 0;
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

    int v  = rand() % V;
    
    /* Opção para entrada personalizada
    cout << "Insira a raiz da busca em profundidade: ";
    cin >> v;

    if (v < 0 || v >= V) {
        cout << "v nao pertence ao grafo!" << endl;
        cout << "Encerrando o programa..." << endl;
        return 0;
    }
    */

    dfs(v);

    cout << "Os vertices conectados ao vertice " << v << " sao:" << endl;
    for (int i = 0; i < V; i++) {
        if (i != v && vis[i]) cout << i << " ";
    }

    cout << endl; 
}