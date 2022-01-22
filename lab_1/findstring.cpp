#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    // begin modifiable parameters
    int threshold = 1;
    string s = "CAAATATCATTCTGAGGAGC";
    // end parameters

    string toss, pork, beef, chicken;
    ifstream fin("cytochrome_b.fasta");
    fin >> toss >> pork;
    fin >> toss >> beef;
    fin >> toss >> chicken;
    // cin >> s;

    cout << "checking primer of length " << s.length() << "\n";
    cout << "=== pork ===\n";
    for(int i = 0; i < pork.length() - s.length(); ++i) {
        int errors = 0;
        for(int j = 0; j < s.length(); ++j) {
            if(pork[i + j] != s[j]) ++errors;
        }
        if(errors <= threshold) cout << "bind starting at " << i << "\n";
    }
    cout << "\n";

    cout << "=== beef ===\n";
    for(int i = 0; i < beef.length() - s.length(); ++i) {
        int errors = 0;
        for(int j = 0; j < s.length(); ++j) {
            if(beef[i + j] != s[j]) ++errors;
        }
        if(errors <= threshold) cout << "bind starting at " << i << "\n";
    }
    cout << "\n";
    cout << "=== chicken ===\n";
    for(int i = 0; i < chicken.length() - s.length(); ++i) {
        int errors = 0;
        for(int j = 0; j < s.length(); ++j) {
            if(chicken[i + j] != s[j]) ++errors;
        }
        if(errors <= threshold) cout << "bind starting at " << i << "\n";
    }
    cout << "\n";

    return 0;
}
