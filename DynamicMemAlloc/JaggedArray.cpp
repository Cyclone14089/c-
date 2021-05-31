#include<iostream>

using namespace std;

void input(int **arr, int rows, int *size) {

    for (int i = 0; i < rows; i++) {

        cout << "Enter number of columns in row ";
        cout << i + 1;
        cout << " : ";

        cin >> size[i];
        arr[i] = (int*)malloc(size[i] * sizeof(int));

        cout << "Enter elements: ";
        for (int j = 0; j < size[i]; j++)
            cin >> arr[i][j];

    } // end of outer for loop
} // end of input(int**, int, int*)

void display(int **arr, int rows, int *size) {
    cout << "Current matrix :-" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < size[i]; j++) {
            cout << arr[i][j];
            cout << " ";
        } // end of inner for loop
        cout << endl;
    } // end of outer for loop
} // end of display(int**, int, int*)

int main() {

    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    int **arr = (int**)malloc(rows * sizeof(int));
    int *size = (int*)malloc(rows * sizeof(int));

    input(arr, rows, size);
    display(arr, rows, size);

    return 0;
} // end of main()