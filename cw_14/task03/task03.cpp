#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inFile("task3_input.txt");
    ofstream outFile("task3_output.txt");
    if (!inFile||!outFile) {
        cout<<"Error opening files"<<endl;
        return 1;
    }
    char c;
    char word[100];
    int n=0;
    while (inFile.get(c)) {
        if (c=='\n' or c==' ') {
            for (int i=n-1; i>=0; i--) {
                outFile<<word[i];
            }
            n=0;
            outFile << c;
        }
        else {
            word[n]=c;
            n++;
        }
    }
    inFile.close();
    outFile.close();
}