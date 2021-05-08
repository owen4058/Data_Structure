//20195300 유욱현
//Sparse Matrix
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;
class SparseMatrix;
class Matrix;
class MatrixTerm{
    friend class SparseMatrix;
    friend class Matrix;
private:
    int row, col, value;
};

class Matrix{
    friend class SparseMatrix;
private:
    int rows, cols;
    MatrixTerm* arr;
public:
    Matrix(int rows, int cols):rows(rows),cols(cols){
        arr = new MatrixTerm[rows*cols];
    }
    Matrix(string filename){
        ifstream file;
        file.open(filename);
        string s;

        if(file.is_open()) {
            getline(file, s);
            stringstream ss(s);
            ss >> rows >> cols;
            arr = new MatrixTerm[rows*cols];
            int row = 0;
            while (getline(file, s)) {
                stringstream ss(s);
                for (int col = 0; col < cols; col++) {
                    int idx = row * cols + col;
                    arr[idx].row = row;
                    arr[idx].col = col;
                    ss >> arr[idx].value;
                }
                row ++;
            }
            file.close();
        }

    }
    ~Matrix(){
        if(arr){
            delete[] arr;
        }
    }
    Matrix* tranpose(){
        Matrix* src = this;
        Matrix* dst = new Matrix(src->cols, src->rows);
        for(int row = 0; row < src->rows; row++){
            for(int col = 0; col < src->cols; col++){
                int src_idx = row*cols+col;
                int dst_idx = col*rows+row;
                dst->arr[dst_idx].row = src->arr[src_idx].row;
                dst->arr[dst_idx].col = src->arr[src_idx].col;
                dst->arr[dst_idx].value = src->arr[src_idx].value;
            }
        }
        return dst;
    }
    void printMatrix(){
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                cout << arr[row*cols+col].value << "\t";
            }
            cout << endl;
        }
    }
};

class SparseMatrix {
private:
    int rows, cols, terms;
    MatrixTerm *smArray;
public:
    SparseMatrix(int rows, int cols, int terms):rows(rows),cols(cols),terms(terms){
        smArray = new MatrixTerm[terms];
    }
    SparseMatrix(Matrix* src):rows(src->rows),cols(src->cols),terms(0){
        smArray = new MatrixTerm[rows*cols];
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                int idx = row*cols+col;
                int term = src->arr[idx].value;
                if(term!=0){
                    smArray[terms].row = row;
                    smArray[terms].col = col;
                    smArray[terms].value = term;
                    terms ++;
                }
            }
        }
        MatrixTerm* tmp = new MatrixTerm[terms];
        memcpy(tmp, smArray, sizeof(MatrixTerm)*terms);
        delete[] smArray;
        smArray = tmp;
    }
    ~SparseMatrix(){
        if(!smArray){
            delete[] smArray;
        }
    }
    SparseMatrix* transpose(){
        SparseMatrix* dst = new SparseMatrix(cols, rows, terms);
        int term = 0;
        if(terms>0){
            for(int i=0; i<cols; i++){
                for(int j=0; j<terms; j++){
                    if(smArray[j].col == i){
                        dst->smArray[term].row = smArray[j].col;
                        dst->smArray[term].col = smArray[j].row;
                        dst->smArray[term].value = smArray[j].value;
                        term ++;
                    }
                }
            }
        }
        return dst;
    }
    SparseMatrix* fastTranspose()
    {
        SparseMatrix* dst = new SparseMatrix(cols, rows, terms);
        if (terms > 0)
        {
            int *rowSize = new int[cols];
            int *rowStart = new int[cols];

            fill(rowSize, rowSize + cols, 0);
            for (int i = 0; i < terms; i++)
                rowSize[smArray[i].col]++;
            rowStart[0] = 0;
            for (int i = 1; i < cols; i++){
                rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
            }
            for (int i = 0; i < terms; i++){
                int j = rowStart[smArray[i].col];
                dst->smArray[j].row = smArray[i].col;
                dst->smArray[j].col = smArray[i].row;
                dst->smArray[j].value = smArray[i].value;
                rowStart[smArray[i].col]++;
            }
            delete[]rowSize;
            delete[]rowStart;
        }
        return dst;
    }
    void printMatrix(){
        cout << rows << "\t" << cols << "\t" << terms << endl;
        cout << "===================" << endl;
        for(int term=0; term<terms; term++){
            cout<<smArray[term].row<<"\t"<<smArray[term].col<<"\t"<<smArray[term].value<<endl;
        }
    }

};

int main(){

    cout << "1) print Original Matrix A\n" << endl;
    Matrix* A = new Matrix("/Users/owen/Desktop/자료구조/lab4-1/lab4.txt");
    A->printMatrix();

    cout << "2) print Transpose Matrix A\n" << endl;
    Matrix* B = A->tranpose();
    B->printMatrix();
    cout << endl;
    cout << "3) Sparse matrix of A - row major\n" << endl;
    SparseMatrix* C = new SparseMatrix(A);
    C->printMatrix();
    cout<<endl;
    cout << "4) Transpose of Sparse matrix A - column major\n" << endl;
    SparseMatrix* D = C->transpose();
    D->printMatrix();
    cout << endl;
    cout << "5) Fast transpose of Sparse matrix A\n" << endl;
    SparseMatrix* E = C->fastTranspose();
    E->printMatrix();

    delete A;
    delete B;
    delete C;
    delete D;
    delete E;
    return 0;
}
