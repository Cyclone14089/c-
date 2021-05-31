#include<iostream>

using namespace std;

class Graph {

    int V; // number of vertices
    int **matrix; // storing connections of vertices

    public: 

        Graph(int V) {
        
            this->V = V;
            matrix = new int*[V];

            for (int i = 0; i < V; i++)
                matrix[i] = new int[V]{0}; // initialising each column

        } // end of constructor

        void addEdge(int x, int y) {

            if (x >= V || y >= V) {

                printf("Vertex not found\n");
                return;
            }

            matrix[x][y] = 1;
            matrix[y][x] = 1;
        } // end of addEdge(int, int)

        int getDegree() {

            int degree = 0;

            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (matrix[i][j])
                        degree++;
            
            return degree;
        } // end of findDegree(int)

        int countEdges() { return (getDegree() / 2); } // end of countEdges()

        void displayAdjacents(int v) {

            if (v >= V) {

                printf("Vertex not found!");
                return;
            }

            printf("Adjacents of vertex %d:", v);

            for (int i = 0; i < V; i++)
                if (matrix[v][i])
                    printf(" %d", i);

            printf("\n");
        } // end of displayAdjacents(int)

        void display() {

            printf("Graph :-");

            for(int v = 0; v < V; v++)
                displayAdjacents(v);
            
        } // end of display()
        
}; // end of Graph class

void createGraph(Graph *g) {

    g->addEdge(0, 1);
    g->addEdge(0, 4);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 5);
    g->addEdge(3, 5);
} // end of createGraph(Graph)

int main() {

    Graph g(6);

    createGraph(&g);

    printf("Enter vertex to find degree: ");
    int v;
    scanf("%d", &v);

    printf("Degree of vertex %d is: %d\n", v, g.findDegree(v));

    return 0;
} // end of main()