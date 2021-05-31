#include<iostream>

using namespace std;

class Node {

	public:
		
		int data;
		Node *next;

		Node() {
			
			data = 0;
			next = NULL;
		}

		Node(int d) {
		
			data = d;
			next = NULL;
		} // end of parameterised constructor
}; // end of Node class

class List {
	
	Node *start;

	public:

		List() { start = NULL; }

		List(Node *temp) { start = temp; } // end of parameterised constructor

		Node* getStartAddr() { return start; } // end of getStartAddr()

		bool isEmpty() { return ( start == NULL ); } // end of isEmpty()

		Node* getEndAddr() {

			if (isEmpty()) return NULL;
		
			Node *end = start;

			while (end->next != NULL) { end = end->next; }

			return end;

		} // end of getEndAddr()

		void insert(int n) {
				
			Node *item = new Node(n);
			Node *end = getEndAddr();

			if (end == NULL)
				start = item;	
			else
				end->next = item;
			
		} // end of insert(int)

		int pop() {

			Node *temp;
			int d;

			if (start != NULL) {

				temp = start;
				d = start->data;
				start = start->next;
			}

			free(temp);

			return d;
		} // end of pop()

		void display() {
		
			Node *ptr = getStartAddr();

			if (ptr == NULL) { // checking for empty list

				cout << "List Empty!" << endl;
				return;
			}

			while (ptr != NULL) {

				cout << ptr->data;
				cout << " ";

				ptr = ptr->next;
			} // end of while loop for parsing list

			cout << endl;

		} // end of display()

        int exportToArr(int *arr, int p) {

            while (start != NULL) arr[p++] = pop();
            return p;
        } // end of exportToArr(int*)
		
}; // end of List class

class Lol {

	public:

		int len;
		List **arr;

		Lol(int n) {
		
			len = n;
			arr = (List**)malloc(len);

			for (int i = 0; i < len; i++)
				arr[i] = NULL;

		} // end of parameterised constructor

		void display() {

			for (int i = 0; i < len; i++) {

				if (arr[i] == NULL)
					cout << "NULL" << endl;
				else
					(arr[i])->display();

			} // end of for loop

			cout << endl;			
		} // end of display()

        void exportToArr(int *arr_ext) {

            int p = 0;

            for (int i = 0; i < len; i++) {

                if (arr[i] != NULL)
                    p = (arr[i])->exportToArr(arr_ext, p);
            } // end of for loop

        } // end of exportToArr(int*)

        void importFromArr(int *arr_ext, int len, int power) {

			int d;
			int divider = 1;

			while (power > 0) {

				divider *= 10;
				power--;
			} // end of while loop

			cout << "flag 1\n";

            for (int i = 0; i < len; i++) {

				d = (arr_ext[i] / divider) % 10;
				cout << d;
				cout << " ";
                
				if (arr[d] == NULL)
					arr[d] = new List();

				(arr[d])->insert(arr_ext[i]);
            }
        } // end of importFromArr(int*, int, int)

}; // end of Lol class

int getLargest(int *arr, int len) {

    int max = arr[0];

    for (int i = 1; i < len; i++) 
        if (arr[i] > max) 
            max = arr[i];

    return max;
} // end of getLargest(int*, int)

int digitCount(int n) {

    int d = 0;

    while (n > 0) {

        n /= 10; 
        d++; 
    }

    return d;
} // end of digitCount(int)

void input(int *arr, int len) {

    cout << "Enter the elements: ";

    for (int i = 0; i < len; i++)
        cin >> arr[i];

} // end of input(int*, int)

void display(int *arr, int len) {

    if (!(len > 0)) {
        cout << "Array Empty!\n";
        return;
    }

    cout << "Elements are: ";

    for (int i = 0; i < len; i++) {

        cout << arr[i];
        cout << " ";
    }

    cout << endl;

} // end of input(int*, int)

int main() {

    int len;
    cout << "Enter the number of elements: ";
    cin >> len;

    int *arr = new int[len];

    input(arr, len);
    display(arr, len);

	Lol *lol = new Lol(10);

	lol->importFromArr(arr, len, 0);
	// lol->display();

} // end of main()