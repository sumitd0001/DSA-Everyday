#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

#define V 6

void addEdge(int adjMatrix[][V], int u, int v) {
    if (u < V && v <V) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
}

void printadjMatrix(int adjMatrix[][V]) {
    for (int i = 0; i<V; ++i) {
        for (int j = 0; j<V; ++j) {
            cout<<adjMatrix[i][j]<<" ";
        }cout<<"\n";
    }
}

void adjMatrix() {
    
    int adjMatrix[V][V];

    //Initialize all elements of adjMatrix to 0
    for (int i = 0; i<V; ++i) {
        for (int j = 0; j<V; ++j) {
            adjMatrix[i][j] = 0;
        }
    }

    //addEdge
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 1, 5);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 5);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 5);
    addEdge(adjMatrix, 4, 5);

    //print graph - adjMatrix
    printadjMatrix(adjMatrix);

    
}

void solve() {
    adjMatrix();
}

int main() {
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
