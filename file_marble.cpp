#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void ricerca(vector<int> & biglie, int risposta, int p, int r, int* pos);

int main() {
    ifstream input("input.txt");
    if (!input.is_open()) {
        cerr << "Impossibile aprire il file di input." << endl;
        return 1;
    }

    int n_biglie = 0, n_risposte, tmp = 0;
    vector<int> biglie;
    vector<int> risposte;
    int pos = -1;

    input >> n_biglie >> n_risposte;

    for (int i = 0; i < n_biglie; i++) {
        input >> tmp;
        biglie.push_back(tmp);
    }

    for (int i = 0; i < n_risposte; i++) {
        input >> tmp;
        risposte.push_back(tmp);
    }

    // Resto del tuo codice...

     for(int i=0;i<n_risposte;i++){
        ricerca(biglie,risposte[i],0,biglie.size()-1, &pos);
        cout<<endl<<"pos: "<<pos<<endl;
        if(pos==-1){
            cout<<risposte[i]<<" not found"<<endl;
        }else{
            cout<<risposte[i]<<" found at "<<pos+1<<endl;
        }
        pos=-1;
    }

    input.close(); // Chiudi il file di input.
    return 0;
}

void ricerca(vector<int> & biglie, int risposta, int p, int r, int* pos){

    if(p<r){
        int q=(r+p)/2;
        ricerca(biglie,risposta,p,q,pos);
        ricerca(biglie,risposta,q+1,r,pos);
    }
    //nodo foglia
    if(p==r){
        cout<<"sono la foglia "<<biglie[p]<<endl;
        if(biglie[p]==risposta){
            cout<<"Sono proprio io"<<endl;
            (*pos) = p;
        }
    }

}


