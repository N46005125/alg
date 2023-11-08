// MERGE SORT C++ CON INSERIMENTO DA TASTIERA

#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& A,int p,int r);
void printArray(vector<int> A);
void merge(vector<int>& A,int p,int q,int r);

int main()
{
    printf("MERGE SORT\n");
    
    int n;
    cout<<"Quanti elementi vuoi inserire? "; cin>>n;
    vector<int> A(n);
    cout<<"Inserisci gli elementi:"<<endl;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    mergeSort(A,0,A.size()-1);
    cout<<"\nArray ordinato:\n";
    printArray(A);
    
    
    return 0;
}


void mergeSort(vector<int>& A,int p,int r){
    
    if(p<r){
        int q = (p+r)/2;  //mi prendo il floor 
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}


void merge(vector<int>& A,int p,int q,int r){
    
    int dim_l=(q-p)+1;
    int dim_r=r-q;
    vector<int> Left(dim_l);
    vector<int> Right(dim_r);
    
    //Riempimento vettori Left e Right
    for(int i=0;i<dim_l;i++){
        Left[i] = A[p+i];
    } 
    for(int i=0;i<dim_r;i++){
        Right[i] = A[q+1+i];
    } 
   
    int ileft=0;
    int iright=0;
    int imerged=p;
    
    while(ileft<dim_l && iright<dim_r){
        if(Left[ileft]<=Right[iright]){
            A[imerged]=Left[ileft];
            ileft++;
        }else{
            A[imerged]=Right[iright];
            iright++;
        }
        imerged++;
    }
    while(ileft<dim_l){
        A[imerged]=Left[ileft];
        ileft++;
        imerged++;
    }
    while(iright<dim_r){
        A[imerged]=Right[iright];
        iright++;
        imerged++;
    }
}

void printArray(vector<int> A){
    
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
}

