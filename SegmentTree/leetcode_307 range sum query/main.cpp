class NumArray {
public:
    vector<int> segarr;
    int sz;
    void updateseg(int& ind,int& val,int i,int l,int r){
        if(l==r){
            segarr[i] = val;
            return;
        }
        int mid = (l+r)/2;
        if(ind<=mid){
            updateseg(ind,val,2*i+1,l,mid);
        }
        else{
            updateseg(ind,val,2*i+2,mid+1,r);
        }
        segarr[i] = segarr[2*i+1] + segarr[2*i+2];
    }
    void CreateSegmentTree(int i,int l,int r,vector<int>& nums){
        if(l==r){
            segarr[i] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        CreateSegmentTree(2*i+1,l,mid,nums);
        CreateSegmentTree(2*i+2,mid+1,r,nums);
        segarr[i] = segarr[2*i+1] + segarr[2*i+2];
    }
    int sumSeg(int i,int l,int r,int &left,int &right){
        if(left>r || right<l){
            return 0;
        }
        if(l>=left && r<=right){
            return segarr[i];
        }
        int mid = (l+r)/2;
        return sumSeg(2*i+1,l,mid,left,right) + sumSeg(2*i+2,mid+1,r,left,right);
    }
    NumArray(vector<int>& nums) {
        segarr.resize(4*nums.size());
        sz = nums.size();
        int i=0;
        CreateSegmentTree(i,0,nums.size()-1,nums);
    }
    
    void update(int index, int val) {
        int i = 0;
        updateseg(index,val,i,0,sz-1);
    }
    
    int sumRange(int left, int right) {
        return sumSeg(0,0,sz-1,left,right);
    }
};

