class Solution { 
  //leetcode 827
    bool isVal(int i , int j, int n ,int m){
        if(i<0 || j<0 || i>=n || j>=m)return false;
        return true;
    }
    //dirn arrays babe
    vector<pair<int,int>>dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    void dfs(vector<vector<bool>>&vis, vector<vector<int>>& grid,                   vector<vector<int>>&color, int i , int j , int c,int &area ){

        int m = grid.size();
        int n =  grid[0].size();
        if(isVal(i,j,m,n) && grid[i][j]==1 && vis[i][j]==false){
            
            area++;
            vis[i][j] = true;
            color[i][j]= c;
            
            for(int k=0;k<4;k++){
                int newi = i+dir[k].first;
                int newj = j+dir[k].second;
                dfs(vis,grid,color,newi,newj,c,area);
            }//dirn loops ends here
        } //if yaha khatam hoga
        
        return ;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
     
        int m = grid.size(), n = grid[0].size();
        unordered_map<int,int>mp;  //map for color
        int res = 0, c = 0; 
        
        vector<vector<int>>color(m,vector<int>(n,INT_MIN)); 
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int area = 0;
                    dfs(visited,grid,color,i,j,c,area);
                    mp[c]=area;
                    c++;
                }   
            }
        }
        
        bool flag = false;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                flag = true;
                int count = 1;
                unordered_map<int,int>temp;
                     for(int k=0;k<4;k++){     
                        int newi = i+dir[k].first;
                        int newj = j+dir[k].second;

                        if(isVal(newi,newj,grid.size(),grid[0].size())){

                            if(color[newi][newj]!=INT_MIN)
                            temp[color[newi][newj]]++;
                        }

                    }
                    
                     for(auto it=temp.begin();it!=temp.end();it++){
                        int a = it->first;
                         count+= mp[a];
                     }
                    
               res = max(res,count);
            } /// if ends here
                    
            }
        }
        

        if(flag==false){
           return m*n; 
        }

        return res;
    }
};