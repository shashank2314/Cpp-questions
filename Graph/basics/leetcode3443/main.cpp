class Solution {
public:
    int maxDistance(string s, int k) {
        int maxi = 0;
        int ans = 0;
        int K = k;
        for(auto x:s){
            if(K>0){
                if(x=='S'||x=='W'){
                    K--;
                }
                ans++;
            }
            else{
                if(x=='S'||x=='W'){
                    ans--;
                }
                else{
                    ans++;
                }
            }
            maxi = max(maxi,ans);
        }
        ans = 0;
        K = k;
        for(auto x:s){
            if(K>0){
                if(x=='N'||x=='W'){
                    K--;
                }
                ans++;
            }
            else{
                if(x=='N'||x=='W'){
                    ans--;
                }
                else{
                    ans++;
                }
            }
            maxi = max(maxi,ans);
        }
        ans = 0;
        K = k;
        for(auto x:s){
            if(K>0){
                if(x=='S'||x=='E'){
                    K--;
                }
                ans++;
            }
            else{
                if(x=='S'||x=='E'){
                    ans--;
                }
                else{
                    ans++;
                }
            }
            maxi = max(maxi,ans);
        }
        ans = 0;
        K = k;
        for(auto x:s){
            if(K>0){
                if(x=='N'||x=='E'){
                    K--;
                }
                ans++;
            }
            else{
                if(x=='N'||x=='E'){
                    ans--;
                }
                else{
                    ans++;
                }
            }
            maxi = max(maxi,ans);
        }
        
return maxi;
    }
};