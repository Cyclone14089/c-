#include<iostream>

using namespace std;

struct Item {

    int value;
    int weight;
};

void ratioSort(Item arr[], unsigned int len) {
            
    // sorting according to ratio in descending :-
    struct Item tempBlock;
    double ratio1, ratio2;
    int f;
        
    for (int i = 0; i < len - 1; i++) { // of course, the good old Bubble Sort

        f = 0;

        for (int j = 0; j < len - i - 1; j++) {

            ratio1 = (1.0 * arr[j].value) / arr[j].weight;
            ratio2 = (1.0 * arr[j + 1].value) / arr[j + 1].weight;
                
            if (ratio1 < ratio2) {

                f = 1;
                    
                tempBlock = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempBlock;
            } // end of if block
        } // end of inner for loop

        if (!f) return;
    } // end of outer for loop

} // end of ratioSort(Item[], unsigned int)

double fractionalKnapsack(unsigned int W, Item arr[], unsigned int len) {
        
    // calculating the max possible profit :-
    unsigned int weight = 0; 
    double profit = 0.0;

    for (int i = 0; i < len; i++) {
            
        if (weight < W) {
                
            if ((W - weight) >= arr[i].weight) {
                    
                weight += arr[i].weight;
                profit += arr[i].value;
            }
            else {
                    
                profit += (W - weight) * ((1.0 * arr[i].value) / arr[i].weight);
                break;
            }
        } // end of outer if block
    } // end of outer for loop
        
    return profit;
} // end of fractionalKnapsack(unsigned int, Item[], unsigned int)

void input(Item arr[], unsigned int len) {

    for (int i = 0; i < len; i++) {

        cout << "Enter value: ";
        cin >> arr[i].value;

        cout << "Enter weight: ";
        cin >> arr[i].weight;
    }
} // end of input(Item[], unsigned int)

void input(Item arr[], unsigned int len, int values[], int weights[]) {

    for (int i = 0; i < len; i++) {

        arr[i].value = values[i];
        arr[i].weight = weights[i];
    }
} // end of input(Item[], unsigned int, int[], int[])

int main() {

    unsigned int capacity;
    unsigned int len;

    // cout << "Enter capacity of sack: ";
    // cin >> capacity;

    // cout << "Enter length of array: ";
    // cin >> len;

    capacity = 15;
    len = 7;    

    struct Item arr[len];

    int values[] = {10, 5, 15, 7, 6, 18, 3};
    int weights[] = {2, 3, 5, 7, 1, 4, 1};

    // input(arr, len);
    input(arr, len, values, weights);

    ratioSort(arr, len);

    double profit = fractionalKnapsack(capacity, arr, len);

    cout << "Max Possible Profit: " << profit << endl;

    return 0;
} // end of main()