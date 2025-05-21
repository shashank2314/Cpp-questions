#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>> t;
	while(t-- > 0){
	    int N,X;
	    cin>>N>>X;
	    vector<int> permutation(N+1,0);
	    for(int i=1;i<=N;i++) permutation[i] = i;
	    vector<bool> check(N+1,false);
	    if(X<=N) check[X] = true;
	    for(int i=1;i<=N;i++){
	        int j = i ^ X;
	        if((i|X==X) && (j|X==X) && (j>=1 && j<=N) && !check[j]){
	            swap(permutation[i],permutation[j]);
	            check[j] = true;
	        }
	        check[i] = true;
	    }
	    for(int i=1;i<=N;i++){
	        cout<<permutation[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
