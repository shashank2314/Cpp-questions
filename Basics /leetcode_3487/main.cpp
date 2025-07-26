class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> s ;
        int sum = nums[0];
        for(auto x:nums){
            if(x>=0){
                sum = 0;
            }
            if(sum!=0){
                sum = max(x,sum);
            }
            s.insert(x);
        }
        for(auto x:s){
            if(x>0)sum+=x;
        }
        return sum;
    }
};