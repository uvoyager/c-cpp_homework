#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;
vector< list <int> > input_matrix( int n, int m ) {

    vector< list <int> > matrix;

    for ( int i = 0; i < n; i++ ) {

        vector< int > lst;
        string line;
        cin.getline( line, 2 * m );
        stringstream ss( line );
        int tmp;
        while ( ss >> tmp ) {
            lst.push_back( tmp );
        }
        if ( lst.size() != m ) {
            cerr << "error parsing " << line << endl;
        }
        matrix[i] = lst;
    }
    return matrix;
}

int max_row( list <int> v ) {
    int m = *v.cbegin();
    for ( list<int>::const_iterator it = v.cbegin(); it != v.cend(); it++ ) {
        if ( m < *it ) {
            m = *it;
        }
    }
    return m;
}

vector< list<int> > sort_by_max_row( vector<list <int> > & mas ) {
    list <pair<int, int> > max_by_row;
    int i = 0;
    for ( auto row: mas ) {
        int max1 = max_row( row );
        max_by_row.push_back( make_pair( max1, i ) );
    }
    max_by_row.sort();

    vector< list <int> > mas2( mas.size() );
    for ( int i = 0; i < mas.size(); i++ ) {
        pair < int, int > el_pair = max_by_row[i];
        int j = el_pair.second;
        mas2[j] = mas[i];
    }
    return mas2;
}