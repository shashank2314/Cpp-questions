class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans = {};
        int i=0;
        while(i<n){
            if(nums[i]==key){
                int ind = max(0,i-k);
                int last = min(n-1,i+k);
                for(int j=ind;j<=last;j++){
                    if(ans.size()==0 || j>ans.back()){
                        ans.push_back(j);
                    }
                }
            }
            i++;
        }
        return ans;
    }
};