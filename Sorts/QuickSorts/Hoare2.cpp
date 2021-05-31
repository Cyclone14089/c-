#include<iostream>

using namespace std;

void input(int arr[], int len) {
    for (int i = 0; i < len; i++)
        cin >> arr[i];
}

void display(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i];
        cout << " ";
    }
    cout << endl;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {

    int pivot = arr[high];
    int left = low - 1;
    int right = high;

    while (left < right) {

        do {
            left++;
        } while (arr[left] < pivot);

        do {
            right--;
        } while (right >= low && arr[right] > pivot);

        if (left < right)
            swap(&arr[left], &arr[right]);

    } // end of outer while loop

    swap(&arr[high], &arr[left]);

    return left;
} // end of partition(int[], int, int)

void quick_sort(int arr[], int low, int high) {

    if (!(low < high)) return;

    int p = partition(arr, low, high);

    quick_sort(arr, low, p - 1);
    quick_sort(arr, p + 1, high);

} // end of quick_sort(int[], int, int)

int main() {

    int len;
    cout << "Enter length of array: ";
    cin >> len;

    int arr[len];

    cout << "Enter elements in array: ";
    input(arr, len);

    cout << "Initial array: ";
    display(arr, len);

    quick_sort(arr, 0, len - 1);

    cout << "Array after sorting: ";
    display(arr, len);
    
    cout << endl;
    return 0;
}