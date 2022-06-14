
//leetcode 130
class Solution {
    
    bool isvalid(int i , int j ,int m , int n){
        return (i>=0 && j>=0 && i<m && j<n && i!=0 && i!=m-1 && j!=0 && j!=n-1);
    }
    
    
    void dfs(vector<vector<char>>&board, int i ,int  j ){
        
        int m = board.size();
        int n = board[0].size();
        if(isvalid(i,j,m,n) && board[i][j]=='O'){
            board[i][j]='X';
            dfs(board,i+1,j);
            dfs(board,i,j+1);
            dfs(board,i,j-1);
            dfs(board,i-1,j);
        }
        
    }
    
     
    void dfs1(vector<vector<char>>&board, int i ,int  j ){
        
        int m = board.size();
        int n = board[0].size();
        if(i>=0 && j>=0 && i<m && j<n && board[i][j]=='O'){
            board[i][j]='1';
            dfs1(board,i+1,j);
            dfs1(board,i,j+1);
            dfs1(board,i,j-1);
            dfs1(board,i-1,j);
        }
        
    }
    
      
    void dfs2(vector<vector<char>>&board, int i ,int  j ){
        
        int m = board.size();
        int n = board[0].size();
        if(i>=0 && j>=0 && i<m && j<n && board[i][j]=='1'){
            board[i][j]='O';
            dfs2(board,i+1,j);
            dfs2(board,i,j+1);
            dfs2(board,i,j-1);
            dfs2(board,i-1,j);
        }
        
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]=='O' && (i==0 || i==m-1 || j==0 || j==n-1)){
                    dfs1(board,i,j);
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]=='O' && isvalid(i,j,m,n)){
                    dfs(board,i,j);
                }
            }
        }
        
          for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]=='1' && (i==0 || i==m-1 || j==0 || j==n-1)){
                    dfs2(board,i,j);
                }
            }
        }
        
        
        
    }
};