
#include "funciones.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){

  ifstream infile(nombre_archivo); //abro el archivo

  string linea;
  vector<string> lista;

  if(infile.good() == false){ //no se pudo abrir el archivo
    cout << "No se pudo abrir el archivo." << endl;
    exit(1);
  }

  while(!infile.eof()){ // mientras el archivo no haya llegado al final
    getline(infile, linea, '\n');
    if(linea.empty() == false){ //si la linea no esta vacia -> la cargo
      lista.push_back(linea);
    }
  }

  infile.close(); // cierro archivo
  return lista; //devuelvo el vector con todas las palabras cargadas
}


bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){
  bool value;
  //si intento esta en la lista y tiene la misma longitud que la palabra secreta
  if (count(listado.begin(), listado.end(), intento) && intento.size() == palabra_secreta.size()){
    value = true;
    
  }else{
    value = false;
  }
  
  return value;
}

vector<EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
  int k = 0;
  int i = 0;
  vector<EstadoLetra> estado_letra;
  //ciclo para recorrer las letras de intento y palabra secreta
  while(k < palabra_secreta.size()){
   while(i < intento.size()){
     
      if (intento[i] == palabra_secreta[k]){
        //LugarCorrecto
        estado_letra.push_back(EstadoLetra::LugarCorrecto);
      }else{
        if (count(palabra_secreta.begin(), palabra_secreta.end(), intento[i])){
          //LugarIncorrecto
          estado_letra.push_back(EstadoLetra::LugarIncorrecto);
        }else{
          //NoPresente
          estado_letra.push_back(EstadoLetra::NoPresente);
        }
      }
      i++;
      k++;
    }
  }
  return estado_letra;
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){
    
  string value = "";
  int i;
  //Traduzco la respuesta a string
  for(i = 0; i < respuesta.size(); i++){
    if (respuesta[i] == EstadoLetra::LugarCorrecto){
      //LugarCorrecto -> "+"
      value = value + "+";
    }
    else if (respuesta[i] == EstadoLetra::LugarIncorrecto){
      //LugarIncorrecto -> "-"
      value = value + "-";
      
    }else{
      //NoPresente -> "X"
      value = value + "X";
    }
  }
  return value;
}
