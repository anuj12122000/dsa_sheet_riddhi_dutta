class Solution {
 //litcode 663
private:

    bool isvalid(int i , int j , int m , int n ){
        return (i>=0 && j>=0 && i<m && j<n);
    }

public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        
        int m  = rooms.size();
        int n  = rooms[0].size();
        
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rooms[i][j]==0){
                    q.push({i,j});
                  }
            }
        }

        int dir[5]={0,1,0,-1,0};

        while(!q.empty()){

            auto temp  = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
     //cout<<x<<" "<<y<<"\n";
            for(int i=0;i<4;i++){

                    int new_x = x+dir[i];
                    int new_y = y+dir[i+1];

                    if( isvalid(new_x,new_y,m,n)  && rooms[new_x][new_y]!=-1){
                        if(rooms[new_x][new_y]>rooms[x][y]+1){
                            rooms[new_x][new_y]=rooms[x][y]+1;
                            q.push({new_x,new_y});
                        }
                    }

            }


        }



    }
};