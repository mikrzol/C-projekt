#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "classes.h"
#include "methods.h"

using namespace std;

int main(){
/*
    Leaf<D> objD;
    objD.create_obj(2);

    Leaf<E> objE;
    objE.create_obj(3);

    Leaf<D> objD_2;
    objD_2.create_obj(4);

    Leaf<E> objE_2;
    objE_2.create_obj(5);

    objE_2.modify_obj(objE_2.get_data(), 7);

    save_list_to_file();

    Leaf<M> obj_m, obj_m2, obj_m3, obj_m4, obj_m5;
    obj_m.create_obj(1);
    obj_m2.create_obj(2);
    obj_m3.create_obj(3);
    obj_m4.create_obj(4);
    obj_m5.create_obj(5);

    objD.print_list();
    objE.print_list();
    obj_m2.print_list();

    save_list_to_file();
*/
    read_list_from_file();
/*
    Leaf<D> objD;
    objD.print_list();
    Leaf<E> objE;
    objE.print_list();
    Leaf<M> objM;
    objM.print_list();
*/
    string tryb = "wlacz";
    string wybor;
    string wezel;
    vector<string> seglist= {"0", "0"};

    while(tryb == "wlacz"){
        cout << "Wybierz dzialanie:\n\
CD [nazwa wezla] -> przejdz do wezla o danej nazwie" << endl;
if(seglist[1] == "D" || seglist[1] == "E" || seglist[1] == "J" || seglist[1] == "K" || seglist[1] == "L" || seglist[1] == "M"){
    cout << "\
MO [nazwa] -> stworz obiekt o podanej nazwie dla tego liscia\n\
DO [nazwa] -> usun dany obiekt dla tego liscia\n\
MDO [nazwa] -> zmodyfikuj obiekt o danej nazwie dla tego liscia" << endl;
}
cout << "\
DIR -> wyswietl liste wszystkich obiektow, ktore dziedzicza z danego wezla\n\
SHOW [obiekt] -> wyswietl szczegolowe informacje o danym obiekcie\n\
SAVE -> zapisz zbior do pliku\n\
READ -> wczytaj zbior z pliku\n\
TREE -> pokaz schemat struktury\n\
EXIT -> zakoncz program" << endl;

        getline(cin, wybor);
        // convert string to upper case
        transform(wybor.begin(), wybor.end(),wybor.begin(), ::toupper);
        cin.clear();
        fflush(stdin);

        string myText(wybor);
        istringstream iss(myText);
        string segment;

        seglist.resize(0);
        while (getline(iss, segment, ' ')){
            seglist.push_back(segment);
        }

/*
        for(int i = 0; i < 2; i++){
            getline(iss, segment, ' ');
            seglist[i] = segment;
        }
*/

        string komenda = seglist[0];
        string klasa = seglist[1];


        if(komenda == "CD"){
            cout << "robie CD" << endl;
            if(klasa == "D"){
                cout << "jestem w klasie D" << endl;
            }
            if(klasa == "E"){
                cout << "jestem w klasie E" << endl;
            }
            if(klasa == "J"){
                cout << "jestem w klasie J" << endl;
            }
            if(klasa == "K"){
                cout << "jestem w klasie K" << endl;
            }
            if(klasa == "L"){
                cout << "jestem w klasie L" << endl;
            }
            if(klasa == "M"){
                cout << "jestem w klasie M" << endl;
            }
        }
        if(komenda == "TREE"){
            cout << "SCHEMAT STRUKTURY:\n\
\t\t\tA\n\
\t\t/\t     \\\n\
\t  B\t \t\tC\t\t\n\
  /\t  \\\t\t/\t\\\n\
D\t\tE\t F\t\tG\n\n\
\t\t\t I\tJ\t\tK\n\n\
\t\t    L\t    M" << endl;
        }
        else if(komenda == "EXIT"){
            tryb = "0";
        }

    }
    create_traversal_objs();
    return 1;
}