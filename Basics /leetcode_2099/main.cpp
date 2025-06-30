class Solution {
public:
    static bool sortf(pair<int,int> a,pair<int,int> b){
        return a.first>b.first;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> arr;
        int i=0;
        for(auto x:nums){
            arr.push_back({x,i++});
        }
        sort(arr.begin(),arr.end(),sortf);
        vector<int> ak;
        for(int i=0;i<k;i++){
            ak.push_back(arr[i].second);
        }
        sort(ak.begin(),ak.end());
        vector<int> ans;
        for(auto x:ak){
            ans.push_back(nums[x]);
        }
        return ans;
    }
};