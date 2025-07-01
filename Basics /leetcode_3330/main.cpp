class Solution {
public:
    int possibleStringCount(string word) {
        char prev = ' ';
        int count = 1;
        for(auto x:word){
            if(prev==x){
                count++;
            }
            else{
                prev = x;
            }
        }
        return count;
    }
};