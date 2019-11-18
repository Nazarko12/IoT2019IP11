#include <iostream>
#include <cmath>
using namespace std;

class Matrix {
private:
    int mtx[5];
public:
    void InputElement(int a) {
        cin >> mtx[a];
    }
    void sMatrix(int a) {
        static int ptr = 0;
        mtx[ptr] = a;
        if (ptr == 4) ptr = -1;
        ptr++;
    }

    int *GetMatrix() {
        return mtx;
    }

        friend void OutputMatrix(Matrix *A, int n);


        void merge(int start, int mid, int end) {
            int t[5];
            int i = start, j = mid + 1, k = 0;

            while (i <= mid && j <= end) {
                if (this->mtx[i] <= this->mtx[j]) {
                    t[k] = this->mtx[i];
                    k++;
                    i++;
                } else {
                    t[k] = this->mtx[j];
                    k++;
                    j++;
                }
            }

            while (i <= mid) {
                t[k] = this->mtx[i];
                k++;
                i++;
            }

            while (j <= end) {
                t[k] = this->mtx[j];
                k++;
                j++;
            }
            for (i = start; i <= end;i++) {
                this->mtx[i] = t[i - start];
            }
        }

        void mergeSort(int start, int end) {

            if (start < end) {
                int mid = (start + end) / 2;
                mergeSort(start, mid);
                mergeSort(mid + 1, end);
                merge(start, mid, end);
            }

        }
};

void OutputMatrix(Matrix* mtx, int n){
    for(int i = 0; i<n; ++i)
    {
        cout << mtx -> mtx[i];
    }
    cout << endl;
}


int main() {
    Matrix matrix[5];
    for (int i = 0; i<5; i++)
        for (int j = 0; j<5;j++){
            matrix[j].InputElement(i);
        }
    Matrix matrix1;
    for (int i = 0; i<5; i++)
        matrix[i].mergeSort(0, 4);
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++) {
            cout << matrix[j].GetMatrix()[i] << "\t ";
            matrix1.sMatrix(matrix[j].GetMatrix()[i]);
        }
        cout << endl;
    }
    double geom = 0;
    int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
        for (int i = 1; i < 5; i++) {                                  // f1
            f1 += matrix[i].GetMatrix()[0];
        }
        for (int i = 2; i < 5; i++) {                                  // f1
            f2 += matrix[i].GetMatrix()[1];
        }
        for (int i = 3; i < 5; i++) {                                  // f1
            f3 += matrix[i].GetMatrix()[2];
        }
        for (int i = 4; i < 5; i++) {                                  // f1
            f4 += matrix[i].GetMatrix()[3];
        }
    cout<<"\n";
    geom = pow(f1*f2*f3*f4, 1.0/4.0);
    cout << "f1(): " << f1 << "\n" << "f2(): " << f2 << "\n" << "f3(): " << f3 << "\n" << "f4(): " << f4 << "\n\n";
    cout << "F(f()): " << geom << "\n";

    return 0;
}