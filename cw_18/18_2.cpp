#include <iostream>
#include <stack>

namespace STACK {

    template <class T>
    class Stack {
        T data;
        Stack *prev;
        bool is_empty;
    public:
        Stack() : data(), prev(nullptr), is_empty(true) {}

        void push( T el );
        T pop();
        bool empty() {
            return is_empty;
        }
        T top() {
            return data;
        }
    };

    template <class T> void Stack <T>::push( T el ) {
        if (is_empty) {
            data = el;
            prev = nullptr;
            is_empty = false;
        } else {
            Stack<T> *p_old = new Stack<T>();
            p_old->data = this->data;
            p_old->prev = this->prev;
            p_old->is_empty = false;

            this->data = el;
            this->prev = p_old;
        }
    }

    template<class T> T Stack <T>::pop() {
        T ret = this->data;
        Stack<T> *old_prev = this->prev;

        if (old_prev != nullptr) {
            this->data = old_prev->data;
            this->prev = old_prev->prev;
            this->is_empty = false;
            old_prev->prev = nullptr;
            delete old_prev;
        } else {
            this->prev = nullptr;
            this->is_empty = true;
        }

        return ret;
    }
}

template <typename T>
void input_std_stack(STACK::Stack<T>& st) {
    do {
        T tmp;
        std::cout << "input number(0 to stop): ";
        std::cin >> tmp;
        if ( tmp == 0 ) break;
        st.push( tmp );
    } while ( true );
}

template <typename T>
STACK::Stack <T> input_std_stack(std::stack<T>& st) {
    do {
        T tmp;
        std::cout << "input number(0 to stop): ";
        std::cin >> tmp;
        if ( tmp == 0 ) break;
        st.push( tmp );
    } while ( true );
}

template <typename T>
int input_math( T*& mas ) {
    STACK::Stack<T> st;
    int count = 0;
    do {
        T tmp;
        std::cout << "input number(0 to stop): ";
        std::cin >> tmp;
        if ( tmp == 0 ) return count;
        mas[count++] = tmp;
    } while ( true );
    STACK::Stack<T> rev;
    while (!st.empty()) {
        rev.push(st.pop());
    }

    delete[] mas;
    mas = (count > 0) ? new T[count] : nullptr;
    for (int i = 0; i < count; i++) {
        mas[i] = rev.pop();
    }

    return count;
}

int main() {

    int n = 10;
    int *mas = new int[n];
    int m = input_math( mas );
    for (int i = 0; i < m; i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << "\n";

    STACK::Stack<int> st1;
    input_std_stack<int>(st1);
    while ( !st1.empty() ) {
        int tmp = st1.pop();
        std::cout << tmp << " ";
    }
    std::cout << "\n";

    std::stack<double> st2;
    input_std_stack<double>(st2);
    while (!st2.empty()) {
        double tmp = st2.top();
        std::cout << tmp << ", ";
        st2.pop();
    }
    std::cout << "\n";
    delete[] mas;
    return 0;
}