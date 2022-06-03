int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum =accumulate(nums.begin(),nums.end(),0);
        int nsum = n*(n+1)/2;
        return nsum-sum;
    }