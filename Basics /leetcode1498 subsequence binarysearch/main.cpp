class Solution {
public:
    int MOD = 1e9+7;
    int power(int &base,int exp){
        if(exp==1){
            return base;
        }
        if(exp==0){
            return 1;
        }
        int ans = power(base,exp/2) %MOD;
        return exp%2==0 ? (int)((1ll*ans*ans)%MOD) : (int)((((1ll*ans*ans)%MOD)*base)%MOD);
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int left = 0;
        int n = nums.size();
        int r = n-1;
        int result = 0;
        while(left<n && nums[left]*2<=target){
            int temp = target - nums[left];
            int l = left;
            int ans = l;
            while(l<=r){
                int mid = (l + r)/2;
                if(nums[mid]>temp){
                    r = mid-1;
                }
                else if(nums[mid]<=temp){
                    ans = mid;
                    l = mid+1;
                }
            }
            int base = 2;
            result+=power(base,ans-left);
            result%=MOD;
            left++;
        }
        return result;
    }
};