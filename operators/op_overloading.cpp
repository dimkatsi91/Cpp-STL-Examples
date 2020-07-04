#include <iostream>
#include <vector>

using namespace std;


class Matrix {
public:
    static Matrix newMatrix(int *arr, int sz) {
        return {arr, sz};
    }
    Matrix operator-(Matrix &rhs) {
        int counter{0};
        while(counter != vec.size()) {
            this->vec.at(counter) -= rhs.vec.at(counter);
            counter++;
        }
        return *this;
    }
    void print() {
        for(int i=0; i<vec.size(); i++) {
            cout << vec.at(i) << " ";
        }
        cout << endl;
    }
private:
    vector<int> vec{};
    Matrix(int *mat, int size)
    {
        int i{0};
        while(i != size) {
            vec.push_back(mat[i]);
            i++;
        }
    }
};


int main() 
{
    const int N = 5;
    int A[N] = {1,2,3,4,5};
    int B[N] = {11,22,33,44,55};

    Matrix m1 = Matrix::newMatrix(A, N);
    Matrix m2 = Matrix::newMatrix(B, N);
    cout << "m1 matrix : ";
    m1.print();
    cout << "m2 matrix : ";
    m2.print();

    cout << "m2 - m1 = ";
    Matrix m4 = m2 - m1;
    m4.print();

    return 0;
}