#include<iostream>

using namespace std;

int sum(int n) {

    if (n == 0) return 0;

    return (n % 10) + sum(n / 10);
} // end of sum(int)

int main() {

    cout << "Enter a number: ";
    int n;
    cin >> n;

    cout << "The sum of digits of ";
    cout << n;
    cout << " is: ";
    cout << sum(n);
    cout << endl;

    return 0;
}