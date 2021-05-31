#include<iostream>

using namespace std;

struct Node {  // structure of a node of the Doubly Linked List

    int data;
    struct Node *prev;
    struct Node *next;
};

class DList {  // the blue-print of a Doubly Linked List

    Node *head;

    public:

        DList() {
            head = NULL;
        } // end of constructor

        ~DList() {

            Node *ptr = head;
            Node *temp;

            while (ptr != NULL) {
                
                temp = ptr;
                ptr = ptr->next;
                delete temp;
            }

        } // end of destructor

        void display() {

            if (head == NULL) {
                cout << "List is empty!" << endl;
                return;
            }

            cout << "List: ";
            Node *ptr = head;

            while (ptr->next != NULL) {  // printing elements

                cout << ptr->data;
                cout << " <--> ";
                ptr = ptr->next;
            }
            cout << ptr->data;

            cout << endl;
        } // end of display()

        void display_rev() {

            if (head == NULL) {
                cout << "List is empty!";
                return;
            }

            cout << "List: ";
            Node *ptr = head;

            while (ptr->next != NULL) { ptr = ptr->next; } // moving to the last node

            while (ptr != NULL) {  // printing elements

                cout << ptr->data;
                cout << " ";
                ptr = ptr->prev;
            }

            cout << endl;
        } // end of display_rev()

        void insertFront(int item) {

            Node *ptr = new(nothrow) Node();

            if (ptr == NULL) {
                cout << "err: unknown... Probably, insufficient memory space" << endl;
                return;
            }

            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = head;

            if (head != NULL) head->prev = ptr;

            head = ptr;
        } // end of insertFront(int)

        void insertEnd(int item) {

            Node *ptr = new(nothrow) Node();

            if (ptr == NULL) {
                cout << "err: unknown... Probably, insufficient memory space" << endl;
                return;
            }

            ptr->data = item;
            ptr->next = NULL;

            if (head == NULL) {  // checking if list is empty

                ptr->prev = NULL;
                head = ptr;
                return;
            }

            Node *temp = head;

            while (temp->next != NULL) { temp = temp->next; } // moving to the last node

            temp->next = ptr;
            ptr->prev = temp;

        } // end of insertEnd(int)

        Node* getItemAddress(int item) {

            Node *ptr = head;

            while (ptr != NULL) {

                if (ptr->data == item) return ptr;
                ptr = ptr->next;
            }

            return NULL;
        }

        void insertAfter(Node *pos, int item) {

            if (pos == NULL) {
                cout << "err: Invalid address" << endl;
                return;
            }

            Node *ptr = new(nothrow) Node();

            if (ptr == NULL) {
                cout << "err: UNKNOWN. Probably, insufficient space" << endl;
                return;
            }

            ptr->data = item;
            ptr->next = pos->next;
            ptr->prev = pos;

            if (pos->next != NULL) (pos->next)->prev = ptr;
            pos->next = ptr;
        }

        void insertBefore(Node *pos, int item) {

            if (pos == NULL) {
                cout << "err: Invalid address" << endl;
                return;
            }

            Node *ptr = new(nothrow) Node();

            if (ptr == NULL) {
                cout << "err: UNKNOWN. Probably, insufficient space" << endl;
                return;
            }

            ptr->data = item;
            ptr->next = pos;
            ptr->prev = pos->prev;

            if (pos->prev != NULL) (pos->prev)->next = ptr;
            pos->prev = ptr;
            head = ptr;

        }

        void delFront() {

            if (head == NULL) {
                cout << "List is empty!";
                return;
            }

            if (head->next == NULL) {  // if link has single node

                delete head;
                head = NULL;

                return;
            }

            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;

        } // end of delFront()

        void delEnd() {

            if (head == NULL) {
                cout << "List is empty!" << endl;
                return;
            }

            if (head->next == NULL) {  // if link has single node

                delete head;
                head = NULL;

                return;
            }

            Node *temp = head;
            
            while (temp->next != NULL) temp = temp->next;  // moving to the last node

            (temp->prev)->next = NULL;
            delete temp;

        } // end of delEnd()

        void delAt(int index) {}

        void delItem(int item) {}

}; // end of DList class

int getChoice() {

    int c;
    cout << "--------------------------------------------------------\n";
    cout << "0. Quit process\n1. Insert at beginning\n2. Insert at end\n3. Display\n4. Delete at beginning\n5. Delete at end\n";
    cout << "--------------------------------------------------------\n";
    cout << "Enter choice: ";
    cin >> c;
    cout << "--------------------------------------------------------\n";

    return c;
}

void handleChoice(DList *lst, int c) {

    switch(c) {

        case 0:
            cout << "Bye" << endl;
        break;

        case 1: {

            cout << "Enter item: ";
            int n;
            cin >> n;
            lst->insertFront(n);
        }
        break;

        case 2: {

            cout << "Enter item: ";
            int n;
            cin >> n;
            lst->insertEnd(n);
        }
        break;

        case 3:
            lst->display();
        break;

        case 4: 
            lst->delFront();
        break;

        case 5:
            lst->delEnd();
        break;

        default:
            cout << "INVALID CHOICE!" << endl;

    } // end of switch-case block
}


int main() {

    cout << "Testing list..." << endl;

    DList *lst = new DList();

    int c = 1;

    while (c != 0) {

        c = getChoice();
        handleChoice(lst, c);
    }

    return 0;
} // end of main()