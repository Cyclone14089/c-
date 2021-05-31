#include<iostream>

using namespace std;

class Node {
    public:

        int payload;
        Node *next; 
        
        Node() {
            payload = 0;
            next = NULL;
        }

        Node(int n) {
            payload = n;
            next = NULL;
        }
};

class List {
    public:

        Node *head;
        Node *tail;

        List() {
            head = NULL;
            tail = NULL;
        }

        void append(Node *ptr) {

            if (this->head == NULL) {
                this->head = ptr;
                this->tail = head;
            }
            else {
                this->tail->next = ptr;
                this->tail = this->tail->next;
            }
        }

        void append(int n) {

            Node *ptr = new Node(n);

            if (this->head == NULL) {
                this->head = ptr;
                this->tail = head;
            }
            else {
                this->tail->next = ptr;
                this->tail = this->tail->next;
            }
        }

        void display() {
            for (Node *ptr = this->head; ptr != NULL; ptr = ptr->next) {
                cout << ptr->payload;
                cout << " ";
            }
            cout << endl;
        }
};

int main() {

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    List *lst = new List();

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> n;
        lst->append(n);
    }

    cout << "Initial List: ";
    lst->display();

    return 0;
} // end of main