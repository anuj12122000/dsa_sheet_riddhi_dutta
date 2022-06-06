  int maxProduct(vector<int>& nums) {

      // i wasn't able to solve it , so i saw its solution from discuss
      // i completely didn't observed it that -ve * -ve is positive
      // https://leetcode.com/problems/maximum-product-subarray/discuss/1608800/C%2B%2B-or-Discussion-in-detail-or-Easy-to-understand


        // maintain two vectors for the the current minimum and the current maximum
        int n = nums.size();
        if(n==0){
            return 0 ;
        }
        vector<int>max_dp(n,0);
        vector<int>min_dp(n,0);

        max_dp[0]=nums[0];
        min_dp[0]=nums[0];

        for(int i=1;i<n;i++){

            if(nums[i]<0){

                max_dp[i] = max(nums[i],min_dp[i-1]*nums[i]);
                min_dp[i]=min(nums[i],max_dp[i-1]*nums[i]);

            }else{

                max_dp[i] = max(nums[i],nums[i]*max_dp[i-1]);
                min_dp[i]=min(nums[i],nums[i]*min_dp[i-1]);

            }


        }

        return *max_element(max_dp.begin(),max_dp.end());
    }