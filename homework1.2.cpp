#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getPrefix(const vector<string>& A, int p, int r);
string findPrefix(const string& left, const string& right); 

int main()
{
    int numTestCases;

    cout << "Inserisci il numero di casi di test: ";
    cin >> numTestCases;

    for (int t = 0; t < numTestCases; ++t) {
        vector<string> A;
        string input;

        cout << "Inserisci le parole per il caso " << t+1 << " (termina con 0):" << endl;

        while (true) {
            cin >> input;
            if (input == "0") {
                break;
            }
            A.push_back(input);
        }

        if(A.empty()) {
            cout << "Nessuna parola inserita per il caso " << t+1 << "." << endl;
        } else {
            string prefix = getPrefix(A, 0, A.size()-1);
            cout << "Risultato per il caso " << t+1 << ": " << prefix << endl;
        }
    }

    return 0;
}

string getPrefix(const vector<string>& A, int p, int r) {
    if(p < r) {
        int q = (p + r) / 2;
        string left = getPrefix(A, p, q);
        string right = getPrefix(A, q + 1, r);
        return findPrefix(left, right);
    } else {
        return A[p];
    }
}

string findPrefix(const string& left, const string& right) {
    int i = 0;
    while(i < left.size() && i < right.size() && left[i] == right[i]) {
        i++;
    }
    return left.substr(0, i);
}
