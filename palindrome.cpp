//20195300 유욱현
//Description : Quiz 1-2(Palindrome Practice)
//input.txt 파일로 열어야 합니다.(\n 기준으로 데이터를 입력받았습니다)

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool check(string s){
    string s_reverse = s;   //make a string for reverse
    reverse(s_reverse.begin(), s_reverse.end()); //reverse string s
    return s == s_reverse ? true : false;   //if s is same as s_reverse, it is palindrome
                                            //if it's not, it's not a palindrome
}

int main() {
    ifstream infile;
    infile.open("input.txt", ios::in);
    if(infile.fail()){
        cout << "can't open the input file" << endl;
        exit(1);
    }
    string line;
    while (getline(infile,line)) { // 한줄 씩 실행
        if(check(line)==true){ // check = true
            cout << line << " ";
            cout << "Palindrome" << endl;
        }
        else{   // check = false
            cout << line << " ";
            cout << "Not a Palindrome" << endl;
        }
    }
    infile.close();

    return 0;
}
