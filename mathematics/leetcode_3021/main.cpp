class Solution {
public:
    long long flowerGame(int n, int m) {
        return 1ll*((m+1)/2)*(n/2) + 1ll*((n+1)/2)*(m/2);// odd even case only 
    }
};