#include<iostream>

using namespace std;

struct job {

    char id;
    unsigned int deadline;
    unsigned int profit;
};

void profitSort(struct job *arr, unsigned int len) {
            
    // sorting according to ratio in descending :-
    struct job tempBlock;
    int f;
        
    for (int i = 0; i < len - 1; i++) { // of course, the good old Bubble Sort

        f = 0;

        for (int j = 0; j < len - i - 1; j++) {
                
            if (arr[j].profit < arr[j + 1].profit) {

                f = 1;
                    
                tempBlock = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempBlock;
            } // end of if block
        } // end of inner for loop

        if (!f) return;
    } // end of outer for loop

} // end of ratioSort(struct job*, unsigned int)

void display(char id[], int len) {

    printf("Schedule ids: ");
    for (int i = 0; i < len; i++) cout << id[i] << " ";
    cout << endl;
} // end of display(char[], int)

int *get_schedule(struct job *jobs, unsigned int len) {

    int *schedule = new int[len]{0};
    char id[len];
    int deadline;

    for (int i = 0; i < len; i++) {

        deadline = jobs[i].deadline - 1;

        while (deadline >= 0) {

            if (!schedule[deadline]) {

                schedule[deadline] = jobs[i].profit;
                id[deadline] = jobs[i].id;
                break;
            }
                 
            deadline--;
        } // end of inner while loop
    } // end of outer for loop

    display(id, len);

    return schedule;
} // end of get_schedule(struct job*, unsigned int)

int schedule_sum(int *schedule, unsigned int len) {

    int sum = 0;

    for (int i = 0; i < len; i++)
        sum += *(schedule + i);
    
    return sum;
} // end of schedule_sum(int*, unsigned int)

void display_schedule(int *schedule, unsigned int len) {

    for (int i = 0; i < len; i++)
        if (schedule[i])
            cout << schedule[i] << " ";
    
    cout << endl;
} // end of display_schedule(int*, unsigned int)

void input(struct job *jobs, unsigned int len, int *profits, int *deadlines) {

    char id = 'A';

    for (int i = 0; i < len; i++) {

        jobs[i].id = id;
        jobs[i].profit = profits[i];
        jobs[i].deadline = deadlines[i];

        id++;
    }
} // end of input(Item[], unsigned int, int[], int[])

int main() {

    int len = 7;

    struct job jobs[len];

    int profits[len] = {3, 5, 20, 18, 1, 6, 30};
    int deadlines[len] = {1, 3, 4, 3, 2, 1, 2};
    
    input(jobs, len, profits, deadlines);

    profitSort(jobs, len);

    int *schedule = get_schedule(jobs, len);

    int total_profit = schedule_sum(schedule, len);

    printf("Schedule profits: ");
    display_schedule(schedule, len);

    printf("Total profit: %d\n", total_profit);

    return 0;
} // end of main()