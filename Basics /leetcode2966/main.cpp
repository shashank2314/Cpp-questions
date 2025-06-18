class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<int> num = nums;
        sort(num.begin(),num.end());
        int n = num.size();
        vector<vector<int>> ans(n/3);
        int a = 0;
        for(int i=2;i<n;i++){
            if(num[i]-num[i-2]<=k){
                ans[a].push_back(num[i-2]);
                ans[a].push_back(num[i-1]);
                ans[a].push_back(num[i]);
                a++;i+=2;
            }
            else{
                return {};
            }
        }
        return ans;
    }
};