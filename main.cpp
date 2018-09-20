#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
vector <tuple <int, int, int>> pos;
int R, C, total, dif;
void backtracking(int **mat);

int come(int i, int j, int pcome, int **mat){
    int ret = 1;
    if(i < R-1 && mat[i+1][j] == pcome ){
        mat[i+1][j] =  mat[i][j];
        mat[i][j] = 0;
        backtracking(mat);
        mat[i][j] = mat[i+1][j];
        mat[i+1][j] = pcome;
    }
    if( i > 0 && mat[i-1][j] == pcome){
        mat[i-1][j] =  mat[i][j];
        mat[i][j] = 0;
        backtracking(mat);
        mat[i][j] = mat[i-1][j];
        mat[i-1][j] = pcome;

    }

    if(j < C-1 && mat[i][j+1] == pcome ){
        mat[i][j+1] =  mat[i][j];
        mat[i][j] = 0;
        backtracking(mat);
        mat[i][j] = mat[i][j+1];
        mat[i][j+1] = pcome;

    }
    if(j > 0 && mat[i][j-1] == pcome ){
        mat[i][j-1] =  mat[i][j];
        mat[i][j] = 0;
        backtracking(mat);
        mat[i][j] = mat[i][j-1];
        mat[i][j-1] = pcome;
    }
    else 
        ret = 0;
    return ret;

}

void backtracking(int **mat){

    int p=0;
    int x, y;
    int tipo;

    int **aux = new int*[R]; //cria matriz auxiliar que contém a matriz alterada 
    for(int i=0; i<R; i++)
        aux[i]= new int[C];

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            aux[i][j] = mat[i][j];

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(aux[i][j] !=0){
                switch(aux[i][j]){
                    case 1:
                        come(i, j, 2, aux);
                        break;

                    case 2:
                        come(i, j, 3, aux);
                        break;

                    case 3:
                        come(i, j, 1, aux);
                        break;
                }
                p++;
                x=i+1;
                y=j+1;
                tipo=aux[i][j];
            }
        }        
    }
    if(p == 1){
        total++;
        int flag = 1;
        
        for(int i = 0; i<pos.size(); i++){
            if(pos[i] == make_tuple(x,y,tipo)){
                flag = 0;
                break;
            }
        }
    
        if(flag){
            pos.push_back(make_tuple(x,y,tipo));
            dif++;
        }
//        for(int i=0; i<R; i++){
//            for(int j=0; j<C; j++)
//                cout << aux[i][j] << " ";
//        }
    }
    for(int i=0; i<R; i++)
        delete[] aux[i];
    delete[] aux;
}



int main(int argc, const char * argv[]) {
    
    cin>>R;
    cin>>C;

    int **tab;
    tab = new int* [R];
    for(int i=0; i<R; i++)
        tab[i]= new int[C]; 
    
    
    for(int i = 0; i<R; i++){
        for(int j = 0;j<C; j++){
            cin>>tab[i][j];
        }
    }

    backtracking(tab);
    
    cout<<total<<endl<<dif<<endl;
    int x, y, tipo;
    for(int i = 0; i<pos.size();i++){
        tie(x, y ,tipo) = pos[i];
        cout<<x<<" "<<y<<" "<<tipo<<endl;
    }
    
 /*  for(int i = 0; i<R; i++){
        for(int j = 0;j<C; j++){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
*/
    for(int i=0; i<R; i++)
        delete[] tab[i];
    delete[] tab;
    
    return 0;
}
