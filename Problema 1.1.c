/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int countInversion(int [],int,int);
int incrementInversion(int [],int,int,int);


int main()
{
    int n_test = 0;
    int n=0;
    int inv = 0;
    printf("Inserisci il numero di test case: ");
    scanf("%d",&n_test);
    printf("\n");
    for(int i=0;i<n_test;i++){
        printf("Inserire il numero di elementi del vettore:");
        scanf("%d",&n);
        printf("\n");
        int *A = malloc(sizeof(int)*n);
        for(int c=0;c<n;c++){
            scanf("%d",&A[c]);
        }
        printf("\n");
        inv = countInversion(A,0,n-1);
        printf("Numero inversioni(Test case %d): %d\n",i,inv);
        printf("\n");
        free(A);
    }
    return 0;
}

int countInversion(int A[],int p,int r){
    int inv = 0;
    if(p<r){
        int q = ((p+r)/2);
        inv += countInversion(A,p,q);
        inv += countInversion(A,q+1,r);
        inv += incrementInversion(A,p,q,r);
    }
    return inv;
}

int incrementInversion(int A[],int p,int q,int r){
    int flag = 0;
    int n1 = q-p+1;
    int n2 = r-q;
    int i,j;
    int inv = 0;
    int L[n1];
    int R[n2];
    for(i=0;i<n1;i++){
        L[i] = A[p+i];
    }
    for(j=0;j<n2;j++){
        R[j] = A[q+j+1];
    }
    i = 0; 
    j = 0;
    int k = p;
    
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }else{
            A[k] = R[j];
            j++;
            inv++;
        }
        k++;
    }
    
    while(i<n1){
        A[k] = L[i];
        i++;
        k++;
        if(flag == 0){
            flag = 1;
            continue;
        }
        /*
            La prima volta in cui si entra nel ciclo 
            non è necessario conteggiare le inversioni,
            poiché sono già state eventualmente conteggiate 
        */
        inv = inv + n2;
    }
    while(j<n2){
        A[k] = R[j];
        j++;
        k++;
    }
    return inv;
}






