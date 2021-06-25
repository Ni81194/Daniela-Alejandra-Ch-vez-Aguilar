#include<time.h>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <NTL/ZZ.h>
#include <Windows.h>
#include <fstream>
using namespace std;
using namespace NTL;
ZZ divi(ZZ a, ZZ n){
  ZZ r=a-((a/n)*n);
  if (r<0){
      if (n<0)
          return r-n;
  return r+n;
 }
   return r;
}

long long divi(long long a, long long n){
  long long r=a-((a/n)*n);
  if (r<0){
        if (n<0)
          return r-n;
  return r+n;
 }
   return r;
}
bool par(ZZ n){
    ZZ r=n-((n>>1)<<1);
    if (r==0) return true;
    return false;
}
vector<ZZ> Euclides_ext(ZZ a, ZZ b){//Euclides extendido
  ZZ x0=conv<ZZ>(1),y0=conv<ZZ>(0),x=conv<ZZ>(0),y=conv<ZZ>(1);
  while(b>0){
  ZZ aux=x;
  ZZ q=a/b;
  ZZ r=divi(a,b);
  x=x0-q*x;
  x0=aux;
  aux=y;
  y=y0-q*y;
  y0=aux;
  a=b;
  b=r;
  }
  ZZ result[]={a,x0,y0};
  vector<ZZ>p(result,result+3);
  return p;
}
ZZ Euclides(ZZ a, ZZ b){//mcd
  while(b>0){
  ZZ r=divi(a,b);
  a=b;
  b=r;
  }
  return a;
}
ZZ inversa(ZZ a, ZZ b){//función inversa (pregunta si el mcd es 1)
  vector<ZZ> dxy = Euclides_ext(a,b);
  ZZ mcd=dxy.at(0);
  ZZ inv=dxy.at(1);
  if(mcd==1){
  if (inv<0){
    return(divi(inv,b));
  }
  return inv;
  }
  ZZ r;
  r=0;
  return r;
}
ZZ inversa_1(ZZ a, ZZ b){//función inversa (asumiendo que el mcd es 1)
  ZZ inv=Euclides_ext(a,b).at(1);
  if (inv<0){
    return(divi(inv,b));
  }
  return inv;
}
ZZ Euler(int seed){ //NO LA LLAMA
  srand (seed);
  ZZ n=divi(conv<ZZ>(rand()),conv<ZZ>(40));
  return n*n+n+41;
}
ZZ exponenciacion_orig(ZZ num){ //NO LA LLAMA
ZZ exp;
exp = 2;

while(num != 1){
    exp <<= 1;
    num--;
    }
    return exp;
}
ZZ exponenciacion(ZZ e){
  ZZ A=conv<ZZ>(1);
  long cont=2;
  while (e!=0){
    if (!par(e))
      A<<=cont;
    e>>=1;
      cont++;
  }
  return A;
}
ZZ ExpMod(ZZ a, ZZ n, ZZ m){ //NO LA LLAMA
  ZZ res_mod;
  if (divi(n,conv<ZZ>(2))==1){
  res_mod=a;}
  else{
  res_mod=1;}
  ZZ mod=a;
  n/=2;
  while(n>0){
    mod=divi(mod*mod,m);
    if (divi(n,conv<ZZ>(2))==1){
      res_mod=divi(res_mod*mod,m);
    }
    n/=2;
  }
  return res_mod;
}

string Num2Str(ZZ a){
    ostringstream str;
    str<<a;
    return str.str();
}
string Num2Str(long a){
    ostringstream str;
    str<<a;
    return str.str();
}

ZZ Str2Num(string a){
    istringstream num(a);
    ZZ n;
    num>>n;
    return n;
}
long Str2Int(string a){
    istringstream num(a);
    long n;
    num>>n;
    return n;
}
ZZ Str2Num(char a){
    return ZZ(a-'0');
}
string Completar0s(ZZ n, int digs){
    string num = Num2Str(n);
    int n_ceros = digs-num.size();
    string ceros(n_ceros,'0');
    num = ceros+num;
    return num;
}
string Completar0s(int n, int digs){
    string num = Num2Str(n);
    int n_ceros = digs-num.size();
    string ceros(n_ceros,'0');
    num = ceros+num;
    return num;
}

bool Fermat_primo(ZZ n, int k){ //NO LA LLAMA
  for (int i=0; i<k; i++){
    ZZ a=divi(conv<ZZ>(rand()),n)+2;
    if (ExpMod(a, n-1, n)!=1)
      return false;
  }
  return true;
}

ZZ Euler_phi(ZZ n){ //NO LA LLAMA
    ZZ a,f,e;
a  =  n; f = 3; e = n;
bool tomar_primo;
  if (divi(n,conv<ZZ>(2))==0)
    e>>=1;
  while (f <= a){
    if (Fermat_primo(f,3)){
    tomar_primo = true;
    while (divi(a,f)==0){
      a = a / f;
      if (tomar_primo){
        e = e * (f -1) / f;
        tomar_primo = false;
        }
      }
    }
    f = f + 2;
  }
return e;
}
vector<ZZ> factores_phi(ZZ n){ //NO LA LLAMA
ZZ a  =  n, f = conv<ZZ>(3);
vector <ZZ> factors;
bool tomar_primo;
  if (divi(n,ZZ(2))==0){
    factors.push_back(ZZ(2));//un factor primo es 2
  }
  while (f <= a){
    if (Fermat_primo(f,3)){
    while (divi(a,f)==0){
      a = a / f;
      factors.push_back(f);
      }
    }
    f = f + 2;
  }
return factors;
}

ZZ phi_euler(ZZ n){ //NO LA LLAMA
  if (n==0)
    return conv<ZZ>(1);
  ZZ j=conv<ZZ>(0);
  for (ZZ i=conv<ZZ>(1); i<n; i++){
    if (Euclides(n,i)==1){
      j++;
  }}
  return j;
}
//////////////////////////
int ReadFile() { //NO LA LLAMA
	fstream datos;
	datos.open("datos.txt", ios::out);
	if (!datos) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!";
		datos.close();
	}
	return 0;
}

vector<ZZ> ReadFile(string nombre_buscado){ //NO LA LLAMA
	ifstream archivo_entrada;
	archivo_entrada.open("datos.txt");
	string linea;
	while(!archivo_entrada.eof())
        {archivo_entrada>>linea;
        int esp=linea.find(' ');
        string nombre = linea.substr(0,esp);
        ZZ n, e;
        int esp2=linea.find_first_of(' ',esp+1);
        int esp3=linea.find_first_of(' ',esp2+1);
        n= conv<ZZ>(Str2Num(linea.substr(esp,esp2)));
        e= conv<ZZ>(Str2Num(linea.substr(esp2,esp3)));
        if(nombre==nombre_buscado){
            ZZ claves[] = {n,e};
            vector<ZZ>cl(claves,claves+2);
            archivo_entrada.close();
            return cl;
        }
        else{
            vector<ZZ>cl(2,conv<ZZ>(0));
            archivo_entrada.close();
            return cl;
            }
    }
}
void WriteFile(string nombre, ZZ N, ZZ e, string correo){ //NO LA LLAMA
	ofstream file;
	file.open("datos.txt", ios::app);
	file<<"\n"<<nombre<<" "<<N<<" "<<e<<" "<<correo;
	file.close();
}
///////////////////////////////////////////
unsigned char* BinSeq(ZZ num){ //NO LA LLAMA
    unsigned char* pp = new unsigned char[NumBytes(num)];
    BytesFromZZ(pp, num, NumBytes(num));
    return pp;
}

string Num2Bits(ZZ num, int t){
 ostringstream bits;
 for (;t>=0;t--){
 if (num!=0){
    bits << (divi(num,conv<ZZ>(2)));
    num>>=1;
 }
/*else{
    bits << 0;
}*/
 }
 return bits.str();
}

////////////////////////////////
ZZ right2left_binary_modexp(ZZ g, ZZ e, ZZ n){
  ZZ A=conv<ZZ>(1), S=g;
  while (e!=0){
    if (!par(e))
      A=divi(A*S,n);
    e>>=1;
    if (e!=0)
      S=divi(S*S,n);
  }
  return A;
}
ZZ right2left_binary_exp(ZZ g, ZZ e){
  ZZ A=conv<ZZ>(1), S=g;
  while (e!=0){
    if (!par(e))
      A=A*S;
    e>>=1;
      S=S*S;
  }
  return A;
}
const int tam = 2;
bool Primos_Entre_Si(ZZ* Primos, ZZ tam) {

    for (int i = 0; i < tam; i++) {

        for (int j = i + 1; j < tam; j++) {
            if (Euclides(Primos[i], Primos[j]) != 1 || Primos[i] == Primos[j]) {

                //cout << Primos[i] << " y " << Primos[j] << " no son primos relativos" << endl;
                return false;
            }
        }
    }

    return true;
}
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

    /*for (int i = 0; i < tam; i++) {
        cout << "P" << i + 1 << " = " << Pi[i] << endl;
    }
    for (int i = 0; i < tam; i++) {
        cout << "q" << i + 1 << " = " << qi[i] << endl;
    }
    for (int i = 0; i < tam; i++) {
        cout << "x" << i + 1 << " = " << x0[i] << endl;
    }
    cout << "X = " << X << " (mod " << P << ")" << endl;
    cout << "X = " << X << " + " << P << "k" << endl;*/
    return X;
}
ZZ pyq[2];
ZZ Expmod_rchino(ZZ b, ZZ e, ZZ m){
  ZZ a1=right2left_binary_modexp(b,divi(e,pyq[0]-1),pyq[0]);
  ZZ a2=right2left_binary_modexp(b,divi(e,pyq[1]-1),pyq[1]);
  ZZ as[]={a1,a2};
  ZZ mods[]={pyq[0],pyq[1]};
  ZZ mod = Resto_Chino(as,mods);
  return mod;
}
////////////////////////////////////
ZZ bitz, exp_bitsminus1, expbits_minus1, expbits;
ZZ binary2ZZ(string binario){
    ZZ decimal, multiplicador = conv<ZZ>(1);
    for(int i=0;i<bitz;i++){
        char dig = binario[i];
        if(dig=='1'){
            decimal+=multiplicador;
        }
        multiplicador<<=1;
    }
    return decimal;
}
/////////////////////////////
ZZ seed_generator(ZZ bits)
{
    POINT P;
    GetCursorPos(&P);

    ZZ seed;
    seed = P.x * P.y +1;
    while(seed<exp_bitsminus1||seed>expbits_minus1){
        if(seed<exp_bitsminus1){
            seed<<=1;
        }
        else if(seed>expbits_minus1){
            seed = divi(seed,expbits_minus1);
        }
    }

    return seed;
}

ZZ random_blum_prime(ZZ bits){
    ZZ newnum;
    newnum = RandomBnd(expbits);
    while(newnum < exp_bitsminus1||divi(newnum,conv<ZZ>(4))!=3){
        newnum = RandomBnd(expbits);
    }
    return newnum;
}
ZZ random_numberBBS(ZZ bits){
    ZZ p,q,n,seed,nextRandNum;
    string resultado="";
    p = random_blum_prime(bits);
    q = random_blum_prime(bits);
    seed = seed_generator(bits);
    n = p*q;
    resultado += "1";
    while(bits != 1){
        nextRandNum = divi((seed*seed),n);
        seed = nextRandNum;
        resultado += Num2Str(par(nextRandNum));
        bits--;
    }
    return binary2ZZ(resultado);}

bool miller_rabin_orig(ZZ n,long t){ //NO LA LLAMA
    ZZ a,y,i,j,s,r;
    s=0;
    r=n-1;
    while(r>1 && par(r)){
        r>>=1;
        s++;
    }
    for(i=1;i<=t;i++){
        a=ZZ(2)+divi(RandomBnd(ZZ(NumBits(n))), n-3);
        y=right2left_binary_modexp(a,r,n);
        if(y!=1 && y!=n-1)
        {
            j=1;
            while(j<=s-1 && y!=n-1)
            {
                y=divi(y*y,n);
                if(y==1)return false;
                j++;
            }
            if(y!=n-1)return false;
        }
    }
    return true;
}
bool miller_rabin(ZZ n,long t){
    //if(par(n)&& n!=2) return false;//ahorrar trabajo si es par
    ZZ a,y,i,j,s,r;
    s=0;
    r=n-1;
    while(r>1 && par(r)){
        r>>=1;
        s++;
    }
    for(i=1;i<=t;i++){
        a=ZZ(2)+divi(RandomBnd(bitz), n-3);
        y=right2left_binary_modexp(a,r,n);
        if(y!=1 && y!=n-1)
        {
            j=1;
            while(j<=s-1 && y!=n-1)
            {
                y=divi(y*y,n);
                if(y==1)return false;
                j++;
            }
            if(y!=n-1)return false;
        }
    }
    return true;
}
bool MillerRabin(ZZ d, ZZ n){ //NO LA LLAMA
ZZ a = conv<ZZ>(2 + divi(conv<ZZ>(rand()),conv<ZZ>(n-4)));
ZZ x = ExpMod(a, d, n);
    if (x == 1  || x == n-1)
       return true;
    while (d != n-1)
    {
        x = divi((x*x),n);
        d *= 2;
        if (x == 1)      return false;
        if (x == n-1)    return true;
    }
    return false;
}

ZZ GenPrimo2(ZZ min, ZZ max){ //NO LA LLAMA
    srand (time(NULL));
    ZZ p;
    bool es_primo=false;
    while(!es_primo){
    p=divi(conv<ZZ>(rand()),max-min+1)+min;
    ZZ d = p-1;
    while (divi(d,conv<ZZ>(2)) == 0)
        d /= 2;
    bool primo;
    for (int i=0; i<3;i++){
        primo=MillerRabin(d,p);
    }
    es_primo=primo;
}
return p;
}
ZZ GenPrimo(long bits){
    ZZ p;
    p=random_numberBBS(bitz);
    bool es_primo=miller_rabin(p,3);
    cout<<p<<endl<<es_primo<<endl;
    while(!es_primo){
        p=random_numberBBS(bitz);
        cout<<p<<endl;
        es_primo=miller_rabin(p,3);
        cout<<es_primo<<endl;
    }
return p;
}
