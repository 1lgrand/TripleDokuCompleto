/*
* Autori: 
    - Abbinante Flavio
    - Campobasso Luca
    - Cillo Andrea
    - De Marzo Alessandro
    - Dell'Aquila Giovanni Luca
*
* Data Inizio: [29/05/2025]
* Nome File: [main.c]
*
* Scopo delle funzioni:
* - main: [Funzione principale del gioco]
* - [nome_funzione_1]: [Breve descrizione dello scopo della funzione 1]
* 
*
*
* Lista delle modifiche effettuate:
* [29/05/2025] - [DE MARZO] - [CREAZIONE DEL FILE]
* [30/05/2025] - [DE MARZO] - [Scrittura della funzione main e test della funzione di inizializzazione]
* [GG/MM/AAAA] - [Autore] - [Descrizione della modifica e del suo impatto] - [Motivo della modifica]
*/

#include "validazione.h"
#include "griglia.h"
#include "gioco.h"

#include <stdio.h>
#include <stdlib.h>

int main(){

    Griglia grigliaDiGioco;
    Griglia grigliaCompleta;
    Partita partita;
    int difficolta = 0; // Inizializzazione di difficolta, 1 = FACILE, 2 = MEDIO, 3 = DIFFICILE
    int tentativi = TENTATIVI; //Inizializzazione con il numero di tentativi validi

    titolo(); //Stampa il titolo del gioco e il gruppo 

    // Inizializzazione di tutte le sottogriglie della griglia "soluzione"
    inizializzaGriglia(grigliaCompleta.grigliaA);
    inizializzaGriglia(grigliaCompleta.grigliaB);
    inizializzaGriglia(grigliaCompleta.grigliaC);

    // Inizializzazione di tutte le sottogriglie della griglia giocabile dall'utente
    inizializzaGriglia(grigliaDiGioco.grigliaA);
    inizializzaGriglia(grigliaDiGioco.grigliaB);
    inizializzaGriglia(grigliaDiGioco.grigliaC);

    //Selezione della difficoltà
    printf("\n\n> Seleziona la difficolta del gioco: \n[1. FACILE]\n[2. MEDIO]\n[3. DIFFICILE]\n\n");
    scanf("%d",&difficolta);

    //Controllo sulla correttezza della difficoltà
    while (difficolta > 3 || difficolta < 1)
    {
        system("cls");
        printf("\n\n> Seleziona la difficolta del gioco: \n[1. FACILE]\n[2. MEDIO]\n[3. DIFFICILE]\n");
        scanf("%d",&difficolta);
    }
    


    //Visualizzazione 
    printf("\nGriglia A:\n");
    visualizzaGriglia(grigliaCompleta.grigliaA);

    printf("\nGriglia B:\n");
    visualizzaGriglia(grigliaCompleta.grigliaB);

    printf("\nGriglia C:\n");
    visualizzaGriglia(grigliaCompleta.grigliaC);

    printf("\n\n");

    printf("Hai selezionato la difficolta: %d\n",difficolta);

    system("pause");
    return 0;
}