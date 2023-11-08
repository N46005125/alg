#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numCasiDiTest;
    cin >> numCasiDiTest;

    for (int casoDiTest = 0; casoDiTest < numCasiDiTest; casoDiTest++) {
        int numParenti;
        cin >> numParenti;
        vector<int> civici(numParenti);

        for (int i = 0; i < numParenti; i++) {
            cin >> civici[i];
        }

        // Ordina i numeri civici in ordine crescente
        sort(civici.begin(), civici.end());

        int mediana;
        if (numParenti % 2 == 1) {
            // Numero dispari di parenti, la mediana è il valore centrale
            mediana = civici[numParenti / 2];
        } else {
            // Numero pari di parenti, la mediana è la media dei due valori centrali
            mediana = (civici[numParenti / 2 - 1] + civici[numParenti / 2]) / 2;
        }

        int distanzaMinima = 0;
        for (int i = 0; i < numParenti; i++) {
            distanzaMinima += abs(civici[i] - mediana);
        }

        cout << distanzaMinima << endl;
    }

    return 0;
}

