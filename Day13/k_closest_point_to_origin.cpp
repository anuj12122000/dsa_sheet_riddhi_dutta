class Solution {
    
    typedef vector<int> VE;
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<VE,vector<VE>,greater<VE>>pq;
        int n = points.size();
        
        for(int i=0;i<n;i++){
        
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist,x,y});
    
        }
        
        vector<VE>res;
        
        
        while( k--){
        
            VE temp = pq.top();
            pq.pop();
            res.push_back({temp[1],temp[2]});
        }
        
        return res;
    }
};