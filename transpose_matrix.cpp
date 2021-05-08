//20195300 유욱현
//Transpose Matrics
#include <iostream>
#include <fstream>
using namespace std;

typedef struct{
    int row;
    int col
    int value;
}element;

typedef struct SparseMatrix{
    element data[Max_terms];
    int rows;
    int cols;
    int terms;
}SparseMatrix;

SparseMatrix matrix_transpose(SparseMatrix a){
    SparseMatrix b;
    int idx_b;
    b.rows = a.rows;
    b.cols = a.cols;
    b.terms = a.terms;

    if( a.terms > 0){
        idx_b = 0;
        for(int c = 0; c < a.cols ; c++){
            for(int i = 0; i < a.terms ; i++){
                if (a.data[i].col == c){
                    b.data[idx_b].row = a.data[i].col;
                    b.data[idx_b].col = a.data[i].row;
                    b.data[idx_b].value = a.data[i].value;
                    idx_b++;
                }
            }
        }
    }
    return b;
}

int main() {
    ifstream infile;
    infile.open("lab4.txt", ios::in);
    if(infile.fail()){
        cout << "can't open the input file" << endl;
        exit(1);
    }

    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            infile >> a[i][j];
        }
    }

    cout << "Original Matrix : A" << endl << endl;

    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix B -row major" << endl << endl;


SparseMatrix b = matrix_transpose(a);

    return 0;
}
