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
* [01/06/2025] - [DE MARZO] - [Implementazione menu di avvio]
* [03/06/2025] - [CAMPOBASSO] - [Prototipi salvaPartita, caricaPartita]
* [06/06/2025] - [ABBINANTE] - [Implementazione funzione visualizzaGriglia]
*/

#include <stdio.h>

#include "griglia.h"
#include "gioco.h"


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
    int i = 0;
    int j = 0;
    while (i < GRIGLIA_LEN) {
        j = 0;
        while (j < GRIGLIA_LEN) {
            printf(" %d ", grigliaSingola[i][j]);
            j = j + 1;
        }
        printf("\n");
        i = i + 1;
    }
}    


int salvaPartita(char * nomeFile, Partita partita, char * nomeSalvataggio){

    FILE * fileBin = fopen(nomeFile, "a+");
    int esito = 1; // TRUE: salvataggio eseguito
    int trovato = 0; // FALSE: nome di salvataggio non esistente

    if (fileBin == NULL) {
        perror("Errore nell'apertura del file");
        return 0; // Errore nell'apertura del file
    }

    // Inizializza la variabile per leggere le righe del file 
    Salvataggio salvataggio;
    salvataggio.nome[0] = '\0'; // Inizializza la stringa
    char * riga;

    // Legge il file riga per riga per verificare se il nome di salvataggio esiste già
    while (fgets(salvataggio.nome, sizeof(salvataggio.nome), fileBin) != NULL) {
        riga = salvataggio.nome;
        if (/*compara le stringhe*/(riga == nomeSalvataggio) == 0) {
            trovato = 1; // Nome di salvataggio già esistente
            break;
        }
    }

    // Se il nome di salvataggio non esiste, lo aggiunge al file
    if (trovato) {
        esito = 0; // FALSE: già esistente
    } else {
        fprintf(fileBin, "%s|%d|%d|", nomeSalvataggio, partita.difficolta, partita.tentativiRimasti);
        int i = 0; 
        int j = 0;

        // Scrive la griglia dell'utente
        while (i < GRIGLIA_LEN) {
            while ( j < GRIGLIA_LEN) {
                fprintf(fileBin, "%d ", partita.grigliaUtente.grigliaA[i][j]);
                j = j + 1;
            }
            i = i + 1;
        }
        
        i = 0;
        j = 0; 
        // Scrive la griglia completa
        while (i < GRIGLIA_LEN) {
            while (j < GRIGLIA_LEN) {
                fprintf(fileBin, "%d ", partita.grigliaCompleta.grigliaA[i][j]);
                j = j + 1;
            }
            i = i + 1;
        }
    }
    fclose(fileBin);
    return esito; // Restituisce 1 se il salvataggio è stato eseguito, 0 se il nome di salvataggio esiste già
}
