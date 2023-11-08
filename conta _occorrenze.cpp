// Prova intercorso 2022 19:47
#include <iostream>
#include <vector>

using namespace std;


void conta_occorrenze(vector<int> &A, int p, int r, int k, int *occorrenza);
void printArray(vector<int>& A);

int main()
{
    int test_case=0;
    cout<<"Inserisci il numero di test case: ";
    cin>>test_case;
    vector<int> K(test_case); //è il numero di cui vogliamo contare le occorrenze
    vector<int> N(test_case); //è il numero di elementi dell'array di quel test case
    vector<vector<int>> A;
    vector<int> tempVec;
    int temp=0;
    int occorrenza=0;
    for(int i=0;i<test_case;i++){
        cout<<"Inserisci il numero di cui vogliamo contare le occorrenze: ";
        cin>>K[i];
        cout<<"Inserisci la dimensione del vettore " << i << ": ";
        cin>>N[i];
        vector<int> tempVec;
        for(int j=0;j<N[i];j++){
            cin>>temp;
            tempVec.push_back(temp);
        }
        A.push_back(tempVec);
    }
    for(int i=0; i<test_case;i++){
        cout<<"\nTest case "<<i<<": ";
        printArray(A[i]);
       // cout<<" N="<<N[i]<<" k= "<<K[i];
        conta_occorrenze(A[i],0,N[i]-1,K[i], &occorrenza);
        cout<<"Occorrenze: "<<occorrenza;
        occorrenza=0;
    }
    return 0;
}


void conta_occorrenze(vector<int> &A, int p, int r, int k, int *occorrenza){

    if(p<r){
       
        int q=(p+r)/2;
        conta_occorrenze(A,p,q,k,occorrenza);
        conta_occorrenze(A,q+1,r,k,occorrenza);
    }else{
            if(k==A[p]){
                (*occorrenza)++;
            }
    }
       
}


void printArray(vector<int>& A){
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    
}

