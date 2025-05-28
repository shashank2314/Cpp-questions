class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(),queries.end());
        priority_queue<int> maxheap;
        priority_queue<int,vector<int>,greater<int>> minheap;
        int count = 0;
        int i=0;
        int j=0;
        int n = nums.size();
        int m = queries.size();
        while(i<n){
            // increase i till that we have make 0 
            while(i<n && nums[i]==0){
                i++;
            }
            // skip that queries that dont affect i
            while(j<m && queries[j][0]<i && queries[j][1]<i){
                j++;
            }
            // push all queries that affect i in maxheap
            while(j<m && queries[j][0]<=i ){
                maxheap.push(queries[j][1]);
                j++;
            }
            // remove all queries from minheap that are not affect now i
            while(!minheap.empty() && minheap.top()<i){
                minheap.pop();
            }
            // use maxheap queries and increase count and check minheap size makes 0 at index i
            while(i<n && !maxheap.empty() && nums[i]>minheap.size()){
                int k = maxheap.top();
                if(k<i) return -1;
                count++;
                maxheap.pop();
                minheap.push(k);
            }
            // to check minheap have sufficient query to make 0 at nums[i]
            if(i<n && nums[i]<=minheap.size()){
                nums[i] = 0;
                i++;
            }
            else{
                // check it because of size or queries lost
                if(i<n){
                    return -1;
                }
            }

        }
        // return ans
        return queries.size()-count;
    }
};