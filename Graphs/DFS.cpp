#include<iostream>
#include<map>
#include<list>

using namespace std;

class Graph {

    map<int, bool> visited;
    map<int, list<int>> adj; // storing the graph by mapping vertices to list of adjacent vertices

    public:

        void addEdge(int v, int item) { adj[v].push_back(item); } // add item to list of v

        void dfsUtil(int v) {

            visited[v] = true; // mark the current node as visited

            printf("%d ", v); // print the current node

            list<int>::iterator i; // used for iterating through all adjacent vertices

            for (i = adj[v].begin(); i != adj[v].end(); i++) 
                if (!visited[*i]) 
                    dfsUtil(*i);

        } // end of dfsUtil(int)

        void dfs() {

            for (auto i : adj) 
                if (!visited[i.first])
                    dfsUtil(i.first);
        } // end of dfs

}; // end of graph class

int main() {

    Graph *g = new Graph;

    g->addEdge(0, 1);
    g->addEdge(0, 9);
    g->addEdge(1, 2);
    g->addEdge(2, 0);
    g->addEdge(2, 3);
    g->addEdge(9, 3);

    printf("Following is Depth First Traversal (starting from vertex 2) \n");

    g->dfs();

    printf("\n");
    return 0;
} // end of main