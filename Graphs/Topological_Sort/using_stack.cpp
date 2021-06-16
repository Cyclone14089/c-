#include<iostream>
#include<list>

using namespace std;

class Graph {

	int V; // number of vertices
	list<int> *adj;

	void topologically_push(int vertex, list<int> *stack, int *visited) {

		visited[vertex] = 1;

		list<int>::iterator i;
		for (i = adj[vertex].begin(); i != adj[vertex].end(); i++)
			if (!visited[*i])
				topologically_push(*i, stack, visited);

		stack->push_back(vertex);
	}

	void build_stack(list<int> *stack, int *visited) {

		for (int i = 0; i < V; i++) if (!visited[i]) topologically_push(i, stack, visited);
	}

	public:

		Graph(int V) {

			this->V = V;
			adj = new list<int>[V];
		} // end of constructor

		~Graph() { delete adj; } // destructor

		void add_edge(int src, int dst) { adj[src].push_back(dst); } // add_edge(int, int)

		void display_graph() {

			list<int>::iterator j;

			printf("\nGraph:-\n");
			for (int i = 0; i < V; i++) {

				printf("%d: ", i);
				for (j = adj[i].begin(); j != adj[i].end(); j++) 
					printf("%d ", *j);
				printf("\n");
			} // end of outer for loop
		} // end of display_graph()

		list<int>* get_topological_stack() {

			int *visited = new int[V]{0}; // keep track of visited vertices
			list<int> *stack = new list<int>;

			build_stack(stack, visited);

			return stack;
		} // end of get_topological_stack()

}; // end of class Graph

void display_stack(list<int> *stack) {

	while (!stack->empty()) {

		printf("%d ", stack->back());
		stack->pop_back();
	}

	printf("\n");
} // end of display_stack(list<int>*)

Graph* create_graph() {

	int V, E;
	printf("Enter the number of vertices: ");
	scanf("%d", &V);
	printf("Enter the number of edges: ");
	scanf("%d", &E);

	Graph *gph = new Graph(V);

	int src, dst;
	printf("Enter edges (source and destination respectively) :-\n");
	for (int i = 0; i < E; i++){

		printf("%d. Enter edge: ", (i + 1));
		cin >> src >> dst;
		gph->add_edge(src, dst);
	}

	return gph;
} // end of create_graph()

int main() {

	Graph *gph = create_graph();
	gph->display_graph();

	list<int> *stack = gph->get_topological_stack();

	printf("\nTopological order: ");
	display_stack(stack);

	return 0;
} // end of main()