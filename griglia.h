/*
* Autori: 
    - Abbinante Flavio
    - Campobasso Luca
    - Cillo Andrea
    - De Marzo Alessandro
    - Dell'Aquila Giovanni Luca
*
* Data Inizio: [29/05/2025]
* Nome File: [griglia.h]
*/

#ifndef GRIGLIA_H
#define GRIGLIA_H

#define GRIGLIA_LEN (9)

//Strutture dati
typedef struct {
    int grigliaA[GRIGLIA_LEN][GRIGLIA_LEN];
    int grigliaB[GRIGLIA_LEN][GRIGLIA_LEN];
    int grigliaC[GRIGLIA_LEN][GRIGLIA_LEN];
} Griglia;

/*  
 **********************************************************************
 *
 * FUNZIONE: void inizializzaGriglia(int grigliaSingola[N][N])
 *
 * DESCRIZIONE: Inizializza tutti gli elementi della griglia di gioco a zero.
 *
 * PARAMETRI:
 * int grigliaSingola[N][N]: La singola griglia della 9x9 dell'intera griglia di gioco.
 *
 * RITORNO: Intero, esito dell'operazione

 *
 ***********************************************************************/
int inizializzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]);


/*
 **********************************************************************
 *
 * FUNZIONE: Griglia generaGrigliaCompleta()
 *
 * DESCRIZIONE: Genera la soluzione della griglia di gioco,
 * che è composta da 3 griglie, le quali sono sincronizzate tra loro
 * 
 * RITORNO: Griglia grigliaCompleta: Tutte le 3 griglie complete e sincronizzate, risolte.
 *
 ***********************************************************************/
Griglia generaGrigliaCompleta();


/*
 **********************************************************************
 *
 * FUNZIONE: Griglia generaGrigliaDiGioco()
 *
 * DESCRIZIONE: Genera la griglia di gioco che il giocatore andrà effettivamente a visualizzare
 * in base alla difficoltà ricevuta vengono eliminate un numero N di celle.
 * - FACILE: 30 Celle complete ( per griglia )
 * - MEDIO: 25 Celle complete ( per griglia )
 * - DIFFICILE: 20 Celle complete ( per griglia )
 * 
 * RITORNO: Griglia grigliaDiGioco: Griglia parzialmente completa da mostrare all'utente.
 *
 ***********************************************************************/
Griglia generaGrigliaGioco(Griglia grigliaCompleta,int difficolta);

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
int sincronizzaQuadranti(int sorgente[GRIGLIA_LEN][GRIGLIA_LEN], int destinazione[GRIGLIA_LEN][GRIGLIA_LEN]);

//Funzione per la visualizzazione
void visualizzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]);

int risolviSudoku(int griglia[GRIGLIA_LEN][GRIGLIA_LEN]);

//Funzione per la mescolazione dell'array
int shuffle(int array[], int lunghezza);

#endif