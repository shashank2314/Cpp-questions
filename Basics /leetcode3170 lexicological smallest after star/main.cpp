class Solution {
public:
    void removelargeindexofsmallelem(vector<vector<int>> &freq,string &s){
        for(int i=0;i<26;i++){
            if(freq[i].size()){
                int k = freq[i].back();
                s[k] = '_';
                freq[i].pop_back();
                break;
            }
        }
    }
    string clearStars(string s) {
        vector<vector<int>> freq(26);
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='*') freq[s[i]-'a'].push_back(i);
            else{
                removelargeindexofsmallelem(freq,s);
            }
        }
        string ans = "";
        for(auto x:s){
            if(x!='*' && x!='_') ans+=x;
        }
        return ans;
    }
};