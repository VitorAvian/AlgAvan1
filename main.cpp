#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int R, C;
    
    cin>>R;
    cin>>C;
    
    int tab[R][C];
    
    for(int i = 0; i<R; i++){
        for(int j = 0;j<C; j++){
            cin>>tab[i][j];
        }
    }
    
    for(int i = 0; i<R; i++){
        for(int j = 0;j<C; j++){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
