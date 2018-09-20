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
            }
        }        
    }
    if(p == 1){
        cout<< endl;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++)
                cout << aux[i][j] << " ";  
            cout<< endl;
        }
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
