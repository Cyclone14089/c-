#include<iostream>
#include<list>

using namespace std;

class Graph {

    int V; // storing number of vertices
    list<int> *adj; // storing adjacent vertices of each vertex

    public:

        Graph(int V) {

            this->V = V;
            adj = new list<int>[V];
        } // end of constructor

        void addEdge(int x, int y) {

            adj[x].push_back(y); // adding y to the list of x
            adj[y].push_back(x); // adding x to the list of y
        } // end of addEdge(int, int)

        int countEdges() {

            int sum = 0;

            for (int i = 0; i < V; i++)
                sum += adj[i].size();

            return (sum / 2);
        } // end of countEdges()
}; // end of Graph class

int main() {

    int V = 9;

    Graph g(V);

    g.addEdge(0, 1 );
    g.addEdge(0, 7 );
    g.addEdge(1, 2 );
    g.addEdge(1, 7 );
    g.addEdge(2, 3 );
    g.addEdge(2, 8 );
    g.addEdge(2, 5 );
    g.addEdge(3, 4 );
    g.addEdge(3, 5 );
    g.addEdge(4, 5 );
    g.addEdge(5, 6 );
    g.addEdge(6, 7 );
    g.addEdge(6, 8 );
    g.addEdge(7, 8 );
  
    cout << "Number of edges: ";
    cout << g.countEdges();
    cout << endl;

    return 0;
} // end of main()