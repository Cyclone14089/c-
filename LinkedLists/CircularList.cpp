#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

class CircularList {

    public:
	    Node *tail;
	
		CircularList() {
	    	tail = NULL;
		} // end of constructor	
	
		int insertFront(int d) {
	    
	    	Node *ptr = new(nothrow) Node();

	    	if (ptr == NULL)
				return 0;
			
			ptr->data = d;
	    
	    	if (tail == NULL) {
				tail = ptr;
                tail->next = tail;
	    	}
	    	else {
				ptr->next = tail->next;
				tail->next = ptr;
	    	}	

	    	return 1;
		} // end of insertFront(int)

		int insertEnd(int d) {
	    
	    	Node *ptr = new(nothrow) Node();

	    	if (ptr == NULL)
				return 0;
			
			ptr->data = d;

            if (tail == NULL) {
				tail = ptr;
                tail->next = tail;
	    	}
            else {
                ptr->next = tail->next;
                tail->next = ptr;
                tail = ptr;
            }
            
	    	return 1;
		} // end of insertEnd(int)

		void display() {

            if (tail == NULL) {
                cout << "List Empty!";
                return;
            }
	    
	    	Node *ptr = tail->next;
	    
	    	do {
                cout << ptr->data;
                cout << " ";
                ptr = ptr->next;
            } while (ptr != tail->next);
	    
	    	cout << endl;
		} // end of display()

		int* delEnd() {

            if (tail == NULL) {
                cout << "List Empty!";
                return NULL;
            }

			Node *temp;
			int *d = NULL;

			if (tail->next == tail) {
				temp = tail;
				tail = NULL;
			}
	    	else {
				
				Node *ptr = tail;
	    
	    		do {
                	ptr = ptr->next;
            	} while (ptr->next != tail);
	    
				temp = tail;
				tail = ptr;
				tail->next = temp->next;
			}

			d = new int(temp->data);
			delete temp;
	    	
			return d;
		} // end of delEnd()

		int* delFirst() {

			if (tail == NULL) {
                cout << "List Empty!";
                return NULL;
            }

			Node *temp;
			int *d = NULL;

			if (tail->next == tail) {
				temp = tail;
				tail = NULL;
			}
			else {
				temp = tail->next;
				tail->next = temp->next;
			}

			d = new int(temp->data);
			delete temp;

			return d;
		} // end of delFirst()

};


int main() {

    cout << "Testing class List...\n";
    
    CircularList *lst = new CircularList();
    
    lst->insertFront(1);
    lst->insertFront(2);
    lst->insertEnd(3);

    cout << "List: ";
    lst->display();
    cout << endl;

	int *d = lst->delEnd();
	cout << "Removed element: ";
	cout << *d;
	cout << endl;

	cout << "List: ";
    lst->display();
    cout << endl;

	d = lst->delFirst();
	cout << "Removed element: ";
	cout << *d;
	cout << endl;

	cout << "List: ";
    lst->display();
    cout << endl;
    
    return 0;
}
