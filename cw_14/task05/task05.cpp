#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Student {
    string name;
    int course;
    char group;
    double grades[21];
};

bool createStudent( Student &s ) {
    cout << "enter name: ";
    cin >> s.name;

    cout << "enter course (number): ";
    while (!(cin >> s.course)) {
        cout << "Invalid input. Enter course as a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "enter group (single char): ";
    cin >> s.group;

    cout << "enter grades (up to 20, -1 to stop): ";
    int i = 0;
    for (; i < 20; i++) {
        while (!(cin >> s.grades[i])) {
            cout << "Invalid grade. Enter a number or -1 to stop: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (s.grades[i] == -1) break;
    }
    if (i <= 20) {
        s.grades[i] = -1;
    }
    return true;
}

bool saveStudent( ofstream &outFile, const Student &s ) {
    outFile << s.name << " " << s.course << " " << s.group << " ";
    for ( int i = 0; i < 21; i++ ) {
        outFile << s.grades[i] << " ";
        if ( s.grades[i] == -1) break;
    }
    outFile << endl;
    return true;
}

double averageGrade( const Student &s ) {
    double sum = 0.0;
    int count = 0;
    for ( int i = 0; i < 20; i++ ) {
        if ( s.grades[i] == -1) break;
        sum += s.grades[i];
        count++;
    }
    return count > 0 ? sum / count : 0.0;
}

void printStudent( const Student &s ) {
    cout << "Name: " << s.name << ", Course " << s.course << ", Group " << s.group << ", Average grade " << averageGrade( s ) << endl;
}

void printWorstStudent( ifstream &inFile ) {
    Student s;
    Student worstStudent;
    double worstAverage = 101;
    while ( inFile >> s.name >> s.course >> s.group ) {
        for ( int i = 0; i < 21; i++ ) {
            if ( !(inFile >> s.grades[i])) break;
            if ( s.grades[i] == -1) break;
        }
        double avg = averageGrade( s );
        if ( avg < worstAverage ) {
            worstStudent = s;
            worstAverage = avg;
        }
    }
    if ( worstAverage < 101 ) {
        printStudent( worstStudent );
    }
}

int main() {
    ofstream outFile( "task5_output.txt" );
    if ( !outFile ) {
        cerr << "Error opening output file" << endl;
        return -1;
    }

    int numStudents;
    cout << "enter number of students: ";
    while (!(cin >> numStudents)) {
        cout << "Invalid input. Enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Student s;
    for ( int i = 0; i < numStudents; i++ ) {
        if ( createStudent( s ) ) {
            saveStudent( outFile, s );
        }
    }
    outFile.close();

    ifstream inFile("task5_output.txt");
    if (!inFile) {
        cerr << "Error opening file for reading" << endl;
        return -1;
    }
    printWorstStudent( inFile );
    return 0;
}