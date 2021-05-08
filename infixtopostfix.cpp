//20195300 유욱현
//Infix-to-Postfix conversion & Evaluation
#include <iostream>
#include <fstream>
#define MAX_SIZE 100
using namespace std;

class ArrStack {
public:
    int top;
    char *stack;
    int MAX;

    ArrStack(int size) {
        top = -1;
        stack = new char(size);
        MAX = size;
    }

    bool isFull();
    bool isEmpty();
    void push(char data);
    char pop();
};
bool ArrStack::isFull() {
    if (top + 1 == MAX) return true;
    else return false;
}
bool ArrStack::isEmpty() {
    if (top == -1) return true;
    else return false;
}
void ArrStack::push(char data) {
    if (isFull()) cout << "Stack is Full" << endl;
    else {
        top++;
        stack[top] = data;
    }
}
char ArrStack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else return stack[top--];
}

class IntStack {
public:
    int top;
    int* stack;
    int MAX;

    IntStack(int size) {
        top = -1;
        stack = new int[size];
        MAX = size;
    }

    bool isFull();
    bool isEmpty();
    void push(int data);
    int pop();
};
bool IntStack::isFull() {
    if (top + 1 == MAX) return true;
    else return false;
}
bool IntStack::isEmpty() {
    if (top == -1) return true;
    else return false;
}
void IntStack::push(int data) {
    if (isFull()) cout << "Stack is Full" << endl;
    else {
        top++;
        stack[top] = data;
    }
}
int IntStack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    else return stack[top--];
}

int priority(char oper);
void infix2postfix(char *buff);
int evaluate4postfix(char *buff);

char bufEval[MAX_SIZE];
int main() {
    char buff[MAX_SIZE];

    ifstream infile("lab5.txt");

    while (infile.getline(buff, MAX_SIZE)) {
        cout << "1) Enter data (infix form)\t: " << buff << endl;
        cout << "2) Conversion (postfix form)\t: ";
        infix2postfix(buff);
        cout << endl;
        cout << "3) Result\t\t\t: " << evaluate4postfix(bufEval) << endl;
    }
}

int priority(char oper) {
    if (oper == ')') return 4;
    else if (oper == '*' || oper == '/') return 3;
    else if (oper == '+' || oper == '-') return 2;
    else if (oper == '(') return 1;
    else if (oper == ' ') return -1;
    else return 0;

}

void infix2postfix(char *buff) {
    ArrStack tmp(MAX_SIZE);

    int i = 0, j = 0;
    while (buff[i] != '\0') {
        switch (priority(buff[i])) {
            case 0:
                bufEval[j++] = buff[i];
                cout << buff[i] << " ";
                break;
            case 4:
                while (tmp.stack[tmp.top] != '(') {
                    bufEval[j] = tmp.pop();
                    cout << bufEval[j++] << " ";
                }
                break;
            case 3:
            case 2:
                if (priority(buff[i]) >= priority(tmp.stack[tmp.top])) tmp.push(buff[i]);
                else{
                    bufEval[j] = tmp.pop();
                    cout << bufEval[j++] << " ";
                    tmp.push(buff[i]);
                }
                break;
            case 1:
                tmp.push(buff[i]);
                break;

            default:
                break;
        }
        i++;
    }

    while (tmp.top != -1) {
        if (tmp.stack[tmp.top] == '(') {
            tmp.pop();
            continue;
        }
        else {
            bufEval[j] = tmp.pop();
            cout << bufEval[j++] << " ";
        }
    }
    bufEval[j] = '\0';
}

int evaluate4postfix(char *buff) {
    IntStack tmp(MAX_SIZE);

    int i = 0;
    int op1,op2;
    while (buff[i] != '\0') {
        switch (priority(buff[i])) {
            case 0:
                tmp.push(buff[i] - '0');
                break;
            case 3:
            case 2:
                op2 = tmp.pop();
                op1 = tmp.pop();

                switch (buff[i]) {
                    case '+':
                        tmp.push(op1 + op2);
                        break;
                    case '-':
                        tmp.push(op1 - op2);
                        break;
                    case '*':
                        tmp.push(op1 * op2);
                        break;
                    case '/':
                        tmp.push(op1 / op2);
                        break;
                }
                break;
            default:
                break;
        }
        i++;
    }
    return tmp.pop();
}
