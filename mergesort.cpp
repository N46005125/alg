// MERGE SORT C++ 

#include <stdio.h>
#include <vector>
using namespace std;

void mergeSort(int A[],int p,int r);
void printArray(int A[], int size);
void merge(int A[],int p,int q,int r);

int main()
{
    printf("MERGE SORT\n");
    
    int A[] = { 12, 11, 13, 5, 6, 7 };
    int arr_dim = sizeof(A)/sizeof(A[0]);            //tecnica per trovare size di un vettore non dichiarato come std::vector
    
    printArray(A,arr_dim);
    mergeSort(A,0,arr_dim-1);
    printf("\nArray ordinato:\n");
    printArray(A,arr_dim);
    
    
    return 0;
}


void mergeSort(int A[],int p,int r){
    
    if(p<r){
        int q = (p+r)/2;  //mi prendo il floor 
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}


void merge(int A[],int p,int q,int r){
    
    int dim_l=(q-p)+1;
    int dim_r=r-q;
    int Left[dim_l];
    int Right[dim_r];
    
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

void printArray(int A[], int size){
    
    for(int i=0;i<size;i++){
        printf("%d ",A[i]);
    }
}
