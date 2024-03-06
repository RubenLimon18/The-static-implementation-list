#include "list.hpp"

using namespace std;

List::List(){ last = -1;}

List::List(const List& list){ //Constructor que recibe una lista
  copyAll(list); //Funcion que nos va ayudar a copiar la lista que recibimos a una nueva lista.
  //Copiar una lista simplemente se basa en copiar los atributos song[] y last.
}

List& List::operator = (const List& list){
  copyAll(list);
  return *this; //Vamos a retornar este objeto.
}

bool List::empty(){
  return last == -1; //Simplemente verificamos si esta vacía.
}

bool List::full(){
  return last == 49; //Simplemente verificamos si esta llena.
}

void List::insertSong(const int& pos, const Song& song){
  //Verificar los errores con los que nos podemos encontrar.
  /* 
    CASOS:
    1. Que la lista esté llena.
    2. Que sea una posición invalida.

   */

  if(full()){
    throw ListException("Desbordamiento de datos. ");
  }

  if(!validPos(pos) && pos != -1){
    throw ListException("Posicion invalida. ");
  }

  int i = last;

  while(i > pos){
    songs[i+1] = songs[i];
    i--;
  }

  songs[pos + 1] = song; //Se agrega despues de la posición que se menciona.
  last++;               //Si se pone la posicion 23, se agrega en la posicion 24.
                        //Para agregar la primera cancion debemos de agregar la posicion -1
                        //Para que se agregue en la posicioón 0.

}


void List::deleteSong(const int& pos){
  /* 
    Verificamos que la posción sea valida.
    1. La lista puede estar vacía.
    2. La posición puede ser invalida.
  */

  if(empty()){
    throw ListException("Lista vacía");
  }

  if(!validPos(pos)){
    throw ListException("Posicion invalida.");
  }

  int i = pos;

  while(i < last){
    songs[i] = songs[i+1];
    i++;
  }
  last--;

}


string List::toString() const{
  string result;

  int i = 0;

  while(i <= last){
    result += ". ";
    result += songs[i].toString();
    result += "\n";

    i++;
  }

  return result;
}

int List::getFirstPos(){
  /* 
  Verificar el unico error que puede pasar.
    1. La lista puede estar vacía.
  */
  return empty() ? -1 : 0;
}

int List::getLastPos(){
  /* 
  Verificar el unico error que puede pasar.
    1. La lista puede estar vacía.
  */

  return empty() ? -1 : last;
}


int List::getPrevPos(const int& pos){
  //Verifica si es una posición invalida o es la primera posición.
  if(!validPos(pos) || pos == getFirstPos()){
    return -1;
  }

  return pos-1;
}

int List::getNextPos(const int& pos){
  //Verifica si es la última posición o si es posición inválida.
  if(!validPos(pos) || pos == last){
    return -1;
  }

  return pos + 1;
}


Song List::retrieve(const int& pos){
  if(!validPos(pos)){
    throw ListException("Posicion invalida");
  }
  
  return songs[pos];
}

void List::deleteList(){
  last = -1;
}

bool List::validPos(const int& pos){
  return pos >= 0 && pos <= last;
}


void List::copyAll(const List& l){
  last = l.last;

  int i = 0;
  while( i <= l.last){
    songs[i] = l.songs[i];
    i++;
  }
}