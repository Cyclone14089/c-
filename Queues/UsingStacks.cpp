#include<iostream>

using namespace std;

class Stack {
    
    int MAX;
    int* arr;
    int top;

    public :

        Stack(int size) {
            MAX = size;
            arr = new int[MAX];
            top = -1;
        }

        void push(int n) {
            arr[++top] = n;
        }

        int pop () {
            return arr[top--];
        }

        int isFull() {
            if (top == MAX - 1) return 1;
            return 0;
        }

        int isEmpty() {
            if ( top == -1 ) return 1;
            return 0;

        }

        void display() {
            for (int i = top; i >= 0; i--) {
                cout << arr[i];
                cout << "  ";
            }
            cout << endl;
        }
};

class Queue {
    int size;

    Stack *inStk; // for insertion purpose
    Stack *outStk; // for deletion purpose

    void fill(Stack *isFilled, Stack *toBeFilled) {
        while (!isFilled->isEmpty())
            toBeFilled->push(isFilled->pop());
    }

    public:

        Queue(int max) { 
            size = max;
            inStk = new Stack(size);
            outStk = new Stack(size); 
        }

        bool isEmpty() { return inStk->isEmpty() && outStk->isEmpty(); }

        bool isFull() { return inStk->isFull() || outStk->isFull(); }

        void enqueue(int n) {
            fill(outStk, inStk);
            inStk->push(n);
        }

        int dequeue() {
            fill(inStk, outStk);
            return outStk->pop();
        }

        void display() {
            fill(outStk, inStk);
            inStk->display();
        }

};

int main() {
    
    cout << "Enter size of queue: ";
    int size;
    cin >> size;
    cout << endl;

    Queue q = Queue(size); // declaring queue

    while (1) {

        int c;

        cout
        << "0. exit" << "  "
        << "1. enqueue" << "  "
        << "2. dequeue" << "  "
        << "3. is_full?" << "  "
        << "4. is_empty?" << "  "
        << "5. display" << endl
        << "Enter choice: ";

        cin >> c;

        switch (c) {

            case 0: {
                cout << "Bye!" << endl << endl;
                exit(1);
            }
            break;

            case 1: {

                if (q.isFull())
                    cout << "Queue is full!" << endl;
                else {

                    cout << "Enter element: ";
                    int n;
                    cin >> n;

                    q.enqueue(n);
                }

                cout << endl;
            }
            break;

            case 2: {

                if (q.isEmpty())
                    cout << "Queue is empty!";
                else {
                    cout << "Deleted element: ";
                    cout << q.dequeue();
                }

                cout << endl << endl;
            }
            break;

            case 3: {
                cout << "status: ";
                cout << q.isFull();
                cout << endl << endl;
            }
            break;

            case 4: {
                cout << "status: ";
                cout << q.isEmpty();
                cout << endl << endl;
            }
            break;

            case 5: {

                if (q.isEmpty() == 1)
                    cout << "Queue is empty!" << endl;
                else
                    q.display();
                
                cout << endl;
            }
            break;

            default:
                cout << "INVALID CHOICE!" << endl << endl;
        }

    }

    return 0;
}