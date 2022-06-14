 int maxLen(int arr[], int n)
    {
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                arr[i]=-1;
            }
        }
        unordered_map<int,int>mp;
        int res=0;
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+= arr[i];
            if(sum==0){
                res=i+1;
            }
            if(mp.find(sum)!=mp.end()){
                if(res<i-mp[sum]){
                    res = i-mp[sum];
                }
            }else{
                mp[sum]=i;
            }

        }
        return res;
    }s