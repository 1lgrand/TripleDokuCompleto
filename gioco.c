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
* [06/06/2025] - [DELL'AQUILA] - [Implementazione funzione salvaPartita]    
*/

#include <stdio.h>
#include <string.h> // Da eliminare

#include "griglia.h"
#include "gioco.h"

extern int confrontaStringhe(const char *stringa1, const char *stringa2);

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


int salvaPartita(char * nomeFile, Salvataggio salvataggio){

    FILE *file = fopen(nomeFile, "ab");  // append in binary

    fwrite(&salvataggio, sizeof(Salvataggio), 1, file);

    fclose(file);

    return 1;
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


int caricaPartita(char *nomeFile, Caricamento *caricamento){
    FILE *file = fopen(nomeFile, "rb");
    if(file == NULL){
        return 0;
    }
    
    int esito = 0;
    Caricamento temp;
    
    while(fread(&temp, sizeof(Caricamento), 1, file) == 1 && !esito){
        if(confrontaStringhe(temp.nome, caricamento->nome)){
            esito = 1;
            *caricamento = temp;  
        }
    }
    
    fclose(file);
    return esito; 
}
