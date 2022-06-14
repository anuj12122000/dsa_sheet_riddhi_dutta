  void dfs(int node,vector<int>adj[],vector<int>&vis)
    {
     vis[node]=1;
        for(auto it:adj[node])
        {
                if(vis[it]==0)
                {dfs(it,adj,vis);}
            }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1)
            return -1;
        
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
             adj[connections[i][1]].push_back(connections[i][0]);
        }
        int cc =0;
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]==0)
            {
                dfs(i,adj,vis);
                cc++;
            }
            
        }
        
    
    
    return cc-1;
    }