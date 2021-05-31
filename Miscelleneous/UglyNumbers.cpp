#include<iostream>

using namespace std;

int get_min(int x, int y) { return (x < y) ? x : y; }

unsigned int get_Nth_UglyNumber(unsigned int n) { // using Dynamic Programming approach

    unsigned int ugly[n];
    ugly[0] = 1;

    unsigned int i2 = 0, i3 = 0, i5 = 0;
    unsigned int 
        nextMultiple2 = 2, 
        nextMultiple3 = 3, 
        nextMultiple5 = 5;

    unsigned int nextUgly;

    for (unsigned int i = 1; i < n; i++) {

        nextUgly = get_min(nextMultiple2, get_min(nextMultiple3, nextMultiple5));
        
        ugly[i] = nextUgly;

        if (nextUgly == nextMultiple2) {

            i2 += 1;
            nextMultiple2 = ugly[i2] * 2;
        }
        if (nextUgly == nextMultiple3) {

            i3 += 1;
            nextMultiple3 = ugly[i3] * 3;
        }
        if (nextUgly == nextMultiple5) {

            i5 += 1;
            nextMultiple5 = ugly[i5] * 5;
        }
    } // end of for loop
    
    return nextUgly;
} // end of get_Nth_UglyNumber(unsigned int)

int main() {
    
    printf("Enter the value of n: ");
    unsigned int n;
    scanf("%d", &n);

    printf("The %dth ugly number is: %d\n", n, get_Nth_UglyNumber(n));

    return 0;
} // end of main()