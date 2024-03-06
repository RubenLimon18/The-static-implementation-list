#ifndef __LISTA_H__
#define __LISTA_H__

#include <iostream>
#include <string>

#include "song.hpp"
#include "listexception.hpp"

class List {
  //Atributos

  private:
    Song songs[50];
    int last;
    bool validPos(const int&);
    void copyAll(const List&);


  //Metodos
  public:
    List();
    List(const List&);
    List& operator = (const List&); //Retornamos la referencia de la lista.

    bool empty();
    bool full();

    void insertSong(const int&, const Song&);
    void deleteSong(const int&);

    std::string toString() const;

    int getFirstPos();
    int getLastPos();
    int getPrevPos(const int&);
    int getNextPos(const int&);

    Song retrieve(const int&);

    void deleteList();

};

#endif // __LISTA_H__