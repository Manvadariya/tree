#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct Term {
    int coeff;
    int powx;
    int powy;
};

class Polynomial {
    list<Term> terms;
public:
    void insert(int coeff, int powx, int powy) {
        if (coeff == 0) return;
        auto it = find_if(terms.begin(), terms.end(), [powx, powy](const Term& term) {
            return term.powx == powx && term.powy == powy;
        });
        if (it != terms.end()) {
            it->coeff += coeff;
        } else {
            terms.push_back({coeff, powx, powy});
        }
    }
    void add(const Polynomial& poly2) {
        for (const auto& term : poly2.terms) {
            insert(term.coeff, term.powx, term.powy);
        }
    }
    void print() {
        terms.sort([](const Term& a, const Term& b) {
            if (a.powx != b.powx)
                return a.powx > b.powx;
            return a.powy > b.powy;
        });
        cout << terms.size() << endl;
        for (const auto& term : terms) {
            cout << term.coeff << " " << term.powx << " " << term.powy << endl;
        }
    }
};;

int main() {
    int m, n;
    cin >> m >> n;
    if (m > MAXSIZE || n > MAXSIZE) {
        cout << "Number of terms exceed the MAXSIZE limit" << endl;
        return 0;
    }
    int coeff, powx, powy;
    Polynomial poly1, poly2;
    for (int i = 0; i < m; i++) {
        cin >> coeff >> powx >> powy;
        poly1.insert(coeff, powx, powy);
    }
    for (int i = 0; i < n; i++) {
        cin >> coeff >> powx >> powy;
        poly2.insert(coeff, powx, powy);
    }
    poly1.add(poly2);
    poly1.print();
    return 0;
}
