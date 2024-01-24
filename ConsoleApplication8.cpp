#include <iostream>
using namespace std;
class Matrix {
private:
    int** matrix;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t rows, size_t cols) : rows{rows}, cols{ cols } {
        matrix = new int* [rows];
        for (size_t i = 0; i < rows; i++) {
            matrix[i] = new int[cols]();
        }
    }
    ~Matrix() {
        for (size_t i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }
    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }
    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < other.cols; j++) {
                for (size_t k = 0; k < cols; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[i][j];
                }
            }
        }
        return result;
    }
    void print() const {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    void fillRandom() {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                matrix[i][j] = rand() % 10;
            }
        }
    }
};

int main() {
    srand(time(0));
    Matrix a(2, 3);
    Matrix b(3, 2);
    a.fillRandom();
    b.fillRandom();
    Matrix c = a + b;
    cout << "A + B:\n";
    c.print();
    Matrix d = a - b;
    cout << "A - B:\n";
    d.print();
    Matrix e = a * b;
    cout << "A * B:\n";
    e.print();
}