class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string t = s;
        int n = s.size();
        char c = 'a';
        for(int i=0;i<n;i++){
            if(s[i]!='9'){
                if(c=='a'){
                    c = s[i];
                    s[i] = '9';
                }
            }
            if(c==s[i]){
                s[i] = '9';
            }
        }
        int maxi = stoi(s);
        s = t;
        c = 'a';
        if(s[0]=='1'){
            for(int i=1;i<n;i++){
                if(s[i]!='0' && s[i]!='1'){
                    if(c=='a'){
                        c = s[i];
                        s[i] = '0';
                    }
                }
                if(c==s[i]){
                    s[i] = '0';
                }
            }
        }
        else{
            c = s[0];
            s[0] = '1';
            for(int i=1;i<n;i++){
                if(c==s[i]){
                    s[i] = '1';
                }
            }
        }
        int mini = stoi(s);
        return maxi-mini;
    }
};