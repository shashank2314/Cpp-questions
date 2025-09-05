class Solution {
public:
    static bool sortf(vector<int> a,vector<int> b){
        return a[0]<b[0] ? true : (a[0]==b[0]) ? (a[1]>=b[1]) : false; 
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),sortf);
        int count = 0;
        int n = points.size();
        for(int i=0;i<n;i++){
            int maxY = INT_MIN;
            for(int j=i+1;j<n;j++){
                if(points[i][1]>=points[j][1]){
                    if(maxY<points[j][1]){
                        maxY = points[j][1];
                        count++;
                    }
                }
            }
        }
        return count;
    }
};