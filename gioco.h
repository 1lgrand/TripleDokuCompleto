/*
* Autori: 
    - Abbinante Flavio
    - Campobasso Luca
    - Cillo Andrea
    - De Marzo Alessandro
    - Dell'Aquila Giovanni Luca
*
* Data Inizio: [29/05/2025]
* Nome File: [gioco.h]
*/

#ifndef GIOCO_H
#define GIOCO_H

#include "griglia.h"

#define TENTATIVI (7) /* Numero di tentativi da cui si parte */
#define FILENAME ("salvataggi.dat") /* Nome del file binario dove sono conservati i salvataggi */
#define MAX_SALVATAGGIO (64) /* Massimo di caratteri accettati per il nome del salvataggio*/

// ================== STRUTTURE DATI ==================

// Struttura che raccoglie tutti i dati relativi alla partita corrente
typedef struct {
    int tentativiRimasti; // numero di tentativi rimasti al giocatore
    int difficolta;       // difficoltà selezionata dall'utente
    Griglia grigliaUtente;  // griglia dove l'utente inserisce i numeri
    Griglia grigliaCompleta; // soluzione del sudoku
} Partita;

// Struttura impiegata per salvare la partita all'interno del file binario
typedef struct {
    char nome[MAX_SALVATAGGIO]; // nome del salvataggio (es. array di char per sequenza di caratteri)
    Partita datiPartita; // dato strutturato contenente le informazioni relative alla partita
} Salvataggio;

/*
 **********************************************************************
 *
 * FUNZIONE: void inizializzaPartita(Partita *partita, int difficolta, Griglia grigliaCompleta, Griglia grigliaUtente, int tentativiRimasti)
 *
 * DESCRIZIONE: Inizializza i campi della struttura Partita con i valori forniti.
 *
 * PARAMETRI:
 * Partita *partita:        Puntatore alla struttura Partita da inizializzare
 * int difficolta:          Livello di difficoltà selezionato (1 = FACILE, 2 = MEDIO, 3 = DIFFICILE)
 * Griglia grigliaCompleta: Griglia completa (soluzione del gioco)
 * Griglia grigliaUtente:   Griglia modificabile dall'utente
 * int tentativiRimasti:    Numero di tentativi rimasti all'utente
 *
 * RITORNO: Nessuno. La struttura viene modificata attraverso il puntatore.
 *
 **********************************************************************/
int inizializzaPartita(Partita *partita, int difficolta, Griglia grigliaCompleta, Griglia grigliaUtente, int tentativiRimasti);

/*
 **********************************************************************
 *
 * FUNZIONE: int SalvaPartita(char *nomeFile, Partita *partita, char *nomeSalvataggio)
 *
 * DESCRIZIONE: Salva i dati della "partita" nel file binario con il nome univoco "nomeSalvataggio".
 * Verifica se un salvataggio con lo stesso nome esiste già nel file.
 *
 * ARGOMENTI:
 * const char *nomeFile: Nome del file binario di salvataggio.
 * const Partita *partita: Puntatore alla struttura Partita da salvare.
 * const char *nomeSalvataggio: Nome univoco da associare a questo salvataggio.
 *
 * RITORNO: int: 1 se il salvataggio è avvenuto con successo, 0 altrimenti (es. nome già esistente).
 *
 ***********************************************************************/
int salvaPartita(char * nomeFile, Salvataggio salvataggio);


/*
 **********************************************************************
 *
 * FUNZIONE: int (char *nomeFile, char *nomeCaricamento, Partita *partita)
 *
 * DESCRIZIONE: Carica i dati di una partita dal file binario di salvataggio, identificata da una stringa univoca "nomeCaricamento".
 * I dati caricati vengono copiati nella struttura "partita".
 *
 * ARGOMENTI:
 * Stringa nomeFile: Nome del file binario da cui caricare.
 * Stringa nomeCaricamento: Nome del salvataggio da cercare nel file.
 * Partita *partita: Puntatore alla struttura Partita dove verranno caricati i dati.
 *
 * RITORNO: esito (intero): 1 se il caricamento è avvenuto con successo, 0 altrimenti (es. salvataggio non trovato).
 *
 ***********************************************************************/
int caricaPartita(char *nomeFile, char * nomeSalvataggio, Partita * partitaDaCaricare);




/* === INTERFACCE ===
Le prossime funzioni riguardano tutte le operazioni di stampa per la visualizzazione delle varie interfacce
*/


/*
 **********************************************************************
 *
 * FUNZIONE: int titolo
 *
 * DESCRIZIONE: Visualizza il titolo del progetto ed il numero gruppo
 *
 * RITORNO: esito (intero): 0 quando viene eseguita la stampa del titolo 
 *
 *
 ***********************************************************************/
int titolo();

/*
 **********************************************************************
 *
 * FUNZIONE: int menuAvvio
 *
 * DESCRIZIONE: Visualizza il menu di avvio con le opzioni per creare una nuova partita, caricarla da file oppure uscire dal gioco
 *
 * RITORNO: esito (intero): 0 quando viene eseguita la stampa del menu 
 *
 *
 ***********************************************************************/
int menuAvvio();

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


void visualizzaSalvataggi(const char *nomeFile);

#endif