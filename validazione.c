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
* [02/06/2025] - [CILLO] - [Prototipo e implementazone calcolaModulo,checkRiga, checkColonna]
* [04/06/2025] - [CILLO] - [Prototipi di funzione: checkQuadrante, checkPosizionamento] 
* [05/06/2025] - [CILLO] - [Implementazione checkRiga, checkColonna, checkQuadrante, checkPosizionamento] 
* [07/06/2025] - [DE MARZO] - [Implementazione copiaStringa] - [Funzione utile per inserire il nome del salvataggio inserito da tastiera, nel record corrispondente]
* [07/06/2025] - [CAMPOBASSO] - [Implementazione confrontaStringa] - [Funzione utile per confrontare i nomi dei salvataggi]

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


// UTILITY 

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
    // Sottrae ripetutamente il divisore dal dividendo finché
    // il dividendo non diventa minore del divisore
    while (dividendo >= divisore) {
        dividendo = dividendo - divisore; 
    }

    return dividendo; // Ritorno del resto della divisione (modulo)
}


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
int copiaStringa(const char *sorgente, char *destinazione) {
    int i = 0; // Indice per scorrere i caratteri delle stringhe

    // Copia ogni carattere della sorgente fino al terminatore '\0'
    while (sorgente[i] != '\0') {
        destinazione[i] = sorgente[i]; // Assegna il carattere corrente
        i = i + 1; // Passa al carattere successivo
    }

    destinazione[i] = '\0'; // Aggiunge il terminatore di stringa
}

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
int confrontaStringhe(const char *str1, const char *str2){
    int i = 0;
    int esito = 0;

    // Confronta i caratteri delle due stringhe finché entrambe non terminano
    while(str1[i] != '\0' && str2[i] != '\0'){
        // Se i caratteri correnti sono diversi, le stringhe non sono uguali
        if(str1[i] != str2[i]){
            esito = 0;   // Imposta l'esito a 0 (non uguali) ma non esce subito
        }
        i = i + 1;
    }

    // Dopo il ciclo, controlla se entrambe le stringhe sono terminate
    if(str1[i] == '\0' && str2[i] == '\0'){
        esito = 1;   // Le stringhe sono uguali
    } else {
        esito = 0;   // Una stringa è più lunga dell'altra, quindi non sono uguali
    }

    return esito;   // Ritorno unico
}