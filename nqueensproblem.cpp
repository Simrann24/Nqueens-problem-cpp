#include<iostream>
using namespace std;
#include<bits/stdc++.h>


void addsol(vector<vector<int>>& ans,vector<vector<int>>& board,int n)
{
    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp.push_back(board[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    ans.push_back(temp);
}
bool issafe(int row,int col,vector<vector<int>>& board ,int n)
{
    int x=row;
    int y=col;

    //check for same row
    while(y>=0)
    {
        if(board[x][y]==1)
       {
        return false;
       }
       y--;
    }

    x=row;
    y=col;
    //check for diagonal
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
        return false;
        }
        y--;
        x--;
    }
    x=row;
    y=col;

    //check for down diagonal
     while(x<n && y>=0)
    {
        if(board[x][y]==1)
        {
        return false;
        }
        y--;
        x++;
    }
    return true;
}
void solve(int col,vector<vector<int>>& ans,vector<vector<int>>& board,int n)
{
    if(col==n)
    {
        addsol(ans,board,n);
        return;
    }

    for(int row=0;row<n;row++)
    {
        if(issafe(row,col,board,n))
        {
            board[row][col]=1;
            solve(col+1,ans,board,n);
            board[row][col]=0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;

    solve(0,ans,board,n);

}