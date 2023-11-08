
#include <vector>
#include <iostream>
using namespace std;

void ricerca(vector<int> & biglie, int risposta, int p, int r, int* pos);
int main()
{
    int n_biglie=0,n_risposte,tmp=0;
    vector<int> biglie;
    vector<int> risposte;
    int pos=-1;
    cin>>n_biglie>>n_risposte;
    //biglie
    for(int i=0;i<n_biglie;i++){
        cin>>tmp;
        biglie.push_back(tmp);
    }
    //queries
    for(int i=0;i<n_risposte;i++){
        cin>>tmp;
        risposte.push_back(tmp);
    }

   // ricerca(biglie,5,0,biglie.size()-1, &pos);
   // cout<<pos;
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


