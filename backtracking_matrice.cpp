
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int value;
    int row;
    int col;
}Node;

void calculate(vector<int> &sol, vector<vector<int>> &matrix, Node input,int row,int col);
bool is_finished(Node input, int row,int col);
void construct_candidates(vector<int> &sol, Node input, vector<vector<int>> &matrix, vector<Node> &c ,int row,int col );
void print (vector<int> &sol);

int main (){

    int row, col,tmp=0;
    cout << "Numero righe: "; cin >> row;
    cout << "Numero colonne: "; cin >> col;
    cout << "Inserisci elementi matrice:" << endl;
    vector<vector<int>>matrix (row, vector < int >(col)); //come dichiarare matrice
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> tmp;
            matrix[i][j]=tmp;
    	    }
    }
    vector<int> sol;

    Node input;
    input.row=0;
    input.col=0;
    input.value=matrix[0][0];
    sol.push_back(matrix[0][0]);
    calculate(sol,matrix,input,row,col);

  return 0;
}


void calculate(vector<int> &sol, vector<vector<int>> &matrix, Node input,int row,int col){
    int tmp;
    vector<Node> c; //serve a mantenere i possibili candidati
    if(is_finished(input,row,col)){
        print(sol);
        return;
    }else{
        construct_candidates(sol,input,matrix,c,row,col);
        for(int i=0;i<c.size();i++){
            tmp=c[i].value;
            sol.push_back(tmp);
            calculate(sol,matrix,c[i],row,col);
            sol.pop_back();
        }
    }
}

bool is_finished(Node input, int row,int col){
    if((input.row==row-1) && (input.col==col-1)){
        return true;
    }else{
        return false;
    }
}

void construct_candidates(vector<int> &sol, Node input, vector<vector<int>> &matrix, vector<Node> &c, int row,int col ){
        Node tmp;
        if(input.row+1<row){
            tmp.value=matrix[input.row +1][input.col];
            tmp.row=(input.row)+1;
            tmp.col=(input.col);
            c.push_back(tmp);
        }
        if(input.col+1<col){
            tmp.value=matrix[input.row][input.col+1];
            tmp.row=(input.row);
            tmp.col=(input.col)+1;
            c.push_back(tmp);
        }
}

void print (vector<int> &sol){
    for(int i=0; i<sol.size();i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;
}


