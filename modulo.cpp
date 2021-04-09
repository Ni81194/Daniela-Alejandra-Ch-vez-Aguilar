#include <iostream>
using namespace std;
int modulo(int a, int n){
  int q=a/n, r=a-(q*n);
  if (a==n){
  	return 0;
  }
  else{
  	if (a<0){
  		if(n>0){
    		q=q-1;
    		r=a-(q*n);
    		return r;
		}	
		else{
			q=q+1;
    		r=a-(q*n);
    		return r;
		}
  	}
  }
  return r;
}
int main() {
    cout<<"R:"<<modulo(-255,11)<<endl;
}
