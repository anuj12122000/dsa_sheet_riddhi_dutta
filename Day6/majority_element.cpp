 int majorityElement(vector<int>& nums) {
     int res = nums[0];
        int n = nums.size();
        int f = 1;
        
        for(int i=1;i<n;i++){
            if(nums[i]==res){
                f++;
            }else{
                f--;
            }
            
            if(f==0){
                res=nums[i];
                f=1;
            }
        }    
        return res;
    }