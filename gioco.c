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
    printf("3. Regole");
    printf("0. Esci\n");
    printf("\n> Cosa desideri fare: ");

    return 0;
}
    
