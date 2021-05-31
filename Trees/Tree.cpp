#include<iostream>

using namespace std;

struct Node {

    int data;
    struct Node *lchild;
    struct Node *rchild;

    Node() {

        data = 0;
        lchild = NULL;
        rchild = NULL;
    }

    Node(int d) {

        data = d;
        lchild = NULL;
        rchild = NULL;
    }
};

int getMax(int x, int y) { return (x > y) ? x : y; }

class BTree {

    Node *root;

    void preOrder(Node *ptr) {

        if (ptr == NULL) return;

        cout << ptr->data;
        cout << " ";

        preOrder(ptr->lchild);
        preOrder(ptr->rchild);
    }

    void inOrder(Node *ptr) {

        if (ptr == NULL) return;
        
        inOrder(ptr->lchild);

        cout << ptr->data;
        cout << " ";

        inOrder(ptr->rchild);
    }

    void postOrder(Node *ptr) {

        if (ptr == NULL) return;

        postOrder(ptr->lchild);
        postOrder(ptr->rchild);

        cout << ptr->data;
        cout << " ";
    }

    int popMin(Node *ptr, Node *parent) {

        if (ptr == NULL) return 0;

        if (ptr->rchild == NULL) {

            int data = ptr->data;
            deleteElement(ptr, parent, data);
            return data;
        }

        return popMin(ptr->rchild, ptr);
    }

    Node* searchItem(Node *ptr, int item) {

        if (ptr == NULL) return NULL;

        if (ptr->data == item) return ptr;

        Node *result;

        if (item < ptr->data) 
            result = searchItem(ptr->lchild, item);
        else
            result = searchItem(ptr->rchild, item);

        if (result != NULL) return result;
        
        return NULL;
    }

    int height(Node *ptr) {

        if (ptr == NULL) return 0;

        return 1 + getMax(height(ptr->lchild), height(ptr->rchild));
    }

    void deleteElement(Node *current, Node *parent, int item) {

        if (current == NULL) return;

        if (current->data == item) {

            if (current->lchild == NULL && current->rchild == NULL) {

                if (current == root) root = NULL;

                else if (parent != NULL) {

                    if (parent->lchild == current) 
                        parent->lchild = NULL;
                    else
                        parent->rchild = NULL;
                }

                delete current;
            } // end of 'both child null' condition handling block

            else if (current->lchild == NULL) {

                if (current == root) {

                    root = current->rchild;
                    return;
                }

                if (parent != NULL) {

                    if (parent->lchild == current) 
                        parent->lchild = current->rchild;
                    else
                        parent->rchild = current->rchild;
                }

                delete current;
            } // end of 'left child null' condition handling block

            else if (current->rchild == NULL) {

                if (current == root) {

                    root = current->lchild;
                    return;
                }

                if (parent != NULL) {

                    if (parent->lchild == current) 
                        parent->lchild = current->lchild;
                    else
                        parent->rchild = current->lchild;
                }

                delete current;
            } // end of 'right child null' condition handling block

            else {

                current->data = popMin(current->lchild, current);
            } // end of 'no child null' condition handling block

            return;
        } // end of outer if block


        if (item < current->data) 
            deleteElement(current->lchild, current, item);
        else
            deleteElement(current->rchild, current, item);

    }

    int countNodes(Node *ptr) {

        if (ptr == NULL) return 0;

        return 1 + countNodes(ptr->lchild) + countNodes(ptr->rchild);
    }

    int countExternalNodes(Node *ptr) {

        if (ptr == NULL) return 0;

        if (ptr->lchild == NULL && ptr->rchild == NULL) return 1;

        return countExternalNodes(ptr->lchild) + countExternalNodes(ptr->rchild);
    }

    public:

        BTree() { root = NULL; }

        Node* getRootAddr() { return root; }

        bool isEmpty() { return (root == NULL); }

        int countTotalNodes() { return countNodes(root); }

        int countExternalNodes() { return countExternalNodes(root); }

        int countInternalNodes() { return countNodes(root) - countExternalNodes(root); }

        void insert(int item) {

            Node *ptr = new(nothrow) Node(item);

            if (ptr == NULL) {

                cout << "err: unknown : probably, low on space" << endl;
                return;
            }

            if (isEmpty()) { 

                root = ptr;
                return;
            }

            Node *temp = root;
            Node *parent = NULL;

            while (temp != NULL) {

                parent = temp;

                if (item < temp->data)
                    temp = temp->lchild;
                else
                    temp = temp->rchild;
            } // end of while loop

            if (item < parent->data)
                parent->lchild = ptr;
            else
                parent->rchild = ptr;
        }

        void preDisplay() {

            preOrder(root);
            cout << endl;
        }
        
        void inDisplay() {

            inOrder(root);
            cout << endl;
        }

        void postDisplay() {

            postOrder(root);
            cout << endl;
        }

        Node* getItemAddr(int item) { return searchItem(root, item); }

        Node* getItemAddr(Node* ptr, int item) { return searchItem(ptr, item); }

        void printSmallest() {
            
            if (root == NULL) {
                
                cout << "Tree is empty" << endl;
                return;
            }

            Node *ptr = root;

            while (ptr->lchild != NULL) { ptr = ptr->lchild; }

            cout << ptr->data;
            cout << endl;

            return;
        }

        void printLargest() {
            
            if (root == NULL) {
                
                cout << "Tree is empty" << endl;
                return;
            }

            Node *ptr = root;

            while (ptr->rchild != NULL) { ptr = ptr->rchild; }

            cout << ptr->data;
            cout << endl;
            
            return;
        }

        int getHeight() { return height(root); }

        void deleteItem(int item) {

            deleteElement(root, NULL, item);
        }

};

void dispChoices() { 

    cout << "--------------------------------------------------------\n";
    
    cout << "1. Insert\n"; 
    cout << "2. PreOrder display\n";
    cout << "3. InOrder display\n";
    cout << "4. PostOrder display\n";
    cout << "5. Find Smallest\n";
    cout << "6. Find Largest\n";
    cout << "7. Search Item\n";
    cout << "8. Print Height\n";
    cout << "9. Delete Item\n";
    cout << "10. Count Total Nodes\n";
    cout << "11. Count Internal Nodes\n";
    cout << "12. Count External Nodes\n";

    cout << "--------------------------------------------------------\n";
    
    cout << "Enter choice: "; 
    }

bool handleChoice(BTree *r, int c) {
    
    switch (c) {

        case 1: {

            int item;
            cout << "Enter item: ";
            cin >> item;
            r->insert(item);
        }
        break;

        case 2:

            r->preDisplay();
        break;

        case 3:

            r->inDisplay();
        break;

        case 4:

            r->postDisplay();
        break;

        case 5:

            r->printSmallest();
        break;

        case 6:

            r->printLargest();
        break;

        case 7: {

            cout << "Enter item to search: ";
            int item;
            cin >> item;

            Node *resultAddr = r->getItemAddr(item);

            if (resultAddr == NULL)
                cout << "Item not found";
            else {
                cout << "Address of item  ";
                cout << resultAddr->data;
                cout << " is: ";
                cout << resultAddr;
            }

            cout << endl;
        }
        break;

        case 8: {

            cout << "Height: ";
            cout << r->getHeight();
            cout << endl;
        }
        break;

        case 9: {

            cout << "Enter item: ";
            int item;
            cin >> item;

            r->deleteItem(item);
        }
        break;

        case 10: {

            cout << "Total number of Nodes: ";
            cout << r->countTotalNodes();
            cout << endl;
        }
        break;

        case 11: {

            cout << "Number of Internal Nodes: ";
            cout << r->countInternalNodes();
            cout << endl;
        }
        break;

        case 12: {

            cout << "Number of External Nodes: ";
            cout << r->countExternalNodes();
            cout << endl;
        }
        break;

        default: {

            cout << "Bye" << endl;
            return false;
        }
    }

    return true;
}

int main() {

    BTree *bt = new BTree();

    int c;

    do {

        dispChoices();
        cin >> c;

    } while (handleChoice(bt, c));
    
    return 0;
} // end of main()