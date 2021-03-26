#include <iostream>
#include <string.h>
using namespace std;
class algoritmoX{
private: 
   int clave=117;
public:
   string cifrado(string & mensaje){ 
     string mensajeC=mensaje+ "  ";
     mensaje="";
      for (int i=0; i< clave/10; i++){
        for (int j=0; j< clave%10; j++){
        mensaje= mensaje+mensajeC[j*(clave/10)+i]; 
          }
      }    
     return mensaje;
   }
   string decifrado(string & mensajeC){ 
     string mensajeO="";
      for (int i=0; i<clave%10; i++){
        for (int j=0; j< clave/10; j++){
        mensajeO= mensajeO + mensajeC[j*(clave%10)+i]; 
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
  string mensajeCifrado= "Ahcs iyteedn o mg hs. ddvtouoes t fieinhdd retaaosst cnne fieinh";
  cout<<"Mensaje Cifrado= "<< mensajeCifrado <<endl;
  string mensajeOriginal= Receptor.decifrado(mensajeCifrado);
  cout<<"Mensaje original= "<<mensajeOriginal<<endl;
}
