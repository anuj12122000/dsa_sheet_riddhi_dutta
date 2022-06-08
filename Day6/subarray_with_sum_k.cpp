int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int count = 0;
    int sum = 0;
    mp[0]++; // ye isliye kara taake jo subarray 0th index se start
    // ho rahe hoon unke liye
    for (int num : nums)
    {
        sum += num;
        int rem = sum - k;
        if (mp.find(rem) == mp.end())
        {
        }
        else
        {
            count += mp[rem];
        }
        mp[sum]++;
    }
    return count;
}
