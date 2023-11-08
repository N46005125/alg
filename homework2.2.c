/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM_STRINGA 30

char* getPrefix(char** A,int p,int r);
char* findPrefix(char *left, char* right); 

int main()
{
    printf("Numero di parole di questo caso di test: ");
    int w_dim=0;
    scanf("%d", &w_dim);
    char** A = (char**)malloc(w_dim*sizeof(char*));
    
    for(int i=0; i<w_dim;i++){                                          
        A[i]= (char*)malloc(MAX_DIM_STRINGA*sizeof(char));
    }
    
    for(int i=0; i<w_dim;i++){
        
        scanf("%s", A[i]);
    }
    
    char* prefix=getPrefix(A,0,w_dim-1);
    
    printf("%s", prefix);

    return 0;
}

char* getPrefix(char** A,int p,int r){
    
    char* prefix;
    if(p<r){                
        int q= (p+r)/2;
        printf("scendo tra p %d e r %d\n", p, r);
        char* left = getPrefix(A,p,q);
        char* right = getPrefix(A,q+1,r);
        printf("Left:%s, right %s tra p %d e r %d\n", left, right, p, r);
        prefix = findPrefix(left, right);
        return prefix;
        
    }else
        return A[p];
}

char* findPrefix(char *left, char* right){
    int i=0;
    while(left[i] == right[i] && left[i]!= '\0'){
        i++;
    }
    char* prefix= (char*)malloc((i+1)*sizeof(char)); //i caratteri di left + uno di terminazione
    strncpy(prefix,left,i);
    prefix[i] = '\0';
    
    return prefix;
}


