class Solution {
public:
    bool static sortf(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),sortf);
        priority_queue<int,vector<int>,greater<int>> pq;
        int count =0;
        int prev = 0;
        int n = events.size();
        int i=0;
        while(i<n){
            if(pq.empty() && prev<events[i][0]){
                prev = events[i][0];
            }
            while(i<n && prev==events[i][0]){
                pq.push(events[i][1]);
                i++;
            }
            if(!pq.empty() && pq.top()>=prev){
                prev++;
                pq.pop();
                count++;
            }
            while(!pq.empty() && pq.top()<prev){
                pq.pop();
            }
        }
        while(!pq.empty()){
            if(pq.top()>=prev){
                prev++;
                pq.pop();
                count++;
            }
            else{
                pq.pop();
            }
        }
        return count;
    }
};