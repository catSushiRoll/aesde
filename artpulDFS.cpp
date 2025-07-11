#include <iostream>
using namespace std;

const int MAX = 100;
int adj[MAX][MAX];     // Matriks adjacency: menyimpan tetangga tiap simpul
int adjSize[MAX];      // Menyimpan jumlah tetangga per simpul (berapa kolom yang dipakai di baris adj[i])
bool visited[MAX];     // Menandai apakah simpul sudah dikunjungi
int disc[MAX], low[MAX]; // disc = waktu discovery, low = nilai low-link
int parent[MAX];       // Menyimpan parent dari simpul dalam DFS tree
bool ap[MAX];          // Menandai apakah simpul adalah articulation point
int timeCounter = 0;   // Waktu global untuk pencatatan waktu penemuan simpul dalam DFS

void DFS(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++timeCounter;
    int children = 0;

    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            children++;
            parent[v] = u;
            DFS(v);

            if (low[u] > low[v]) low[u] = low[v];

            // u articulation point jika:
            // 1. u adalah root dan punya 2 anak
            if (parent[u] == -1 && children > 1)
                ap[u] = true;
            // 2. u adalah articulation point jika low[v] >= disc[u]
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = true;
        }
        // v bukan anak dari u maka ada back edge
        else if (v != parent[u]) {
            if (low[u] > disc[v]) low[u] = disc[v];
        }
    }
}

void findArticulationPoints(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        parent[i] = -1;
        ap[i] = false;
    }
    timeCounter = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            DFS(i);

    cout << "Articulation Points: ";
    bool found = false;
    for (int i = 0; i < n; i++)
        if (ap[i]) {
            cout << i << " ";
            found = true;
        }
    if (!found) cout << "None";
    cout << endl;
}

/* misal mau bikin graph gini

            2
           /
          1
        /  \
       3----5 
            \
            4
*/

int main() {
    int n = 6;

    for (int i = 0; i < n; i++) adjSize[i] = 0;

    adj[2][adjSize[2]++] = 1;

    adj[1][adjSize[1]++] = 2;
    adj[1][adjSize[1]++] = 3;
    adj[1][adjSize[1]++] = 5;

    adj[3][adjSize[3]++] = 1;
    adj[3][adjSize[3]++] = 5;

    adj[5][adjSize[5]++] = 1;
    adj[5][adjSize[5]++] = 3;
    adj[5][adjSize[5]++] = 4;

    adj[4][adjSize[4]++] = 5;

    findArticulationPoints(n);
    return 0;
}


// KODE ASLI!!!!!!!!! uncomment if needed
// int main() {
//     int n = 5;
//     // Clear adjacency
//     for (int i = 0; i < n; i++) adjSize[i] = 0;

//     // adj[0] = {1, 2};
//     adj[0][adjSize[0]++] = 1;
//     adj[0][adjSize[0]++] = 2;
//     // adj[1] = {0, 2, 3};
//     adj[1][adjSize[1]++] = 0;
//     adj[1][adjSize[1]++] = 2;
//     adj[1][adjSize[1]++] = 3;
//     // adj[2] = {0, 1};
//     adj[2][adjSize[2]++] = 0;
//     adj[2][adjSize[2]++] = 1;
//     // adj[3] = {1, 4};
//     adj[3][adjSize[3]++] = 1;
//     adj[3][adjSize[3]++] = 4;
//     // adj[4] = {3};
//     adj[4][adjSize[4]++] = 3;

//     findArticulationPoints(n);
//     return 0;
// }
