#include <stdio.h>
#include <stdlib.h>

struct Graph_undirected {

    int V;  // number of vertices
    int E;  // number of edges

    int *compact_list;
};

typedef struct Graph_undirected Graph_undirected;

Graph_undirected* new_graph_undirected() {

    Graph_undirected *graph = (Graph_undirected*)malloc(sizeof(Graph_undirected));
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    graph->V = V;
    graph->E = E;

    graph->compact_list = (int*)malloc(sizeof(int) * (V + 2 * E + 2));

    return graph;
} // end of new_graph_undirected()

void input_edges(Graph_undirected *graph) {

    int *list = graph->compact_list;
    
    int i, j;

    *(list + 1) = graph->V + 2;

    for (i = 1; i <= graph->V; i++) {

        printf("Enter the number of edges for vertex %d: ", i);
        scanf("%d", (list + i + 1));

        *(list + i + 1) += *(list + i);

        printf("Enter edges for vertex %d: ", i);
        for (j = *(list + i); j < *(list + i + 1); j++) { scanf("%d", (list + j)); }
    } // end of outer for loop

} // end of input_edges(Graph_undirected*)

void display_undirected_graph(Graph_undirected *graph) {

    int *list = graph->compact_list;
    int i, j;

    for (i = 1; i <= graph->V; i++) {
        
        printf("vertex %d: ", i);
        for (j = *(list + i); j < *(list + i + 1); j++) { printf("%d ", *(list + j)); }
        printf("\n");
    } // end of outer loop

} // end of display_undirected_graph(Graph_undirected*)

void display_compact_list(Graph_undirected *graph) {

    int i = 0;
    int length = graph->V + 2 * graph->E + 2;

    for (i = 0; i < length; i++) { printf("%d ", *(graph->compact_list + i)); }

} // end of display_compact_list(Graph_undirected*)


// **************  Queue starts  **************

struct Node {

	int data;
	struct Node* next;
};

typedef struct Node Node;

Node* new_node() {

    Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = 0;
    newNode->next = NULL;
        
    return newNode;
} // end of constructor for struct Node


struct Queue {
	
	struct Node* head;
	struct Node* tail;
};

typedef struct Queue Queue;

Queue* new_queue() {
	
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));

	newQueue->head = NULL;
	newQueue->tail = NULL;

	return newQueue;
} // end of constructor for struct Queue

int is_queue_empty(Queue *queue) { return (queue->head == NULL); }

void enqueue(Queue* queue, int value) {

	Node *node = new_node();
	node->data = value;

	if (is_queue_empty(queue)) { queue->head = node; }
	else { (queue->tail)->next = node; }

	queue->tail = node;
} // end of enqueue(Queue*, int)

int dequeue(Queue* queue) {

	if (is_queue_empty(queue)) { return 0; }

	int value = (queue->head)->data;

	Node *node = queue->head;
	queue->head = (queue->head)->next;

	if (queue->head == NULL) { queue->tail = NULL; } // resolving dangling pointer

	free(node);

	return value;
} // end of dequeue(Queue*)

// ***************  Queue ends  ****************

void bfs_traversal(Graph_undirected *graph, int starting_vertex) {

    int *list = graph->compact_list;

    Queue *queue = new_queue();
    int is_visited[graph->V + 1];
    int i, j;
    int vertex;

    // initialising the is_visited array
    for (i = 0; i <= graph->V; i++) { *(is_visited + i) = 0; }

    enqueue(queue, starting_vertex);
    is_visited[starting_vertex] = 1;

    while (!is_queue_empty(queue)) {

        vertex = dequeue(queue);
        printf("%d ", vertex);

        for (j = *(list + vertex); j < *(list + vertex + 1); j++) {

            if (!is_visited[*(list + j)]) {
                
                enqueue(queue, *(list + j));
                is_visited[*(list + j)] = 1;
            }
        } // end of for loop

    } // end of outer while loop

} // end of bfs_traversal(Graph_undirected*)


int main() {

    Graph_undirected *graph = new_graph_undirected();

    input_edges(graph);

    printf("\nGraph :-\n");
    display_undirected_graph(graph);

    printf("\nCompact list: ");
    display_compact_list(graph);
    printf("\n");

    int starting_vertex;
    printf("\nEnter starting vertex for bfs traversal: ");
    scanf("%d", &starting_vertex);

    printf("\nBFS traversal: ");
    bfs_traversal(graph, starting_vertex);
    printf("\n");

    return 0;
} // end of main()