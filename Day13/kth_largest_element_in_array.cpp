class Solution {
    
    
    int partition(vector<int>&nums, int low , int high){
        
        int pivot = nums[high];
        
        int index =low;
        
        for(int j=low;j<=high-1;j++){
            
            if(nums[j]>pivot){
                swap(nums[j],nums[index]);
                index++;
            }
            
        }
        swap(nums[index],nums[high]);
        return index;
    }
    
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int low=0;
        int high = n-1;
        
        while(low<=high){
            
        int i = partition(nums,low,high);            
           // cout<<i<<"\n";
            if(i==k-1){
                return nums[i];
            }else if(i<k-1){
                low = i+1;
            }else{
                high = i-1;
            }
            
            
        }
        
        return -1;
    }
};