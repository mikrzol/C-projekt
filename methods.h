#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "classes.h"

class Metaklasa{
    class A* A;
    class B* B;
    class C* C;
    Leaf<D>* D;
    Leaf<E>* E;
    class F* F;
    class G* G;
    class I* I;
    Leaf<J>* J;
    Leaf<K>* K;
    Leaf<L>* L;
    Leaf<M>* M;
};

using namespace std;

void save_list_to_file(){
        ofstream data;
        data.open("data.dat");

        Leaf<D> obj_D;
        Leaf<D> *obj_D_ptr = obj_D.get_head(obj_D);
        while(obj_D_ptr != NULL){
            data << obj_D_ptr->get_class_name() << "#" << obj_D_ptr->get_data()<< "\n"; 
            obj_D_ptr = obj_D.get_next(obj_D_ptr);
        }

        Leaf<E> obj_E;
        Leaf<E> *obj_E_ptr = obj_E.get_head(obj_E);
        while(obj_E_ptr != NULL){
            data << obj_E_ptr->get_class_name() << "#" << obj_E_ptr->get_data() << "\n"; 
            obj_E_ptr = obj_E.get_next(obj_E_ptr);
        }

        Leaf<J> obj_J;
        Leaf<J> *obj_J_ptr = obj_J.get_head(obj_J);
        while(obj_J_ptr != NULL){
            data << obj_J_ptr->get_class_name() << "#" << obj_J_ptr->get_data() << "\n"; 
            obj_J_ptr = obj_J.get_next(obj_J_ptr);
        }

        Leaf<K> obj_K;
        Leaf<K> *obj_K_ptr = obj_K.get_head(obj_K);
        while(obj_K_ptr != NULL){
            data << obj_K_ptr->get_class_name() << "#" << obj_K_ptr->get_data() << "\n"; 
            obj_K_ptr = obj_K.get_next(obj_K_ptr);
        }

        Leaf<J> obj_L;
        Leaf<J> *obj_L_ptr = obj_L.get_head(obj_L);
        while(obj_L_ptr != NULL){
            data << obj_L_ptr->get_class_name() << "#" << obj_L_ptr->get_data() << "\n"; 
            obj_L_ptr = obj_L.get_next(obj_L_ptr);
        }

        Leaf<M> obj_M;
        Leaf<M> *obj_M_ptr = obj_M.get_head(obj_M);
        while(obj_M_ptr != NULL){
            data << obj_M_ptr->get_class_name() << "#" << obj_M_ptr->get_data() << "\n"; 
            obj_M_ptr = obj_M.get_next(obj_M_ptr);
        }
        data.close();
};

void read_list_from_file(){
    ifstream data;
    data.open("data.dat");
    string line_from_file;
    while(getline(data, line_from_file)){
        string myText(line_from_file);
        istringstream iss(myText);
        string segment;
        vector<string> seglist;
        while (getline(iss, segment, '#')){
            seglist.push_back(segment);
        }
        string klasa = seglist[0];
        
        if(klasa == "D"){
            Leaf<D>* obj = (Leaf<D>*)malloc(sizeof(Leaf<D>));
            obj->create_obj(stoi(seglist[1]));
        }
        if(klasa == "E"){
            Leaf<E>* obj = (Leaf<E>*)malloc(sizeof(Leaf<E>));
            obj->create_obj(stoi(seglist[1]));
        }
        if(klasa == "J"){
            Leaf<J>* obj = (Leaf<J>*)malloc(sizeof(Leaf<J>));
            obj->create_obj(stoi(seglist[1]));
        }
        if(klasa == "K"){
            Leaf<K>* obj = (Leaf<K>*)malloc(sizeof(Leaf<K>));
            obj->create_obj(stoi(seglist[1]));
        }
        if(klasa == "L"){
            Leaf<L>* obj = (Leaf<L>*)malloc(sizeof(Leaf<L>));
            obj->create_obj(stoi(seglist[1]));
        }
        if(klasa == "M"){
            Leaf<M>* obj = (Leaf<M>*)malloc(sizeof(Leaf<M>));
            obj->create_obj(stoi(seglist[1]));
        }
    }
};

void print_D_list(){
    Leaf<D> obj;
    obj.print_list();
};
void print_E_list(){
    Leaf<E> obj;
    obj.print_list();
};
void print_J_list(){
    Leaf<J> obj;
    obj.print_list();
};
void print_K_list(){
    Leaf<K> obj;
    obj.print_list();
};
void print_L_list(){
    Leaf<L> obj;
    obj.print_list();
};
void print_M_list(){
    Leaf<M> obj;
    obj.print_list();
};
