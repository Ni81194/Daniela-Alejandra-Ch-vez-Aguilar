#include <iostream>
#include <string>
#include <sstream>
#include "algebra.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

string alfabeto="abcdefghijklmnopqrstuvwxyz ";
class RSA {
  ZZ d,p,q,oN;
  public:
  ZZ e,n;
  RSA(long bits){
    Generar_claves(bits);
    cout<<"p:"<<p<<" q:"<<q<<" n:"<<n<<" oN:"<<oN<<" e:"<<e<<" d:"<<d<<endl;
  }
  RSA(ZZ e, ZZ n){
    this->e=e;
    this->n=n;
  }
  string cifrado(string m)
    {   ostringstream c;
        long num_dig=Num2Str(alfabeto.size()-1).size();
        long k=Num2Str(n).size()-1;
        while(divi((m.size()*num_dig),k)!=0)
            m+=' ';
            //cout<<k<<" "<<m<<endl;
        for (long i=0; i<m.size(); i++){
        long l=alfabeto.find(m[i]);
        c<<Completar0s(l,num_dig);
        }
        string C=c.str();
        //cout<<C<<endl;
        string Cifrado="";
        for (long i=0; i<C.size(); i=i+k){
            string bloque=C.substr(i,k);
            //cout<<bloque<<endl;
            ZZ cypher=Expmod_rchino(Str2Num(bloque),e,n);
            Cifrado+= Completar0s(cypher,k+1);
        }
        //cout<<Cifrado<<endl;
        return Cifrado;
    }
  string descifrado(string m)
    {   string Descifrado="",D="";
        long long num_dig=Num2Str(alfabeto.size()-1).size();
        long long k=Num2Str(n).size();
        for (long long i=0; i<m.size(); i=i+k){
            //cout<<"k:"<<k<<" "<<D<<endl;
            string bloque=m.substr(i,k);
            //cout<<"i:"<<i<<" "<<bloque<<endl;
            ZZ decode=Expmod_rchino(Str2Num(bloque),d,n);
            D+= Completar0s(decode,k-1);
        }
        //cout<<"k:"<<k<<" "<<D<<endl;
        for (long long i=0; i<D.size(); i=i+num_dig){
            string bloque=D.substr(i,num_dig);
            long long pos=Str2Int(bloque);
            char a=alfabeto[pos];
            Descifrado+=a;
        }
        return Descifrado;
    }
  void Generar_claves(long bits){
    bitz=ZZ(bits);
    exp_bitsminus1=exponenciacion(bitz-1);
    expbits=exp_bitsminus1<<1;
    expbits_minus1=expbits-1;
    pyq[0]=p=GenPrimo(bits);//Str2Num("");
    pyq[1]=q=GenPrimo(bits);//Str2Num("");
    while (p==q){
      q=GenPrimo(bits);
    }
    n=p*q;//Str2Num("");
    oN=(p-1)*(q-1);
    e=divi(random_numberBBS(bitz),oN);//Str2Num("");
    ZZ ee=Euclides(e,oN);
    while(ee!=1){
      e=divi(random_numberBBS(bitz),oN);
      ee=Euclides(e,oN);
    }
    d=inversa_1(e,oN);//Str2Num("");
  }
};

int main()
{ZZ e,n;
e=Str2Num("");
n=Str2Num("");
  RSA Receptor(1024);
  RSA Emisor(Receptor.e, Receptor.n);
  string m="its high noon somewhere in the world";
  string m_C=Emisor.cifrado(m);
  string m_D=Receptor.descifrado(m_C);
  cout<<m_C<<endl;
  cout<<m_D<<endl;
ZZ a,b,c;
a=25909,b=139,c=2840;
  //cout<<miller_rabin(Str2Num("102639592829741105772054196573991675900716567808038066803341933521790711307779"),4);
}
