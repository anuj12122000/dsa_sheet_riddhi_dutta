int findPlatform(int arr[], int dep[], int n)
    {
    	if(n==0){
    	    return 0 ;
    	}
    	int res = 1;
    	vector<pair<int,int>>dp;
    	for(int i=0;i<n;i++){
    	    dp.push_back({arr[i],dep[i]});
    	}
    	sort(dp.begin(),dp.end());
    	priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(dp[0].second);    	
    	for(int i=1;i<n;i++){
    	    if(pq.top()<dp[i].first){
    	        pq.pop();
    	        pq.push(dp[i].second);
    	    }else{
    	        pq.push(dp[i].second);
    	    }
    	}	
    	return pq.size();
    }

    // ye he gfg ke editorial waale approach
    int findPlatform(int arr[], int dep[], int n)
{
    // Insert all the times (arr. and dep.)
    // in the multiset.
    multiset<pair<int, char> > order;
    for (int i = 0; i < n; i++) {
 
        // If its arrival then second value
        // of pair is 'a' else 'd'
        order.insert(make_pair(arr[i], 'a'));
        order.insert(make_pair(dep[i], 'd'));
    }
 
    int result = 0;
    int plat_needed = 0;
 
    // Start iterating the multiset.
    for (auto it : order) {
 
        // If its 'a' then add 1 to plat_needed
        // else minus 1 from plat_needed.
        if (it.second == 'a')
            plat_needed++;
        else
            plat_needed--;
 
        if (plat_needed > result)
            result = plat_needed;
    }
    return result;
}


// ye he constant time approach 
//kyunki isme kara kya hain actually humne dekha ke max time 23:60 se upper nahe jaa
//sakta
int minPlatform(int arrival[], int departure[], int n)
{
 
    // as time range from 0 to 2359 in 24 hour clock,
    // we declare an array for values from 0 to 2360
    int platform[2361] = {0};
    int requiredPlatform = 1;
    for (int i = 0; i < n; i++) {
 
        // increment the platforms for arrival
        ++platform[arrival[i]];
 
         // once train departs we decrease the platform count
        --platform[departure[i] + 1];
    }
 
    // We are running loop till 2361 because maximum time value
    // in a day can be 23:60
    for (int i = 1; i < 2361; i++) {
 
        // taking cumulative sum of platform give us required
        // number of platform for every minute
        platform[i] = platform[i] + platform[i - 1];
        requiredPlatform = max(requiredPlatform, platform[i]);
    }
    return requiredPlatform;
}