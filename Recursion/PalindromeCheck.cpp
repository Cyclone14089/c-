#include<iostream>

using namespace std;

int reverseOf(int n, int result) {

    if (n == 0) return result;

    result = result * 10 + (n % 10);

    return reverseOf(n / 10);
} // end of reverseOf(int, int)

bool isPalin(int n) { return (n == reverseOf(n))} // end of isPalin(int)

int main() {

    cout << "Enter a number: ";
    int n;
    cin >> n;

    cout << n;

    if (isPalin(n))
        cout << " is a palindrome.";
    else
        cout << " is not a palindrome.";

    cout << endl;

    return 0;
}