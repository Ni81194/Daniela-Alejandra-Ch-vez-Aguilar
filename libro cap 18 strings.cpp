#include<iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
using namespace std;
/*
(Cifrado simple) Cierta información en Internet se puede cifrar con un algoritmo simple conocido como “rot13”, el
cual rota cada carácter 13 posiciones en el alfabeto....
*/
class algoritmoX{
private: 
   int clave=13;
public:
	string abc="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	string ROT13(string cadena){
    string mensajeC;
  for (int i = 0; i < cadena.size(); ++i) {
  	int f= abc.find( cadena[i] ) ;
  	mensajeC.append(1,  abc[f+clave]);
  }
  return mensajeC;
}

string descifrar (string cadena){
  string mensajeD;
  for (int i = 0; i < cadena.size(); ++i) {
	int f= abc.rfind( cadena[i] ) ;
  	mensajeD.append(1,  abc[f-clave]);
  }
  return mensajeD;
}
 
};


int main()
{
	algoritmoX Emisor; 
	 algoritmoX Receptor;
	string mensaje= "hola";
	cout<<"Mensaje= "<<mensaje <<endl;
  string mensajeCifrado= Emisor.ROT13(mensaje); 
  cout<<"Mensaje Cifrado= "<< mensajeCifrado <<endl;

  string mensajeOriginal= Receptor.descifrar(mensajeCifrado);
  cout<<"Mensaje original= "<<mensajeOriginal<<endl;

//////////////////////////////////////////////////////////////////

	//Escriba un programa que introduzca por separado un primer nombre y un apellido, y que concatene los dos en un
	//nuevo objeto string.
	string nombre, apellido, concatenacion;
	cout<<"Introduzca un nombre:";
	cin>>nombre;
	cout<<"Introduzca un apellido:";
	cin>>apellido;
	concatenacion=nombre+apellido;
	cout<<concatenacion<<endl;
	
 
 //18.19 Escriba un programa que inserte los caracteres "******" en la mitad exacta de un objeto string.
 string cadenax="******";
 string cadena1="hola";
 int tamanio= cadena1.size();
 cout<< cadena1<<endl;
 cadena1.insert( tamanio/2, cadenax );
 cout<< cadena1<<endl;
 
//18.21 Escriba un programa que introduzca una línea de texto, reemplace todos los signos de puntuación con espacios y utilice
//la función strtok de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales (tokens).

cout<< "EJERCICIO 18.21"<<endl<<endl;
string texto;
cout<<"introduzca una linea de texto: ";
cin>> texto;

int posicion = texto.find( "." );
  while ( posicion != string::npos )
  {
  texto.replace( posicion, 1, " " );
  posicion = texto.find( ".", posicion + 1 );
  } 
  cout << texto<<endl;
cout<< "EJERCICIO 18.21 PARTE 2"<<endl<<endl;
char *cstr = new char [texto.size()+1];
  strcpy (cstr, texto.c_str());
  char *ptr = strtok (cstr," ");
  while (ptr!=0)
  {
    cout << ptr << '\n';
    ptr = strtok(NULL," ");
  }
  delete[] cstr; 


//18.22 Escriba un programa que introduzca una línea de texto y la imprima al revés. Use iteradores en su solución.
cout<< "EJERCICIO 18.22"<<endl<<endl;
 string cadenaI= "hola mundo ";
 string ::const_iterator iterador1 = cadenaI.end();
 cout << "cadenaI = " << cadenaI
  << "\n cadenaI invertida es:";
 while ( iterador1 != cadenaI.begin()-1 )
  {
  cout << *iterador1;
  iterador1--; 
  } 
  cout << endl;



 }
 






