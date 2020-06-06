#include <iostream>
#include <cstdio>
#include <typeinfo>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

#ifndef CLASSES_H
#define CLASSES_H

/*
class Metaklasa{
    public:
    class A* A;
    class B* B;
    class C* C;
    class D* D;
    class E* E;
    class F* F;
    class G* G;
    class I* I;
    class J* J;
    class K* K;
    class L* L;
    class M* M;
};
*/
class A {
//  class B* B_child;
//  class C* C_child;
    public:
    A(){
        this->children_list = {"B", "C"};
    };
/*
    void assign_B_child(class B b_child){
        this->B_child = &b_child;
    };
    void assign_C_child(class C c_child){
        this->C_child = &c_child;
    };
*/
    vector<string> children_list;
    vector<string> get_children_list(){
        return this->children_list;
    };
    
    int data;
    virtual int get_data(){
        cout << this->data << endl;
        return this->data;
    };
};

class B : public A {
//    Leaf<D>* D_child;
//    Leaf<E>* E_child;
    vector<string> children_list;
    public:
    B(){
        this->children_list = {"D", "E"};
    };
/*
    void assign_D_children(Leaf<D> D_child){
        this->D_child = &D_child;
    };
    Leaf<D>* get_D_children(){
        return D_child;
    };
    void assign_E_children(Leaf<E> E_child){
        this->E_child = &E_child;
    };
    Leaf<E>* get_E_children(){
        return E_child;
    }
*/
};

class C : public A {
};

class D : public B {
    //to jest lisc
};

class E : public B {
    //to jest lisc
};

class F : public C {
};

class G : public C {
};

class I : public F {
};

class J : public G {
    //to jest lisc
};

class K : public G {
    //to jest lisc
};

class L : public I {
    //to jest lisc
};

class M : public I {
    //to jest lisc
};


template <class X>
class Leaf : public A {
    class Leaf* next;
    static class Leaf *head;
    public:
    void list_insert(){
        if(this->head == NULL){
            this->head = this;
            this->next = NULL;
        }
        else{
            class Leaf* ptr = this->head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = this;
            this->next = NULL;
        }
    };

    int get_data(){
        return this->data;
    };

    void print_list(){
        Leaf *ptr = this->head;
        while(ptr != NULL){
            cout << ptr->data << " " << ptr->get_class_name() << endl;
            ptr = ptr->next;
        }
    };

    Leaf<X>* list_search(int data){
        Leaf<X> *ptr = this->head;
        while(ptr->get_data() != data && ptr != NULL){
            ptr = ptr->next;
        }
        if(ptr == NULL){
            cout << "Nie znaleziono takich danych" << endl;
            return NULL;
        }
        return ptr;
    };
    // usuwanie po kluczu
    void list_delete(int key){
        Leaf<X>* ptr = this->head;
        if(ptr != NULL && ptr->get_data() == key){
            this->head = this->head->next;
            free(ptr);
            return;
        }
        Leaf<X>* prev = ptr;
        while(ptr != NULL && ptr->get_data() != key){
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr == NULL){
            cout << "Nie znaleziono takich danych" << endl;
            return;
        }
        prev->next = ptr->next;
        free(ptr);
    };

    public:
    void create_obj(int data){
        this->data = data;
        this->list_insert();
    };

    void modify_obj(int z_ktorego, int na_co){
        this->get_data();
        Leaf<X>* obj = this->list_search(z_ktorego);
        obj->data = na_co;
    };

    void destroy_obj(int key){
        this->list_delete(key);
    };

    char get_class_name(){
        string full_name = typeid(this).name();
        char klasa = full_name.at(8);
        return klasa;
    };

    Leaf<X>* get_head(Leaf<X> obj){
        return obj.head;
    };
    
    Leaf<X>* get_next(Leaf<X>* obj){
        return obj->next;
    };

};

template <class X>
class Leaf<X> *Leaf<X>::head = NULL;
#endif