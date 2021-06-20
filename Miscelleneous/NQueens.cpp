#include<iostream>

using namespace std;

class Board {

    int N; // the N in N x N board
    int *positions; // keep track of positions of queens
    int soln_count; // counting the total number of solutions

    void display_positions() {

        printf("Positions: (");
        for (int i = 0; i < N - 1; i++) printf("%d, ", positions[i]);
        printf("%d)\n", positions[N - 1]);
    } // end of display_positions()

    void dump_board() {

        for (int i = 0; i < N; i++) printf("----");
        printf("-\n");

        for (int row = 0; row < N; row++) {

            printf("|");
            for (int col = 0; col < N; col++) {

                if (col == positions[row])
                    printf(" Q |");
                else
                    printf("   |");
            } // end of inner for loop

            printf("\n");
            for (int i = 0; i < N; i++) printf("----");
            printf("-\n");
        } // end of outer for loop
    } // end of dump_board()

    bool is_possible(int row, int column) {

        for (int i = 0; i < row; i++) // checking columns
            if (positions[i] == column) return false;

        int tmp_row = row--, tmp_column = column++;

        while (row >= 0 && column < N) // checking upper right diagonals
            if (positions[row--] == column++) return false;

        row = tmp_row - 1;
        column = tmp_column - 1;

        while (row >= 0 && column >= 0) // checking upper left diagonals
            if (positions[row--] == column--) return false;

        return true;
    } // end of is_possible(int, int)

    void display_possible_positions(int row) {

        if (row == N) {
            
            printf("Solution %d :-\n", ++soln_count);
            display_positions();
            dump_board();
            printf("\n");
            return;
        }

        for (int column = 0; column < N; column++) {
            if (is_possible(row, column)) {

                positions[row] = column;
                display_possible_positions(row + 1);
            }
        } // end of for loop
    } // end of display_possible_positions(int)

    public:

        Board(int N) {

            this->N = N;
            positions = new int[N];
            soln_count = 0;
        } // end of parameterised constructor

        ~Board() { delete positions; } // destructor

        int get_solutions_count() { return soln_count; } // get_solutions_count() 

        void display_all_possible_positions() { // wrapper function

            display_possible_positions(0);
        } // wrapper function for display_possible_positions(int)

}; // end of class Board

Board* create_board() {

    int n;

    while (1) {
        
        printf("Enter N for a N x N board: ");
        scanf("%d", &n);

        if (n > 0) break;

        printf("C'mon man. This joke ain't funny!\n");
    }

    return (new Board(n));
} // end of create_board()

int main() {

    Board *board = create_board();

    printf("\n");
    board->display_all_possible_positions();

    printf("The total number of possible cases: %d\n", board->get_solutions_count());

    return 0;
} // end of main()