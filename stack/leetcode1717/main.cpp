class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int n = s.size();
        int ans = 0;
        if(x>y){
            for(int i=0;i<n;i++){
                if(!st.empty() && st.top()=='a' && s[i]=='b'){
                    
                    st.pop();
                    ans+=x;
                }
                else{
                    st.push(s[i]);
                }
            }
            s = "";
            while(!st.empty()){
                s+=st.top();
                st.pop();
            }
            n = s.size();
            for(int i=0;i<n;i++){
                if(!st.empty() && st.top()=='a' && s[i]=='b'){
                    st.pop();
                    ans+=y;
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(!st.empty() && st.top()=='b' && s[i]=='a'){

                    st.pop();
                    ans+=y;
                }
                else{
                    st.push(s[i]);
                }
            }
            s = "";
            while(!st.empty()){
                s+=st.top();
                st.pop();
            }
            n = s.size();
            for(int i=0;i<n;i++){
                if(!st.empty() && st.top()=='b' && s[i]=='a'){
                    st.pop();
                    ans+=x;
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        return ans;
    }
};