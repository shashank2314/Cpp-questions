class Solution {
public:
    bool solve(int &mid,vector<int>& nums, int p){
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=mid){
                p--;
                i++;
            }
        }
        if(p<=0) return true;
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n-1];
        int ans = right;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(solve(mid,nums,p)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;

    }
};