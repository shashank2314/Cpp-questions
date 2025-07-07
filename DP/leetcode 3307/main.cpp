class Solution {
public:
    int solverec(int i,long long reqlen,long long k, vector<int>& operations){
        if(k==1){
            return 0;
        }
        if(k<=reqlen/2){
            return solverec(i-1,reqlen/2,k,operations);
        }
        else{
            if(operations[i]==0){
                return solverec(i-1,reqlen/2,k-reqlen/2,operations);
            }
            else{
                return 1+solverec(i-1,reqlen/2,k-reqlen/2,operations);
            }
        }
    }
    char kthCharacter(long long k, vector<int>& operations) {
        long long reqleng = 1;
        if(k==1) return 'a';
        int n = operations.size();
        for(int i=0;i<n;i++){
            reqleng*=2;
            if(reqleng>=k){
                return (char)('a' + (solverec(i,reqleng,k,operations)%26));
            }
        }
        return 'a';
    }
};

// lovable question