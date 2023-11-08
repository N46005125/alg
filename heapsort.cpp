//HEAPSORT
#include <iostream>
using namespace std;
#include <vector>

void printArray(vector<int>& A);
void heapSort(vector<int>& A);
void buildMaxHeap(vector<int>&A);
void maxHeapify(vector<int>&A,int i, int heap_size);

int main()
{
    cout<<"Inserisci la dimensione del vettore: ";
    int dim=0;
    cin>>dim;
    cout<<"Inserisci vettore da ordinare:"<<endl;
    vector<int> A(dim);
    for(int i=0;i<dim;i++){
        cin>>A[i];
    }
    heapSort(A);
    printArray(A);

    return 0;
}

void heapSort(vector<int>& A){
    int temp=0;
    int heap_size=A.size();
    buildMaxHeap(A);                     //rende l'array un maxHeap
    for(int i=A.size()-1;i>0;i--){        
        temp = A[i];                    //viene scambiato il primo elemento con l'ultimo
        A[i]= A[0];
        A[0]= temp;
        heap_size--;                    //decremento dimensione heap
        maxHeapify(A,0,heap_size);                //per mantenere la proprietà del maxheap dopo la modifica
    }
}

void buildMaxHeap(vector<int>&A){
    for(int i=(A.size()/2)-1;i>=0;i--){
        maxHeapify(A,i,A.size());      //heap_size=A.size()
    }
}


void maxHeapify(vector<int>&A, int i, int heap_size){  //fa' sì che l'albero con root(i) sia un maxheap, assumendo che right(i) e left(i) siano già maxheap
    int l= 2*i +1;                          //proprietà degli indici dei figli in un maxheap
    int r= 2*i+2;
    int largest=i;                      //questo valore largest lo assumo prima pari a i
    if(l<heap_size && A[l]>A[largest]){
        largest=l;
    }
    if(r<heap_size && A[r]>A[largest]){
        largest=r;
    }
    int temp=0;
    if(largest!=i){
        temp = A[i];                    
        A[i]= A[largest];
        A[largest]= temp;
        maxHeapify(A,largest,heap_size);
    }
}


void printArray(vector<int>& A){
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
}
