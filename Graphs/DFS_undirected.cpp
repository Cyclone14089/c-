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

        void dfs_recursive(int v) {

            visited[v] = true; // mark the node as visited

            printChar(v);
            printf(" "); // print the node

            for (int i = 0; i <= V; i++) // traverse through connected nodes
                if ((adj[v][i] == 1) && !visited[i])
                    dfs_recursive(i);
        } // end of dfs_recursive(int)

        void dfs_iterative(int v) {

            list<int> stack;

            stack.push_back(v); // push the starting element into stack

            while (!stack.empty()) {
                
                v = stack.back(); // get top-most element in stack

                if (!visited[v]) {
                    
                    printChar(v);
                    printf(" ");
                    visited[v] = true;
                }

                for (int i = 0; i <= V; i++) {

                    if ((adj[v][i] == 1) && !visited[i]) {
                        
                        stack.push_back(i);
                        break;
                    }
                    
                    if (i == (V - 1)) stack.pop_back();
                } // end of inner for loop
            } // end of outer while loop

        } // end of dfs_iterative(int)

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

        void dfs_recursive(int v) {

            visited[v] = true; // mark the node as visited

            printf("%d ", v); // print the node

            list<int>::iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); i++) // traverse through connected nodes
                if (!visited[*i])
                    dfs_recursive(*i);
        } // end of dfs_recursive(int)

        void dfs_iterative(int v) {

            list<int> stack;

            stack.push_back(v); // push the starting element into stack

            list<int>::iterator i;

            while (!stack.empty()) {
                
                v = stack.back(); // get top-most element in stack

                if (!visited[v]) printf("%d ", v);
                visited[v] = true;

                for (i = adj[v].begin(); i != adj[v].end(); i++) {

                    if (!visited[*i]) {
                        
                        stack.push_back(*i);
                        break;
                    }
                    
                    if (*i == adj[v].back()) stack.pop_back();
                } // end of inner for loop
            } // end of outer while loop

        } // end of dfs_iterative(int)

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

    cout << "DFS recursive: ";
    g.dfs_recursive(0);
    cout << endl << endl;

    g.clearVisited();

    cout << "DFS iterative: ";
    g.dfs_iterative(0);
    cout << endl << endl;

    g.displayGraph();

    cout << endl;
    return 0;
} // end of main()