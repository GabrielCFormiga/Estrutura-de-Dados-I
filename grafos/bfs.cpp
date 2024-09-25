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

// vetor de visitados que indica se o vértice i foi visitado na bfs
vector<bool> vis(MAX_V); 

// vetor que indica a distancia do vértice i até a raiz da bfs
vector<int> dist(MAX_V);

// veotor que indica o pai do vértice i
vector<int> parent(MAX_V);

void bfs(int raiz) {
    queue<int> q;
    q.push(raiz);
    vis[raiz] = true;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : listaAdj[v]) {
            if (!vis[u]) {
                vis[u] = true;
                
                q.push(u);
                dist[u] = dist[v] + 1;
                parent[u] = v;
            }
        }
    }
}

void imprimeCaminho(int u) {
    if (parent[u] == -1 && vis[u]) {
        cout << "O vertice " << u << " eh a raiz!" << endl;
    } else if (!vis[u]) {
        cout << "Nao ha caminho entre os vertices!" << endl;;
    } else {
        vector<int> path;

        for (int v = u; v != -1; v = parent[v]) path.push_back(v);

        reverse(path.begin(), path.end());

        cout << "Caminho: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << endl;
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
    cout << "Insira a raiz da busca em largura: ";
    cin >> v;

    if (v < 0 || v >= V) {
        cout << "v nao pertence ao grafo!" << endl;
        cout << "Encerrando o programa..." << endl;
        return 0;
    }
    */

    // organiza o vetor de pais e distancia antes da busca
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        dist[i] = 0;
    }

    bfs(v);

    // Imprime o caminho entre os vértices e a raiz
    for (int i = 0; i < V; i++) {
        imprimeCaminho(i);
    }

    cout << endl; 
}