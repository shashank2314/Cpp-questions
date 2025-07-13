class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int n = players.size();
        int j= trainers.size()-1;
        int count = 0;
        for(int i=n-1;(i>=0) && (j>=0);i--){
            if(players[i]>trainers[j]){
                continue;
            }
            else{
                count++;
                j--;
            }
        }
        return count;
    }
};