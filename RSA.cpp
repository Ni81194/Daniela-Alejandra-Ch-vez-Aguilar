#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>
using std::istringstream;
using namespace std;

//INT CLAVES
//MODULO
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

//FUNCION INVERSA
int inversa(int a, int b){
	int r1=a, r2=b, r;
	int s1=1, s2=0, s;
	int t1=0,t2=1,t;
	while(r2>0){
		int q=r1/r2;
		r= r1-q*r2;
		r1=r2; 
		r2=r;
		s1=s2;
	}
	return s1;
}
//EXPONENCIACION MODULAR 
int exponenciacion_modular(int base, int exponente, int N){
	int x= base;
	int m=exponente;
	int m_mod2;
	
	int elev;
	int acumulador;
	int res;
	while ( m >=1 ){
		m_mod2=(modulo(m,2));
		if(m== exponente && m_mod2==1 ){
			elev=x;
			acumulador=x;
			res=x;
			m=m/2;
		}
		else if (m_mod2==1){
			elev=modulo(elev*elev,N);
			acumulador=x*elev;
			res=modulo(acumulador,N);
			m=m/2;
		}
		else{
			elev=modulo(elev*elev,N);
			m=m/2;	
		}
		/*
		cout<<endl;
		cout<<elev<<endl;
		cout<<acumulador<<endl;
		cout<<res<<endl; */
	}
	//<<"respuesta final:"<<res;
	return res;
}

//CONVERSION (STRING - INT )
int string_a_int(string entrada){
  istringstream cadenaEntrada( entrada );
  int entero;
  cadenaEntrada >>  entero ;
  cout<< "\n int: " << entero<<endl;
  return entero;
}


//CLASE 

class RSA{
private: 
   int p=7;
   int q=13;
public:
	int N=p*q;
	int N1=(p-1)*(q-1);
	int e=5;
	int d=inversa(e,N1);
	int clavePublica= e;
	int clavePrivada= d;
	
	//FUNCION CIFRADO
	int cifrar(int m){
		//int c = modulo(pow(m,clavePublica), N);
		int c= exponenciacion_modular(m,clavePublica,N);
  		return c;
	}	

	//FUNCION DESCIFRADO
	int descifrar (int c){
		//int d = modulo(pow(c,clavePrivada), N);
		int D= exponenciacion_modular(c,29,N);
  		return D;
	}
 
};
int main () {
	RSA Emisor; 
	RSA Receptor;
	
	int mensaje= 48;
	cout<<"Mensaje= "<<mensaje <<endl;
	
	int mensajeCifrado= Emisor.cifrar(mensaje); 
  	cout<<"Mensaje Cifrado= "<< mensajeCifrado <<endl;
  	
  	int mensajeOriginal= Receptor.descifrar(mensajeCifrado);
  	cout<<"Mensaje original= "<<mensajeOriginal<<endl;

}
