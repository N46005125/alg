/*Sia data una sequenza di n numeri interi, memorizzata in un vettore A. Si
implementi un algoritmo che esegua in tempo O(nlogn) per determinare il numero di
 elementi minori uguali dell�elemento i-esimo, riportando il risultato
 corrispondente in un secondo vettore B (sempre di dimensione n) alla posizione i.
*/
#include<iostream>
#include<vector>
using namespace std;

typedef struct{
    int value;
    int ind;
}Node;


void calculus(vector<Node>& A, int p, int r);
void merge(vector<Node>& A, int p, int q,int r);
void print(vector<Node>& A);

int main()
{
    vector<Node> A;
    int n;
    Node tmp;
    cout<<"Inserire il numero di elementi: "; cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp.value;
        tmp.ind=i;
        A.push_back(tmp);
    }
    
    print(A);
   calculus(A,0,A.size()-1);
   print(A);


    return 0;
}

void calculus(vector<Node>& A, int p, int r){

    if(p<r){
    int q=(p+r)/2;
        calculus(A,p,q);
        calculus(A,q+1,r);
        merge(A,p,q,r);
    }
}

void merge(vector<Node>& A, int p, int q,int r){

    int diml = (q-p)+1;
    int dimr = (r-q);

    vector<Node> L(diml);
    vector<Node> R(dimr);
   // cout<<"\nRiempio L: "<<endl;
    for(int i=0;i< diml;i++){
        L[i]=A[p+i];
        
  //      cout<<L[i].value<<"("<<L[i].ind<<")"<<endl<<endl;

    }
    //cout<<"Riempio R: "<<endl;
    for(int j=0;j<dimr;j++){
        R[j]=A[q+1+j];
    //     cout<<R[j].value<<"("<<R[j].ind<<")"<<endl<<endl;

    }

    int ileft=0, iright=0,imerged=p;

    while(ileft<diml &&iright<dimr){
        if(L[ileft].value<=R[iright].value){
     //       cout<<"Scambio. Metto in posizione "<<imerged<<" L: "<<L[ileft].value<<"( "<<L[ileft].ind<<")"<<endl;
            A[imerged]=L[ileft];
            ileft++;
        }else{
            A[imerged]=R[iright];
      //      cout<<"Scambio. Metto in posizione "<<imerged<<" R: "<<R[iright].value<<"( "<<R[iright].ind<<")"<<endl;
          //  A[imerged].ind=R[iright].ind;
            iright++;
        }
        imerged++;

    }
    while(ileft<diml ){
        A[imerged]=L[ileft];
    //    cout<<"Scambio. Metto in posizione "<<imerged<<" L: "<<L[ileft].value<<"( "<<L[ileft].ind<<")"<<endl;
       // A[imerged].ind=L[ileft].ind;
        ileft++;
        imerged++;

    }
    while(iright<dimr){
        A[imerged]=R[iright];
  //      cout<<"Scambio. Metto in posizione "<<imerged<<" R: "<<R[iright].value<<"( "<<R[iright].ind<<")"<<endl;
       // A[imerged].ind=R[iright].ind;
        iright++;
        imerged++;
    }
}

void print(vector<Node>& A){
    for(int i=0;i<A.size();i++){
        cout<<A[i].value<<"("<<A[i].ind<<") - ";
    }
}



