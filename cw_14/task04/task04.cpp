#include <iostream>
#include <fstream>

using namespace std;
int main() {
    ifstream inFile("task4.txt");
    if ( !inFile ) {
        cerr << "Error opening file!" << endl;
        return -1;
    }

    string line;
    int count_closed = 0;
    int count_opened = 0;
    while ( getline( inFile, line ) ) {
        for ( int i = 0; i < line.length(); i++ ) {
            if (  line.substr(i, 4) == "<td>" ) {
                count_opened++;
            }
            else if ( line.substr(i, 5) == "</td>" ) {
                count_closed++;
            }
        }
        if ( count_closed > count_opened || count_opened - count_closed > 1 ) {
            cout << "file with inappropriate amounts or order of opened and closed tags" << endl;
            inFile.close();
            return 0;
        }
    }
    if ( count_opened != count_closed ) {
        cout << "file with inappropriate amounts of opened and closed tags";
    }
    else cout << "file with appropriate amounts of closed tags, the file is correct" << endl;

    inFile.close();
    return 0;
}