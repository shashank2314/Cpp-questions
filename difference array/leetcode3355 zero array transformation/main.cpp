class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size(),0);
        for(auto x:queries){
            int a = x[0];
            int b = x[1];
            diff[a]+=1;
            if(b<nums.size()-1){
                diff[b+1]-=1;
            }
        }
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=diff[i];
            if(sum<nums[i]) return false;
        }
        return true;
    }
};