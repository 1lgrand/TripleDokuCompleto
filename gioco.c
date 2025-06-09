/*
* Autori: 
    - Abbinante Flavio
    - Campobasso Luca
    - Cillo Andrea
    - De Marzo Alessandro
    - Dell'Aquila Giovanni Luca
*
* Data Inizio: [29/05/2025]
* Nome File: [gioco.c]
*
* Scopo delle funzioni:
* - [nome_funzione_1]: [Breve descrizione dello scopo della funzione 1]
* 
*
*
* Lista delle modifiche effettuate:
* [29/05/2025] - [DE MARZO] - [CREAZIONE DEL FILE]
* [01/06/2025] - [DE MARZO] - [IMPLEMENTAZIONE menu di avvio]
* [03/06/2025] - [CAMPOBASSO] - [PROTOTIPI salvaPartita, caricaPartita]
* [06/06/2025] - [ABBINANTE] - [IMPLEMENTAZIONE funzione visualizzaGriglia]
* [06/06/2025] - [DELL'AQUILA] - [IMPLEMENTAZIONE funzione salvaPartita]  
* [07/06/2025] - [CAMPOBASSO] - [IMPLEMENTAZIONE caricaPartita]
* [08/06/2025] - [DE MARZO] - [OTTIMIZZAZIONE caricaPartita] - [Viene passata per riferimento la partita per rendere piu facile il caricamento dei dati di gioco]  
* [09/06/2025] - [DELL'AQUILA] - [OTTIMIZZAZIONE salvaPartita] - [Viene divisa la funzione utilizzando sotto-funzioni per specializzare meglio salvaPartita]  
*/

#include <stdio.h>

#include "griglia.h"
#include "gioco.h"
#include "validazione.h"

int titolo() {

    printf("****************************************************\n");
    printf("*                 TRIPLE DOKU 18Bis                *\n");
    printf("****************************************************\n");

    return 0;
}

int menuAvvio(){
    
    printf("\t\t MENU DI AVVIO\n\n");
    printf("1. Nuova Partita\n");
    printf("2. Carica Partita\n");
    printf("3. Regole\n");
    printf("0. Esci\n");
    printf("\n> Cosa desideri fare: ");

    return 0;
}
    
void visualizzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]) {
    int i = 0; // inizializza l'indice delle righe
    int j = 0; // inizializza l'indice delle colonne

    // ciclo sulle righe della griglia
    while (i < GRIGLIA_LEN) {
        j = 0; // reimposta l'indice delle colonne a 0

        // ciclo sulle colonne della riga corrente
        while (j < GRIGLIA_LEN) {
            printf(" %d ", grigliaSingola[i][j]); // stampa l'elemento corrente
            j = j + 1; // passa alla colonna successiva
        }

        printf("\n"); // va a capo dopo aver stampato una riga
        i = i + 1; // passa alla riga successiva
    }
}
  



int salvaPartita(char * nomeFile, Salvataggio salvataggio){    

    FILE *file = fopen(nomeFile, "ab");  // apre il file in modalità append binario

    fwrite(&salvataggio, sizeof(Salvataggio), 1, file); // scrive la struttura Salvataggio nel file

    fclose(file); // chiude il file

    return 1; // restituisce 1 per indicare successo
}


int inizializzaPartita(Partita *partita, int difficolta, Griglia grigliaCompleta, Griglia grigliaUtente, int tentativiRimasti) {

    partita->difficolta = difficolta; // assegna il livello di difficoltà alla partita
    partita->grigliaCompleta = grigliaCompleta; // assegna la griglia completa alla partita
    partita->grigliaUtente = grigliaUtente; // assegna la griglia dell'utente alla partita
    partita->tentativiRimasti = tentativiRimasti; // assegna il numero di tentativi rimasti

    return 1; // restituisce 1 per indicare successo
}



int caricaPartita(char *nomeFile, char * nomeSalvataggio, Partita * partitaDaCaricare){

    FILE* fp = fopen(nomeFile,"rb"); // apre il file in modalità lettura binaria
    int esito = 0; // inizializza la variabile esito a 0
    Salvataggio s; // struttura temporanea per leggere i salvataggi

    // legge il file salvataggio per salvataggio fino a trovarne uno valido o raggiungere la fine
    while (fread(&s,sizeof(Salvataggio),1,fp) == 1 && esito == 0)
    {
        if(confrontaStringhe(s.nome,nomeSalvataggio) == 1){ // confronta il nome del salvataggio con quello richiesto
            printf("Salvataggio Trovato!"); // messaggio di conferma
            inizializzaPartita(partitaDaCaricare,s.datiPartita.difficolta,s.datiPartita.grigliaCompleta,s.datiPartita.grigliaUtente,s.datiPartita.tentativiRimasti); // inizializza la partita con i dati trovati
            esito = 1; // imposta esito a 1 per indicare successo
        }        
    }

    return esito; // restituisce 1 se trovato, 0 altrimenti
}



void visualizzaSalvataggi(const char *nomeFile) {
    FILE *file = fopen(nomeFile, "rb"); // apre il file in modalità lettura binaria

    Salvataggio s; // struttura temporanea per leggere i salvataggi

    printf("nomeSalvataggio       | tentativi | difficolta |\n"); // intestazione tabella
    printf("------------------------------------------------\n"); // separatore

    // legge ogni salvataggio dal file e lo stampa a video
    while (fread(&s, sizeof(Salvataggio), 1, file) == 1) {
        printf("%-22s | %-9d | %-10d |\n",
               s.nome,
               s.datiPartita.tentativiRimasti,
               s.datiPartita.difficolta); // stampa nome, tentativi e difficoltà del salvataggio
    }

    fclose(file); // chiude il file
}
