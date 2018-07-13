#include <iostream>
#define N 8
using namespace std;

int issafe(int x, int y, int sol[N][N])
{
    return (x>=0 && y>=0 && x<N && y<N && sol[x][y]==-1);
}

void printfun(int sol[N][N])
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
}
}
int checkkt(int x, int y, int movei, int xmove[], int ymove[], int sol[N][N])
{
    int k, nextx, nexty;
    if(movei==N*N){
        return true;
    }
    for(k=0;k<8;k++){
        nextx = x + xmove[k];
        nexty = y + ymove[k];
        if(issafe(nextx, nexty, sol)==true){
                sol[nextx][nexty] = movei;
            if(checkkt(nextx, nexty, movei+1, xmove, ymove, sol)==true){
               return true;
            }

        else{
            sol[nextx][nexty] = -1;
        }
    }
    }
    return false;

}

bool check()
{
    int sol[N][N];
    int i,j;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            sol[i][j] = -1;
        }
    }
    //starting at position 0,0
    sol[0][0] = 0;
    //no of moves in x and y direction..
    int xmove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int ymove[8] = {1, 2,  2,  1, -1, -2, -2, -1 };

    if(checkkt(0, 0, 1, xmove, ymove, sol)==false){
        cout<<"no solution";
        return false;
    }
    else{
        printfun(sol);
        return true;
    }

}

int main()
{
    cout << "Hello try!" << endl;
    check();
    return 0;
}
