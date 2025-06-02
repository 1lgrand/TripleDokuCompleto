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
* [31/05/2025] - [DE MARZO] - [IMPLEMENTAZIONE sincronizzaQuadranti] - [Funzione per sincronizzare i quadranti condivisi delle griglie]
* [GG/MM/AAAA] - [Autore] - [Descrizione della modifica e del suo impatto] - [Motivo della modifica]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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







/*
 **********************************************************************
 *
 * FUNZIONE: void sincronizzaQuadranti(int sorgente[GRIGLIA_LEN][GRIGLIA_LEN], int destinazione[GRIGLIA_LEN][GRIGLIA_LEN])
 *
 * DESCRIZIONE: Sincronizza i quadranti condivisi tra due griglie del Triple Doku.
 *              Copia gli ultimi 2 quadranti (6,7) della griglia sorgente 
 *              nei primi 2 quadranti (0,1) della griglia destinazione.
 *              Il quadrante 6 (basso-sinistra) viene copiato nel quadrante 0 (alto-sinistra)
 *              e il quadrante 7 (basso-centro) viene copiato nel quadrante 1 (alto-centro).
 *
 * PARAMETRI:
 * int sorgente[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia sorgente da cui copiare i quadranti
 * int destinazione[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia destinazione dove copiare i quadranti
 *
 * RITORNO: esito, 1 quando la funzione termina con successo, intero
 *
 ***********************************************************************/
int sincronizzaQuadranti(int sorgente[GRIGLIA_LEN][GRIGLIA_LEN], int destinazione[GRIGLIA_LEN][GRIGLIA_LEN]) {
    // Variabili per gli indici dei cicli
    int i = 0;
    int j = 0;
    
    // Copia del quadrante 6 (basso-sx) -> quadrante 0 (alto-sx)
    i = 6; 
    while (i <= 8) { // Cicla nelle righe del quadrante sorgente
        j = 0; // Inizializza l'indice della colonna
        while (j <= 2) { // Cicla nelle colonne del quadrante sorgente
            destinazione[i - 6][j] = sorgente[i][j]; // Copia l'elemento dalla sorgente alla destinazione
            j = j + 1; // Incrementa l'indice della colonna
        }
        i = i + 1; // Incrementa l'indice della riga
    }
    
    // Copia quadrante 7 (basso-centro) -> quadrante 1 (alto-centro)
    i = 6;
    while (i <= 8) { // Cicla nelle righe del quadrante sorgente
        j = 3; // Inizializza l'indice della colonna
        while (j <= 5) { // Cicla nelle colonne del quadrante sorgente
            destinazione[i - 6][j] = sorgente[i][j]; // Copia l'elemento dalla sorgente alla destinazione
            j = j + 1; // Incrementa l'indice della colonna
        }
        i = i + 1; // Incrementa l'indice della riga
    }

    return 1;
}

// Visualizza una sola matrice della Griglia di gioco !
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
 **********************************************************************
 *
 * FUNZIONE: int risolviSudoku(int griglia[GRIGLIA_LEN][GRIGLIA_LEN])
 * 
 * DESCRIZIONE: Genera una singola griglia completa
 *
 * PARAMETRI:
 * int griglia[GRIGLIA_LEN][GRIGLIA_LEN] : griglia di grandezza 9x9
 *
 * RITORNO: soluzioneValida, Risultato per la cella specifica nel sudoku; 1, se la cella è gia piena ovverola griglia è completa
 *
 ***********************************************************************/

int risolviSudoku(int griglia[GRIGLIA_LEN][GRIGLIA_LEN]){
    
}



