//leetcode 41

int firstMissingPositive(vector<int>& nums) {
            
        for(int i=0;i<nums.size();i++){        
            if(nums[i]>0 && nums[i]<=nums.size()){
               if(nums[i]!=nums[nums[i]-1]){   
  //suppose nums[i]is 3 then aapko second index ke number ko seap karna hain isliye nums[nums[i]-1]
                    swap(nums[i],nums[nums[i]-1]);
                    i--;
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i+1!=nums[i]){
                return i+1;
            }
        }
        return nums.size()+1;
    }