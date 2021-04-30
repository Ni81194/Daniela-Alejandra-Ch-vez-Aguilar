#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int numRandom(int rango){
	int x;
    srand (time (0));
    for (int i=0; i<=rango; i++){
      x= 1+(rand()%rango);
    }
    return x;
}

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
	return s1;
}

int generar_claveA(int claveA, int tam){
	claveA=numRandom(tam);
	while (Euclides(claveA,tam)!= 1){
		claveA=numRandom(tam);
	}
	return claveA;
}


//CLASE 
class algoritmoX{
private: 
   string abc="abcdefghijklmnopqrstuvwxyz";
   int tam= abc.size();
public:
	int claveA=1,claveB=1;
	algoritmoX() = default;
	algoritmoX(int a, int b){
		claveA= a;
		claveB=b;
	}
	
	//FUNCION CLAVE A
    	int A(int claveA, int tam){
			claveA=numRandom(tam);
			while (Euclides(claveA,tam)!= 1){
				claveA=numRandom(tam);
			}
			return claveA;
		}
		//FUNCION CLAVE B
		int B(int tam){
			claveB=numRandom(tam);
			return claveB;
		}
	
	//FUNCION CIFRADO
	string cifrar(string cadena, int claveA, int claveB){
    	string mensajeC;
    	
   		cout<<"claveA:"<< claveA <<"  claveB:"<<claveB<<endl;
   		
  		for (int i = 0; i < cadena.size(); ++i) {
  			int aux= abc.find( cadena[i] ) ;
  			aux=(aux*claveA);
  			if (aux >tam){
  				aux=(modulo(aux, tam)+claveB);
			  }
			else{
				aux= aux+claveB;
			}
  			
  			
  			if (cadena[i]==' '){
  				mensajeC.append(1, ' ');
  				continue;
			  }
			else if (aux>25){
				mensajeC.append(1,  abc[modulo(aux,tam)]); // usando modulo positivo
			}
			else {
				mensajeC.append(1,  abc[aux]);
			}
  		}
  		
  		return mensajeC;
	}	

	//FUNCION DESCIFRADO
	string descifrar (string cadena, int claveA, int claveB){
  		string mensajeD;
  		claveA= EuclidesExtendido(claveA,tam); //inversa de A
  		if (claveA>tam || claveA <0 ){
  			claveA= modulo(claveA, tam);
		  }
		cout<<"claveA:"<< claveA <<"  claveB:"<<claveB<<endl;
  		
  		for (int i = 0; i < cadena.size(); ++i) {
			int aux= abc.rfind( cadena[i] ) ;
			aux= (aux - claveB);
			if (aux<0){
				aux= modulo(aux, tam);
			}
			aux=(aux*claveA);
			
			if (cadena[i]==' '){
				mensajeD.append(1,' ');
				continue;
			}
			else if(aux<0){
				mensajeD.append(1,  abc[modulo(aux,tam)]);
			}
			else if(aux> tam){
				mensajeD.append(1,  abc[modulo(aux,tam)]);
			}
  			else{
  				mensajeD.append(1,  abc[aux]);
			  }
  		}
  		return mensajeD;
	}
 
};


int main() {
	algoritmoX Emisor; 
	int clave_a=Emisor.A(1,26);
	int clave_b=Emisor.B(26);
	algoritmoX Receptor(clave_a, clave_b);
	string mensaje= "holaa";
	cout<<"Mensaje= "<<mensaje <<endl;
  	string mensajeCifrado= Emisor.cifrar(mensaje,clave_a , clave_b); 
  	cout<<"Mensaje Cifrado= "<< mensajeCifrado <<endl;
  	string mensajeOriginal= Receptor.descifrar(mensajeCifrado, clave_a , clave_b);
  	//receptor.descifrar(emisor.claveb() )
  	cout<<"Mensaje original= "<<mensajeOriginal<<endl;
}

