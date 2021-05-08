/*******************************************************/
//File Name : hw2.cpp
//Submittee : 20195300 유욱현
//Descriptions : Parenthesis Practice Code
/*******************************************************/
#include <iostream>
#include <fstream>
#define MAX_SIZE 999

using namespace std;

class Stack // class로 스택 관리
{
private:
    int top;
    int size;
    char* stack;
public:
    Stack(int value); // 생성자
    bool isFull();  //가득 찬다면
    bool isEmpty(); //비어 있다면
    void push(char value); // push 함수
    char pop(); // pop 함수
};

Stack::Stack(int value)     //스택 생성
{
    top = -1;
    size = value;
    stack = new char[size];
}

bool Stack::isFull()
{
    if (top == size - 1)    //꽉 차 있다
        return true;        //참
    else                    //아니라면
        return false;       //거짓
}

bool Stack::isEmpty()       //비어있다면
{
    if (top == -1)          //참
        return true;
    else                    //아니라면
        return false;       //거짓
}

void Stack::push(char value)// push 함수
{
    if (isFull())   // 꽉 차있다면
        return;     // 함수 종료
    else            //아니라면
        stack[++top] = value;   // 맨 위에 추가
}

char Stack::pop()   // pop 함수
{
    if (isEmpty())  //비어있다면
        return -1;  //종료
    else            //아니라면
        return stack[top--];    // 스택 top -1;

}

int checkParenthesis(char* buffer); //괄호 계산 함수
bool match(char a, char b); //비교 함수

int main()
{
    ifstream infile;
    infile.open("hw2.txt", ios::in);
    char buffer[80];
    int balanced=0;
    int unbalanced=0;
    int mismatched = 0;

    while (infile.getline(buffer, 80)) // check line by line
    {
        cout << buffer << endl;
        int validity = checkParenthesis(buffer);    //Validity Check
        switch(validity){   //3개의 case로 나눔
            case 1:     // 유효할 때
                cout << "The Expression is Valid" << endl;
                balanced++;
                break;
            case 2:
                unbalanced++; //유효하지 않을 떄
                break;
            case 3:         //갯수는 맞지만 종류가 다를 때
                mismatched++;
        }
        cout << endl;
    }
    cout << "Total:"<< "\tBalanced: "<< balanced << "\tUnbalanced: " << unbalanced << "\tMismatched: " << mismatched << endl;
}

int checkParenthesis(char* buffer)
{
    Stack stack(MAX_SIZE);
    int i = 0;

    while(buffer[i]!='\0') // check line by line
    {
        if (buffer[i] == '(' || buffer[i] == '{' || buffer[i] == '[') // 왼쪽 괄호가 있다면
            stack.push(buffer[i]);
        if (buffer[i] == ')' || buffer[i] == '}' || buffer[i] == ']') // 오른쪽 괄호가 있다면
        {
            if (stack.isEmpty())    // 왼쪽괄호만 있고 오른쪽 괄호는 없을
            {
                cout << "The Expression has unbalanced parentheses" << endl;
                return 2;
            }
            else
            {
                char temp = stack.pop();
                if (!match(temp, buffer[i]))    //왼쪽괄호와 오른쪽 괄호가 다를 때
                {
                    cout << "The Mismatched Parenthesis in the Expression are " << temp << " and " <<  buffer[i] << endl;
                    return 3;
                }
            }
        }
        i++;
    }
    if (stack.isEmpty()) //match success
        return 1;
    else    //아니면
    {
        cout << "The Expression has unbalanced parentheses" << endl;
        return 2;
    }

}

bool match(char a, char b)  //비교 함수
{
    switch (a)      //왼쪽괄호가 a 오른쪽 괄호가 b로 치환후 비
    {
        case '(':
            if (b == ')')
                return true;
            else
                return false;
        case '{':
            if (b == '}')
                return true;
            else
                return false;
        case '[':
            if (b == ']')
                return true;
            else
                return false;
    }
}
