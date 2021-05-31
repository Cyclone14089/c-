#include<iostream>

using namespace std;

void input(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cin >> arr[i];
} // end of input(int[], int)

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        cout << " ";
    }
    cout << endl;
} // end of display(int[], int)

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
} // end of swap(int*, int*)

int partition(int arr[], int low, int high) {

    int pivot = arr[low];
    int left = low;
    int right = high + 1;

    while (left < right) {

        do {
            ++left;
        } while (left <= high && arr[left] < pivot);

        do {
            --right;
        } while (arr[right] > pivot);

        if (left < right)
            swap(&arr[left], &arr[right]);

    } // end of outer while loop

    swap(&arr[low], &arr[right]);

    return right;
} // end of partition(int[], int, int)


int main() {

    cout << "Enter length of array: ";
    int n;
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    input(arr, n);

    cout << "Initial array: ";
    display(arr, n);

    int p = partition(arr, 0, n - 1);

    cout << "Array after sorting first element: ";
    display(arr, n);

    cout << "Index of first element after the sort: ";
    cout << p;

    return 0;
} // end of main()