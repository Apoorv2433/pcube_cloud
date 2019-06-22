#include<iostream>
using namespace std;
int issafe(int a[][10],int x,int y,int n){
if(x>=0 && x<=n-1 && y>=0 && y<=n-1 && a[x][y]==1)
    return 1;
else
    return 0;

}
int rat_in_maze(int a[][10],int x,int y,int n){
if(x==n-1 && y==n-1 && a[x][y]==1)
    return 1;
if(issafe(a,x,y,n)){
    int f1=rat_in_maze(a,x+1,y,n);
    if(f1){
        return 1;
    }
    int f2=rat_in_maze(a,x,y+1,n);
    if(f2){
        return 1;
    }
}
return 0;
}
int main(){
cout<<"Enter matrix size";
int n;
cin>>n;
int i,j;
int a[10][10];
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        cin>>a[i][j];
    }
}
cout<<rat_in_maze(a,0,0,n);
return 0;
}
