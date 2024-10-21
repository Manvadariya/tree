using namespace std;

// Function to multiply two polynomials
vector<int> multiplyPolynomials(const vector<int>& poly1, const vector<int>& poly2) {
    int n = poly1.size();
    int m = poly2.size();
    vector<int> result(n + m - 1, 0);

    // Multiplication of polynomials
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> poly1(n + 1);
    vector<int> poly2(n + 1);

    // Input coefficients of first polynomial
    for (int i = 0; i <= n; i++) {
        cin >> poly1[i];
    }

    // Input coefficients of second polynomial
    for (int i = 0; i <= n; i++) {
        cin >> poly2[i];
    }

    // Multiply the polynomials
    vector<int> result = multiplyPolynomials(poly1, poly2);

    // Output the result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}