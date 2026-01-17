#include <bits/stdc++.h>
using namespace std;

template <typename T>
bool detect_cycle_directed_graph_DFS (unordered_map <T, unordered_set<T>>& adj, unordered_map <T, bool>& visited,
unordered_map <T, bool>& recStack, T source) {
    if(visited[source] == false) {
        cout<<"Source Marked visited and recStack True : "<<source<<"\n";
        visited[source] = true;
        recStack[source] = true;

        for (auto& node : adj[source]) {
            if (!visited[node]) {
                cout<<"Node  not visited : "<<node<<"\n";
                if (detect_cycle_directed_graph_DFS(adj, visited, recStack, node)) {
                    return true;
                }
            }
            else if (recStack[node]) {
                cout<<"Node  visited and recStack True as well, so cycle: "<<node<<"\n";
                return true;
            }
        }
    }
    cout<<"Source Marked recStack False : "<<source<<"\n";
    recStack[source] = false;
    return false;
}

template <typename T>
bool detect_cycle_directed_graph_DFS (unordered_map <T, unordered_set<T>>& adj) {
    unordered_map <T, bool> visited;
    unordered_map <T, bool> recStack;

    for (auto& node : adj) {
        visited[node.first] = false;
        recStack[node.first] = false;
    }
    
    for (auto& node : adj) {
        if (!visited[node.first]) {
            if (detect_cycle_directed_graph_DFS(adj, visited, recStack, 1)) return true;
        }
    }
    return false;
}