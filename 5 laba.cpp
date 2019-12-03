#include <iostream>
#include <cmath>
#define size 5
using namespace std;


class Matrix {
private:
    int matrix[size];
public:
    friend void outputMatrix(Matrix*, int);

    void inputElement(int arrayElementNum) {
        cin >> matrix[arrayElementNum];
    }
    void showMatrix(int arrayElement) {
        static int elementIndicator = 0;
        matrix[elementIndicator] = arrayElement;
        if (elementIndicator == 4) elementIndicator = -1;
        elementIndicator++;
    }

    int *getMatrix() {
        return matrix;
    }

    void merge(int start, int middle, int end) {
        int temporaryArray[5];
        int i = start, j = middle + 1, k = 0;

        while (i <= middle && j <= end) {
            if (this->matrix[i] <= this->matrix[j]) {
                temporaryArray[k] = this->matrix[i];
                k++;
                i++;
            } else {
                temporaryArray[k] = this->matrix[j];
                k++;
                j++;
            }
        }

        while (i <= middle) {
            temporaryArray[k] = this->matrix[i];
            k++;
            i++;
        }

        while (j <= end) {
            temporaryArray[k] = this->matrix[j];
            k++;
            j++;
        }
        for (i = start; i <= end;i++) {
            this->matrix[i] = temporaryArray[i - start];
        }
    }

    void mergeSortByGrowth(int start, int end) {
        if (start < end) {
            int middle = (start + end) / 2;
            mergeSortByGrowth(start, middle);
            mergeSortByGrowth(middle + 1, end);
            merge(start, middle, end);
        }
    }
};

void outputMatrix(Matrix* matrixExample, int numElements){
    for(int i = 0; i < numElements; ++i)
    {
        cout << matrixExample -> matrix[i];
    }
    cout << endl;
}


int main() {
    Matrix matrixExample[5];

    for (int i = 0; i<5; i++)
        for (int j = 0; j<5;j++){
            matrixExample[j].inputElement(i);
        }
    Matrix matrixTemporary;
    for (int i = 0; i<5; i++) {
        matrixExample[i].mergeSort(0, 4);
    }

    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++) {
            cout << matrixExample[j].getMatrix()[i] << "\t ";
            matrixTemporary.showMatrix(matrixExample[j].getMatrix()[i]);
        }
        cout << endl;
    }

    double geometricAverage = 0;
    int sumDiagonal1 = 0, sumDiagonal2 = 0, sumDiagonal3 = 0, sumDiagonal4 = 0;
        for (int i = 1; i < 5; i++) {
            sumDiagonal1 += matrixExample[i].getMatrix()[0];
        }
        for (int i = 2; i < 5; i++) {
            sumDiagonal2 += matrixExample[i].getMatrix()[1];
        }
        for (int i = 3; i < 5; i++) {
            sumDiagonal3 += matrixExample[i].getMatrix()[2];
        }
        for (int i = 4; i < 5; i++) {
            sumDiagonal4 += matrixExample[i].getMatrix()[3];
        }
    cout << "\n";
    geometricAverage = pow(sumDiagonal1*sumDiagonal2*sumDiagonal3*sumDiagonal4, 1.0/4.0);
    cout << "f1(): " << sumDiagonal1 << "\n" << "f2(): " << sumDiagonal2 << "\n" << "f3(): " << sumDiagonal3 << "\n" << "f4(): " << sumDiagonal4 << "\n\n";
    cout << "F(f()): " << geometricAverage << "\n";

    return 0;
}
