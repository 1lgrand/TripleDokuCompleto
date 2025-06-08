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
*/

#include <stdio.h>
#include <string.h> // Da eliminare

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



// Salva il salvataggio creato nel file
int salvaPartita(char * nomeFile, Salvataggio salvataggio){

    FILE *file = fopen(nomeFile, "ab");  

    fwrite(&salvataggio, sizeof(Salvataggio), 1, file);

    fclose(file);

    return 1;
}

int inizializzaPartita(Partita *partita, int difficolta, Griglia grigliaCompleta, Griglia grigliaUtente, int tentativiRimasti) {

    partita->difficolta = difficolta;
    partita->grigliaCompleta = grigliaCompleta;
    partita->grigliaUtente = grigliaUtente;
    partita->tentativiRimasti = tentativiRimasti;

    return 1;
}


int caricaPartita(char *nomeFile, char * nomeSalvataggio, Partita * partitaDaCaricare){

    FILE* fp = fopen(nomeFile,"rb");
    int esito = 0;
    Salvataggio s;


    while (fread(&s,sizeof(Salvataggio),1,fp) == 1 && esito == 0)
    {
        if(confrontaStringhe(s.nome,nomeSalvataggio) == 1){
            printf("Salvataggio Trovato!");
            inizializzaPartita(partitaDaCaricare,s.datiPartita.difficolta,s.datiPartita.grigliaCompleta,s.datiPartita.grigliaUtente,s.datiPartita.tentativiRimasti);
            esito = 1;
        }        
    }


    return esito;

}


void visualizzaSalvataggi(const char *nomeFile) {
    FILE *file = fopen(nomeFile, "rb");
    if (!file) {
        perror("Errore nell'apertura del file");
        return;
    }

    Salvataggio s;

    printf("nomeSalvataggio       | tentativi | difficolta |\n");
    printf("------------------------------------------------\n");

    while (fread(&s, sizeof(Salvataggio), 1, file) == 1) {
        printf("%-22s | %-9d | %-10d |\n",
               s.nome,
               s.datiPartita.tentativiRimasti,
               s.datiPartita.difficolta);
    }

    fclose(file);
}