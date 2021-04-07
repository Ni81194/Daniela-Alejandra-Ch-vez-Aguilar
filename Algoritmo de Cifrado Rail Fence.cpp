#include <iostream>
#include <string.h>
using namespace std;
class algoritmoX{
private: 
   int clave=3;
public:
   string cifrado(string &mensaje){ 
     int largo=mensaje.size();
     int salto=0,cont=1;
     string mensajeC=mensaje;
     mensaje="";
      for (int i=0; i< clave; i++){
      	for(int j=i; j<largo; j=j+salto){
      	mensaje=mensaje+mensajeC[j];
        if(clave-i==1 || clave-i==clave){
        	salto=(2*clave)-2;
		}
		else {
			if (clave%2!=0 && i==(clave-1)/2){//el del medio para las claves impares
				salto=((i+1)*2)-2;
			}
			else {// los demas en clave par o impar 
			if(cont==1){
					salto= 2*(clave-i)-2;
					cont=0;
				}
			else{
					salto= 2*i;
					cont=1;
				}
			}
		}
		
      }    }
       return mensaje;
   }
   string decifrado(string & mensajeC){
     int largo=mensajeC.size();
     int salto=0,cont=1,x=0;
     string mensajeO=mensajeC;
      for (int i=0; i< clave; i++){
      	for(int j=i; j<largo; j=j+salto){
      	mensajeO[j]=mensajeC[x++]; 
        if(clave-i==1 || clave-i==clave){
        	salto=(2*clave)-2;
		}
		else {
			if (clave%2!=0 && i==(clave-1)/2){
				salto=((i+1)*2)-2;
			}
			else {
			if(cont==1){
					salto= 2*(clave-i)-2;
					cont=0;
				}
			else{
					salto= 2*i;
					cont=1;
				}
			}
		}
		
      }    }
       return mensajeO;
   }

};
int main() {
  algoritmoX Emisor; 
  algoritmoX Receptor;
  string mensaje = "Hola como estan";
  cout<<"Mensaje= "<<mensaje <<endl;
  string mensajeCifrado= Emisor.cifrado(mensaje); 
  cout<<"Mensaje Cifrado= "<< mensajeCifrado <<endl;
  string mensajeOriginal= Receptor.decifrado(mensajeCifrado);
  cout<<"Mensaje original= "<<mensajeOriginal<<endl;
}
