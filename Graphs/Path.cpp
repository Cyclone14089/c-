#include<iostream>
#include<list>
#include<map>

using namespace std;

class Graph {

    map<int, list<int>> arr;

    public:

        void addEdge(int x, int y) {

            arr[x].push_back(y);
            arr[y].push_back(x);
        } // end of addEdge(int, int)

        void show() {

            printf("Graph :-\n");
            
            map<int, list<int>>::iterator i;
            list<int>::iterator j;

            for (i = arr.begin(); i != arr.end(); i++) {

                printf(" %d -->  ", i->first);

                j = (i->second).begin();
                printf("%d", *j);
                j++;

                for (; j != (i->second).end(); j++)
                    printf(", %d", *j);
                
                printf("\n");
            } // end of outer for loop
        } // end of show()
    
}; // end of Graph class

void createGraph(Graph *g) {

    g->addEdge(0, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 5);
    g->addEdge(2, 3);
    g->addEdge(2, 4);
    g->addEdge(2, 5);
} // end of createGraph()

int main() {

    Graph g;

    createGraph(&g);

    g.show();

    return 0;
} // end of main()