class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m  = grid.size();
        int n  = grid[0].size();
        int res = -1;  // we started with -1 because initially all the rotten oranges started at 0 
        queue<pair<int,int>>q;
        int orange=0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    orange++;
                }
            }
        }
        
        int dir[5]={0,1,0,-1,0};
        
        while(!q.empty()){
            
           
            
            int a = q.size();
            while(a--){
            
                
             auto temp = q.front();
             q.pop();
                
            int x = temp.first;
            int y = temp.second;
            
            for(int i=0;i<4;i++){
                int new_x = x+dir[i];
                int new_y = y+dir[i+1];
                
                if(new_x>=0 && new_y>=0 && new_x<m && new_y<n && grid[new_x][new_y]==1){
                    grid[new_x][new_y]=2;
                    orange--;
                    q.push({new_x,new_y});
                }
                  
            } // direction loops ends here
                    
            } // inner while loop ends here
                res++;
        } // my bigger while loop ends here
        
        
        
        
        if(orange>0){
            return -1;
        }
        if(res==-1){
            return 0;
        }
        return res;
    }
};