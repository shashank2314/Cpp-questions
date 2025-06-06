class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start1 = 0;
        int end1 = nums.size()-1;
        int ans1 =-1;
        while(start1<=end1){
            int mid = start1 + (end1-start1)/2;
            if(nums[mid]==target){
                if(mid-1>=0){
                    if(nums[mid-1]<nums[mid]){
                        ans1 = mid;
                        break;
                    }
                    else{
                        end1 = mid-1;
                    }
                }
                else{
                    ans1 = mid;
                    break;
                }
            }
            else if(nums[mid]>target){
                end1 = mid-1;
            }
            else{
                start1 = mid+1;
            }
        }
        start1 = 0;
        end1 = nums.size()-1;
        int ans2 = -1;
        while(start1<=end1){
            int mid = start1 + (end1-start1)/2;
            if(nums[mid]==target){
                if(mid+1<nums.size()){
                    if(nums[mid+1]>nums[mid]){
                        ans2 = mid;
                        break;
                    }
                    else{
                        start1 = mid+1;
                    }
                }
                else{
                    ans2 = mid;
                    break;
                }
            }
            else if(nums[mid]>target){
                end1 = mid-1;
            }
            else{
                start1 = mid+1;
            }
        }
        return {ans1,ans2};
    }
};