/*Una progressione aritmetica è una successione di numeri tali che la differenza tra ciascun termine
(o elemento) della successione e il suo precedente è costante. La somma degli elementi in una
progressione di n elementi è data da: S = ½ * n * (a1 + an), dove a1 ed an sono il primo e l’ultimo
elemento. E’ dato in input un array di interi positivi che rappresenta una progressione aritmetica
dove però manca un elemento. La massima lunghezza è 50, il massimo valore è 1000. Si implementi
un algoritmo che trova l’elemento mancante.
*/
#include<iostream>
#include<vector>
using namespace std;


bool calculus(vector<int>& A, int p, int r,int* find,int passo);
bool check_diff(vector<int>& A, int p, int r,int* find, int passo);
int trova_il_passo(vector<int>& B);
void print(vector<int>& A);

int main()
{
  /*  vector<int> A;
    int n,tmp;
    cout<<"Inserire il numero di elementi: "; cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        A.push_back(tmp);
    }*/
    vector<int> B{0,3,6,9,12,15,18,21};
    int passo=trova_il_passo(B);
    int find=0;
    print(B);
    if(!calculus(B,0,B.size()-1,&find,passo)){
        cout<<endl<<find;
    }else{
        cout<<"Errore";
    }


    return 0;
}

bool calculus(vector<int>& A, int p, int r, int*find,int passo){
    bool checked=1;
    
    if(p<r){
        int q=(p+r)/2;
        checked*=calculus(A,p,q,find,passo);
        checked*=calculus(A,q+1,r,find,passo);
        if(checked==1){
            if(p==q){
               checked=check_diff(A,p,r,find,passo);
            }else{
                checked=check_diff(A,q,q+1,find,passo);
            }
        }
        return checked;
    }
    return 1;
}

bool check_diff(vector<int>& A, int p, int r,int *find,int passo){
    int diff= A[r]-A[p];
    if(diff==passo){
        return true;
    }else{
        (*find)=A[p]+passo;
        return false;
    }
}

int trova_il_passo(vector<int>& B){
    int passo=0;
    
    if((B[1]-B[0])==(B[2]-B[1])){
        passo=(B[1]-B[0]);
        return passo;
    }
    if((B[2]-B[1])==(B[1]-B[0])){
        passo=(B[2]-B[1]);
        return passo;
    }
    
    return passo;
}

void print(vector<int>& A){
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
}


