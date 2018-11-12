/**
 *
 *          Trabalho 2
 *     Algoritmos Avançados
 *     Rafael Roque 10295412
 *     Vitor Avian  10295392
 *
 **/
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
vector <tuple <int, int, int>> pos;
int R, C, total, dif;
void backtracking(int **mat);

bool ordena(tuple<int, int, int> a, tuple<int, int, int> b){
	int x1, y1, tipo1;
	int x2, y2, tipo2;
	tie(x1, y1,tipo1) = a;
	tie(x2, y2,tipo2) = b;
	
	if(x1 == x2){
		if(y1 == y2)
		return (tipo1<tipo2);
		return(y1<y2);
	}
	return (x1<x2);
	
}

void come(int i, int j, int pcome, int **mat){//procura posições onde a peça pode comer
	if(i < R-1 && mat[i+1][j] == pcome ){//se achar uma peça que pode ser comida
		mat[i+1][j] =  mat[i][j];
		mat[i][j] = 0;
		backtracking(mat);//movimenta e chama a recurção
		mat[i][j] = mat[i+1][j];//volta a matriz para o estado anterior e tenta movimentar para outras direções
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
	
}

void backtracking(int **mat){
	
	int p=0;
	int x, y;
	int tipo;
	
	int **aux = new int*[R]; //cria matriz auxiliar que contém a matriz alterada.
	for(int i=0; i<R; i++)
	aux[i]= new int[C];
	
	for(int i=0; i<R; i++)
	for(int j=0; j<C; j++)
	aux[i][j] = mat[i][j];
	
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){//passa em cada casa procurando peças, se encontrar tenta movimentar.
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
				tipo=aux[i][j];//salva ultima casa movimentada.
			}
		}
	}
	if(p == 1){//se restar apenas uma peça, indica fim de jogo e salva as informações
		total++;
		int flag = 1;
		
		for(int i = 0; i<pos.size(); i++){
			if(pos[i] == make_tuple(x,y,tipo)){
				flag = 0;
				break;
			}
		}
		
		if(flag){//se final distinto, salva.
			pos.push_back(make_tuple(x,y,tipo));
			dif++;
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
	
	sort(pos.begin(), pos.end(), ordena);
	
	cout<<total<<endl<<dif<<endl;
	int x, y, tipo;
	for(int i = 0; i<pos.size();i++){
		tie(x, y ,tipo) = pos[i];
		cout<<x<<" "<<y<<" "<<tipo<<endl;
	}
	
	for(int i=0; i<R; i++)
	delete[] tab[i];
	delete[] tab;
	
	return 0;
}
