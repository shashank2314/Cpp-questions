class Solution {
public:
    bool ispal(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool check(long long num,int& k){
        string s = "";
        if(num%k==0) return false;
        while(num){
            char c = '0';
            c += (num%k);
            num/=k;
            s+=c;
        }
        if(ispal(s)){
            return true;
        }
        return false;
    }
    pair<long long,int> palindrome10(int dig,int cnt,int &k){
        int half = dig/2;
        string s = "";
        long long sum = 0;
        if(half){
            s+='1';
        }
        for(int i=1;i<half;i++){
            s+='0';
        }
        if(dig%2 == 0){
            long long num = stoll(s);
            long long last = num*10 -1;
            while(num<=last){
                string s1 = to_string(num);
                string rev1 = s1;
                reverse(rev1.begin(),rev1.end());
                string ans = s1 + rev1;
                long long checkdig = stoll(ans);
                if(check(checkdig,k)){
                    cnt--;
                    sum+=checkdig;
                }
                if(cnt==0){
                    return {sum,0};
                }
                num++;
            }
        }
        else{
            s +='0';
            long long num = stoll(s);
            long long last = num*10 -1;
            while(num<=last){
                string s1 = to_string(num);
                string sub = s1.substr(0,s1.size()-1);
                reverse(sub.begin(),sub.end());
                string ans = s1 + sub;
                long long checkdig = stoll(ans);
                if(check(checkdig,k)){
                    cnt--;
                    sum+=checkdig;
                }
                if(cnt==0){
                    return {sum,0};
                }
                num++;
            }
        }
        return {sum,cnt};
    }
    long long kMirror(int k, int n) {
        long long ans = 0;
        vector<long long> digit1 = {1,2,3,4,5,6,7,8,9};
        for(auto x:digit1){
            if(check(x,k)){
                ans+=x;
                n--;
                if(n==0) return ans;
            }
        }
        int dig = 2;
        while(dig<=20){
            auto [a,b] = palindrome10(dig,n,k);
            ans += a;
            n=b;
            if(n==0){
                return ans;
            }
            dig++;
        }
        return 0;
    }
};