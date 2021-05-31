#include<iostream>

using namespace std;

class bio {
    public:
        string name;
        int age;

        bio() {
            name = "";
            age = 0;
        } // end of default constructor

        bio(string n, int a) {
            name = n;
            age = a;
        } // end of parameterised constructor
}; // end of bio class

void input(bio arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << i + 1;
        cout << " Enter name: ";
        cin >> arr[i].name;
        cout << "  Enter age: ";
        cin >> arr[i].age;
    }
}

void display(bio arr[], int len) {

    for (int i = 0; i < len; i++) {
        cout << arr[i].name;
        cout << " : ";
        cout << arr[i].age;
        cout << "\n";
    }
    cout << endl;
}

void merge(bio arr[], int l, int m, int r) {

    int n1 = m - l + 1;
    int n2 = r - m;

    bio arrL[n1], arrR[n2];

    for (int i = 0; i < n1; i++)
        arrL[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        arrR[i] = arr[m + 1 + i];

    int i1 = 0, i2 = 0, i3 = l;   // Initial index of subarrays
 
    while (i1 < n1 && i2 < n2) {

        if (arrL[i1].age <= arrR[i2].age)
            arr[i3] = arrL[i1++];
        else 
            arr[i3] = arrR[i2++];
            
        i3++;
    }
 
    // Copying the remaining elements

    while (i1 < n1)
        arr[i3++] = arrL[i1++];
 
    while (i2 < n2)
        arr[i3++] = arrR[i2++];
    
} // end of merge(int[], int, int, int)
 

void mergeSort(bio arr[], int l, int r) {

    if (l >= r)
        return;

    int m = (l + r - 1) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);

} // end of mergeSort(int[], int, int)


int main() {

    int len;
    cout << "Enter length of array: ";
    cin >> len;

    bio arr[len];

    cout << "Enter elements in array :-\n";
    input(arr, len);

    cout << "\nInitial array :-\n";
    display(arr, len);

    mergeSort(arr, 0, len - 1);

    cout << "Array after sorting :-\n";
    display(arr, len);

    return 0;
} // end of main