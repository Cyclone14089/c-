#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

class List {

    public:

        Node *head;
	    Node *tail;
	
		List() {
	    	head = NULL;
	    	tail = NULL;
		} // end of constructor	

		~List() {

            Node *ptr = head;
            Node *temp;

            while (ptr != NULL) {
                
                temp = ptr;
                ptr = ptr->next;
                delete temp;
            }

        } // end of destructor

		bool isEmpty() {
			if (head == NULL) 
				return true;
			return false;
		}
	
		int insert(int d) {
	    
	    	Node *ptr = new(nothrow) Node();

	    	if (ptr == NULL)
				return 0;
			
			ptr->data = d;
	    
	    	if (tail == NULL) {
				head = tail = ptr;
	    	}
	    	else {
				tail->next = ptr;
				tail = ptr;
	    	}	

	    	return 1;
		} // end of insert(int)

		int insert(Node *ptr) {

            if (ptr == NULL)  
                return 0;

            if (tail == NULL) {
                head = tail = ptr;
            }
            else {
                tail->next = ptr;
                tail = ptr;
            }

            return 1;
        } // end of insert(Node*)

		void display() {

			if (head == NULL) {
				cout << "Empty List!";
				return;
			}
	    
	    	Node *ptr = head;
	    
	    	while (ptr != NULL) {
				cout << ptr->data;
				cout << "  ";
				ptr = ptr->next;
	    	} // end of while loop
	    
	    	cout << endl;
		} // end of display()

		int* remove(int index) {

			if (index < 0 || isEmpty()) {

				cout << "err: index does not exist" << endl;
				return NULL;
			}
			
			Node *ptr = head;

			if (index == 0) {

				head = head->next;
				delete ptr;
				return NULL;
			}

			Node *temp = head->next;
			int *d = NULL;

			while (temp != NULL) {
				
				index--;

				if (index == 0) {

					ptr->next = temp->next;
					d = new int(temp->data);
					delete temp;
					return d;
				}

				temp = temp->next;
				ptr = ptr->next;
			} // end of while loop

			cout << "err: index does not exist" << endl;

			return NULL;
		} // end of remove()

		int getItemIndex(int item) {

			Node *ptr = head;
			int i = 0;

			while (ptr != NULL) {

				if (ptr->data == item) return i;

				ptr = ptr->next;
				i++;
			}

			return -1;
		} // end of getItemIndex(int)

};


int main() {

    cout << "Testing class List...\n";
    
    List *lst = new List();
    
    lst->insert(1);
    lst->insert(2);
    lst->insert(3);

	Node *ptr = new Node();
	ptr->data = 4;
	lst->insert(ptr);

    cout << "List: ";
    lst->display();
    cout << endl;

	int i;
	cout << "Enter index to delete item: ";
	cin >> i;

	lst->remove(i);
	cout << "List: ";
    lst->display();
    cout << endl;

	int item;
	cout << "Enter item to search: ";
	cin >> item;
	cout << "Index: ";
	cout << lst->getItemIndex(item);
	cout << endl;

	cout << "List: ";
    lst->display();
    cout << endl;
    
    return 0;
}
