#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Impossibile aprire il file di input." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> matrix;
    int num;
    
    // Leggi la matrice da file e memorizzala in una struttura dati (un vettore bidimensionale).
    while (!input.eof()) {
        std::vector<int> row;
        while (input >> num) {
            row.push_back(num);
        }
        matrix.push_back(row);
    }
    
    // Stampa la matrice letta.
    for (const std::vector<int>& row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    input.close(); // Chiudi il file di input.
    return 0;
}
