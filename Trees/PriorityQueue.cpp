#include<stdio.h>

using namespace std;

class Node {

    public:

        int data;
        Node *lchild;
        Node *rchild;

        Node() {

            data = 0;
            lchild = NULL;
            rchild = NULL;
        } // end of constructor

        Node (int d) {

            data = d;
            lchild = NULL;
            rchild = NULL;
        } // end of parameterised constructor
};

class Tree {

    Node *root;


    void recur_insert(Node* current, Node* parent, Node* newElement) {

        if (current->lchild == NULL) {

            current->lchild = newElement;
            return;
        }
        else if (current->rchild == NULL) {

            current->rchild = newElement;
            return;
        }
        else {

            recur_insert(current->lchild, current, newElement);
        }

        return;
    } // end of recur_insert(Node*, Node*, Node*)

    public:

        Tree() { root = NULL; } // end of contructor

        Tree(Node *r) { root = r; } // end of parameterised constructor

        Node* getRootAddr() { return root; }

        int insert(int val) {

            Node *newElement = new(nothrow) Node(val);
            
            if (newElement == NULL) {

                cout << "err: Unable to allocate memory\n";
                return 0;
            }

            if (root == NULL) {

                root = newElement;
                return 1;
            }

            recur_insert(root, NULL, newElement);
            return 1;

        } // end of insert(int)
};