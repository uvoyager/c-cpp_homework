#include <iostream>
#include <list>
#include <cmath>

using namespace std;

template <typename T>
class Polynomial {
    list<T> coeff;
public:
    Polynomial() {}
    Polynomial(const list<T>& c) : coeff(c) {}

    void print() {
        for (const T& x : coeff) {
            cout << x << endl;
        }
    }

    void input() {
        int n;
        cout << "Enter number of coefficients: ";
        cin >> n;
        if (n <= 0) return;

        cout << "Input coefficients: ";
        for (int i = 0; i < n; ++i) {
            T val;
            cin >> val;
            coeff.push_back(val);
        }
    }

    T value( const T& x ) {
        T res = 0;
        T x_pow = 1;
        list<T> temp = coeff;

        while (!temp.empty()) {
            T c = temp.front();
            temp.pop_front();
            res += c * x_pow;
            x_pow *= x;
        }
        return res;
    }
    Polynomial<T> add(const Polynomial<T>& other) const {
        list<T> a = coeff;
        list<T> b = other.coeff;
        list<T> res;

        while (!a.empty() && !b.empty()) {
            res.push_back(a.front() + b.front());
            a.pop_front();
            b.pop_front();
        }

        while (!a.empty()) {
            res.push_back(a.front());
            a.pop_front();
        }

        while (!b.empty()) {
            res.push_back(b.front());
            b.pop_front();
        }

        return Polynomial<T>(res);
    }

    Polynomial<T> multiply(const Polynomial<T>& other) const {

        Polynomial<T> res;
        list<T> a = coeff;
        int shift = 0;

        while (!a.empty()) {
            T a_val = a.front();
            a.pop_front(); // first element in list

            list<T> term_list; // power
            for (int k = 0; k < shift; ++k) {
                term_list.push_back(0); //
            }

            list<T> b = other.coeff;
            while (!b.empty()) {
                T b_val = b.front();
                b.pop_front();
                term_list.push_back(a_val * b_val);
            }

            res = res + Polynomial<T>(term_list);
            shift++;
        }
        return res;
    }

    Polynomial<T> operator+(const Polynomial<T>& other) const {
        return add(other);
    }

    Polynomial<T> operator*(const Polynomial<T>& other) const {
        return multiply(other);
    }
};

int main() {
    Polynomial<int> p1;
    Polynomial<int> p2;

    p1.input();
    p2.input();

    cout << "p1: ";
    p1.print();

    cout << "p2: ";
    p2.print();

    Polynomial<int> sum = p1 + p2;
    cout << "p1 + p2: " << endl;
    sum.print();

    Polynomial<int> prod = p1 * p2;
    cout << "p1 * p2: " << endl;
    prod.print();

    cout << "p1(2) = " << p1.value(2) << endl;

    return 0;
}