//cavallo backtracking
/*Progettare un algoritmo per partire da una posizione data e fare eseguire al cavallo le mosse per effettuare 
un giro completo, passando esattamente una volta su ogni posizione. Saranno richieste 63 mosse.
*/
#include <iostream>
#include <vector>
using namespace std;

#define DIM 8 
int flag=1;

typedef struct{
    int row;
    int col;
    int n_mossa;
}Cella;

void contstruct_candidates(vector<vector<int>> &scacchiera, Cella &cella, vector<Cella> &c );
void muovi_caballo(vector<vector<int>> &scacchiera, Cella &cella);
bool is_finished(Cella cella);

int main()
{
    vector<vector<int>> scacchiera(DIM, vector<int>(DIM));
    for(int i= 0;i<DIM;i++){
        for(int j= 0;j<DIM;j++){
            scacchiera[i][j]= 0;
        }
    }
    Cella primo;
    primo.n_mossa=1;
    cout<<"Scegli la cella di partenza: "; cin>>primo.row>>primo.col;
    scacchiera[primo.row][primo.col]=1;
    muovi_caballo(scacchiera,primo);
    

    return 0;
}

void muovi_caballo(vector<vector<int>> &scacchiera, Cella &cella){
    

    if(is_finished(cella)){
        cout<<"Ho trovato la soluzione: "<<cella.n_mossa << " a riga-colonna: "<<cella.row<<" "<<cella.col<<endl;
        for(int i= 0;i<DIM;i++){
            for(int j= 0;j<DIM;j++){
                cout<<scacchiera[i][j]<< "  ";
            }
            cout<<endl;
         }
         cout<<endl;
        flag=0;
        return;
    }
    
    vector<Cella> c;
    contstruct_candidates(scacchiera,cella,c); //for(int i=0;i<c.size();i++){cout<<"Candidato: "<<i<< " riga "<<c[i].row<<" colonna "<<c[i].col<<endl; }

    for(int i=0;i<c.size();i++){
        if(flag==1){
           // scacchiera[c[i].row][c[i].col]=cella.n_mossa+1; cout<<"Numero mossa: "<<cella.n_mossa<< " riga "<<c[i].row<<" colonna "<<c[i].col<<endl;
            c[i].n_mossa=(cella.n_mossa+1);
            muovi_caballo(scacchiera,c[i]);
        //    cout<<"me ne fotto"<<endl;
            if(flag==1){
                scacchiera[c[i].row][c[i].col]=0;
                c[i].n_mossa=0;
         //   }
       // }
    }
    
    
}

void contstruct_candidates(vector<vector<int>> &scacchiera, Cella &cella, vector<Cella> &c ){
    Cella tmp;
    if((cella.row-2)>=0){
        if((cella.col+1)<DIM && scacchiera[cella.row-2][cella.col+1]==0){
            tmp.row=cella.row-2;
            tmp.col=cella.col+1;
            tmp.n_mossa=0;
            c.push_back(tmp);
        }
        if((cella.col-1)>=0 && scacchiera[cella.row-2][cella.col-1]==0){
            tmp.row=cella.row-2;
            tmp.col=cella.col-1;
            c.push_back(tmp);
        }
    }
    if((cella.row-1)>=0){
       // cout<<"entro in primo if"<<endl;
        if((cella.col+2)<DIM && scacchiera[cella.row-1][cella.col+2]==0){
           // cout<<"entro in secondo if"<<endl;
            tmp.row=cella.row-1;
            tmp.col=cella.col+2;
            c.push_back(tmp);
        }
        if((cella.col-2)>=0 && scacchiera[cella.row-1][cella.col-2]==0){
          //  cout<<"entro in terzo if"<<endl;
            tmp.row=cella.row-1;
            tmp.col=cella.col-2;
            c.push_back(tmp);
        }
    }
    if((cella.row+1)<DIM){
        if((cella.col+2)<DIM && scacchiera[cella.row+1][cella.col+2]==0){
            tmp.row=cella.row+1;
            tmp.col=cella.col+2;
            c.push_back(tmp);
        }
        if((cella.col-2)>=0 && scacchiera[cella.row+1][cella.col-2]==0){
            tmp.row=cella.row+1;
            tmp.col=cella.col-2;
            c.push_back(tmp);
        }
    }
    if((cella.row+2)<DIM){
        if((cella.col+1)<DIM && scacchiera[cella.row+2][cella.col+1]==0){
            tmp.row=cella.row+2;
            tmp.col=cella.col+1;
            c.push_back(tmp);
        }
        if((cella.col-1)>=0 && scacchiera[cella.row+2][cella.col-1]==0){
            tmp.row=cella.row+2;
            tmp.col=cella.col-1;
            c.push_back(tmp);
        }
    }
    
}

bool is_finished(Cella cella){
    if(cella.n_mossa == 62){
        return true;
    }
    return false;
}


