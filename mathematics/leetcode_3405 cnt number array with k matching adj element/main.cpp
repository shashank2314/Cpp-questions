class Solution {
public:
    int MOD = 1e9+7;
    int findpower(int base, int exp){
        if(exp==0) return 1;
        if(exp==1) return base;

        int ans = findpower(base,exp/2);
        return exp%2==0 ? (int)((1ll * ans * ans)%MOD) : (int)(((1ll * ans * ans)%MOD * base)%MOD);
    }
    int countGoodArrays(int n, int m, int k) {
        vector<long long> fact(n+1);
        fact[0] = 1;
        fact[1] = 1;
        for(int i=2;i<=n;i++){
            fact[i] = (i*fact[i-1])%MOD;
        }
        int fermantfact1 = findpower(fact[n-k-1],MOD-2);
        int fermantfact2 = findpower(fact[k],MOD-2);
        
        return (int)(((((fact[n-1] * fermantfact1)%MOD * fermantfact2)%MOD * m)%MOD * findpower(m-1,n-k-1))%MOD);
    }
};