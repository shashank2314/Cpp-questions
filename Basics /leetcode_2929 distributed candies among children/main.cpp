class Solution {
public:
    
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        int lower = (n >= 2*limit) ? n-2*limit : 0;
        for(int i=lower;i<=limit;i++){
            if(n-i<0) break;
            if(n-i<=limit) ans+=1ll*(n-i+1);
            else ans+=1ll*(2*limit-(n-i)+1);
        }
        return ans;
    }
};