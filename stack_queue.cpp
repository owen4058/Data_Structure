//20195300 유욱현
//Description : Making List with Stack and ques

#include <iostream>
#include <algorithm>
using namespace std;


const int Queuesize = 10;
const int Stacksize = 10;
int cnt1 = 0, cnt2 = 0;
class Queue {

public:
    int queue[Queuesize];
    int front = -1;
    int rear = -1;
    void ENQUE(int item);
    void DEQUE();
    bool QFull();
    bool QEmpty();
    void display_Q();
    void deleteLargestElement();
};

class Stack {
public:
    int stack[Stacksize];

    int top = -1;

    void push(int item);
    void pop();
    bool StackFull();
    bool StackEmpty();
    void display_stack();
    void Remove_Max();
    void Invert(Stack s);
};
void Invert(Stack s){
    sort(0,Stacksize);
    for(int i=0; i<Stacksize; i++) {
        s.stack[i] = s.stack[i + 1];
    }
    for(int i=0; i<Stacksize-1; i++){
        cout << s.stack[i];
    }
}

void RemoveMax(Stack a){
    sort(0, Stacksize);
    for(int i=0; i<Stacksize; i++){
        a.stack[i] = a.stack[i+1];
    }


}
void MakeList(Queue q,Stack s){
    int arr[Queuesize + Stacksize];
    for(int i=0; i<cnt1;i++){
        arr[i] = s.stack[i];
    }
    for(int i=0; i<cnt2; i++){
        arr[i+cnt1] = q.queue[i];
    }
    sort(arr,arr+cnt1+cnt2);
    for(int i=0; i<cnt1+cnt2; i++){
        cout << arr[i] << " ";
    }
}

void Queue::ENQUE(int item) {
    if (QFull()) {
        cout << "QueueFull,   " << endl;;
    }
    else {
        queue[++rear] = item;
        cnt1++;
    }
}

void Queue::DEQUE() {
    if (QEmpty()) {
        cout << "QueueEmpty" << endl;
    }
    else {
        cout << queue[++front] << " ";
    }
}

bool Queue::QFull() {
    if (rear == Queuesize - 1) {
        return true;
    }
    else {
        return false;
    }
}

bool Queue::QEmpty() {
    if (rear == front) {
        return true;
    }
    else {
        return false;
    }
}

void Queue::display_Q() {
    int i;
    if (QEmpty()) {
        cout << "QueueEmpty" << endl;
    }
    else {
        i = front + 1;
        cout << "Queue: ";
        while (i <= rear) {
            cout << queue[i] << " ";
            i = i + 1;
        }
        cout << endl;
    }
}



void Stack::push(int item) {
    if (StackFull()) {
        cout << "StackFull,   ";
    }
    else {
        stack[++top] = item;
        cnt2++;
    }
}

void Stack::pop() {
    if (StackEmpty()) {
        cout << "StackEmpty   ";
    }
    else {
        cout << stack[top--] << " ";
    }
}

bool Stack::StackFull() {
    if (top == Stacksize - 1) {
        return true;
    }
    else {
        return false;
    }
}

bool Stack::StackEmpty() {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

void Stack::display_stack() {
    int i;
    if (StackEmpty()) {
        cout << "StackEmpty" << endl;
    }
    else {
        i = top;
        cout << "Stack: ";
        while (i >= 0) {
            cout << stack[i] << " ";
            i--;
        }
        cout << endl;
    }
}

int main() {
    Queue q;
    Stack s;
    int c, data;
    while(1){
        cout << "1.Push,  2.pop,  3,Merge,  4,Invert,  5.RemoveMax, 6.quit ";
        cin >> c;
        switch(c){
            case 1:
                cin >> data;
                s.push(data);
                s.display_stack();
                break;
            case 2:
                s.pop();
                s.display_stack();
                break;
            case 3:
                q.ENQUE(data);
                q.display_Q();
                break;
            case 4:
                s.Merge();
                q.display_Q();
                break;
            case 5:
                MakeList(q,s);
                break;
            case 6:
                return 0;

        }
    }

}

