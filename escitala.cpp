#include <iostream>
#include <string.h>
using namespace std;
class algoritmoX{
private: 
   int a=6,b=3;
public:
   string cifrado(string & mensaje){ 
     string mensajeC=mensaje+ "  ";
     mensaje="";
      for (int i=0; i< a; i++){
        for (int j=0; j< b; j++){
        mensaje= mensaje+mensajeC[j*(a)+i]; 
          }
      }    
     return mensaje;
   }
   string decifrado(string & mensajeC){ 
     string mensajeO="";
      for (int i=0; i<b; i++){
        for (int j=0; j< a; j++){
        mensajeO= mensajeO + mensajeC[j*(b)+i]; 
      }
      }
     return mensajeO;
   }
};
int main() {
  algoritmoX Emisor; 
  algoritmoX Receptor;
  string mensaje = "hola como estAn";
  cout<<"Mensaje= "<<mensaje <<endl;
  string mensajeCifrado= Emisor.cifrado(mensaje); 
  cout<<"Mensaje Cifrado= "<< mensajeCifrado <<endl;
  string mensajeOriginal= Receptor.decifrado(mensajeCifrado);
  cout<<"Mensaje original= "<<mensajeOriginal<<endl;
}
