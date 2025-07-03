class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while(k>s.size()){
            string temp = s;
            int i=0;
            for(auto x:temp){
                char c = x + 1;
                temp[i++] = c;
            }
            s+=temp;
        }
        return s[k-1];
    }
};