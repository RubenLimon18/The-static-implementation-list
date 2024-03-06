#include "menu.hpp"

using namespace std;

Menu::Menu(List& list){
    interfaceMenu(list);
}


void Menu::interfaceMenu(List& list){
    char option;

    do{
        cout<<"\n|------------------------------------------|";
        cout<<"\n|                    Songs                 |";
        cout<<"\n|----------------------|-------------------|";
        cout<<"\n| [A] New song         | [E] Retrieve song |";
        cout<<"\n| [B] Delete song      | [F] Exit          |";
        cout<<"\n| [C] Delete list      |                   |";
        cout<<"\n| [D] Show songs       |                   |";
        cout<<"\n|----------------------|-------------------|";
        cout<<"\nOption: ";
        cin>> option;
        cin.ignore();
        
        option = toupper(option); //Convert to capital letter.

        switch(option){
            case 'A':
                interfaceNewSong(list);
                break;
            case 'B':
                interfaceDeleteSong(list);
                break;
            case 'C':
                interfaceDeleteList(list);
                break;
            case 'D':
                interfaceShowSongs(list);
                break;
            case 'E':
                interfaceRetrieveSong(list);
                break;
            case 'F':
                cout<<"\n\n EXIT \n\n";
                cout<<"\nPresione ENTER para continuar.";
                getch();
                //system("pause");
                break;
            default:
                cout<<"\n\n Opcion invalida.\n\n";
        }
    }while(option != 'F');
}


void Menu::interfaceNewSong(List& list){
    Song auxSong;

    string nameSong, autor, interpreter;
    int pos;
    
    cout<<"\n\n NEW SONG \n\n";

    cout<<"Song: ";
    getline(cin, nameSong);

    cout<<"Autor: ";
    getline(cin, autor);

    cout<<"Interpreter: ";
    getline(cin, interpreter);

    cout<<"What position do you want to add the song: ";
    cin>> pos;

    auxSong.setAutorName(autor);
    auxSong.setSong(nameSong);
    auxSong.setInterpreter(interpreter);

    try{
        list.insertSong(pos, auxSong);
    }
    catch(ListException error){
        cout<<"Algo anda mal: "<<error.what()<<endl;
    }

    cout<<"\n\n SONGS \n\n";
    cout<< list.toString()<<endl;
}


void Menu::interfaceDeleteSong(List& list){
    int pos;

    cout<<"\n\n DELETE SONG \n\n";
    cout<<"What position do you want delete the song: ";
    cin>> pos;

    try{
        list.deleteSong(pos);
    }
    catch(ListException error){
        cout<<"Algo anda mal: "<<error.what();
    }

    cout<<"\n\n SONGS \n\n";
    cout<< list.toString()<<endl;

    system("pause");
    system("cls");
}


void Menu::interfaceDeleteList(List& list){
    char option;
    cout<<"\n\n DELETE LIST \n\n";
    cout<<"Do you want to delete the list s/n: ";
    cin>> option;
    cin.ignore();

    option = tolower(option);

    if(option == 's'){
        list.deleteList();
        cout<<"\nSONGS\n\n";
        cout<<list.toString()<<endl;
        system("pause");
        system("cls");
    }

}


void Menu::interfaceShowSongs(List& list){
    cout<<"\n\n SONGS \n\n";
    cout<< list.toString();

    system("pause");
    system("cls");
}


void Menu::interfaceRetrieveSong(List& list){
    int pos;

    cout<<"What position do you retrieve: ";
    cin>> pos;

    try{
        cout<<list.retrieve(pos).toString()<<endl<<endl;
    }
    catch(ListException error){
        cout<<"Algo anda mal: "<<error.what()<<endl;
    }
}

