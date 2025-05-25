class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        for(auto x:words){
            mp[x]++;
        }
        int ans = 0;
        for(auto x:mp){
            string k = x.first;
            if(k[0]!=k[1]){
                swap(k[0],k[1]);
                if(mp[k]>0){
                    ans+=(min(mp[x.first],mp[k])*2);
                }
            }
            else{

                ans += ((x.second/2)*4);
            }
        }
        for(auto x:mp){
            if((x.first[0]==x.first[1]) && (x.second%2==1)){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};