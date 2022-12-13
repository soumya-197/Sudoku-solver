#include <iostream>
using namespace std;

int suduko[9][9];
bool isSafe(int row, int col, int suduko[9][9], int value){
    for(int i=0;i<9;i++){
        //row check
        if(suduko[row][i]==value){
           return false; 
        }
        //col check
        else if(suduko[i][col]==value){
            return false;
        }
        //check for matrix;
        else if(suduko[(3*(row/3))+(i/3)][3*(col/3)+(i%3)]==value){
            return false;
        }
    }
    return true;
}

bool sudukoSolver(int suduko[][9],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(suduko[i][j]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe(i,j,suduko,val)==true){
                        suduko[i][j]=val;
                        //recursive call;
                        bool isPossible = sudukoSolver(suduko,n);
                        if(isPossible==true){
                            return true;
                        }
                        else{
                            suduko[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n;
    n=9;
    cout<<"Enter suduko elements (for empty space, enter 0) : \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>suduko[i][j];
        }
    }
    sudukoSolver(suduko,n);
    cout<<"\nSolved suduko : \n\n";
    for(int i=0;i<n;i++){
        if(i==3||i==6){
            for(int k=0;k<n;k++){
                cout<<"---";
            }
            cout<<endl;
        }
        for(int j=0;j<n;j++){
            if(j==3||j==6){
                cout<<" | ";
            }
            cout<<suduko[i][j]<<" ";
        }
        cout<<endl;
    }
}