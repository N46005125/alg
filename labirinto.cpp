//Labirinto backtracking
//compplessità esponenziale 
#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    bool value;
    int row;
    int col;
}Node;

void findPath(vector<vector<bool>> &labirinth, vector<vector<bool>> &path, Node &start);
bool inTheEnd(vector<vector<bool>> &path,int n);
void construct_candidates(vector<vector<bool>> &labirinth, vector<Node> &c,Node& start);
void printpath(vector<vector<bool>> &path);

int main()
{
    int n=4;
    vector<vector<bool>> labirinth(n,vector<bool>(n));
    labirinth={
              {1,0,0,0},
              {1,1,1,1},
              {0,0,0,1},
              {1,1,1,1}
    };
    
    vector<vector<bool>> path(n,vector<bool>(n,false)); //inizializzare a 0;
    path[0][0]=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< labirinth[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    Node start;
    start.value=labirinth[0][0];
    start.row=0;
    start.col=0;
    
    findPath(labirinth,path,start);
    

    return 0;
}

void findPath(vector<vector<bool>> &labirinth, vector<vector<bool>> &path, Node &start){
    
    if(inTheEnd(path,labirinth.size()-1)){
        printpath(path);
        return;
    }
    
    vector<Node> c;
    construct_candidates(labirinth,c,start);
    for(int i=0;i<c.size();i++){
        //make move
        path[c[i].row][c[i].col]=true;
        findPath(labirinth,path,c[i]);
        //unmake move
        path[c[i].row][c[i].col]=false;
    }
}


void construct_candidates(vector<vector<bool>> &labirinth, vector<Node> &c,Node& start){
    
    Node tmp;
    tmp.value=1;
    if(start.row < labirinth.size()-1){
        if(labirinth[start.row+1][start.col]==1){
            tmp.row=start.row+1;
            tmp.col=start.col;
            c.push_back(tmp);
        }
    }
    if(start.col < labirinth.size()-1){
        if(labirinth[start.row][start.col+1]==1){
            tmp.row=start.row;
            tmp.col=start.col+1;
            c.push_back(tmp);
        }
    }
}


bool inTheEnd(vector<vector<bool>> &path,int n){
    
    if(path[n][n]==true){
        return true;
    }
    return false;
}

void printpath(vector<vector<bool>> &path){
    for(int i=0;i<path.size();i++){
        for(int j=0;j<path.size();j++){
            cout<< path[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
