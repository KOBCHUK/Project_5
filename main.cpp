#include <iostream>
using namespace std;

void calculate(int** array, int rows, int cols, unsigned long long & sum, unsigned long long& product) {
    sum = 0;
    product = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += array[i][j];
            product *= array[i][j];
        }
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 100;
            if (array[i][j] == 0) {
                /// restart random
                array[i][j] = rand() % 100;
            }
        }

        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    unsigned long long sum, product;
    calculate(array, rows, cols, sum, product);
    cout << "Сума: " << sum << ", Добуток: " << product << endl;

    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}