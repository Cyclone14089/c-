#include<iostream>
#include<fstream>
#include<list>

using namespace std;

void printChar(int v) { cout << (char)(v + 'A'); }

class GraphMatrix {

    int V;
    int **adj;
    bool *visited;

    public:

        GraphMatrix(int V) {

            this->V = V;
            adj = new int*[V];
            for (int i = 0; i < V; i++) adj[i] = new int[V]{0};
            visited = new bool[V]{false};
        } // end of constructor

        void addEdge(int x, int y) { adj[x][y] = 1; }

        void displayVisited() {

            printf("Visited: ");
            for (int i = 0; i < V; i++) printf("%d ", visited[i]);
            printf("\n");
        } // end of displayVisited()

        void clearVisited() { for (int i = 0; i < V; i++) visited[i] = false; }

        void displayGraph() {

            printf("Graph :-\n");

            for (int i = 0; i < V; i++) {

                printChar(i);
                printf(": ");

                for (int j = 0; j < V; j++) 
                    if (adj[i][j]) {

                        printChar(j);
                        printf(" ");
                    }

                printf("\n");
            }
        } // end of displayGraph()

        void bfs(int v) {

            list<int> queue; 

            visited[v] = true; // marking starting node as visited

            queue.push_back(v);

            while(!queue.empty()) {

                v = queue.front();
                printChar(v);
                printf(" ");
                queue.pop_front();

                for (int i = 0; i < V; i++) {

                    if ((adj[v][i] == 1) && !visited[i]) {

                        visited[i] = true;
                        queue.push_back(i);
                    }
                } // end of for loop

            } // end of outer while loop
        } // end of bfs(int)

}; // end of GraphMatrix class

class GraphList {

    int V;
    list<int> *adj;
    bool *visited;

    public:

        GraphList(int V) {

            this->V = V;
            adj = new list<int>[V];
            visited = new bool[V]{false};
        } // end of constructor

        void addEdge(int x, int y) { adj[x].push_back(y); }

        void displayVisited() {

            printf("Visited: ");
            for (int i = 0; i < V; i++) printf("%d ", visited[i]);
            printf("\n");
        } // end of displayVisited()

        void clearVisited() { for (int i = 0; i < V; i++) visited[i] = false; }

        void displayGraph() {

            printf("Graph :-\n");

            for (int i = 0; i < V; i++) {

                printf("%d: ", i);
                for (int v : adj[i]) printf("%d ", v);
                printf("\n");
            }
        } // end of displayGraph()

        void bfs(int v) {

            list<int> queue; 

            visited[v] = true; // marking current vertex as visited

            queue.push_back(v); // enqueue value of current vertex

            list<int>::iterator i; // used for iterating through all adjacent vertices

            while (!queue.empty()) {

                v = queue.front();
                printf("%d ", v);
                queue.pop_front();

                for (i = adj[v].begin(); i != adj[v].end(); i++) {

                    if (!visited[*i]) {

                        visited[*i] = true;
                        queue.push_back(*i);
                    }
                } // end of inner for loop

            } // end of outer while loop
        } // end of bfs(int)

}; // end of GraphList class

void createGraph(GraphMatrix *g) {

    fstream file;
    file.open("importGraph.txt", ios::in);

    if (!file) {

        printf("Error accessing file contents\n");
        exit(1);
    } 

    int V, val;
    file >> V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {

            file >> val;
            if (val) g->addEdge(i, j);
        }
    } // end of outer for loop

    file.close();
} // end of createGraph(GraphMatrix*)

void createGraph(GraphList *g) {

    fstream file;
    file.open("importGraph.txt", ios::in);

    if (!file) {

        printf("Error accessing file contents\n");
        exit(1);
    } 

    int V, val;
    file >> V;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {

            file >> val;
            if (val) g->addEdge(i, j);
        }
    } // end of outer for loop

    file.close();
} // end of createGraph(GraphList*)

int main() {

    GraphMatrix g(6);
    createGraph(&g);

    cout << endl;

    cout << "BFS: ";
    g.bfs(0);
    cout << endl << endl;

    g.displayGraph();

    cout << endl;
    return 0;
} // end of main()