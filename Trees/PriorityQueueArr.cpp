#include<iostream>

using namespace std;

void swap(int* x, int* y) {

    int temp = *x;
    *x = *y;
    *y = temp;
} // end of swap(int*, int*)

class Heap {

    int *arr;
    int len;

    public:

        Heap() {

            arr = NULL;
            len = 0;
        }

        void insert(int val) {

            arr = (int *)realloc(arr, (len + 1) * sizeof(int));
            arr[len++] = val;

            int parent, i = len - 1;

            while (i > 0) {

                parent = (i - 1) / 2;

                if (arr[parent] < arr[i]) {

                    swap(&arr[parent], &arr[i]);
                    i = parent;
                }
                else
                    return;
            }
        } // end of insert(int)

        void display() {

            if (len == 0) cout << "Heap is empty";

            for (int i = 0; i < len; i++) {

                cout << arr[i];
                cout << " ";
            }

            cout << "\n";
        }

};

int main() {

    Heap *heap = new Heap();

    heap->display();

    heap->insert(2);
    heap->insert(1);
    heap->insert(3);

    heap->display();

    heap->insert(5);
    heap->insert(4);

    heap->display();
}