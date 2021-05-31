#include<iostream>

using namespace std;

void input(int *arr, int len) {

    for (int i = 0; i < len; i++)
        cin >> arr[i];

} // end of input(int*, int)

void display(int *arr, int len) {

    for (int i = 0; i < len; i++) {
        cout << arr[i];
        cout << " ";
    }

} // end of display(int*, int)

int* getElements(int *arr, int len, int k) {

    int *arr1 = new(nothrow) int[2];

    if (arr1 == NULL)
        return NULL;

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == k) {
                arr1[0] = arr[i];
                arr1[1] = arr[j];
                return arr1;
            } // end of if block
        } // end of inner for loop
    } // end of outer for loop

    return NULL;
} // end of getElements(int*, int, int)

int main() {

    cout << "Enter length of array: ";
    int n;
    cin >> n;
    
    int *arr = new(nothrow) int[n];

    if (arr == NULL) {
        cout << "err: UNKNOWN, probably insufficient space" << endl;
        exit(0);
    }
    
    cout << "Enter elements in array: ";
    input(arr, n);

    cout << "Elements in array: ";
    display(arr, n);
    cout << endl;

    int *result = new(nothrow) int[2];

    if (result == NULL) { 
        cout << "err: UNKNOWN, probably insufficient space" << endl;
        exit(0);
    }

    cout << "Enter the value of k: ";
    int k;
    cin >> k;
    
    result = getElements(arr, n, k);

    if (result == NULL)
        cout << "No such pair of elements";
    else {
        cout << "The elements found are: ";
        display(result, 2);
    }

    cout << endl;
    return 0;
} // end of main()
