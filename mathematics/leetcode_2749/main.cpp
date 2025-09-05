class Solution {
public:
// good question
    vector<long long> arr;
    bool check(long long num,int c){
        int count = 0;
        for(int i=60;i>=0;i--){
            if(arr[i]<=num){
                count+=(num/arr[i]);
                num%=arr[i];
            }
            if(num==0){
                return count<=c;
            }
        }
        return false;
    }
    int makeTheIntegerZero(int num1, int num2) {
        if(num1<num2){
            return -1;
        }
        if(num1==0){
            return 0;
        }
        arr.resize(61);
        arr[0] = 1;
        long long temp=1;
        for(int i=1;i<=60;i++){
            temp*=2;
            arr[i] = temp;
        }
        for(int count = 1;count<=60;count++){
            long long ans = num1 - 1ll*num2*count;
            if(ans<count){
                return -1;
            }
            if(check(ans,count)){
                return count;
            } 
        }
        
        return -1;
    }
};