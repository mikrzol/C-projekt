#include <iostream>
#include <cstdio>
#include <typeinfo>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
//#include "leaf.h"
using namespace std;

#ifndef CLASSES_H
#define CLASSES_H

/*
class Base {
private:
	static Base* instance;
	Base* child1;
	Base* child2;
public:
	virtual Base* get();
	virtual void zrobCokolwiek();
};
*/
/*
class Base {
    private:
        string name;
        int id;
        int val;
    public:
        string get_name(){
            return this->name;
        };
        void change_name(string new_name){
            this->name = new_name;
        };
        int get_id(){
            return this->id;
        };
        int get_val(){
            return this->val;
        };
    Base(string name, int val);
    ~Base(){};
};
*/

class A {
/*
    private:
        static A* A_instance;
*/
    protected:
        A(){
            this->name = "A";
            this->children_list = {string("B"), string("C")};
        };
    class B* B_child;
    class C* C_child;
    public:
    vector<string> children_list;
    string name;
    int data;
    int get_data(){
        return this->data;
    };
/*
        static A* Get_A_instance(){
            if(A_instance == NULL) {
                A_instance = new A();
            }
            return A_instance;
            };
        virtual string go_up(){
            cout << "To jest korzen - nie mozna isc wyzej" << endl;
        };
*/
        virtual vector<string> go_down(){
            return this->children_list;
        };
        virtual string get_name(){
            return this->name;
        };
        virtual string sciezka(){
            return string("A:\\>");
        };
};
//A* A::A_instance = NULL;



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
        cout << "Lista obiektow dziedziczacych z tej klasy/ tej klasy: " << endl;
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


class B : public A {
/*
    private:
        static B* B_instance;
*/
    protected:
        B(){
            this->name = "B";
            this->children_list = {string("D"), string("E")};
        };
        class A* A_parent;
        Leaf<D>* D_child;
        Leaf<E>* E_child;
    public:
/*
    static B* Get_B_instance(){
        if(B_instance == NULL){
            B_instance = new B();
        }
        return B_instance;
    };
*/
    virtual string go_up(){
        return string("A");
    };
    virtual string sciezka(){
        return string("A:\\B>");
    };
};
//B* B::B_instance = NULL;

//TUTAJ SKONCZYLEM
class C : public A {
};

class D : public B {
    //to jest lisc
    vector<string> children_list;
    public:
    D(){
        this->children_list = {"To jest lisc", " "};
    }
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




/*
struct node_kolejki{
    class A* prev_A;

    class B* next_B;
    class B* prev_B;

    class C* next_C;
    class C* prev_C;

    Leaf<D>* next_D;

    Leaf<E>* next_E;

    class F* next_F;
    class F* prev_F;

    class G* next_G;
    class G* prev_G;

    class I* next_I;
    class I* prev_I;

    Leaf<J>* next_J;

    Leaf<K>* next_K;

    Leaf<L>* next_L;

    Leaf<M>* next_M;

    node_kolejki(){
    class A* prev_A = NULL;

    class B* next_B = NULL;
    class B* prev_B = NULL;

    class C* next_C = NULL;
    class C* prev_C = NULL;

    Leaf<D>* next_D = NULL;

    Leaf<E>* next_E = NULL;

    class F* next_F = NULL;
    class F* prev_F = NULL;

    class G* next_G = NULL;
    class G* prev_G = NULL;

    class I* next_I = NULL;
    class I* prev_I = NULL;

    Leaf<J>* next_J = NULL;

    Leaf<K>* next_K = NULL;

    Leaf<L>* next_L = NULL;

    Leaf<M>* next_M = NULL;
    }
};
struct node_kolejki2{
    struct node_kolejki2* prev_A;

    struct node_kolejki2* next_B;
    struct node_kolejki2* prev_B;

    struct node_kolejki2* next_C;
    struct node_kolejki2* prev_C;

    struct node_kolejki2* next_D;

    struct node_kolejki2* next_E;

    struct node_kolejki2* next_F;
    struct node_kolejki2* prev_F;

    struct node_kolejki2* next_G;
    struct node_kolejki2* prev_G;

    struct node_kolejki2* next_I;
    struct node_kolejki2* prev_I;

    struct node_kolejki2* next_J;

    struct node_kolejki2* next_K;

    struct node_kolejki2* next_L;

    struct node_kolejki2* next_M;

    class A* this_A;
    class B* this_B;
    class C* this_C;
    Leaf<D>* this_D;
    Leaf<E>* this_E;
    class F* this_F;
    class G* this_G;
    class I* this_I;
    Leaf<J>* this_J;
    Leaf<K>* this_K;
    Leaf<L>* this_L;
    Leaf<M>* this_M;

    node_kolejki2(){
    struct node_kolejki2* prev_A = NULL;
    class A* this_A = NULL;;

    struct node_kolejki2* next_B = NULL;
    struct node_kolejki2* prev_B = NULL;
    class B* this_B = NULL;

    struct node_kolejki2* next_C = NULL;
    struct node_kolejki2* prev_C = NULL;
    class C* this_C = NULL;

    struct node_kolejki2* next_D = NULL;
    Leaf<D>* next_D = NULL;

    struct node_kolejki2* next_E;
    Leaf<E>* next_E = NULL;

    struct node_kolejki2* next_F = NULL;
    struct node_kolejki2* prev_F = NULL;
    class B* this_F = NULL;

    struct node_kolejki2* next_G = NULL;
    struct node_kolejki2* prev_G = NULL;
    class B* this_G = NULL;

    struct node_kolejki2* next_I = NULL;
    struct node_kolejki2* prev_I = NULL;
    class B* this_I = NULL;

    struct node_kolejki2* next_J = NULL;
    Leaf<J>* next_J = NULL;

    struct node_kolejki2* next_K = NULL;
    Leaf<K>* next_K = NULL;

    struct node_kolejki2* next_L = NULL;
    Leaf<L>* next_L = NULL;

    struct node_kolejki2* next_M = NULL;
    Leaf<M>* next_M = NULL;
    }
};
*/
#endif