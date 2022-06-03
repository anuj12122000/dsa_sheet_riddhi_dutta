int lengthOfLongestSubstring(string s) {
        
        vector<int>mp(786,0);
        int res=0;
        int i=0;
        int j=0;
        int n = s.size();
        
        if(n==0){
            return 0 ;
        }
        
        while(j<n){
            
            mp[s[j]]++;
            
            if(mp[s[j]]>1){
                
                res = max(res,j-i);
                while(mp[s[j]]>1){
                    mp[s[i]]--;
                    i++;
                }
            }
            j++;
        }
        res=max(res,j-i);
        
        return res;
    }