class FindSumPairs {
public:
    unordered_map<int,int> mp;
    vector<int> num2;
    vector<int> num1;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num2 = nums2;
        num1 = nums1;
        for(auto x:nums2){
            mp[x]++;
        }
    }
    
    void add(int index, int val) {
        mp[num2[index]]--;
        num2[index]+=val;
        mp[num2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto x:num1){
            if(mp.find(tot-x)!=mp.end()){
                ans+=mp[tot-x];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */