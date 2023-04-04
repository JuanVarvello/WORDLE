#include "funciones.h"
#include <iostream>
#include <ctime>

using namespace std;

int main(){
  
  int intentos = 6; //defino cantidad de intentos
  
  const string filename = "../listado.txt"; //se corre en la carpeta build, poreso tengo q salir para acceder a listado.txt
  
  vector<string> listado_palabras = cargar_listado(filename); //cargamos el archivo al vector<string>
  
  srand(time(0));
  int s = rand()%(listado_palabras.size()-1); //genera un numero de posicion aleatorio entre [0 y len(palabras)-1]
  
  string palabra_secreta = listado_palabras[s]; //selecciono la palabra secreta
  

  while(intentos != 0){
    string intento;
    cout<< "Ingrese su palabra:" << endl;
    cin >> intento;

    if (intento == palabra_secreta){ //si adivino la palabra secreta
      cout << "Adivinaste la palabra -> GANASTE!" << endl;
      exit(0);

    }else{
      if(intento_valido(intento, palabra_secreta, listado_palabras)){//evaluo validez del intento

        vector<EstadoLetra> resultado = evaluar_intento(intento, palabra_secreta);
        cout << respuesta_en_string(resultado) << endl;
        intentos = intentos - 1;

      }else{
        cout << "Intento NO valido" << endl;
      }
    }
  }
  if (intentos == 0){ //se quedo sin intentos, perdio
    cout << "Perdiste =( -> Agotaste todos tus intentos" << endl; 
  }
  exit(0); 
}
