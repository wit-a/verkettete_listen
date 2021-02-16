#include "vektettelisten.h"
// + + + Class Kunde + + +
Kunde::Kunde(string& vorname_vm, string& name_vm)
    :name_kunde(name_vm), vorname_kunde(vorname_vm) {
    next_address_of_kunde = NULL;
}
// adresse schreiben und holen aus der Class
void Kunde::addresseKunde(Kunde* adresse_vm) {
    next_address_of_kunde = adresse_vm;
}
Kunde* Kunde::addresseKunde() {
    return next_address_of_kunde;
}
void Kunde::nameKunde(string& name_vm) {
    name_kunde = name_vm;
}
string Kunde::nameKunde() {
    return name_kunde;
}
void Kunde::vornameKunde(string& vorname_vm) {
    vorname_kunde = vorname_vm;
}
string Kunde::vornameKunde() {
    return vorname_kunde;
}
// END + + + Class Kunde + + +

// + + + Class Liste + + +
// holen/schreiben der daten aus dem ersten node
void Liste::firstNode(Kunde* first_node_el_vm) {
    first_node = first_node_el_vm;
}
Kunde* Liste::firstNode() {
    return first_node;
}
// holen/schreiben der daten aus dem letzten node
void Liste::lastNode(Kunde* last_node_el_vm) {
    last_node = last_node_el_vm;
}

Kunde* Liste::lastNode() {
    return last_node;
}


void Liste::deleteNode() {

    string vorname_met;
    string name_met;
    Kunde* tmp1 = NULL;
    Kunde* tmp2 = NULL;
    Kunde* tmp3 = NULL;
    cout << "Es wird ein Kunde geloescht:\nBitte geben Sie den Vornamen ein";
    cin >> vorname_met;
    cout << "\nBitte geben Sie den Nachnamen ein:";
    cin >> name_met;
    tmp1 = first_node;
    //ist das gesuchte element das erste Element
    if (tmp1->vornameKunde() == first_node->vornameKunde() && tmp1->nameKunde() == first_node->nameKunde()) {
        tmp1 = first_node->addresseKunde();
        delete first_node;
        first_node = tmp1;
        cout << endl << "das ERSTE Node wurde geloescht";
        return;
    }
    //ist das gesuchte element das letzte Emelemnt
    if (tmp1->vornameKunde() == last_node->vornameKunde() && tmp1->nameKunde() == last_node->nameKunde()) {
        tmp1 = first_node;
        while (tmp1 != last_node) {
            tmp2 = tmp1->addresseKunde();
            if (tmp2 == last_node) { //am vorletzten element
                last_node = tmp1;
                delete tmp2;
                cout << endl << "das LETZTE Node wurde geloescht";
                return;
            }
            tmp1 = tmp2;
        }
    }
    // suchen in der liste
    while (tmp1 != last_node) {
        tmp2 = tmp1->addresseKunde();
        if (vorname_met == tmp2->vornameKunde() && name_met == tmp2->nameKunde()) {
            tmp3 = tmp2->addresseKunde();
            tmp1->addresseKunde(tmp3);
            delete tmp2;
            return;
        }
        tmp1 = tmp2;
    }
}

void Liste::objektAnhaengenFirst() {
    string vorname_met;
    string name_met;
    Kunde* tmp = NULL;
    Kunde* adresse_neu_1 = NULL;
    cout << "Es wird ein neuer Kunde angelegt:\nBitte geben Sie den Vornamen ein";
    cin >> vorname_met;
    cout << "\nBitte geben Sie den Nachnamen ein:";
    cin >> name_met;
    tmp = new Kunde(vorname_met, name_met);
    adresse_neu_1 = first_node;
    tmp->addresseKunde(adresse_neu_1);
    first_node = tmp;
} // END objektAnhaengenFirst
void Liste::objektAnhaengenLast() {
    string vorname_met;
    string name_met;
    Kunde* tmp;
    cout << "Es wird ein neuer Kunde angelegt:\nBitte geben Sie den Vornamen ein";
    cin >> vorname_met;
    cout << "\nBitte geben Sie den Nachnamen ein:";
    cin >> name_met;
    tmp = new Kunde(vorname_met, name_met);
    last_node->addresseKunde(tmp);
    last_node = tmp;
} // END objektAnhaengenLast
// END + + + Class Liste + + +
