class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        int i=0;
        for(auto word:words){
            if(word.find(x)!=-1) ans.push_back(i);
            i++;
        }
        return ans;
    }
};