#include<iostream>

using namespace std;

int get_max(int a, int b) { return a > b ? a : b; } // get_max(int, int)

class Item {

	public:

		int value;
		int weight;

		Item() {

			value = 0;
			weight = 0;
		} // end of default constructor

		Item(int value, int weight) {

			this->value = value;
			this->weight = weight;
		} // end of paprameterised constructor
}; // end of class Item

class Knapsack {

	int N;
	int capacity;
	Item **items;
	int **table;
	int is_table_made;

	void make_first_row() {

		int value = items[0]->value;
		for (int i = items[0]->weight; i <= capacity; i++) table[0][i] = value;
	} // end of make_first_row()

	public: 
		
		Knapsack(int N, int capacity) {

			this->N = N;
			this->capacity = capacity;

			items = new Item*[N];

			is_table_made = 0;
			
			table = new int*[N];
			for (int i = 0; i < N; i++) table[i] = new int[capacity + 1]{0};
		} // end of constructor

		void add_item(Item *item, int index) { items[index] = item; } // add_item(Item, int)

		void list_items() {

			printf("--------------------------------\n");
			printf("| Index |   Value   |  Weight  |\n");
			printf("--------------------------------\n");

			for (int i = 0; i < N; i++) {

				printf("|   %d   |     %d     |     %d    |\n", i, items[i]->value, items[i]->weight);
				printf("--------------------------------\n");
			} // end of for loop
		} // end of list_items()

		void display_table() {

			printf("      -");
			for (int j = 0; j <= capacity; j++) printf("------", j);
			printf("\n");

			printf("      |");
			for (int j = 0; j <= capacity; j++) {

				if (j / 10) printf(" %d  |", j);
				else printf("  %d  |", j);
			}
			printf("\n");
			printf("-------");
			for (int j = 0; j <= capacity; j++) printf("------");
			printf("\n");

			for (int i = 0; i < N; i++) {

				printf("|  %d  |", i);
				for (int j = 0; j <= capacity; j++) {

					if (table[i][j] / 10) printf(" %d  |", table[i][j]);
					else printf("  %d  |", table[i][j]);
				}

				printf("\n");
				printf("-------");
				for (int j = 0; j <= capacity; j++) printf("------");
				printf("\n");
			} // end of outer for loop
		} // end of display_table()

		void sort_items_weight() {

			int flag;
			Item *temp;

			for (int i = 0; i < N - 1; i++) {

				flag = 0;
				for (int j = 0; j < N - i - 1; j++) {

					if ((items[j]->weight) > (items[j + 1]->weight)) {

						flag = 1;

						temp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = temp;
					}
				} // end of inner for loop

				if (!flag) break;
			} // end of outer for loop
		} // end of sort_items_weight()

		void make_table() {

			make_first_row();

			int i, j;

			for (i = 1; i < N; i++) {

				j = 0;
				while ((j <= capacity) && (j < items[i]->weight)) {

					table[i][j] = table[i - 1][j];
					j++;
				} // end of inner while loop

				for (; j <= capacity; j++)
					table[i][j] = get_max((items[i]->value + table[i - 1][j - items[i]->weight]), table[i - 1][j]);

			} // end of outer for loop

			is_table_made = 1;
		} // end of make_table()

		int get_best_value() {

			if (!is_table_made) make_table();
			return table[N - 1][capacity];
		} // end of get_best_value()

}; // end of class Knapsack

Knapsack* create_knapsack() {

	printf("Enter the number of items: ");
	int n;
	scanf("%d", &n);

	printf("Enter capacity of knapsack: ");
	int capacity;
	scanf("%d", &capacity);

	Knapsack *ksack = new Knapsack(n, capacity);
	int value;
	int weight;

	printf("Enter value and weight respectively :-\n");
	for (int i = 0; i < n; i++) {

		cout << (i + 1) << ". ";
		cin >> value >> weight;

		Item *item = new Item(value, weight);

		ksack->add_item(item, i);
	} // end of for loop

	return ksack;
} // end of create_knapsack()

int main() {

	Knapsack *knapsack = create_knapsack();
	
	printf("\nThe items are:-\n");
	knapsack->list_items();
	
	knapsack->sort_items_weight();

	printf("\nThe items after sorting are:-\n");
	knapsack->list_items();

	int best_value = knapsack->get_best_value();

	printf("\nThe table:-\n");
	knapsack->display_table();

	printf("\nBest value: %d\n", best_value);

	return 0;
} // end of main()