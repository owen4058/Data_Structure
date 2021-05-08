// Binary Search
// 20195300 유욱현
#include <iostream>
#include <fstream>

using namespace std;

int iterativeBinarySearch(int* list, int count, int num, int left, int right);
int recursiveBinarySearch(int* list, int count, int num, int left, int right);
int compare(int x, int y);
int list[10];
const int SIZE = sizeof(list)/sizeof(list[0]);

int main()
{
    ifstream infile;
    int i=0;
    int searchNum;
    int methodNum;
    int searchPos=0;
    
    infile.open("lab3-1.txt",ios::in);
    
    if(infile.fail()){
        cout << "can't open the input file" << endl;
        exit(1);
    }
    else{
        cout << "Before sort : ";
    for(int i=0; i<SIZE; i++){
        infile >> list[i];
    }
        
    for(int i=0; i<SIZE; i++){
    cout << list[i] << " ";
        }
    }
    cout << endl;

    cout << "Enter an integer to search : ";
    cin >> searchNum;
    cout << "Enter method of search(1.Binary Search    2.Recursive Binary Search    3.Sequential Search) : ";
    cin >> methodNum;

    switch (methodNum)
    {
    case 1:
        searchPos = iterativeBinarySearch(list, sizeof(list) / sizeof(int), searchNum, 0, 9);
    case 2:
        searchPos = recursiveBinarySearch(list, sizeof(list) / sizeof(int), searchNum, 0, 9);
    }

    if (searchPos == -1)
        cout << searchNum << " is NOT FOUND" << endl;
    else
        cout << searchNum << " is at position " << searchPos + 1 << endl;
}

int iterativeBinarySearch(int* list, int count, int num, int left, int right)
{
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (num < list[middle])
            right = middle - 1;
        else if (num == list[middle])
            return middle;
        else
            left = middle + 1;
    }
    return -1;
}

int recursiveBinarySearch(int* list, int count, int num, int left,int right)
{
    while (left <= right)
    {
        int middle = (left + right) / 2;
        switch (compare(list[middle], num))
        {
        case -1:
            left = middle + 1;
            break;
        case 0:
            return middle;
        case 1:
            right = middle - 1;
            break;
        }
    }
    return -1;
}

int compare(int x, int y)
{
    if (x > y) return 1;
    else if (x < y) return -1;
    else return 0;
}
