#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    ofstream fout("output.txt");
    if (!fout) {
        cerr<<"Unable to open output.txt"<<endl;
        return -1;
    }

    ifstream fin("input.txt");
    if (!fin) {
        cerr<<"Unable to open input.txt"<<endl;
        return -1;
    }
    string line;
    int max = 0;
    int min = 0;
    string max_line;
    string min_line;
    bool first_line = true;
    while (getline(fin, line)) {
        int len = line.length();
        if (first_line) {
            max = len;
            max_line = line;
            min = len;
            min_line = line;
            first_line = false;
        }
        else {
            if (len > max) {
                max = len;
                max_line = line;
            }
            else if (len < min) {
                min = len;
                min_line = line;
                }
            }
        }

    if (first_line) {
        fout << "The file is empty." << endl;
    }
    else {
        fout << "max characters in a line: " << max_line << "\n" << endl;
        fout << "min characters in a line: " << min_line << "\n" << endl;
    }
    fin.close();
    fout.close();
    cout << "open \"output.txt\" to see the result." << endl;
}