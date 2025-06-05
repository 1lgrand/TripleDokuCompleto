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
#define C_FACILE (35) /* Numero di celle piene nella modalità FACILE */
#define C_INTERMEDIO (25) /* Numero di celle piene nella modalità INTERMEDIO */
#define C_DIFFICLE (20) /* Numero di celle piene nella modalità DIFFICILE */

/*
* Numero massimo di coordinate memorizzabili
* per evitare che ci siano duplicati nella generazione casuale
* annullando la possibilita di riempire meno celle di quanto previsto dalla difficoltà
*/
#define MAX_COORDINATE_MEMORIZZABILI (35) 

// ================== STRUTTURE DATI ==================

typedef struct {
    int grigliaA[GRIGLIA_LEN][GRIGLIA_LEN];
    int grigliaB[GRIGLIA_LEN][GRIGLIA_LEN];
    int grigliaC[GRIGLIA_LEN][GRIGLIA_LEN];
} Griglia;

typedef struct {
    int x;
    int y;
} Coordinate;

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
 * DESCRIZIONE: Mescola gli elementi di un array
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

//TODO: cambiare DS nei parametri da int (x3) a Griglia * grigliaCompleta, e rimuovere l'inizializzazione
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

//TODO: SCRIVERE COMMENTO
int generaGrigliaDiGioco(Griglia * grigliaCompleta, Griglia * grigliaDiGioco, int difficolta);

/*
 **********************************************************************
 *
 * FUNZIONE: ricercaCoordinate(Coordinate * coordinate, int x, int y )
 *
 * DESCRIZIONE: Ricerca usando l'algoritmo di ricerca lineare le coordinate generate per la generazione della griglia di gioco per l'utente
 *              Qualora si verificasse un duplicato, il numero di celle già riempite potrebbe risultare minore rispetto al numero previsto dalla difficoltà.
 *              Si risolve il problema, salvando le coordinate generate al fine di garantire la corretta generazione.
 *
 * PARAMETRI:
 * Coordinate coordinate, array di coordinate dove sono salvate tutte le precedenti, di dimensione 30, che è il caso "peggiore", dove è necessario salvare piu coordinate
 * int x, coordinata x della griglia che si sta andando a generare
 * int y, coordinata y della griglia che si sta andando a generare
 *
 * RITORNO: int, 1 se è stato trovato un duplicato, 0 se non è stato trovato alcun duplicato
 * 
 * NOTA SUGLI ALGORITMI: viene utilizzata l'algoritmo di ricerca lineare per controllare eventuali duplicati.
 *
 ***********************************************************************/
int ricercaCoordinate(Coordinate * coordinate, int x, int y );


/*
 **********************************************************************
 *
 * FUNZIONE: inizializzaCoordinate(Coordinate * coordinate)
 *
 * DESCRIZIONE: Inizializza tutte le coordinate dell'array passato come parametro
 *              con valori predefiniti (x = 9, y = 9).
 *              Serve a evitare che nell'array siano presenti valori superflui o duplicati
 *              prima della generazione delle vere coordinate per la singola griglia.
 *
 * PARAMETRI:
 * Coordinate * coordinate, array di coordinate da inizializzare,
 * utilizzato per salvare tutte le coordinate generate finora per prevenire duplicati.
 *
 * RITORNO: int, 1 per indicare che l'inizializzazione è stata completata con successo
 * 
 *
 *
 **********************************************************************/
int inizializzaCoordinate(Coordinate * coordinate);


#endif