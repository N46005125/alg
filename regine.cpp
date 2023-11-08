//regine backtracking
//permutazioni: n!
#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int row;
    int col;
}Node;

void calculate_path(vector<Node> &sol, vector<vector<bool>> &scacchiera, Node &input, int *counter_ptr);
void construct_candidates(vector<Node> &sol, vector<vector<bool>> &scacchiera, vector<Node> &c, Node &input);
bool is_finished(vector<Node> &sol, vector<vector<bool>> &scacchiera);
bool controllo_diagonali(Node tmp, Node input, int n);

int main()
{
    int n=0;
    cout<<"Inserisci la dimensione N: ";
    cin>>n;
    vector<vector<bool>> scacchiera(n,vector<bool>(n));
    cout<<scacchiera.size();
    
    vector<Node> sol;
    Node input;
    int counter=0;
    for(int i=0;i<n;i++){
            input.row=i;
            input.col=0;
            sol.push_back(input);
            cout<<"Inizio calculate"<<endl;
            calculate_path(sol,scacchiera,input,&counter);
            sol.pop_back();
        
    }
    cout<<endl<<"Counter: "<<counter;
    return 0;
}

void calculate_path(vector<Node> &sol, vector<vector<bool>> &scacchiera, Node &input, int *counter_ptr){
    
    vector<Node> c;  //candidates
    
    if(is_finished(sol,scacchiera)){  //ho raggiunto le n regine
        cout<<"Is finished ";
        (*counter_ptr)++;
        return;
    }else{
        construct_candidates(sol,scacchiera,c,input);
        cout<<"\nHo "<<c.size()<<" candidati"<<endl;
        for(int i=0;i<c.size();i++){
            sol.push_back(c[i]);
            calculate_path(sol,scacchiera,c[i],counter_ptr);
            sol.pop_back();
        }
    }
}

void construct_candidates(vector<Node> &sol, vector<vector<bool>> &scacchiera, vector<Node> &c,Node &input){
    
    Node tmp;
    bool flag=1;
    if(sol.back().col+1<scacchiera.size()){
        tmp.col=sol.back().col+1;
        for(int j=0;j<scacchiera.size();j++){
            tmp.row=j;
            flag=1;
            for(int k=0;k<sol.size();k++){
                if(tmp.row==sol[k].row || tmp.col==sol[k].col || controllo_diagonali(tmp,sol[k],scacchiera.size())){ 
                    cout<<"Secondo if. tmp.col: "<<tmp.row<<" input.col "<< input.row<<endl;
                    flag=0;
                }
            }
            if(flag==1){
                c.push_back(tmp);
                cout<<"Ho fatto push_back c"<<endl;
            }
        }
    }
}

bool is_finished(vector<Node> &sol, vector<vector<bool>> &scacchiera){
    if(sol.size()==scacchiera.size()) return true;
    return false;
}

bool controllo_diagonali(Node tmp, Node input,int n){           //dice se input è sulla diagonale di tmp
    
    for(int i=tmp.row, j=tmp.col;i>=0 && j>=0;i--,j--){
            if(input.row==i && input.col==j){
                cout<<"Diagonali"<<endl;
                return true;
            }
    }
    for(int i=tmp.row, j=tmp.col;i<n && j>=0;i++,j--){
            if(input.row==i && input.col==j){
                cout<<"Diagonali"<<endl;
                return true;
            }
    }
    
    return false;
    
}

