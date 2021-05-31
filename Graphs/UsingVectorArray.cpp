#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int> adj[], int x, int y) {

    adj[x].push_back(y); // creating link(edge) x --> y
    adj[y].push_back(x); // creating link(edge) y --> x
} // end of addEdge(vector<int>[], int, int)

void printGraph(vector<int> adj[], int V) {

    for (int v = 0; v < V; v++) {

        printf("\nAdjacency list of vertex %d \n head ", v);

        for (int x : adj[v])
            printf("-> %d", x);
        
        printf("\n");
    } // end of outer for loop
} // end of printGraph(vector<int>[], int)

int main() {

    int V = 5; // number of vertices

    vector<int> adj[V]; // to store the graph

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printGraph(adj, V);
    
    return 0;
} // end of main()