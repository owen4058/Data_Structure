//20195300 유욱현

#include <iostream>
#include <iomanip>

using namespace std;
class Node{
    int data;
    Node* next;
    Node(int data):data(data){}
    friend class SLL;
};

class SLL{
private:
    Node* head;
    Node* tail;
    int nodeCount;
public:
    SLL();
    bool isEmpty(); // SLL이 비었는지 확인해본다.
    void insertNode(int data); // 오름차순
    void deleteNode(int data); // 해당 데이터를 가지는 노드 제거
    void searchList(int data);
    void findmax(int data);
    void displayList();

    ~SLL();
};

SLL::SLL():nodeCount(0) {
    head = tail = nullptr;
}
SLL::~SLL(){
    if(!isEmpty()){
        Node* curr;
        while(head != nullptr){
            curr = head;
            head = head->next;
            delete curr;
        }
    }
}
bool SLL::isEmpty(){
    if(head==nullptr){return 1;}
    return 0;
}
void SLL::insertNode(int data){ // 오름차순
    Node *tmp = new Node(data);
    Node *prev,*curr;
    if(isEmpty()) head = tail = tmp;
    else if(data < head->data){ // 맨 앞에 넣는 경우
        tmp->next = head;
        head = tmp;
    }else{
        curr = head;
        while((curr)&&(curr->data < data)){ //멈춘지점이
            prev = curr;
            curr = curr->next;
        }
        if(curr){// 중간에
            tmp->next = curr;
            prev->next = tmp;
        }else{// 맨끝에
            prev->next = tmp;
            tail = tmp;
        }
    }
    nodeCount++;
}
void SLL::deleteNode(int data) {
    Node *prev, *curr;
    if(isEmpty()) {
        cout << "not found(list is Empty)" << endl;
        return;
    }
    if(head->data == data){
        curr = head;
        head = head->next;
        delete curr;
        nodeCount --;
    }else{
        curr = head;
        while((curr)&&(curr->data != data)){
            prev = curr;
            curr = curr->next;
        }
        if(curr){ // 멈췄는데 중간에 멈춘경우
            cout << "delete data " << endl;
            prev->next = curr->next;
            if(curr==tail) tail = prev;
            delete curr;
            nodeCount--;
        }else{ // 멈췄는데 끝까지 간 경우
            cout << "not found(not in list)" << endl;
        }
    }
}
void SLL::searchList(int data){
    if(!isEmpty()) {
        Node *curr = head;
        while (curr) {
            if (curr->data == data) {
                cout << data << " is in the list"<< endl;
                return;
            }
            curr = curr->next;
        }
        cout << data << " is not in the list." << endl;
    }
    cout << "List Empty" << endl;
}

void SLL::displayList() {
    Node *next;
    if (head == 0) cout << "List is empty!\n";
    else {
        next = head;
        cout << "--- List ---\n";
        for (int i = 1; next != 0; i++) {
            cout << setw(5) << i << " : " << next->data << endl;
            next = next->next;
        }
    }
}
/*void SLL::findmax(int data){
    int max;
    Node *p;
    p = head;
    while(p->next != NULL){
        p->next;
        if(max<p->data){
            max= next->data;
            p ->next;
        }

    }
    cout << max << "is Max Data\n";
}*/



int main(){
    SLL A;
    int a = 0;
    int num = 0;
    while (1) {
        cout << "(1. insert 2. delete 3. search 4. displayList 5. FindMax 6. Quit)" << endl;
        cin >> a;
        switch (a) {
            case 1:
                cin >> num;
                A.insertNode(num);
                break;
            case 2:
                A.deleteNode(num);
                break;
            case 3:
                A.searchList(num);
                break;
            case 4:
                A.displayList();
                break;
            case 5:
               // A.findMax(num);
                break;
            case 6:
                return 0;


        }
    }

    return 0;
}