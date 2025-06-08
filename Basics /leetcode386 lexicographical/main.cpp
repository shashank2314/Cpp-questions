class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int i = 1;
        int num = i;
        vector<int> ans;
        while(i <= n ){
            ans.push_back(num);
            if(num*10<=n){
                num*=10;
            }
            else{
                if(num>=n){
                    num/=10;
                }
                num++;
                while(num%10==0){
                    num/=10;
                }
            }
            i++;
        }
        return ans;
    }
};