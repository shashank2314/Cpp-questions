class Solution {
public:
    char mini(vector<int> freq){
        for(int i=0;i<26;i++){
            if(freq[i]) return 'a'+i;
        }
        return 'a';
    }
    string robotWithString(string s) {
        string ans = "";
        stack<char> st;
        vector<int> freq(26,0);
        for(auto x:s){
            freq[x-'a']++;
        }
        for(auto x:s){
            st.push(x);
            freq[x-'a']--;
            while(!st.empty() && st.top()<=mini(freq)){
                ans+=st.top();
                st.pop();
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};