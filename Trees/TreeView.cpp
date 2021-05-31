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

class View {

    int maxLevel;

    public:

    View() { maxLevel = 0; } // end of constructor

    void left(Node *root, int level) {

        if (root == NULL) return;

        if (maxLevel < level) {
            cout << root->data;
            cout << " ";
            maxLevel = level;
        }

        left(root->lchild, level + 1);
        left(root->rchild, level + 1);
    }

    void right(Node *root, int level) {

        if (root == NULL) return;

        if (maxLevel < level) {
            cout << root->data;
            cout << " ";
            maxLevel = level;
        }

        left(root->rchild, level + 1);
        left(root->lchild, level + 1);
    }

    void leftMost_rev(Node *root) {

        if (root == NULL) return;

        leftMost_rev(root->lchild);

        cout << root->data;
        cout << " ";
    }

    void rightMost(Node *root) {

        if (root == NULL) return;

        cout << root->data;
        cout << " ";

        rightMost(root->rchild);
    }

    void border(Node *root) {

        if (root == NULL) return;

        leftMost_rev(root->lchild);

        cout << root->data;
        cout << " ";

        maxLevel = 0;
        rightMost(root->rchild);
    }

}; // end of class View

int main() {

    Node *root = new Node();

    root->data = 1;
    root->lchild = new Node(2);
    root->rchild = new Node(3);
    (root->rchild)->rchild = new Node(6);

    cout << "left view: ";
    (new View())->left(root, 1);
    cout << endl;

    cout << "right view: ";
    (new View())->right(root, 1);
    cout << endl;

    cout << "border elements: ";
    (new View())->border(root);
    cout << endl;

    return 0;
}