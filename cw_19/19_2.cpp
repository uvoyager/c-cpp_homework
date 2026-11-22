#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<double> input_vec( int d ) {

    vector<double> res;
    for ( int i = 0; i < d; ++i ) {
        double x;
        cout << "x[" << i << "] = " << x << endl;
        cin >> x;
        res.push_back( x );
    }
    return res;
}

double norm( const vector<double>& v ) {
    double res = 0;
    for ( int i = 0; i < v.size(); i++ ) {
        res += v[i] * v[i];
    }
    return sqrt( res );
}

double sum_norms( const vector< vector<double> >& v ) {
    double sum = 0;
    for ( int i = 0; i < v.size(); i++ ) {
        sum += norm( v[i] );
    }
    return sum;
}

int main() {
    int d, n;
    cout << "space dim: ";
    cin >> d;
    cout << "num of vectors: ";
    cin >> n;
    vector< vector<double> > mas;

    for ( int i = 0; i < n; i++ ) {
        vector<double> v = input_vec( d );
        mas.push_back( v );
    }

    cout << sum_norms( mas );

    array< vector<double>, n > mas2; // other variant through array

    for ( int i = 0; i < n; i++ ) {
        mas2[i] = input_vec( d );
    }
}