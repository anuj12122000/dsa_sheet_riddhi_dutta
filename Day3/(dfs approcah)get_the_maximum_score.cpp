
//leetcode 1537 -> this solution would give us tle , but good for intuition purposes
class Solution {
    private:
    void dfs(unordered_map<int,vector<int>>&adj, int src , int& res,int sum , unordered_map<int,bool>&vis){
        if(sum>res){
            res = sum;
        }
        vis[src]=true;
        for(auto it:adj[src]){
            if( vis.find(it)==vis.end() ||  vis[it]==false ){
                dfs(adj,it,res,sum+it,vis);
            }   
        }   
                vis[src]=false;
    }    
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,vector<int>>adj;
            int res = 0;
        for(int i=0;i<nums1.size()-1;i++){
            int a = nums1[i];
            int b = nums1[i+1];
            adj[a].push_back(b);
        }

          for(int i=0;i<nums2.size()-1;i++){
            int a = nums2[i];
            int b = nums2[i+1];
            adj[a].push_back(b);
        }
        
        unordered_map<int,bool>vis1;
        // unordered_map<int,bool>vis2;
        dfs(adj,nums1[0],res,nums1[0],vis1);
        // vis1.clear();
        // vis2.clear();
        dfs(adj,nums2[0],res,nums2[0],vis1);
        
        return res;
    }
};