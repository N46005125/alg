//Backtrackinng sciatore
//complexity: 3^(n*m) in generale esponenziale, numero di direzioni che posso prendere alla dimensione matrice

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct{      //ogni nodo mantiene il suo valore e gli indici dei suoi adiacenti.
    int value;
    int row;
    int col;
}Node;

void calculate(vector<int> &sol, vector<vector<int>> &matrix, Node& input, int* lenght);
bool is_finished(Node &input, vector<vector<int>> &matrix);
void construct_candidates(vector<int> &sol, vector<vector<int>> &matrix, Node &input, vector<Node>& c);

int main()
{
    int test_case=0,row=0,col=0,temp=0;
   //cin>>test_case;
    string area;
    
    //Riempimento matrice
 //   for(int i=0;i<test_case;i++){
       // cout<<"test case "<<i<<endl; 
       // cout<<"Nome area: "; cin>>area;
        cout<<"Numero righe: "; cin>>row;
        cout<<"Numero colonne: "; cin>>col;
        cout<<"Inserisci elementi matrice:"<<endl;
        vector<vector<int>> matrix(row,vector<int>(col));
        for(int j=0;j<row;j++){
            for(int k=0;k<col;k++){
                cin>>temp;
                matrix[j][k]=temp;
                
            }
        }
        cout<<endl;
   // }
    
    //Inizio backtracking
    vector<int> sol;   //il vettore che mantiene il percorso parziale accettato fino ad ora
    Node input;
    int lenght=0, tmp=0;
    //for(int i=0;i<test_case;i++){
        //cout<<area<<": ";
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                input.value=matrix[i][j];
                input.row=i;
                input.col=j;
                sol.push_back(matrix[i][j]);
                calculate(sol,matrix,input,&tmp);
                if(tmp>lenght) lenght=tmp;
                cout<<"\nLa lunghezza massima partendo da "<<matrix[i][j]<<" è "<<lenght;
                sol.pop_back();
        }
    }
    cout<<"La lunghezza massima è: "<<lenght;
    return 0;
}

void calculate(vector<int> &sol, vector<vector<int>> &matrix, Node& input, int* len){
    
    int tmp;
    vector<Node> c;
    if(is_finished(input,matrix)){
        cout<<"Is finished"<<endl;
        tmp= sol.size();
        if(tmp>(*len)) (*len)=tmp;
        return;
    }else{
        construct_candidates(sol,matrix,input,c);
        for(int i=0;i<c.size();i++){
            tmp=c[i].value;
            cout<<"Sol: "<<tmp<<endl;
            sol.push_back(tmp);
            calculate(sol,matrix,c[i],len);
            sol.pop_back();
        }
    }
}


bool is_finished(Node &input, vector<vector<int>> &matrix){
    
    if((input.row>=1 && input.value<matrix[input.row-1][input.col]) ||input.row==0){ //non posso andare sopra
        if((input.row<(matrix.size()-1) && input.value<matrix[input.row+1][input.col]) || input.row==matrix.size()-1){
            if((input.col>=1 && input.value<matrix[input.row][input.col-1]) ||input.col==0 ){
                if((input.col<(matrix[0].size()-1) && input.value<matrix[input.row][input.col+1] )|| input.col==matrix[0].size()-1){
                    return true;
                }
            }
        }
    }
    return false;
}

void construct_candidates(vector<int> &sol, vector<vector<int>> &matrix, Node &input, vector<Node>& c){
    Node tmp;
    if((input.row<(matrix.size()-1) && input.value>matrix[input.row+1][input.col])){
        tmp.value=matrix[input.row+1][input.col];
        tmp.row=input.row+1;
        tmp.col=input.col;
        c.push_back(tmp);
    }
    if(input.col<(matrix[0].size()-1) && input.value>matrix[input.row][input.col+1]){
        tmp.value=matrix[input.row][input.col+1];
        tmp.row=input.row;
        tmp.col=input.col+1;
        c.push_back(tmp);
    }
    
    if((input.row>=1 && input.value>matrix[input.row-1][input.col])){
        tmp.value=matrix[input.row-1][input.col];
        tmp.row=input.row-1;
        tmp.col=input.col;
        c.push_back(tmp);
    }
    if(input.col>=1 && input.value>matrix[input.row][input.col-1]){
        tmp.value=matrix[input.row][input.col-1];
        tmp.row=input.row;
        tmp.col=input.col-1;
        c.push_back(tmp);
    }
    
}




//void calculate(vector<int> &sol, vector<vector<int>> &matrix){
 
//    while(/*ho altri rami del grafo da scorrere*/){
           
     /*   Node candidate= findCandidate(sol,matrix);
        sol.push_back(candidate.value);
        if(!sol.empty() &&current_height >= sol.back()){       //non ho più valori più piccoli attorno a me
            process_solution(); //confronta la lunghezza di questo perocrso con quella massima
            //dopo aver salvato questa soluzione,devo fare unmake per passare a un altro ramo
            sol.pop_back(candidate.value);
        }else{ //non ho ancora finito questo percorso
            calculate() //chiamata ricorsiva
        
        }
    }
}*/




