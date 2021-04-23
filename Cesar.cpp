#include<iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
using namespace std;
///FUNCION MODULO
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
//CLASE CIFRADO CESAR
class algoritmoX{
private: 
   int clave=5;
   string abc="abcdefghijklmnopqrstuvwxyz";
public:
	//FUNCION CIFRADO
	string cifrar(string cadena){
    	string mensajeC;
  		for (int i = 0; i < cadena.size(); ++i) {
  			int aux= abc.find( cadena[i] ) ;
  			aux+=clave;
  			
  			if (cadena[i]==' '){
  				//mensajeC.append(1, ' ');
  				continue;
			  }
			else if (aux>25){
				mensajeC.append(1,  abc[modulo(aux,26)]); // usando modulo positivo
			}
			else {
				mensajeC.append(1,  abc[aux]);
			}

  		}
  		
  		return mensajeC;
	}	

	//FUNCION DESCIFRADO
	string descifrar (string cadena){
  		string mensajeD;
  		for (int i = 0; i < cadena.size(); ++i) {
			int aux= abc.rfind( cadena[i] ) ;
			aux-=clave;
			if (cadena[i]==' '){
				mensajeD.append(1,' ');
			}
			else if(aux<0){
				mensajeD.append(1,  abc[modulo(aux,26)]);
			}
  			else{
  				mensajeD.append(1,  abc[aux]);
			  }
  		}
  		return mensajeD;
	}
 
};


int buscar( string palabra, char caracter){
  int cont = 0;
  for (int i=0;i<palabra.size();i++){ 
             if ( palabra[i] == caracter ) { 
               cont++;
             } 
    }
    return cont;
}

char letra_mas_usada(string palabra){
int mayor, menor,aux;
char letra;
mayor= buscar (palabra, palabra[0]);
  
  for (int i=0; i<palabra.size();i++){
    menor= buscar (palabra, palabra[i+1]);
    	if (mayor <= menor){ 
        aux=mayor;
        mayor=menor;
        menor=mayor;
      	}  
    	if(buscar(palabra,palabra[i])== mayor) {
  		letra=palabra[i];
  		}
  }
  return letra;
}


void criptoanalisis(string mensajeC){
	string abc="abcdefghijklmnopqrstuvwxyz"; //  e=4 , a=0 , o=14
	string mensajeD;
	char letra;
	int clave;
  		for (int i = 0; i < mensajeC.size(); ++i) {
 
			// Letra que mas se repite:
			
			letra= letra_mas_usada(mensajeC);
			
			//POSIBLES CASOS:
			clave= 26- abc.find("e") + abc.find( letra );
            //clave= 26- abc.find("a") + abc.find( letra );
            //clave= 26- abc.find("o") + abc.find( letra );
            //clave= 26- abc.find("s") + abc.find( letra );
            //clave= 26- abc.find("t") + abc.find( letra );
            
            //clave=   abc.find( letra )- abc.find("e") ;
            //clave=   abc.find( letra )- abc.find("a") ;
            //clave=   abc.find( letra )- abc.find("o") ;
            //clave=   abc.find( letra )- abc.find("s") ;
            //clave=   abc.find( letra )- abc.find("t") ;

			
			int aux= abc.rfind( mensajeC[i] ) ;
			aux-=clave;
			if (mensajeC[i]==' '){
				mensajeD.append(1,' ');
			}
			else if(aux<0){
				mensajeD.append(1,  abc[modulo(aux,26)]);
			}
  			else{
  				mensajeD.append(1,  abc[aux]);
			  }
  		}
  		cout<<"El mensaje encriptado con clave "<<clave <<" es:"<< mensajeD<<endl;
}


int main()
{
	algoritmoX Emisor; 
	algoritmoX Receptor;
	//string mensaje= "hola amigos como estan todos el dia de hoy";
	//string mensaje= "efectivamente";
	//string mensaje= "em pues jajaj noje que poner de mensaje asi que pondre esto xd";
	string mensaje= "me acabo de dar cuenta que no funciona con claves mayores a treinta y tres";
	cout<<"Mensaje= "<<mensaje <<endl;
  	string mensajeCifrado= Emisor.cifrar(mensaje); 
  	cout<<"Mensaje Cifrado= "<< mensajeCifrado <<endl;

  	string mensajeOriginal= Receptor.descifrar(mensajeCifrado);
  	cout<<"Mensaje original= "<<mensajeOriginal<<endl;
  	
  	criptoanalisis("jxofxjbozbabpmxpbosfoibxra");

}
