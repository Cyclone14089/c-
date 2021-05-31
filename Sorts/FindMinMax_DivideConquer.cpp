#include<iostream>

using namespace std;

class Array {

    public:

        int *arr;
        int n;

        Array() {

            printf("Enter size of array: ");
            scanf("%d", &n);

            arr = new int[n];
        } // end of constructor

        ~Array() {

            delete arr;
        } // end of destructor

        void input() {

            printf("Enter elements in array: ");
            for (int i = 0; i < n; i++)
                scanf("%d", &arr[i]);
        } // end of input()

        void display() {

            printf("The elements in array are: ");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);

            printf("\n");
        } // end of display()

}; // end of Array class

int getMin(int a, int b) { return (a < b) ? a : b; }

int getMax(int a, int b) { return (a > b) ? a : b; }

class MinMax {

    Array *arr;

    int* findMinMax(int l, int r) {

        int *parcel = new int[2]; // container variable to store and dispatch min and max

        if ((r - l) == 0) {

            parcel[0] = arr->arr[l];
            parcel[1] = arr->arr[l];
            
            return parcel;
        } // if length of array is 1

        int m = (l + r - 1) / 2;

        int *parcel1 = findMinMax(l, m);
        int *parcel2 = findMinMax(m + 1, r);

        parcel[0] = getMin(parcel1[0], parcel2[0]);
        parcel[1] = getMax(parcel1[1], parcel2[1]);

        delete parcel1;
        delete parcel2;

        return parcel;
    } // end of findMinMax(int, int)

    public:

        MinMax(Array *arr) {

            this->arr = arr;
        } // end of constructor

        void display() {

            int *parcel = findMinMax(0, arr->n - 1);

            printf("Minimum value: %d\nMaximum value: %d\n", parcel[0], parcel[1]);

            delete parcel;
        } // end of display()

}; // end of MinMax class

int main() {

    Array arr;
    arr.input();
    arr.display();

    MinMax m = MinMax(&arr);
    m.display();

    return 0;
} // end of main()