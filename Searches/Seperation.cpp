#include<iostream>

using namespace std;

int pointOfSeperation(bool *arr, int lb, int rb) {

	if (rb < lb) return rb;
    
	int mid = (lb + rb) / 2;
    
	if (arr[mid]) return pointOfSeperation(arr, mid + 1, rb);

        return pointOfSeperation(arr, lb, mid - 1);
} // end of pointOfSeperation(bool*, int)


void display(bool *arr, int n) {

    if (n == 0) return;

    printf("{ ");
    for (int i = 0; i < n - 1; i++) printf("%d, ", arr[i]);
    printf("%d }", arr[n - 1]);

    printf("\n");
} // end of display(bool*, int)

int main() {

    int len = 6;
    bool arr[len] = {true, true, true, true, false, false};

    printf("array: ");
    display(arr, len);

    if (!arr[0] || arr[len - 1]) {
    	
	    printf("Point of seperation absent in array.\n");
	    exit(0);
    }

    int seperation = pointOfSeperation(arr, 0, len - 1);
    printf("Point of seperation lies between index %d and %d of the array.\n", seperation, seperation + 1);

    return 0;
} // end of main
