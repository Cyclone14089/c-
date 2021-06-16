#include<iostream>
#include<list>

using namespace std;

class Graph {

	int V; // number of vertices
	list<int> *adj;

	int* get_inDegree() {

		int *inDegree = new int[V]{0};
		list<int>::iterator vertex;

		for (int i = 0; i < V; i++)
			for (vertex = adj[i].begin(); vertex != adj[i].end(); vertex++)
				inDegree[*vertex]++;

		return inDegree;
	} // end of compute_inDegree()

	list<int>* get_queue(int *inDegree) {

		list<int> *queue = new list<int>;

		for (int i = 0; i < V; i++)
			if (!inDegree[i]) queue->push_back(i);

		return queue;
	} // end of get_queue()

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

		void display_inDegree(int *inDegree) {

			printf("\nin-degree: ");
			for (int i = 0; i < V; i++)
				printf("%d ", inDegree[i]);
			printf("\n");
		} // end of display_inDegree()

		void topological_sort_print() {

			int *inDegree = get_inDegree();
			list<int> *queue = get_queue(inDegree);

			printf("Topological Order: ");

			while (!queue->empty()) {

				int curr_vrtx = queue->front();
				queue->pop_front();

				list<int>::iterator i;
				for (i = adj[curr_vrtx].begin(); i != adj[curr_vrtx].end(); i++)
					if (!(--inDegree[*i])) queue->push_back(*i);

				printf("%d ", curr_vrtx);
			} // end of outer while loop

			printf("\n");
		} // end of topological_sort()

}; // end of class Graph

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
	printf("\n");
	gph->topological_sort_print();

	return 0;
} // end of main()