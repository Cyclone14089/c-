#include<iostream>
#include<vector>

using namespace std;

void addEdge(int **matrix, int x, int y) {

    matrix[x][y] = 1; // creating link(edge) x --> y
    matrix[y][x] = 1; // creating link(edge) y --> x
} // end of addEdge(int**, int, int)

void printGraph(int **matrix, int V) {

    for (int v = 0; v < V; v++) {

        printf("\nAdjacency list of vertex %d \n head ", v);

        for (int i = 0; i < V; i++) {

            if (matrix[v][i] == 1)
                printf("-> %d", i);
        }
        
        printf("\n");
    } // end of outer for loop
} // end of printGraph(int**, int)

int main() {

    int V = 5; // number of vertices

    int **matrix = new int*[V]; // to store the graph

    for (int i = 0; i < V; i++)
        matrix[i] = new int[V]{0}; // initialising each column

    addEdge(matrix, 0, 1);
    addEdge(matrix, 0, 4);
    addEdge(matrix, 1, 2);
    addEdge(matrix, 1, 3);
    addEdge(matrix, 1, 4);
    addEdge(matrix, 2, 3);
    addEdge(matrix, 3, 4);

    printGraph(matrix, V);
    
    return 0;
} // end of main()