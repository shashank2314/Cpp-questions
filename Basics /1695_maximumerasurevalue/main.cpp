class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = -1;
        int right = 0;
        int sum = 0;
        unordered_map<int,bool> mp;
        int n = nums.size();
        int maxi = 0;
        while(right<n){
            if(mp.find(nums[right])!=mp.end()){
                left++;
                sum-=nums[left];
                mp.erase(nums[left]);
            }
            else{
                sum+=nums[right];
                mp[nums[right]] = true;
                right++;
                maxi = max(sum,maxi);
            }
        }
        return maxi;
    }
};