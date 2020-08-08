#include <iostream>
//biblioteca para almacenar archivos
#include <fstream>
//Para ingresar los nombres;
#include <string>
int Ingreselosnombres();
//visuzaliar los nombre
int visualizar();
using namespace std;

int main() 
{
  int opcion;
  while(opcion!=3)
  {
    cout << "\n________________________________________\n";
    cout << "\n1.- Ingresar Datos del usuario\n";
    cout << "\n2.- Visuzaliar los datos\n";
    cout << "\n3.-Salir\n\n";
    // Ingresando la opcion junto al cout
    cout << "Escoja una opcion: ";cin >> opcion;

    switch(opcion)
    {
      case 1:
      Ingreselosnombres();
      case 2:
      visualizar();
      case 3:
      cout << "\n Salio del sistema\n";
    }

  }
  return 0;
}

int Ingreselosnombres()
{
  ofstream archivodatos;
  char r;
  int edad;
  string nombre, apellido;
  do
  {
    system("cls");
    archivodatos.open("Datos.txt",ios::out|ios::app);

    cout << "\n________________________________________\n";
    cout << "Ingrese el Nombre: "; 
    cin >> nombre;
    // Ayuda a elminar los datos exedidos
    cin.ignore(' ', '\n'); 
    cout << "Ingrese el Apellido: ";
    cin >> apellido;
    cin.ignore(' ', '\n');
    cout << "Ingrese su edad: ";
    cin >> edad;

    archivodatos<< "Nombre: " << nombre << "\n";
    archivodatos <<"Apellido: " << apellido << "\n";
    archivodatos << "Edad: " << edad <<"\n\n";

    

    cout << "Desea ingresar mas datos?(s/n): ";
    cin >> r;

    archivodatos.close(); 

    
  }while(r=='s');

  

  return main();
}

int visualizar()
{
  string nombre,apellido;
  int edad;
  system("cls");
  ifstream archivodatos;
  string texto;
  archivodatos.open("Datos.txt",ios::in);
  while(!archivodatos.eof())
  {
    getline(archivodatos,texto);
    //Imprime el texto
    cout  << texto << endl ;
  }

  return main();
}
