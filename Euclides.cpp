#include <iostream>
using namespace std; 

int Euclides(int a, int b){
	if (a%b==0){
		return b;
	}
	else{
		int aux=b;
		b= a%b;
		a=aux;
		Euclides (a,b);
	}
	
}
int EuclidesExtendido(int a, int b){
	int r1=a, r2=b, r;
	int s1=1, s2=0, s;
	int t1=0,t2=1,t;
	while(r2>0){
		int q=r1/r2;
		r= r1-q*r2;
		r1=r2; 
		r2=r;
		
		s=s1-q *s2;
		s1=s2;
		s2=s;
		
		t=t1-q*t2;
		t1=t2;
		t2=t;
		
	}
    //cout<<"Euclides "<<"("<<a<<","<<b<<") :"<<r1<<endl;

	cout<<"x:"<<s1<<endl;
	//cout<<"y:"<<t1<<endl;
}
int main() {
	cout<<Euclides(4864, 3458)<<endl;
	cout<<Euclides(25, 26)<<endl;
	cout<<Euclides(11, 26)<<endl;
	cout<<Euclides(3, 26)<<endl;
	//EuclidesExtendido(161,28);
	//EuclidesExtendido(250,111);
	//EuclidesExtendido(7, 26);
    
}
