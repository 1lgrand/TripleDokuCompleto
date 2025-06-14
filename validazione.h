/*
* Autori: 
    - Abbinante Flavio
    - Campobasso Luca
    - Cillo Andrea
    - De Marzo Alessandro
    - Dell'Aquila Giovanni Luca
*
* Data Inizio: [29/05/2025]
* Nome File: [validazione.c]
* 
*/

#ifndef VALIDAZIONE_H
#define VALIDAZIONE_H

#include "gioco.h"
#include "griglia.h"
#include <stdio.h>



/*
 **********************************************************************
 *
 * FUNZIONE: int checkRiga(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int riga, int num)
 *
 * DESCRIZIONE: Verifica se un numero è già presente nella riga specificata
 *
 * PARAMETRI:
 * int griglia[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia da controllare
 * int riga: L'indice della riga da verificare
 * int num: Il numero da cercare nella riga
 *
 * RITORNO: int, 1 se il numero NON è presente (valido), 0 se è già presente
 *
 ***********************************************************************/
int checkRiga(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int riga, int num);

/*
 **********************************************************************
 *
 * FUNZIONE: int checkColonna(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int col, int num)
 *
 * DESCRIZIONE: Verifica se un numero è già presente nella colonna specificata
 *
 * PARAMETRI:
 * int griglia[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia da controllare
 * int col: L'indice della colonna da verificare
 * int num: Il numero da cercare nella colonna
 *
 * RITORNO: int, 1 se il numero NON è presente (valido), 0 se è già presente
 *
 ***********************************************************************/
int checkColonna(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int col, int num);

/*
 **********************************************************************
 *
 * FUNZIONE: int checkQuadrante(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int rigaInizio, int colInizio, int num)
 *
 * DESCRIZIONE: Verifica se un numero è già presente nel quadrante 3x3 specificato
 *
 * PARAMETRI:
 * int griglia[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia da controllare
 * int rigaInizio: Riga di inizio del quadrante (0, 3, o 6)
 * int colInizio: Colonna di inizio del quadrante (0, 3, o 6)
 * int num: Il numero da cercare nel quadrante
 *
 * RITORNO: int, 1 se il numero NON è presente (valido), 0 se è già presente
 *
 ***********************************************************************/
int checkQuadrante(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int rigaInizio, int colInizio, int num);

/*
 **********************************************************************
 *
 * FUNZIONE: int checkPosizionamento(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int riga, int col, int num)
 *
 * DESCRIZIONE: Verifica se è possibile inserire un numero in una posizione specifica
 *              controllando riga, colonna e quadrante
 *
 * PARAMETRI:
 * int griglia[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia da controllare
 * int riga: L'indice della riga dove inserire
 * int col: L'indice della colonna dove inserire
 * int num: Il numero da inserire
 *
 * RITORNO: int, 1 se il posizionamento è valido, 0 altrimenti
 *
 ***********************************************************************/
int checkPosizionamento(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int riga, int col, int num);

/*
 **********************************************************************
 *
 * FUNZIONE: int checkNomeSalvataggio(const char *nomeSalvataggio, const char *FILENAME)
 *
 * DESCRIZIONE: Verifica che il nome di salvataggio fornito non sia già 
 *              presente all'interno del file binario specificato.
 *              Utilizza la funzione confrontaStringhe per il confronto.
 *
 * PARAMETRI:
 * const char *nomeSalvataggio: Nome del salvataggio da verificare
 * const char *FILENAME:         Nome del file binario in cui cercare
 *
 * RITORNO: Intero. 
 *          1 = Il nome è valido (non esiste)
 *          0 = Il nome esiste già o si è verificato un errore
 *
 **********************************************************************/
int checkNomeSalvataggio(char *nomeSalvataggio, char *nomeFile);


/*
 **********************************************************************
 *
 * FUNZIONE: int calcolaModulo(int dividendo, int divisore)
 *
 * DESCRIZIONE: Calcola il modulo (resto della divisione intera) tra due 
 *              numeri interi positivi utilizzando sottrazioni successive.
 *
 * PARAMETRI:
 * int dividendo: Il numero da dividere
 * int divisore:  Il numero per cui dividere
 *
 * RITORNO: Intero, il valore del resto (modulo) tra dividendo e divisore
 *
 **********************************************************************/
int calcolaModulo(int dividendo, int divisore);


/*
 **********************************************************************
 *
 * FUNZIONE: void copiaStringa(const char *sorgente, char *destinazione)
 *
 * DESCRIZIONE: Copia i caratteri dalla stringa sorgente alla stringa 
 *              destinazione finché non viene raggiunto il terminatore '\0'.
 *
 * PARAMETRI:
 * const char *sorgente:   Stringa da cui leggere (input)
 * char *destinazione:     Stringa in cui scrivere (output)
 *
 * RITORNO: Nessuno. La copia viene effettuata direttamente nella destinazione.
 *
 **********************************************************************/
int copiaStringa(const char *sorgente, char *destinazione);

/*
 **********************************************************************
 *
 * FUNZIONE: int confrontaStringhe(const char *str1, const char *str2)
 *
 * DESCRIZIONE: Confronta due stringhe carattere per carattere per verificare 
 *              se sono uguali. Restituisce 1 se sono uguali, 0 altrimenti.
 *
 * PARAMETRI:
 * const char *str1: Prima stringa da confrontare
 * const char *str2: Seconda stringa da confrontare
 *
 * RITORNO: Intero, 1 se le stringhe sono uguali, 0 altrimenti
 *
 **********************************************************************/
int confrontaStringhe(const char *str1, const char *str2);

#endif