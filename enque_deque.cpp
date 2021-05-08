//20195300 유욱현
//Description : RemoveMax and Invert Practice

#include <iostream>
#include <algorithm>
using namespace std;


const int Queuesize = 10;
const int Stacksize = 10;
int cnt1 = 0, cnt2 = 0; // cnt1 : number of Stack, cnt2 : number of Queue
int arr[Queuesize + Stacksize]; // Merge할 배열

class Queue {

public:
    int queue[Queuesize];
    int front = -1;
    int rear = -1;
    void ENQUE(int item);
    bool QFull();
    bool QEmpty();
    void display_Q();
};

class Stack {
public:
    int stack[Stacksize];
    int top = -1;

    void push(int item);
    bool StackFull();
    bool StackEmpty();
    void display_stack();
};

void Invert(){
    sort(arr,arr+cnt1+cnt2,greater<int>()); // 내림차순 정렬
    for(int i=0; i<cnt1+cnt2; i++){ // 정렬 후 출력
        cout << arr[i] << " ";
    }
    cout << endl;
}

void RemoveMax(Stack a){
    for(int i=0; i<cnt1 + cnt2-1; i++){ // Invert 후 최대값인 맨 앞 데이터 한개 지우기
        arr[i] = arr[i+1];
    }
    for(int i=0; i<cnt1+cnt2-1; i++){ // 출력
        cout << arr[i] << " ";
    }
    cout << endl;


}
void Merge(Queue q,Stack s){
    for(int i=0; i<cnt1;i++){ //Merge stack data
        arr[i] = s.stack[i];
    }
    for(int i=0; i<cnt2; i++){ // Merge queue data
        arr[i+cnt1] = q.queue[i];
    }
    sort(arr,arr+cnt1+cnt2); // sort data in descending
    for(int i=0; i<cnt1+cnt2; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Queue::ENQUE(int item) { // Enqueue in queue
    if (QFull()) {
        cout << "QueueFull,   " << endl;;
    }
    else {
        queue[++rear] = item;
        cnt1++;
    }
}
bool Queue::QFull() { // Check Q full
    if (rear == Queuesize - 1) {
        return true;
    }
    else {
        return false;
    }
}

bool Queue::QEmpty() { // Check Q empty
    if (rear == front) {
        return true;
    }
    else {
        return false;
    }
}

void Queue::display_Q() { // display queue
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
    int m[Stacksize + Queuesize];
    while(1){
        cout << "1.Push,  2.Enque,  3,Merge,  4,Invert,  5.RemoveMax, 6.quit ";
        cin >> c;
        switch(c){
            case 1:
                cin >> data;
                s.push(data);
                s.display_stack();
                break;
            case 2:
                cin >> data;
                q.ENQUE(data);
                q.display_Q();
                break;
            case 3:
                Merge(q,s);
                break;
            case 4:
                Invert();
                break;
            case 5:
                RemoveMax(s);
                break;
            case 6:
                return 0;

        }
    }

}

