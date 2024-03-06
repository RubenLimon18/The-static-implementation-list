#ifndef __SONG_H__
#define __SONG_H__

#include<iostream>

class Song{
  //Atributos

  private:
    std::string song;
    std::string autorName;
    std::string interpreter;


  public:
    Song(); //Constructor vacío
    Song(const Song&); // Constructor que recibe un dato de tipo Song por referencia


    void setSong(const std::string&); //Recibe el nombre de la canción por referencia.
    void setAutorName(const std::string&); //Recibe el nombre del autor por referencia.
    void setInterpreter(const std::string&); //Recibe el nombre del interprete

    std::string toString() const; //Imprime el objeto Song

    std::string getSong() const; //Retorna el nombre de la canción
    std::string getAutorName() const; //Retorna el nombre del autor
    std::string getInterpreter() const; // Retorna el nombre del interprete

};



#endif // __SONG_H__