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

#include <stdio.h>
#include <stdlib.h>

#define GRIGLIA_LEN (9) /* Dimensione fissa della griglia Sudoku 9x9 */

// ================== STRUTTURE DATI ==================

typedef struct {
    int grigliaA[GRIGLIA_LEN][GRIGLIA_LEN];
    int grigliaB[GRIGLIA_LEN][GRIGLIA_LEN];
    int grigliaC[GRIGLIA_LEN][GRIGLIA_LEN];
} Griglia;

// ================== PROTOTIPI FUNZIONI ==================

/*
 **********************************************************************
 *
 * FUNZIONE: int inizializzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN])
 *
 * DESCRIZIONE: Inizializza tutti gli elementi della griglia a zero.
 *
 * PARAMETRI:
 * int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]: La singola griglia da inizializzare
 *
 * RITORNO: Intero, esito dell'operazione (sempre 0 per successo)
 *
 ***********************************************************************/
int inizializzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]);

/*
 **********************************************************************
 *
 * FUNZIONE: int sincronizzaQuadrante(int sorgente[GRIGLIA_LEN][GRIGLIA_LEN], int destinazione[GRIGLIA_LEN][GRIGLIA_LEN], int qOrigine, int qDestinazione)
 *
 * DESCRIZIONE: Copia un singolo quadrante da una griglia sorgente a una destinazione.
 *              Mantiene la posizione relativa delle celle all'interno del quadrante.
 *
 * PARAMETRI:
 * int sorgente[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia sorgente da cui copiare
 * int destinazione[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia destinazione dove copiare
 * int qOrigine: Indice del quadrante sorgente (0-8)
 * int qDestinazione: Indice del quadrante destinazione (0-8)
 *
 * RITORNO: int, 1 quando la funzione termina con successo
 *
 ***********************************************************************/
int sincronizzaQuadrante(int sorgente[GRIGLIA_LEN][GRIGLIA_LEN], int destinazione[GRIGLIA_LEN][GRIGLIA_LEN], int qOrigine, int qDestinazione);

/*
 **********************************************************************
 *
 * FUNZIONE: void visualizzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN])
 *
 * DESCRIZIONE: Visualizza una singola griglia 9x9 del gioco stampandola a schermo
 *
 * PARAMETRI:
 * int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia da visualizzare
 *
 * RITORNO: void
 *
 ***********************************************************************/
void visualizzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]);

/*
 **********************************************************************
 *
 * FUNZIONE: int risolviSudoku(int griglia[GRIGLIA_LEN][GRIGLIA_LEN])
 *
 * DESCRIZIONE: Risolve una griglia Sudoku utilizzando l'algoritmo backtracking.
 *
 * PARAMETRI:
 * int griglia[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia da risolvere
 *
 * RITORNO: int, 1 se la soluzione è stata trovata, 0 altrimenti
 *
 ***********************************************************************/
int risolviSudoku(int griglia[GRIGLIA_LEN][GRIGLIA_LEN]);

/*
 **********************************************************************
 *
 * FUNZIONE: int shuffle(int array[], int lunghezza)
 *
 * DESCRIZIONE: Mescola gli elementi di un array utilizzando l'algoritmo Fisher-Yates
 *
 * PARAMETRI:
 * int array[]: array da mescolare
 * int lunghezza: la lunghezza dell'array
 *
 * RITORNO: int, 1 se mescolato correttamente
 *
 ***********************************************************************/
int shuffle(int array[], int lunghezza);

/*
 **********************************************************************
 *
 * FUNZIONE: int generaGrigliaCompleta(int griglia[GRIGLIA_LEN][GRIGLIA_LEN])
 *
 * DESCRIZIONE: Genera una griglia Sudoku completa e valida utilizzando backtracking
 *
 * PARAMETRI:
 * int griglia[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia da riempire
 *
 * RITORNO: int, 1 se la generazione è riuscita, 0 altrimenti
 *
 ***********************************************************************/
int generaGrigliaCompleta(int griglia[GRIGLIA_LEN][GRIGLIA_LEN]);

/*
 **********************************************************************
 *
 * FUNZIONE: int generaGrigliaVincolata(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int quadrantiBloccati[9])
 *
 * DESCRIZIONE: Genera una griglia Sudoku completa rispettando i quadranti già popolati.
 *              I quadranti bloccati non vengono modificati durante la generazione.
 *
 * PARAMETRI:
 * int griglia[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia da completare (può avere quadranti già popolati)
 * int quadrantiBloccati[9]: Array che indica quali quadranti non devono essere modificati (1=bloccato, 0=libero)
 *
 * RITORNO: int, 1 se la generazione è riuscita, 0 altrimenti
 *
 ***********************************************************************/
int generaGrigliaVincolata(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int quadrantiBloccati[9]);

/*
 **********************************************************************
 *
 * FUNZIONE: int generaTripleDoku(int griglia1[GRIGLIA_LEN][GRIGLIA_LEN], int griglia2[GRIGLIA_LEN][GRIGLIA_LEN], int griglia3[GRIGLIA_LEN][GRIGLIA_LEN])
 *
 * DESCRIZIONE: Genera le tre griglie del Triple Doku con la logica di condivisione dei quadranti.
 *              Griglia1: completa
 *              Griglia2: condivide quadranti 7,8 di griglia1 come quadranti 0,1
 *              Griglia3: condivide quadranti 5,6 di griglia2 come quadranti 0,1
 *
 * PARAMETRI:
 * int griglia1[GRIGLIA_LEN][GRIGLIA_LEN]: Prima griglia del Triple Doku
 * int griglia2[GRIGLIA_LEN][GRIGLIA_LEN]: Seconda griglia del Triple Doku  
 * int griglia3[GRIGLIA_LEN][GRIGLIA_LEN]: Terza griglia del Triple Doku
 *
 * RITORNO: int, 1 se la generazione è riuscita per tutte e tre le griglie, 0 altrimenti
 *
 ***********************************************************************/
int generaTripleDoku(int griglia1[GRIGLIA_LEN][GRIGLIA_LEN], int griglia2[GRIGLIA_LEN][GRIGLIA_LEN], int griglia3[GRIGLIA_LEN][GRIGLIA_LEN]);

#endif