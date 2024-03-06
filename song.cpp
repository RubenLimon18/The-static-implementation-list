#include "song.hpp"

using namespace std;

Song::Song(){} //Constructor vacío

Song::Song(const Song& s){ //Constructor que recibe una cancion y tomamos sus atributos
    song = s.song;
    autorName = s.autorName;
    interpreter = s.interpreter;
}

void Song::setSong(const string& nameSong){ //Método para establecer el nombre de la canción
    song = nameSong;
}

void Song::setAutorName(const string& autor){ //Método para establecer el nombre del autor
    autorName = autor;
}

void Song::setInterpreter(const string& inter){
    interpreter = inter;
}

string Song::toString() const{ //Método para imprimir el objeto Song.
    string result;

    result = "Cancion: ";
    result += getSong();
    result.resize(35,' ');
    result += " Autor: ";
    result += getAutorName();
    result.resize(70,' ');
    result += " Interprete: ";
    result += getInterpreter();
    
    return result;
}

string Song::getSong() const{ //Método para obtener el nombre de la canción
    return song;
}

string Song::getAutorName() const{ //Método para obtener el nombre del autor
    return autorName;
}

string Song::getInterpreter() const{ //Método para obtener el nombre del interpreter
    return interpreter;
}
