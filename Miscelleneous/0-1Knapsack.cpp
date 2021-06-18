#include<iostream>
#include<stack>

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

	stack<Item*> *find_chosen_items() {

			if (!is_table_made) return NULL;

			stack<Item*> *chosen_items = new stack<Item*>; // keep track of the chosen items

			int remaining_capacity = capacity;
			int j = remaining_capacity; // column index
			int curr_value = table[N - 1][j];

			for (int i = N - 2; i >= 0; i--) {

				if (table[i][j] != curr_value) {

					chosen_items->push(items[i + 1]); // pushing item into stack

					remaining_capacity -= (items[i + 1]->weight); // updating remaining capacity of knapsack
					j = remaining_capacity; // updating column index
					curr_value = table[i][j]; // updating current value
				} // end of if block

				if (!curr_value) break; // if current value == 0, there are no selected items left

				if (i == 0) chosen_items->push(items[0]); // if i == 0 and the loop hasn't terminated, 1st item is choosen
			} // end of outer for loop

			return chosen_items;
		} // end of find_chosen_items()

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

		void display_chosen_items() {

			stack<Item*> *chosen_items = find_chosen_items();
			Item *item;
			int value, weight;

			printf("\n");
			printf("------------------\n");
			printf("| Value | Weight |\n");
			printf("------------------\n");

			while (!chosen_items->empty()) {

				item = chosen_items->top();
				chosen_items->pop();

				value = item->value;
				weight = item->weight;

				if (value / 10) printf("|  %d   ", value);
				else printf("|   %d   ", value);
				printf("|");
				if (weight / 10) printf("   %d   |\n", weight);
				else printf("    %d   |\n", weight);

				printf("------------------\n");
			} // end of while loop
		} // end of display_chosen_items()

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

	printf("\nThe items after sorting are:-\n");
	knapsack->list_items();

	int best_value = knapsack->get_best_value();

	printf("\nThe table:-\n");
	knapsack->display_table();

	printf("\nBest value: %d\n", best_value);

	printf("\nChosen items:-");
	knapsack->display_chosen_items();

	return 0;
} // end of main()