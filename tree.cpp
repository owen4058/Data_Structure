//20195300 유욱현
//Description : tree basic Practice

#include <iostream>

using namespace std;

static const char prec[4][2] = { '*',2,'/',2,'+',1,'-',1 };

struct Node {
    char data;
    int prio;
    Node* left;
    Node* right;
    Node(char value) {
        data = value;
        prio = 4;
        left = 0;
        right = 0;
    }
};

class Tree {
private:
    Node *root;
public:
    Tree() { root = 0; }
    bool isEmpty();
    bool isdigit(int value);
    void inorder(Node *ptr);
    void postorder(Node *ptr);
    void preorder(Node *ptr);
    void Operand(Node *ptr);
    void Operator(Node *ptr);
    void buildTree(char input);
    int evalTree(Node *ptr);
    void parentheses(Node *ptr);
    void PrintTree(Node* P, int level);
    Node* getRoot();
};
void Tree::PrintTree(Node* P, int level) {
    int j = 1;
    if (P != NULL) {
        PrintTree(P->right, level + 1); //Space over (skip levels)
        while (j++ < level) cout << "       "; // Print data
        cout << P->data;
        if (P->left != 0 && P->right != 0) cout << " <"; //two child
        else if (P->right != 0) cout << " /"; //only right child
        else if (P->left != 0) cout << " \\"; //only left child
        cout << endl;
        PrintTree(P->left, level + 1);
    }
}

bool Tree::isdigit(int value) {
    if (value == 5)
        return true;
    else
        return false;
}

bool Tree::isEmpty() {
    if (root == 0)
        return true;
    else
        return false;
}

void Tree::inorder(Node *ptr) {
    if (ptr) {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

void Tree::postorder(Node *ptr) {
    if (ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";

    }
}

void Tree::preorder(Node *ptr) {
    if (ptr) {
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void Tree::buildTree(char input) {
    while (input != NULL) {
        Node *temp = new Node(input);

        for (int i = 0; i < 4; i++) {
            if (temp->data == prec[i][0]) {
                temp->prio = prec[i][1] - '0';
                break;
            }
            else
                temp->prio = 5;
        }

        if (temp->prio == 5) {
            Operand(temp);
            break;
        }
        else {
            Operator(temp);
            break;
        }
    }
}

void Tree::Operand(Node *ptr) {
    Node *p;
    if (isEmpty())
        root = ptr;
    else {
        p = root;
        while (p->right != NULL)
            p = p->right;
        p->right = ptr;
    }
}

void Tree::Operator(Node *ptr) {
    if (root->prio >= ptr->prio) {
        ptr->left = root;
        root = ptr;
    }
    else {
        ptr->left = root->right;
        root->right = ptr;
    }
}

Node* Tree::getRoot() {
    return root;
}

int Tree::evalTree(Node *ptr) {
    int value, left, right;
    if (!isEmpty()) {
        if (ptr->left == 0 && ptr->right == 0)
            value = ptr->data - '0';
        else {
            left = evalTree(ptr->left);
            right = evalTree(ptr->right);
            switch (ptr->data) {
                case '+':
                    value = left + right;
                    break;
                case '-':
                    value = left - right;
                    break;
                case '*':
                    value = left * right;
                    break;
                case '/':
                    value = left / right;
                    break;
            }
        }
    }
    else {
        cout << "Tree is Empty" << endl;
        return 0;
    }
    return value;
}

void Tree::parentheses(Node *ptr) {
    if (ptr != NULL) {
        if (!isdigit(ptr->prio))
            cout << "( ";
        parentheses(ptr->left);
        cout << ptr->data << " ";
        parentheses(ptr->right);
        if (!isdigit(ptr->prio))
            cout << ") ";
    }
}

int main() {
    Tree tree1;
    char input1[100];
    int i = 0;

    cout << "Infix Expression1 : ";
    cin >> input1;
    while (input1[i] != 0) {
        tree1.buildTree(input1[i]);
        i++;
    }

    cout << endl;
    cout << "  Inorder : ";
    tree1.inorder(tree1.getRoot());
    cout << endl;

    cout << endl;
    cout << "  Postorder : ";
    tree1.postorder(tree1.getRoot());
    cout << endl;

    cout << endl;
    cout << "  Preorder : ";
    tree1.preorder(tree1.getRoot());
    cout << endl;

    cout << endl;
    cout << "  Evaluation : ";
    cout << tree1.evalTree(tree1.getRoot()) << endl;
    tree1.PrintTree(tree1.getRoot(),i);

    cout << endl;;

    Tree tree2;
    char input2[100];
    i = 0;

    cout << "Infix Expression2 : ";
    cin >> input2;
    while (input2[i] != 0) {
        tree2.buildTree(input2[i]);
        i++;
    }

    cout << endl;
    cout << "  Inorder : ";
    tree2.inorder(tree2.getRoot());
    cout << endl;

    cout << endl;
    cout << "  Postorder : ";
    tree2.postorder(tree2.getRoot());
    cout << endl;

    cout << endl;
    cout << "  Preorder : ";
    tree2.preorder(tree2.getRoot());
    cout << endl;
    tree2.PrintTree(tree2.getRoot(),i);
    cout << endl;

}
