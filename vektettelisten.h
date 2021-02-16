// vektettelisten.h
#ifndef VERKETTETELISTE_H
#define VERKETTETELISTE_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h> // EXIT_SUCCESS, CLS
using namespace std;
/* 
Classe Kunden enhält Namen und Vornamen des Kunden sowie Pointer zum nächsten Node,

*/
class Kunde {
private:
    // speichert die Daten des Kunden
    string name_kunde;
    string vorname_kunde;
    // speichert die Adresse des nächsten Kunde Node
    Kunde* next_address_of_kunde;
public:
    // adresse schreiben und holen aus der Class
    void addresseKunde(Kunde*);
    Kunde* addresseKunde();
    // daten schreiben und holen aus der Class
    void nameKunde(string&);
    string nameKunde();
    void vornameKunde(string&);
    string vornameKunde();

    Kunde(string&, string&);
};
/*
Classe Liste baut die Kntoen auf enthält den ersten sowei ltzten Element als Pointer
*/
class Liste {
private:
    // Speichert anfang und das ende der Liste
    Kunde* first_node;
    Kunde* last_node;
public:
    // holen/schreiben der daten aus dem ersten node
    Kunde* firstNode();
    void firstNode(Kunde*);
    // holen/schreiben der daten aus dem letzten node
    Kunde* lastNode();
    void lastNode(Kunde*);

    void deleteNode();
    void objektAnhaengenFirst();
    void objektAnhaengenLast();
};

#endif // VERKETTETELISTE_H
