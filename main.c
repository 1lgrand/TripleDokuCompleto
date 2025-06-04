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
* [01/06/2025] - [DE MARZO] - [Test menu di avvio] 
*/

#include "validazione.h"
#include "griglia.h"
#include "gioco.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0));

    Griglia grigliaDiGioco;
    Griglia grigliaCompleta;
    Partita partita;
    int tentativi = TENTATIVI; //Inizializzazione con il numero di tentativi validi

    int difficolta = 0; // Inizializzazione di difficolta, 1 = FACILE, 2 = MEDIO, 3 = DIFFICILE
    int menuIniziale = 0; //Inizializza la variabile che si occupa di gestire la scelta del menu di avvio, a 0

    // Inizializzazione di tutte le sottogriglie della griglia "soluzione"
    inizializzaGriglia(grigliaCompleta.grigliaA);
    inizializzaGriglia(grigliaCompleta.grigliaB);
    inizializzaGriglia(grigliaCompleta.grigliaC);


    // Inizializzazione di tutte le sottogriglie della griglia giocabile dall'utente
    inizializzaGriglia(grigliaDiGioco.grigliaA);
    inizializzaGriglia(grigliaDiGioco.grigliaB);
    inizializzaGriglia(grigliaDiGioco.grigliaC);



    //TODO: Funzione (validazione.c) che validi la scelta del menu iniziale e ritorni qualcosa per gestire il menu
    titolo(); //Stampa il titolo del gioco e il gruppo 
    menuAvvio();
    scanf("%d",&menuIniziale);

    while (menuIniziale < 0 || menuIniziale > 3)
    {
        system("cls");
        titolo(); //Stampa il titolo del gioco e il gruppo 
        menuAvvio();
        scanf("%d",&menuIniziale);
    }

    system("cls");
    titolo();

    /* TODO: TRASFORMARE IN FUNZIONE TUTTA LA SELEZIONE DELLA DIFFICOLTA' E RITORNARE UN INTERO COMPRESO TRA 1 E 3
             Scrivendo una funzone in validazione che gestisca il tutto
    */
    //Selezione della difficoltà
    printf("\n\n> Seleziona la difficolta del gioco: \n1. FACILE\n2. MEDIO\n3. DIFFICILE\n\n");
    scanf("%d",&difficolta);

    //Controllo sulla correttezza della difficoltà
    while (difficolta > 3 || difficolta < 1)
    {
        system("cls");
        titolo();
        printf("\n\n> Seleziona la difficolta del gioco: \n1. FACILE\n2. MEDIO\n3. DIFFICILE\n\n");
        scanf("%d",&difficolta);
    }
    
    
    generaTripleDoku(grigliaCompleta.grigliaA,grigliaCompleta.grigliaB,grigliaCompleta.grigliaC);

    

    //Visualizzazione delle griglie
    // TODO: Modificare e mettere in una funzione in gioco.h per la visualizzazione corretta 
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


