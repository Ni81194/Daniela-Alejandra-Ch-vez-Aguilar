#include<iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>
  using std::istringstream;
using namespace std;
int main() {
	cout<<"EJERCICIO 1"<<endl<<endl<<endl;
  string texto;
  int num;
  cout<<"ingrese los caracteres:";
  cin>>texto;
  cout<<"ingrese numero:";
  cin>>num;

while(num< texto.size() ){
	texto.insert(num, " ");
	num+=num;
}

char *cstr = new char [texto.size()+1];
  strcpy (cstr, texto.c_str());
  char *ptr = strtok (cstr," ");
  while (ptr!=0)
  {
    cout << ptr << '\n';
    ptr = strtok(NULL," ");
  }
  delete[] cstr; 
  
  
/////////////////////////////////////
cout<<endl<<endl<<endl;
cout<<"EJERCICIO 2"<<endl;
string entrada( "1112" );
  istringstream cadenaEntrada( entrada );
  int entero;
  cadenaEntrada >>  entero ;

  cout<< "\n int: " << entero<<endl;
  
///////////////////
cout<<endl<<endl<<endl;
cout<<"EJERCICIO 3"<<endl;
// usando libreria  #include <sstream>

int numero= 1234;
stringstream a;
a<<numero<<endl;
string newString= a.str();
cout<< newString<<endl;


}









