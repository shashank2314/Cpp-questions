class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string j = s;
        int n = s.size();
        for(int i=1;i<n;i++){
            if(j[0]==j[i]){
                j[i] = '0';
            }
        }
        j[0] = '0';
        int mini = stoi(j);
        char c = 'a';
        for(int i=0;i<n;i++){
            if(s[i]!='9'){
                if(c=='a'){
                    c = s[i];
                    s[i] = '9';
                }
            }
            if(s[i]==c){
                s[i] = '9';
            }
        }
        int maxi = stoi(s);
        return maxi-mini;
    }
};