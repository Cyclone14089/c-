#include<iostream>

using namespace std;

class Queue {

    int size;
    int *arr;
    int start;
    int end;

    public:

        Queue(int max) {

            size = max;
            arr = new int[size];
            start = 0;
            end = -1;
        }

        void enqueue(int n) { arr[ ++end % size ] = n; }

        int dequeue() { return arr[ start++ % size ]; }

        int peek() { return arr[ start % size ]; }

        bool isEmpty() {
            return ( end < start );
        }

        bool isFull() {
            return ( end - start == size - 1 );
        }

        void display() {

            for (int i = end; i >= start; i--) {
                cout << arr[ i % size ];
                cout << "  ";
            }

            cout << endl;
        }
};


int main() {

    cout << "Enter size of queue: ";
    int size;
    cin >> size;
    cout << endl;

    Queue q = Queue(size);  // declaring queue

    while (1) {

        int c;

        cout
        << "0. exit" << "  "
        << "1. enqueue" << "  "
        << "2. dequeue" << "  "
        << "3. peek" << "  "
        << "4. is_full?" << "  "
        << "5. is_empty?" << "  "
        << "6. display" << endl
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

                if (q.isEmpty())
                    cout << "Queue is empty!";
                else {
                    cout << "First element in queue: ";
                    cout << q.peek();
                }
                
                cout << endl << endl;
            }
            break;

            case 4: {
                cout << "status: ";
                cout << q.isFull();
                cout << endl << endl;
            }
            break;

            case 5: {
                cout << "status: ";
                cout << q.isEmpty();
                cout << endl << endl;
            }
            break;

            case 6: {

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