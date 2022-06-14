// jaise ki matrix nahe given hain sirf uska size , or coordinates hain

//  
//https://www.lintcode.com/problem/434/description


class Solution {
public:

    int dir[5]={0,1,0,-1,0};


    int find_union(int idx, vector<int>&parent){
        if(parent[idx]==idx){
            return idx;
        }
        return find_union(parent[idx],parent);
    }
   
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        vector<int>res;
        int count  = 0;

        vector<int>parent(n*m,-1);
        vector<int>rank(n*m,0);
        

        for(int i=0;i<operators.size();i++){

            int x = operators[i].x;
            int y = operators[i].y;

            int getcell_idx = m*x + y;  // with this formula you can get the cell
                    //number as we are representing the cells on one-d grid , the parent's array 

            if(parent[getcell_idx]!=-1){
                    res.push_back(count);
                    continue;
            }
            parent[getcell_idx] = getcell_idx;
            rank[getcell_idx]=1;
            count++;

            for(int j=0;j<4;j++){
                int new_x = x + dir[j];
                int new_y = y+ dir[j+1];

                int newcell_idx = m* new_x + new_y;

                if(new_x<0 || new_y<0  || new_x>=n || new_y>=m || parent[newcell_idx]==-1){
                    continue;
                }

                int parentof_getcell_idx= find_union(getcell_idx,parent);
                int parentof_newcell_idx = find_union(newcell_idx,parent);


            if(parentof_getcell_idx != parentof_newcell_idx){

                if(rank[parentof_getcell_idx]>rank[parentof_newcell_idx]){
                   parent[parentof_newcell_idx]=parentof_getcell_idx;
                }else if(rank[parentof_newcell_idx]>rank[parentof_getcell_idx]){
                        parent[parentof_getcell_idx]=parentof_newcell_idx;
                }else{
                        parent[parentof_newcell_idx]=parentof_getcell_idx;
                        rank[parentof_getcell_idx]++;
                }

               // cout<<count<<"\n";
                count--;
            } //outer if loops ends here

              



            }//dir loops ends here
            res.push_back(count);
        }

        return res;
    }
};