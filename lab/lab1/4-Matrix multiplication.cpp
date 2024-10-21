int main() {
    int m, n, x, y;
    cin >> m >> n >> x >> y;

    // Allocate memory for matrix1
    int **matrix1 = new int*[m];
    for (int i = 0; i < m; ++i) {
        matrix1[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> matrix1[i][j];
        }
    }

    // Allocate memory for matrix2
    int **matrix2 = new int*[x];
    for (int i = 0; i < x; ++i) {
        matrix2[i] = new int[y];
        for (int j = 0; j < y; ++j) {
            cin >> matrix2[i][j];
        }
    }

    // Check if matrix multiplication is possible
    if (n != x) {
        cout << "-1";
        return 0;
    }

    int p = m, q = y;

    // Allocate memory for the result matrix
    int **result = new int*[p];
    for (int i = 0; i < p; ++i) {
        result[i] = new int[q];
        for (int j = 0; j < q; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << p << " " << q << endl;

    // Print the result matrix
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < q; ++j) {
            cout << result[i][j];
            if (j < q - 1) {
                cout << "\t";
            }
        }
        cout << endl;
    }

    // Deallocate memory for matrix1
    for (int i = 0; i < m; ++i) {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    // Deallocate memory for matrix2
    for (int i = 0; i < x; ++i) {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    // Deallocate memory for the result matrix
    for (int i = 0; i < p; ++i) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}
