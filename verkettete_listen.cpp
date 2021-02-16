/*
Verkettete Listen Aufgabe RDF 03.02.2021
wit-a 
*/
#include "vektettelisten.h"

void listeEinlesen(Liste&, fstream&);
void listeAusgeben(Liste&);
void listeLoeschen(Liste&);

int main() {
    int steuerung_menu = 0;
    Liste KundenListe;
    fstream datei;

    cout << endl << endl << " - - - - - Kunden Datenbank! - - - - - " << endl << endl;
    // Menu 
    do {
        cout << "Steuerung mit Zahlentasten:" << endl << endl
            << "Liste einlesen mit 1" << endl
            << "Liste ausgeben mit 2" << endl
            << "Neuen Kunden anlegen am ANFANG der Liste 3" << endl
            << "Neuen Kunden anlegen am ENDE der Liste 4" << endl
            << "Kunden loeschen mit 6" << endl
            << "Liste komplett loeschen mit 9" << endl
            << "Beenden mit 0" << endl
            << "- - - - - - - - - - - - - - - - - - - -" << endl;
        cin >> steuerung_menu;

        if (steuerung_menu == 1) {
            system("CLS");
            listeEinlesen(KundenListe, datei);
        }
        if (steuerung_menu == 2) {
            system("CLS");
            cout << "hier" << endl;
            listeAusgeben(KundenListe);
        }
        if (steuerung_menu == 3) {
            KundenListe.objektAnhaengenFirst();
        }
        if (steuerung_menu == 4) {
            KundenListe.objektAnhaengenLast();
        }
        if (steuerung_menu == 6) {
            KundenListe.deleteNode();
        }
        if (steuerung_menu == 9) {
            listeLoeschen(KundenListe);
        }
        if (steuerung_menu == 0) {
            cout << "ende..." << endl << endl;
            return EXIT_SUCCESS;
        }

    } while (steuerung_menu != 0);

    return EXIT_SUCCESS;
} // END main

void listeEinlesen(Liste& KundenListe, fstream& datei) {
    string vorname_im, name_im;
    Kunde* adresse_neu_1 = NULL;
    Kunde* adresse_neu_2 = NULL;
    bool erster_kunde = true;

    string list_name;
    bool list_is_io = false;

    do { // Datei oefnen
        cout << "Geben Sie den Namen der Kundenliste ein: ";
        cin >> list_name;
        datei.open(list_name);
        if (datei.good()) {
            cout << "date erfolgreich eingelesen" << endl;
            list_is_io = true;
        }
    } while (list_is_io == false);

    while (getline(datei, vorname_im, ';')) { // Inhalte aud der Datei in Objekt speichern
        getline(datei, name_im);
        adresse_neu_1 = new Kunde(vorname_im, name_im);
        if (erster_kunde == true) {
            KundenListe.firstNode(adresse_neu_1);
            erster_kunde = false;
        }
        else {
            adresse_neu_2->addresseKunde(adresse_neu_1);
        }
        adresse_neu_2 = adresse_neu_1;
    }
    KundenListe.lastNode(adresse_neu_1);
    datei.close();
} // END listeEinlesen

void listeAusgeben(Liste& KundenListe) {
    Kunde* adresse_neu_1 = KundenListe.firstNode();
    Kunde* adresse_neu_2 = NULL;
    while (adresse_neu_2 != KundenListe.lastNode()) {
        cout << adresse_neu_1->vornameKunde() << "," << adresse_neu_1->nameKunde() << endl;
        adresse_neu_2 = adresse_neu_1;
        adresse_neu_1 = adresse_neu_2->addresseKunde();
    }
} // END listeAusgeben

void listeLoeschen(Liste& KundenListe) {
    Kunde* adresse_neu_1 = KundenListe.firstNode();
    Kunde* adresse_neu_2 = NULL;
    do {
        adresse_neu_2 = adresse_neu_1->addresseKunde();
        delete adresse_neu_1;
        adresse_neu_1 = adresse_neu_2;
    } while (adresse_neu_1 != KundenListe.lastNode());
    cout << "Lister erfolgreich geloescht!" << endl << endl;
}// END liesteLoeschen
