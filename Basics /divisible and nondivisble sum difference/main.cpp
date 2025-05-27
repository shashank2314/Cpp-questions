class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum1 = 0;
        int sum2 = (n*(n+1))/2;
        int k = m;
        while(k<=n){
            sum1+=k;
            k+=m;
        }
        return sum2-2*sum1;
    }
};