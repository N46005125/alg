//Homework #2 problema 1 19:12
#include <iostream>
#include <vector>

using namespace std;

void Divide(vector<int> &A,int p, int r,int *somma);
void calcolaSomma(vector<int> &A, int p, int *somma);

int main()
{
    int test_case;
    int dim,temp;
    int somma=-1000000;
    cout<<"Numero di test case: "; cin>>test_case;
    vector<vector<int>> A(test_case);
    for(int i=0;i<test_case;i++){
        cin>>dim;
        for(int j=0;j<dim;j++){
            cin>>temp;
            A[i].push_back(temp);
        }
        Divide(&A[i],0,dim-1,&somma);
    }
        
    return 0;
}

void calcolaSomma(vector<int> &A, int p,int *somma){
        
    if(p!= (A.size()-1) && (A[p]+A[p+1])>(*somma)){
        somma=A[p]+A[p+1];
        
}

void Divide(vector<int> &A, int p, int r,int *somma){
    
    if(p<r){
        int q=(p+r)/2;
        Divide(A,p,q,somma);
        Divide(A,q+1,r,somma);
        calcolaSomma(A,p,somma);
}
