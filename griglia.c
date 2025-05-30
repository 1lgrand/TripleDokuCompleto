/*
* Autori: 
    - Abbinante Flavio
    - Campobasso Luca
    - Cillo Andrea
    - De Marzo Alessandro
    - Dell'Aquila Giovanni Luca
*
* Data Inizio: [29/05/2025]
* Nome File: [griglia.c]
*
* Scopo delle funzioni:
* - [inizializzaGriglia]: [Inizializza a 0 tutti i valori delle griglie del gioco]
* 
* 
* Lista delle modifiche effettuate:
* [29/05/2025] - [DE MARZO] - [CREAZIONE DEL FILE]
* [30/05/2025] - [DELL'AQUILA] - [IMPLEMENTAZIONE DELLE FUNZIONI: inizializzaGriglia ] - [Implementazione della funzione di inizializzazione per le griglie]
* [GG/MM/AAAA] - [Autore] - [Descrizione della modifica e del suo impatto] - [Motivo della modifica]
*/

#include <stdio.h>
#include <stdlib.h>


#include "griglia.h"

/*
 **********************************************************************
 *
 * FUNZIONE: void inizializzaGriglia(int grigliaSingola[N][N])
 *
 * DESCRIZIONE: Inizializza tutti gli elementi della griglia di gioco e della griglia dove sarà presente la soluzione, a zero.
 *
 * PARAMETRI:
 * int grigliaSingola[N][N]: La singola griglia della 9x9 dell'intera griglia di gioco.
 *
 * RITORNO: Intero, esito dell'operazione
 *
 ***********************************************************************/
int inizializzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]){

    //Inizializzazione degli indici x e y della griglia
    int y = 0;
    int x = 0;

    //Ciclo che scorre sulle RIGHE della griglia 
    while (y <= GRIGLIA_LEN) {
        x = 0;
        
        //Ciclo che scorre sulle COLONNE della griglia 
        while (x <= GRIGLIA_LEN) {
            grigliaSingola[y][x] = 0; //Inizializza a 0 l'elemento nella posizione y,x
            x = x + 1;
        }

        //Incrementa l'indice per passare alla riga successiva
        y = y + 1;
    }

    return 0; //Ritorna 0 al termine dell'operazione
}


void visualizzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]){
    int i = 0;
    int j = 0;

    while (i<GRIGLIA_LEN)
    {
        j = 0;
        while (j < GRIGLIA_LEN)
        {
            printf(" %d ", grigliaSingola[i][j]);
            j = j + 1;
        }
        printf("\n");
        i = i + 1;
    }
    
}



/*
Griglia generaGrigliaCompleta(){
    Griglia grigliaCompleta;

    int x = 0;
    int y = 0;
    int valido = 0;
    int riempiti = 0;
    int numeroCasuale = 0;

    inizializzaGriglia(grigliaCompleta.grigliaA);
    inizializzaGriglia(grigliaCompleta.grigliaB);
    inizializzaGriglia(grigliaCompleta.grigliaC);

    while (riempiti < n) {
        x = rand() % GRIGLIA_LEN; 
        y = rand() % GRIGLIA_LEN; 
        numeroCasuale = rand() % GRIGLIA_LEN; 

        valido = validaNumero(grigliaCompleta.ga, x, y, numeroCasuale);

        if (valido == 1) {
            grigliaCompleta.ga[y][x] = numeroCasuale;
            riempiti++;
        }
    }

    riempiti = 0;
    while (riempiti < n) {
        x = rand() % GRIGLIA_LEN; 
        y = rand() % GRIGLIA_LEN;
        numeroCasuale = rand() % GRIGLIA_LEN; 

        valido = validaNumero(grigliaCompleta.ga, x, y, numeroCasuale);

        if (valido == 1) {
            grigliaCompleta.gb[y][x] = numeroCasuale;
            riempiti++;
        }
    }

    riempiti = 0;
    while (riempiti < n) {
        x = rand() % GRIGLIA_LEN; 
        y = rand() % GRIGLIA_LEN; 
        numeroCasuale = rand() % GRIGLIA_LEN; 
        valido = validaNumero(grigliaCompleta.gc, x, y, numeroCasuale);

        if (valido == 1) {
            grigliaCompleta.gc[y][x] = numeroCasuale;
            riempiti++;
        }
    }

    sincronizzaQuadranti(grigliaCompleta);

    //Risolvi(grigliaCompleta.ga);
    //Risolvi(grigliaCompleta.gb);
    //Risolvi(grigliaCompleta.gc);

    return grigliaCompleta;
}
*/


/*
Griglia generaGrigliaGioco(Griglia grigliaCompleta, int difficolta){
    Griglia grigliaDiGioco;
    int celleDaLasciare = 0;
    int celleDaRimuovere = 0;

    grigliaDiGioco.ga = (int**)malloc(GRIGLIA_LEN * sizeof(int*));
    grigliaDiGioco.gb = (int**)malloc(GRIGLIA_LEN * sizeof(int*));
    grigliaDiGioco.gc = (int**)malloc(GRIGLIA_LEN * sizeof(int*));
    
    int i = 0;
    while (i < GRIGLIA_LEN) {
        grigliaDiGioco.ga[i] = (int*)malloc(GRIGLIA_LEN * sizeof(int));
        grigliaDiGioco.gb[i] = (int*)malloc(GRIGLIA_LEN * sizeof(int));
        grigliaDiGioco.gc[i] = (int*)malloc(GRIGLIA_LEN * sizeof(int));
        i = i + 1;
    }

    if (difficolta == 1) {
        celleDaLasciare = 30;
    } else if (difficolta == 2) {
        celleDaLasciare = 25;
    } else if (difficolta == 3) {
        celleDaLasciare = 20;
    }
    celleDaRimuovere = 81 - celleDaLasciare;

    grigliaDiGioco = grigliaCompleta;

    riempiti = 0;
    while (riempiti < celleDaRimuovere) {
        int x = rand() % GRIGLIA_LEN; 
        int y = rand() % GRIGLIA_LEN; 

        if (grigliaDiGioco.ga[y][x] != 0) {
            grigliaDiGioco.ga[y][x] = 0;
            riempiti++;
        }
    }

    riempiti = 0;
    while (riempiti < celleDaRimuovere) {
        int x = rand() % GRIGLIA_LEN;
        int y = rand() % GRIGLIA_LEN;

        if (grigliaDiGioco.gb[y][x] != 0) {
            grigliaDiGioco.gb[y][x] = 0;
            riempiti++;
        }
    }

    riempiti = 0;
    while (riempiti < celleDaRimuovere) {
        int x = rand() % GRIGLIA_LEN; 
        int y = rand() % GRIGLIA_LEN; 

        if (grigliaDiGioco.gc[y][x] != 0) {
            grigliaDiGioco.gc[y][x] = 0;
            riempiti++;
        }
    }

    sincronizzaQuadranti(grigliaDiGioco);

    return grigliaDiGioco;
}*/


/*void sincronizzaQuadranti(Griglia griglia){
    int x = 3;
    int y = 6;

    while(y < GRIGLIA_LEN) {
        while (x < GRIGLIA_LEN) {
            griglia.gb[y - 5][x - 2] = griglia.ga[y][x];
            griglia.gc[y - 5][x - 2] = griglia.gb[y][x];
            x = x + 1;
        }
        y = y + 1;
    }
}*/