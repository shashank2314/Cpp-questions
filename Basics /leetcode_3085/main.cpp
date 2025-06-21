class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(auto x:word){
            freq[x-'a']++;
        }
        sort(freq.begin(),freq.end());
        int n = word.size();
        int ans = 0;
        int mini = n;
        int left = 0;
        int right = 1;
        int i = 0;
        for( i=0;i<26;i++){
            if(freq[i]!=0){
                break;
            }
        }
        int r = i+1;
        int leftrest = 0;
        cout<<"n"<<n<<endl;
        if(i<26) ans+=freq[i];
        while(i<26){
            while(r<26 && (abs(freq[r]-freq[i]) <= k)){
                ans+=freq[r];
                r++;
            }
            int rightleft = 26-r;
            int rightsum = n- ans;
            int delright = rightsum - (freq[i]+k)*rightleft;
            
            mini = min(mini,delright + leftrest);
            n-=freq[i];
            leftrest+=freq[i];
            ans-=freq[i];
            i++;
        }
        return mini;
    }
};