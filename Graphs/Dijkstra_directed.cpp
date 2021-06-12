#include<iostream>
#include<list>

using namespace std;

int get_id(char c) { return ((int)c - 65); }

char get_char(int id) { return (char)(id + 65); }

class Vertex; // forward declaration to let class Connection know

class Connection {

    public:

        Vertex *dst; // destination Vertex
        int wgt; // weight of the connection

        Connection() {

            dst = NULL;
            wgt = 0;
        } // end of constructor

        Connection(Vertex *dst, int wgt) {

            this->dst = dst;
            this->wgt = wgt;
        } // end of parameterised constructor

        ~Connection(); // declaring destructor

}; // end of class Connection

class Vertex {

    public:

        int id; // id of the vertex
        int parent_id; // to store the parent of the vertex
        int min_wgt; // minimum weight of the vertex
        list<Connection> connections; // storing the connections of the vertex

        Vertex() {

            id = -1;
            parent_id = -1;
            min_wgt = 0;
        } // end of constructor

        void add_connection(Connection *conn) { connections.push_back(*conn); }
}; // end of class Vertex

class Graph {

    public:

        int V; // number of vertices
        Vertex *vertices; // storing the vertices according to adjacency

        Graph(int V) {

            this->V = V;
            vertices = new Vertex[V];

            for (int i = 0; i < V; i++) vertices[i].id = i;
        } // end of constructor

        ~Graph() { delete vertices; } // destructor

        void add_edge(int src, int dst, int wgt) {

            Connection *conn = new Connection(&vertices[dst], wgt);
            vertices[src].add_connection(conn);
        } // end of add_edge(int, int, wgt)

        void display_edges() {

            printf("\nDisplaying edges:-\n");
            printf("Srce    Dest    Wght\n");

            list<Connection>::iterator conn;

            for (int src = 0; src < V; src++) {

                for (conn = (vertices[src].connections).begin(); conn != (vertices[src].connections).end(); conn++)
                    printf(" %d  -->  %d   :   %d\n", src, (conn->dst)->id, conn->wgt);
            } // end of outer for loop
        } // end of display_edges()

        void display_vertices() {

            printf("\nDisplaying vertices:-\n");
            printf(" ______________________________________\n");
            printf("|   vertex   |   parent   |   weight   |\n");
            printf("----------------------------------------\n");

            Vertex *vrtx;

            for (int i = 0; i < V; i++) {
                
                vrtx = (vertices + i);

                printf("|     %c      |      %c     |     %d      |\n", get_char(vrtx->id), get_char(vrtx->parent_id), vrtx->min_wgt);
                printf("----------------------------------------\n");
            } // end of for loop
        } // end of display_vertices()

}; // end of Graph class

// Debugging functions *************************

void display_vertex(Vertex *vrtx) {

    cout << "Vertex:-\n";
    cout << "vrtx->id: " << vrtx->id << endl;
    cout << "vrtx->parent_id: " << vrtx->parent_id << endl;
    cout << "vrtx->min_wgt: " << vrtx->min_wgt << endl;
}

void display_vertex(Vertex vrtx) {

    cout << "Vertex:-\n";
    cout << "vrtx.id: " << vrtx.id << endl;
    cout << "vrtx.parent_id: " << vrtx.parent_id << endl;
    cout << "vrtx.min_wgt: " << vrtx.min_wgt << endl;
}

void display_connection(Connection *conn) {

    cout << "Connection:-\n";
    cout << "conn->wgt: " << conn->wgt << endl;
    cout << "(conn->dst)->id: " << (conn->dst)->id << endl;
}

void display_connection(Connection conn) {

    cout << "Connection:-\n";
    cout << "conn.wgt: " << conn.wgt << endl;
    cout << "(conn.dst)->id: " << (conn.dst)->id << endl;
}

void display_visited(int *visited, int V) {

    cout << "visited: ";
    for (int i = 0; i < V; i++) printf("%d ", visited[i]);
    cout << endl;
}
// *********************************************

class Dijkstra {

    Graph *gph;
    int src_id;

    int get_minOfUnvisited(int *visited) {

        int min = -1;
        int min_id;
        int v_wgt;

        for (int i = 0; i < gph->V; i++) {

            if (!visited[i]) {

                v_wgt = ((gph->vertices) + i)->min_wgt; // storing current minimum weight of vertex
                // cout << "v_wgt: " << v_wgt << "\n"; // debugging

                if ((v_wgt != 0) && (min == -1 || v_wgt < min)) {
                
                    min = v_wgt;
                    min_id = i;
                }
            } // end of outer if block
        } // end of for loop

        return min_id;
    } // end of get_minOfUnvisited(int*)

    void do_Dijkstra(int src_id, int *visited, int visit_count) {
    
        visited[src_id] = 1;
        visit_count++;

        // cout << "\nsrc_id: " << src_id << "\n"; // debugging
        // display_visited(visited, gph->V); // debugging

        Vertex *src_vrtx = (gph->vertices) + src_id; // storing address of source vertex
        list<Connection>::iterator conn;
        int dst_id;
        Vertex *dst_vrtx;

        // display_vertex(src_vrtx); // debugging

        for (conn = (src_vrtx->connections).begin(); conn != (src_vrtx->connections).end(); conn++) {
        
            dst_id = (conn->dst)->id;
            // cout << "dst_id: " << dst_id << "\n"; // debugging

            if (!visited[dst_id]) { // checking if destination vertex is visited

                dst_vrtx = (gph->vertices) + dst_id; // storing address of destination vertex

                // display_vertex(dst_vrtx); // debugging

                if ((dst_vrtx->min_wgt == 0) || ((src_vrtx->min_wgt + conn->wgt) < dst_vrtx->min_wgt)) {
                
                    dst_vrtx->parent_id = src_id; // updating parent
                    dst_vrtx->min_wgt = (src_vrtx->min_wgt + conn->wgt); // calculating total weight
                }
            } // end of outer if block
        } // end of for loop

        if (visit_count == ((gph->V) - 1)) return;

        int minOfUnvisited = get_minOfUnvisited(visited);
        // cout << "minOfUnvisited: " << minOfUnvisited << "\n"; // debugging
        do_Dijkstra(minOfUnvisited, visited, visit_count);
    } // end of do_Dijkstra(int, int*, int)

    public:

        Dijkstra(Graph *gph, int src_id) { 
        
            this->gph = gph;
            this->src_id = src_id; 
        } // end of constructor

        int get_source_id() { return src_id; }

        char get_source() { return get_char(src_id); }

        void compute_min_paths() {

            int *visited = new int[gph->V]{0}; // to keep track of visited vertices

            do_Dijkstra(src_id, visited, 0);
        } // end of get_min_unvisited(int*, int)

        void show_distance(int dst_id) {

            int distance = ((gph->vertices) + dst_id)->min_wgt;

            printf("Minimum total distance: %d\n", distance);
        } // end of show_distance(int)

        void show_path(int dst_id) {

            printf("Path: ");
            Vertex *vrtx = (gph->vertices) + dst_id;

            while (vrtx->parent_id != -1) {

                printf("%c <- ", get_char(vrtx->id));
                vrtx = (gph->vertices) + (vrtx->parent_id);
            }

            printf("%c\n", get_char(vrtx->id));
        } // end of show_path(int)

}; // end of class Dijkstra

Graph* create_graph() {

    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);
    
    Graph *gph = new Graph(V);

    printf("Enter edges (source, destination, weight, respectively) :-\n");
    char src, dst;
    int wgt;

    for (int i = 0; i < E; i++) {

        printf("%d Enter edge: ", (i + 1));
        cin >> src >> dst >> wgt;

        gph->add_edge(get_id(src), get_id(dst), wgt);
    }

    //
    // gph->add_edge(get_id('A'), get_id('B'), 7);
    // gph->add_edge(get_id('A'), get_id('D'), 2);
    // gph->add_edge(get_id('D'), get_id('B'), 3);
    // gph->add_edge(get_id('B'), get_id('D'), 2);
    // gph->add_edge(get_id('B'), get_id('C'), 1);
    // gph->add_edge(get_id('D'), get_id('C'), 8);
    // gph->add_edge(get_id('D'), get_id('E'), 5);
    // gph->add_edge(get_id('E'), get_id('C'), 5);
    // gph->add_edge(get_id('C'), get_id('E'), 4);
    //

    return gph;
} // end of graph_init(int, int)

int main() {

    Graph *gph = create_graph();
    gph->display_edges();

    printf("\nEnter source vertex for Dijkstra: ");
    char source;
    cin >> source;

    Dijkstra djk(gph, get_id(source));
    djk.compute_min_paths();

    gph->display_vertices();

    printf("\nEnter destination vertex to get path: ");
    char destination;
    cin >> destination;

    int dst_id = get_id(destination);

    djk.show_path(dst_id);
    djk.show_distance(dst_id);

    return 0;
} // end of main()