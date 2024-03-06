#ifndef __MENU_H__
#define __MENU_H__



#include <iostream>
#include <string>
#include <cctype>
#include <conio.h>

#include "list.hpp"

class Menu{

    private:
        void interfaceMenu(List&);
        void interfaceNewSong(List&);//
        void interfaceDeleteSong(List&);//
        void interfaceDeleteList(List&);//
        void interfaceShowSongs(List&); //
        void interfaceRetrieveSong(List&);//
        
    public:
        Menu(List&); //Constructor
};

#endif // __MENU_H__