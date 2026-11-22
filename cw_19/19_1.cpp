#include <iostream>
#include <vector>

using namespace std;

vector<int> input_vec_of_people( int d ) {

    vector<int> res;
    for ( int i = 0; i < d; ++i ) {
        int x;
        cout << "t(" << i << ") = ";
        cin >> x;
        res.push_back( x );
    }
    return res;
}

int get_time_of_being( vector<int> v, int j ) {
    int time = 0;
    for ( int i = 0; i <= j; ++i ) {
        int arrival_time = i;
        int start_service = ( time > arrival_time ) ? time : arrival_time;
        time = start_service + v[i];
    }
    return time - j;
}

int get_max_time_in_queue( vector<int> v ) {
    int max_time = get_time_of_being( v, 0 );
    int max_time_idx = 0;
    for ( int i = 1; i < v.size(); i++ ) {
        int time = get_time_of_being( v, i );
        if ( time > max_time ) {
            max_time = time;
            max_time_idx = i;
        }
    }
    return max_time_idx;
}

int get_min_time_in_service( vector<int> v ) {
    int min_time = v[0];
    int min_time_idx = 0;
    for ( int i = 1; i < v.size(); i++ ) {
        if ( v[i] < min_time ) {
            min_time = v[i];
            min_time_idx = i;
        }
    }
    return min_time_idx;
}

int main() {
    int n;
    cout << "enter number of people: ";
    cin >> n;
    vector <int> v = input_vec_of_people( n );

    int res1 = get_max_time_in_queue( v );
    int res2 = get_min_time_in_service( v );

    cout << "customer with max_time in queue: " << res1 << endl;
    cout << "customer with min_time in service: " << res2 << endl;

    cout << "time in queue for each customer: " << endl;
    for ( int i = 0; i < v.size(); i++ ) {
        cout << "customer " << i << ": "<< get_time_of_being( v, i ) << endl;
    }
}