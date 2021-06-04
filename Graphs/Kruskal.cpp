#include<iostream>

using namespace std;

class Edge {

    public:
        
        int src;
        int wgt;
        int dst;
};

void sort_onWeight(Edge *arr, int E) {

    Edge temp;
    bool flag;

    for (int i = 0; i < E - 1; i++) {
        
        flag = false;

        for (int j = 0; j < E - i - 1; j++) {

            if (arr[j].wgt > arr[j + 1].wgt) {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = true;
            }
        } // end of inner for loop

        if (!flag) return;
    } // end of outer for loop
} // end of sort(Edge*, int)

int find_parent(int v, int *parent) {  // finds the most distant parent of a vertex recursively

    if (v == parent[v])
        return v;
    
    return find_parent(parent[v], parent);
} // end of find_parent(int, int*)

Edge *get_MinSpanTree_Kruskal(Edge *arr, int V, int E) {

    sort_onWeight(arr, E); // sort the edges
    
    Edge *result = new Edge[V - 1];

    int *parent = new int[V]; // to store parents of vertices
    for (int i = 0; i < V; i++) parent[i] = i; // initialising parents

    int count = 0;
    for (int i = 0; count != V - 1; i++) {

        Edge currEdge = arr[i];

        int srcParent = find_parent(currEdge.src, parent);
        int dstParent = find_parent(currEdge.dst, parent);

        if (srcParent != dstParent) {

            result[count] = currEdge;
            count++;

            parent[srcParent] = dstParent; // dstParent is the parent of srcParent
        } // end of inner if block

    } // end of for loop

    return result;
} // end of get_MinSpanTree_Kruskal(Edge*, int, int)

void input(Edge *arr, int E) {

    cout << "Enter source, destination, weight respectively for every edge :-\n";

    for (int i = 0; i < E; i++) {

        cout << i << " Enter: ";
        cin >> arr[i].src >> arr[i].dst >> arr[i].wgt;
    }

    cout << endl;
} // end of input(Edge*, int)

void output(Edge *arr, int E) {

    cout << "Edges on Minimum Spanning Tree :-\n";
    cout << "Source    Destination    Weight\n";

    int sum = 0;

    for (int i = 0; i < E; i++) {
     
        printf("%d            %d             %d\n", arr[i].src, arr[i].dst, arr[i].wgt);
        sum += arr[i].wgt;
    } // end of for loop
    
    printf("\nTotal weight of minimum spanning tree: %d\n", sum);
} // end of output(Edge*, int)

int main() {

    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Edge *arr = new Edge[E];

    input(arr, E);

    Edge *result = get_MinSpanTree_Kruskal(arr, V, E);

    output(result, V - 1);

    return 0;
} // end of main()