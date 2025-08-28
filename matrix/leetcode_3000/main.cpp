class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long diag = 0;
        long long area = 0;
        for(auto d:dimensions){
            int w = d[0];
            int h = d[1];
            if(w*w + h*h >diag){
                diag = w*w + h*h;
                area = w*h;
            }
            else if(w*w + h*h ==diag){
                area = max(area,1ll*w*h);
            }
        }
        return area;
    }
};