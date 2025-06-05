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
* Scopo delle funzioni:
* - [checkRiga]: [Verifica se un numero è già presente nella riga specificata] 
* - [checkColonna]: [Verifica se un numero è già presente nella colonna specificata] 
* - [checkQuadrante]: [Verifica se un numero è già presente nel quadrante 3x3 specificato] 
* - [checkPosizionamento]: [Verifica se è possibile inserire un numero in una posizione specifica]
* - [calcolaModulo]: [Calcola il resto della divisione tra due numeri interi]
* 
*
*
* Lista delle modifiche effettuate:
* [29/05/2025] - [DE MARZO] - [CREZIONE DEL FILE]
* [02/06/2025] - [DE MARZO] - [Prototipo e implementazone calcolaModulo,checkRiga, checkColonna]
* [04/06/2025] - [CILLO] - [Prototipi di funzione: checkQuadrante, checkPosizionamento] 
* [05/06/2025] - [CILLO] - [Implementazione checkRiga, checkColonna, checkQuadrante, checkPosizionamento] 

*/

#include "gioco.h"
#include "griglia.h"
#include "validazione.h"
#include <stdio.h>

/* == PER CILLO: COMMENTA BENE LE ISTRUZIONI DELLE FUNZIONI */

int checkRiga(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int riga, int num) {
    int col = 0;
    int esito = 1;
    while (col < GRIGLIA_LEN && esito == 1) {
        if (griglia[riga][col] == num) {
            esito = 0;
        }
        col = col + 1;
    }
    return esito;
}



int checkColonna(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int col, int num) {
    int riga = 0;
    int esito = 1;
    while (riga < GRIGLIA_LEN && esito == 1) {
        if (griglia[riga][col] == num) {
            esito = 0;
        }
        riga = riga + 1;
    }
    return esito;
}



int checkQuadrante(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int rigaInizio, int colInizio, int num) {
    int i = rigaInizio;
    int j = 0;
    int esito = 1;
    while (i < rigaInizio + 3 && esito == 1) {
        j = colInizio;
        while (j < colInizio + 3 && esito == 1) {
            if (griglia[i][j] == num) {
                esito = 0;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    return esito;
}



int checkPosizionamento(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int riga, int col, int num) {
    int rigaQuadrante = (riga / 3) * 3;
    int colQuadrante = (col / 3) * 3;
    int esito = 0;
    if (checkRiga(griglia, riga, num) == 1 && checkColonna(griglia, col, num) == 1 && checkQuadrante(griglia, rigaQuadrante, colQuadrante, num) == 1) {
        esito = 1;
    }
    return esito;
}




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
int calcolaModulo(int dividendo, int divisore) {
    while (dividendo >= divisore) {
        dividendo = dividendo - divisore; 
    }
    return dividendo; // Ritorno del modulo
}