
ZZ divi(ZZ a, ZZ n){
  ZZ r=a-((a/n)*n);
  if (r<0){
      if (n<0)
          return r-n;
  return r+n;
 }
   return r;
}
ZZ division(ZZ a, ZZ n){
  ZZ r=a-((a/n)*n);
  if (r<0){
      if (n<0)
          return r-n;
  return r+n;
 }
   return r;
}
ZZ modulo(ZZ a, ZZ n){
  ZZ r=a-((a/n)*n);
  if (r<0){
      if (n<0)
          return r-n;
  return r+n;
 }
   return r;
}
bool Fermat_primo(ZZ n, int k){
  for (int i=0; i<k; i++){
    ZZ a=divi(conv<ZZ>(rand()),n)+2;
    if (ExpMod(a, n-1, n)!=1)
      return false;
  }
  return true;
}

ZZ Euler_phi(ZZ n){
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

vector<ZZ> factores_phi(ZZ n){
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

ZZ phi_euler(ZZ n){
  if (n==0)
    return conv<ZZ>(1);
  ZZ j=conv<ZZ>(0);
  for (ZZ i=conv<ZZ>(1); i<n; i++){
    if (Euclides(n,i)==1){
      j++;
  }}
  return j;
}
string Num2Bits(ZZ num, int t){
 ostringstream bits;
 for (;t>=0;t--){
 if (num!=0){
    bits << (divi(num,conv<ZZ>(2)));
    num>>=1;
 }
else{
    bits << 0;
}
 }
 return bits.str();
}