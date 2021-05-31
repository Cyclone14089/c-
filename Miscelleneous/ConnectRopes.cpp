#include<iostream>

using namespace std;

void swap(int *x, int *y) { // swaps the data between 2 provided addresses

    int temp = *x;
    *x = *y;
    *y = temp;
} // end of swap(int*, int)

class MinHeap {

    unsigned int capacity;

    public:

        unsigned int size;
        int *arr;

        MinHeap(int capacity) {

            this->capacity = capacity;
            size = capacity;
            arr = new int[size];
        } // end of constructor

        ~MinHeap() { delete arr; } // destructor

        void heapify(int root) { // creates min heap of sub-array

            int smallest = root;
            int left = root * 2 + 1;
            int right = root * 2 + 2;

            if (left < size && arr[left] < arr[smallest]) smallest = left;
            if (right < size && arr[right] < arr[smallest]) smallest = right;

            if (smallest != root) {

                swap(&arr[smallest], &arr[root]);
                heapify(smallest);
            }
        } // end of heapify(int)

        void build() { // creates min heap from an array

            int i = (size - 1) / 2;
            for (; i >= 0; i--) heapify(i);
        } // end of build

        int extractMin() {

            if (size == 0) return 0;

            int temp = arr[0];
            arr[0] = arr[--size];
            heapify(0);
            return temp;
        } // end of extractMin()

        void insert(int val) {

            if (size == capacity) return;

            int i = size++;
            arr[i] = val;
            int parent = (i - 1) / 2;

            while (i && (val < arr[parent])) {

                swap(&arr[parent], &arr[i]);
                i = parent;
                parent = (i - 1) / 2;
            } // end of while loop
        } // end of insert()

};// end of class MinHeap

void input(int *arr, int len) { // receiving input elements for provided array

    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
} // end of input(int*, int)

void display(int *arr, int len) { // prints all elements of the provided array

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
} // end of display(int*, int)

MinHeap *createMinHeap(int *arr, int len) { // returns the address of MinHeap built from an array

    MinHeap *minHeap = new MinHeap(len);

    for (int i = 0; i < len; i++)
        minHeap->arr[i] = arr[i];

    minHeap->build();    
        
    return minHeap;
} // end of createMinHeap(int*, int)

int getMinCost(int *arr_ropes, int n) {

    int cost = 0;

    MinHeap *minHeap = createMinHeap(arr_ropes, n);
    int min1, min2;

    while (minHeap->size != 1) {

        min1 = minHeap->extractMin();
        min2 = minHeap->extractMin();

        cost += min1 + min2;

        minHeap->insert(min1 + min2);
    } // end of while loop

    return cost;
} // end of getMinCost(int*, int)

int main() {

    printf("Enter length of array: ");
    int n;
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements in array: ");
    input(arr, n);

    // printf("Array: ");
    // display(arr, n);
    // printf("\n");

    printf("Total minimum cost required: %d\n", getMinCost(arr, n));

    return 0;
} // end of main()