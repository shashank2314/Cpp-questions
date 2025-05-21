#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>> t;
	while(t-- > 0){
	    int X,Y,K;
	    cin>>X>>Y>>K;
	    int prev = 0;
	    if(X>=Y){
	        prev = min(X,K);
	        X-= min(X,K);
	    }
	    else{
	        prev = min(Y,K);
	        Y-= min(Y,K);
	    }
	    if(prev >= max(X,Y)){
	        cout<<"Alice"<<endl;
	    }
	    else{
	        cout<<"Bob"<<endl;
	    }
	    
	}
	return 0;
}
