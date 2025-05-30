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
*
*
* Lista delle modifiche effettuate:
* [29/05/2025] - [DE MARZO] - [CRAEZIONE DEL FILE, AGGIUNTE STRUTTURE DATI, PROTOTIPI DI inizializzaGriglia,generaGrigliaCompleta,generaGrigliaGioco]
* [GG/MM/AAAA] - [Autore] - [Descrizione della modifica e del suo impatto] - [Motivo della modifica]
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

//Funzione per la visualizzazione
void visualizzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]);








#endif