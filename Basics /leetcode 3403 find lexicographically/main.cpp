class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        char c = word[0];
        int i = 0;
        int k = i;
        int wordlength = word.size();
        int maxlength = wordlength - numFriends + 1;
        string ans = word.substr(0,maxlength);
        for(int i=1;i<wordlength;i++){
            int k = 0;
            while(k<maxlength && k+i<wordlength){
                if(word[k+i]<ans[k]){
                    break;
                }
                else if(word[k+i]>ans[k]){
                    ans = word.substr(i,min(maxlength,wordlength-i));
                    break;
                }
                k++;
            }
        }
        return ans;   
    }
};