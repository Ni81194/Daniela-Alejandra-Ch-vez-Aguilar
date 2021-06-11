#include<iostream>
#include <NTL/ZZ.h>
#include<cstdlib>
#include <vector>
#include <conio.h>
#include <cmath>
#include "funciones.h"
using namespace std;
using namespace NTL;

ZZ naive_exponentiation(ZZ num, ZZ e, ZZ mod){
    ZZ exp,i; exp=1;
    for(i=1;i<=e;i++){
        exp = division((num*exp),mod);
    }

    return exp;
}

ZZ right2left_binary_modexp(ZZ g, ZZ e, ZZ n){
  ZZ A=conv<ZZ>(1), S=g;
  while (e!=0){
	if (divi(e,conv<ZZ>(2))==1)
  	A=divi(A*S,n);
	e>>=1;
	if (e!=0)
  	S=divi(S*S,n);
  }
  return A;
}

ZZ left2right_binary_modexp(ZZ g, string e, ZZ n){
  ZZ A=conv<ZZ>(1);
  for (int i=t; i>0; i--){
	A=divi(A*A,n);
	if (e[t-i]=='1')
  	A=divi(A*g,n);
  }
  return A;
}

ZZ left2right_4ary_modexp(ZZ g, string e, ZZ n){
  ZZ G[16]; G[0]=ZZ(1);
  for (int i=1; i<=15; i++){
	G[i]=G[i-1]*g;
  }
  ZZ A=conv<ZZ>(1);
  for (int i=t; i>0; i--){
	A=left2right_binary_modexp(A, Num2Bits(conv<ZZ>(16),t),n);
	A=divi(A*G[e[t-i]-'0'],n);
  }
  return A;
}
ZZ expmod_fermat_euler(ZZ b, ZZ e, ZZ m){
  if (Euclides(b,m)==1){
	if (Fermat_primo(m, 3)){
    		return right2left_binary_modexp(b,divi(e,m-1),m);}
	return right2left_binary_modexp(b,divi(e,Euler_phi(m)),m);
  }
  return right2left_binary_modexp(b,e,m);
}
//OTROS ALGORITMOS:

const int tam = 3;
ZZ Resto_Chino(ZZ* ai, ZZ* pi) {

    ZZ X = conv<ZZ>(0), P = conv<ZZ>(1);
    ZZ Pi[tam],qi[tam],x0[tam];

    if (Primos_Entre_Si(pi, ZZ(tam)) == 1) {
        for (int i = 0; i < tam; i++) {
            P *= pi[i];
        }

        for (int i = 0; i < tam; i++) {
            Pi[i] = P / pi[i];
            qi[i] = inversa(Pi[i], pi[i]);
        }

        for (int i = 0; i < tam; i++) {
            x0[i] = divi(ai[i] * Pi[i] * qi[i], P);
        }

        for (int i = 0; i < tam; i++) {
            X += x0[i];
        }
        X = divi(X, P);
    }

    for (int i = 0; i < tam; i++) {
        cout << "P" << i + 1 << " = " << Pi[i] << endl;
    }
    for (int i = 0; i < tam; i++) {
        cout << "q" << i + 1 << " = " << qi[i] << endl;
    }
    for (int i = 0; i < tam; i++) {
        cout << "x" << i + 1 << " = " << x0[i] << endl;
    }
    cout << "X = " << X << " (mod " << P << ")" << endl;
    cout << "X = " << X << " + " << P << "k" << endl;
    return X;
}
ZZ Expmod_rchino(ZZ b, ZZ e, ZZ m){
  vector<ZZ>pyq=factores_phi(m);
  ZZ a1=right2left_binary_modexp(b,divi(e,pyq[0]-1),pyq[0]);
  ZZ a2=right2left_binary_modexp(b,divi(e,pyq[1]-1),pyq[1]);
  ZZ as[]={a1,a2};
  ZZ mods[]={pyq[0],pyq[1]};
  ZZ mod = Resto_Chino(as,mods);
  return mod;
}

ZZ Exponenciacion(ZZ a,ZZ p,ZZ n){
	ZZ r;// salida: r= modulo(pow(a, p) ,n);
	r=1;
	for (int i=1 ; i <= p;i++){
		r=modulo((r*a),n);
	}
	return r;
}

ZZ Exponenciacion2 (ZZ a,ZZ p,ZZ n){
	ZZ r; //salida: r= modulo(pow(a, p) ,n)
	ZZ t;
	if (p==0){
		return ZZ(1);
	}
	if (modulo(p,2)==0){
		t= Exponenciacion2 (a,p/2,n);
		return modulo(t*t,n);
	}
	t= Exponenciacion2 (a,(p-1)/2,n);
	return modulo(a*(modulo(t*t,n)),n);
}