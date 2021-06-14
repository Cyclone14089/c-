#include<iostream>

using namespace std;

class Fibonacci {
	
	int *values; // for storing fibonacci values

	public:

		Fibonacci(int N) { 
			
			values = new int[N]{0}; 
			values[1] = 1;
		} // constructor

		~Fibonacci() { delete values; } // destructor
		
		int get_fibonacci(int n) {

			if (n < 0) return -1;
			
			if (n == 0) return 0;
			if (n == 1) return 1;

			// if fibonnacci value not already computed, compute and set
			if (!values[n]) values[n] = get_fibonacci(n - 1) + get_fibonacci(n - 2);
		
			return values[n];
		} // end of get_fibonacci(int)

		void dump_values_till(int n) {

			for (int i = 0; i < n; i++) printf("%d ", values[i]);
		} // end of dump_values(int)

}; // end of Fibonacci class

int main() {

	cout << "Enter number to get fibonacci: ";
	int n;
	cin >> n;
	
	Fibonacci fibo(n);

	int fibo_val = fibo.get_fibonacci(n - 1);

	cout << "Fibonacci value: " << fibo_val;
	cout << "\nSeries: ";
	
	fibo.dump_values_till(n);

	cout << endl;
	return 0;	
} // end of main()
