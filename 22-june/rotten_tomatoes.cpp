#include<iostream>
#include<queue>
using namespace std;
class node{
public:
    int r;
    int c;
    public:
    node(){
     r=-1;
     c=-1;
    }

};
int main(){
cout<<"Enter row and colomn";
int row,col,i,j;
cin>>row>>col;
int a[row][col];
for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        cin>>a[i][j];
    }
}
int row1=row;
int col1=col;
queue<node *> q;
node *temp,*t;
for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        if(a[i][j]==2){
            temp=new node();
            temp->r=i;
            temp->c=j;
            q.push(temp);
        }
    }
}
temp=new node();
q.push(temp);
int count=0;
while(!q.empty()){
    temp=q.front();
    row=temp->r;
    col=temp->c;
    if(col-1>=0 && col!=-1){
        if(a[row][col-1]==1){
            t=new node();
            t->r=row;
            t->c=col-1;
            q.push(t);
            a[row][col-1]=2;
        }
    }
    if(row-1>=0 && row!=-1){
        if(a[row-1][col]==1){
            t=new node();
            t->r=row-1;
            t->c=col;
            q.push(t);
            a[row-1][col]=2;
        }
        }
        if(row+1<row1 && row!=-1){
        if(a[row+1][col]==1){
            t=new node();
            t->r=row+1;
            t->c=col;
            q.push(t);
            a[row+1][col]=2;
        }
        }
        if(col+1<col1 && col!=-1){
        if(a[row][col+1]==1){
            t=new node();
            t->r=row;
            t->c=col+1;
            q.push(t);
            a[row][col+1]=2;
        }
        }
        if(col==-1 && row==-1){
            count++;
            q.pop();
            if(!q.empty()){
                t=new node();
                q.push(t);
            }
        }
        else{
            q.pop();
        }
    }
    cout<<count-1<<endl;
return 0;
}

