//jolly, divide et impera

/*Complessità: 
-Divide() viene chiamata log(n) volte (l'altezza dell'albero di ricorsione) con un costo costante, 
quindi abbiamo un primo contributo pari a O(log(n)).
-Calculus() ha un tempo lineare perché i for per riempire L e R dipendono dal numero di elementi n -> O(n)
-find_jolly() ha un ciclo while dipendente da n e un for interno da n-> n^2
La complessità totale dell'algoritmo è data dalla somma di questi contributi e vale O(n^2);


*/
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void divide(vector<int> &stinga, int p, int r,vector<int> &diff);
void calculus(vector<int> &stinga,int p, int q, int r,vector<int> &diff);
bool find_jolly(vector<int> &diff,int n);

int main()
{
    int n=0;
    cout<<"Inserisci il numero di elementi: "; cin>>n;
    if(n<=0 || n> 3000){
        cout<<"Error!";
        return 1;
    }
    vector<int> stringa(n);
    cout<<"Elementi: "<<endl;
    for(int i=0;i<n;i++){
        cin>>stringa[i];
    }
    vector<int> diff;
    divide(stringa,0,n-1,diff);
    if(find_jolly(diff,n)){
        cout<<"Jolly";
    }else{
        cout<<"Not Jolly";
    }
    return 0;
}

void divide(vector<int> &stringa,int p, int r,vector<int> &diff){
    
    if(p<r){
        int q= (p+r)/2;
        divide(stringa,p,q,diff);
        divide(stringa,q+1, r,diff);
        calculus(stringa,p,q,r,diff);
    }
}

void calculus(vector<int> &stringa,int p, int q, int r,vector<int> &diff){
    int dim_l=(q-p)+1;
    int dim_r = (r-q);
    vector<int> L(dim_l);
    vector<int> R(dim_r);
    
    //Riempimento vettori L e R
    for(int i=0;i<dim_l;i++){
        L[i]=stringa[p+i];
    }
    for(int j=0;j<dim_r;j++){
        R[j]=stringa[q+1+j];
    }
    
    //calcolo la differenza in valore assoluto tra due valori consecutivi
    int tmp= R[0]-L.back();
    cout<<"Differenza tra "<<R[0]<<"e "<<L.back()<<"= "<<abs(tmp)<<endl;
    
    diff.push_back(abs(tmp));

}

bool find_jolly(vector<int> &diff, int n){
    
    for(int i=0;i<diff.size();i++){  //se ci sono valori non nel range 1/n-1
        if(diff[i]>(n-1) || diff[i]<1) return false;
    }
    
    int tmp=1,flag=0;
    
    while(tmp<=(n-1)){   //verifico se ci sono proprio tutti gli elementi del range o manca qualcuno
        for(int i=0;i<diff.size();i++){
            if(tmp==diff[i]){
                flag=1;
                continue;  
            }
        }
        if(flag==0){
            return false;
        }
        flag=0;
        tmp++;
    }
    return true;
}
    
    

