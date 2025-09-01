class Solution {
public:
    #define p pair<double,pair<int,int>> 
    double maxAverageRatio(vector<vector<int>>& c, int e) {
        priority_queue<p> pq;
        int n = c.size();
        double sum = 0;
        for(auto x:c){
            int a = x[0];
            int b = x[1];
            pq.push({((double)(b-a))/((1ll*b*(b+1))),{a,b}});
            sum+=((double)a/b);
        }
        for(int i=0;i<e;i++){
            p x = pq.top();
            pq.pop();
            int a = x.second.first;
            int b = x.second.second;
            double c = x.first;
            sum+=c;
            a++;
            b++;
            pq.push({((double)(b-a))/((1ll*b*(b+1))),{a,b}});
        }
        return sum/n;
    }
};