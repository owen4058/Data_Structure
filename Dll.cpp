/*
 * Name: 유욱현
 * Student ID: 20195300
 * Description: Doubly linked list Practice
*/
#include <iostream>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node* prev;
    Node* next;
    Node(T data):data(data),next(nullptr),prev(nullptr){}
};

/*
 * Class: DLL // 템플릿을 적용한 이중연결리스트 자료구조
 * Variable:
    head : head 노드를 가리키는 포인터
    curr : 가장 최근 클래수 함수들을 적용한 노드를 가리키는 포인터
    tail : 맨 마지막 노드를 가리키는 포인터
    nodeCount : 총 노드의 갯수

 * 함수 설명 :
    bool isEmpty();//DLL이 비어있는지 확인 
    int getSize(); //총 노드의 갯수를 반환
    void insertAfter(T data); //curr 뒤에 삽입
    void insertBefore(T data); //curr 앞에 삽입
    void insertFirst(T data); //curr 앞에 삽입
    void insertLast(T data); // tail 뒤에 삽입
    void deleteCurrent(); // curr가 가리키는 노드 삭제
    void locateCurrent(int Nth); // curr의 위치(인덱스 출력)
    void updateCurrent(T data); // curr에 있는 데이터 업데이트
    void displayList(); // DLL 전체출력

*/
template <typename T>
class DLL{
    Node<T>* head;
    Node<T>* tail;
    Node<T>* curr;
    int nodeCount;
public:
    DLL();
    ~DLL();
    bool isEmpty();
    void insertAfter(T data);
    void insertBefore(T data);
    void insertFirst(T data);
    void insertLast(T data);
    void deleteCurrent();
    void locateCurrent(int Nth);
    void updateCurrent(T data);
    void displayList();
};
template<typename T>
DLL<T>::DLL():head(nullptr),tail(nullptr),curr(nullptr),nodeCount(0){};
template<typename T>
DLL<T>::~DLL(){
    if(!isEmpty()) {
        Node<T> *p;
        while(!isEmpty()){
            p = head;
            head = head->next;
            delete p;
        }
    }
}
template<typename T>
bool DLL<T>::isEmpty() {
    return(head==nullptr);
}
template<typename T>
void DLL<T>::insertAfter(T data) {
    Node<T>* temp = new Node<T>(data);
    if(isEmpty()){
        head = tail = temp;
    }else if(curr->next!=nullptr){ // curr가 마지막 노드가 아니라면
        temp->next = curr->next;
        curr->next = temp;
        temp->prev = curr;
    }else{ // curr가 마지막 노드라면
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    curr = temp;
    nodeCount++;
    displayList();
}
template<typename T>
void DLL<T>::insertBefore(T data) {
    Node<T>* temp = new Node<T>(data);
    if(isEmpty()){
        head = tail = temp;
    }else if(curr == head){ // curr가 맨 앞자리면
        temp->next = curr;
        curr->prev = temp;
        head = temp;
    }else{ // curr가 맨 앞자리가 아니라면
        curr->prev->next = temp;
        temp->prev = curr->prev;
        curr->prev = temp;
        temp->next = curr;

    }
    curr = temp;
    nodeCount++;
    displayList();
}
template<typename T>
void DLL<T>::insertFirst(T data) {
    Node<T>* temp = new Node<T>(data);
    if(isEmpty()){
        head = tail = temp;
    }else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    curr = temp;
    nodeCount++;
    displayList();
}
template<typename T>
void DLL<T>::insertLast(T data) {
    Node<T>* temp = new Node<T>(data);
    if(isEmpty()){
        head = tail = temp;
    }else{
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    curr = temp;
    nodeCount++;
    displayList();
}
template<typename T>
void DLL<T>::deleteCurrent(){
    if(isEmpty()){
        cout << "list is Empty" << endl;
        return;
    }else if(curr == head){
        head = curr->next;
        head->prev = nullptr;
    }else if(curr == tail){
        tail = curr->prev;
        tail->next = nullptr;
    }else{
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    delete curr;
    nodeCount--;
    curr = head;
    displayList();
} // 여기서 에러 curr를 누구로 설정 해야 할까
template<typename T>
void DLL<T>::locateCurrent(int Nth) {
    if(isEmpty()) {
        cout << "List is Empty" << endl;
        return;
    }else if(nodeCount<Nth||Nth<1){
        cout << "No such a line" << endl;
    }else{
        Node<T>* p = head;
        int i=1;
        while(i<Nth){
            p = p->next;
            i++;
        }
        cout << "Address("<<Nth<<"): "<<p->data <<endl;
        curr = p;
    }
    displayList();
}
template<typename T>
void DLL<T>:: updateCurrent(T data){
    if(isEmpty()){
        cout << "List is Empty" << endl;
        return;
    }
    curr->data = data;
    displayList();
}
template<typename T>
void DLL<T>:: displayList() {
    if(isEmpty()){
        cout << "List is Empty" << endl;
        return;
    }
    Node<T>* p = head;
    cout << "--- List ---" << endl;
    int idx = 1;
    while(p){
        if(curr != p)
            cout << "\t"<< idx<< " :   "<<p->data << endl;
        else
            cout << "\t"<< idx<< " *   "<<p->data << endl;
        p = p->next;
        idx ++;
    }
}



int main(){
    DLL<int>* A = new DLL<int>();
    int option;
    while(true){
        cout << "Command: (1)insertAfter\t(2)insertBefore\t(3)insertFirst\t(4)insertLast\t(5)deleteCurrent\n\t";
        cout << "(6)locateCurrent\t(7)updateCurrent\t(8)displayList\t(9)Quit\n ==>  ";
        cout << "";
        cin >> option;
        int data;
        switch(option){
            case 1:
                cout << "Enter a data to insert => "; cin >> data;
                A->insertAfter(data);
                continue;
            case 2:
                cout << "Enter a data to insert => "; cin >> data;
                A->insertBefore(data);
                continue;
            case 3:
                cout << "Enter a data to insert => "; cin >> data;
                A->insertFirst(data);
                continue;
            case 4:
                cout << "Enter a data to insert => "; cin >> data;
                A->insertLast(data);
                continue;
            case 5:
                A->deleteCurrent();
                continue;
            case 6:
                cout << "Enter a position to locate => "; cin >> data;
                A->locateCurrent(data);
                continue;
            case 7:
                cout << "Enter a data to update => "; cin >> data;
                A->updateCurrent(data);
                continue;
            case 8:
                A->displayList();
                continue;
            case 9:
                break;
        }
        break;
    }
    return 0;
}