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
* - [nome_funzione_1]: [Breve descrizione dello scopo della funzione 1]
* 
*
*
* Lista delle modifiche effettuate:
* [29/05/2025] - [DE MARZO] - [CREZIONE DEL FILE]
* [02/06/2025] - [DE MARZO] - [Implementazione verificaValiditaGenerazione, calcolaModulo] 

*/

#include "gioco.h"
#include "griglia.h"
#include "validazione.h"
#include <stdio.h>


/*
**********************************************************************
*
* FUNZIONE: int verificaValiditaNumeroSudoku(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int riga, int col, int num)
*
* DESCRIZIONE: Verifica se un numero può essere inserito in una posizione 
*              specifica della griglia rispettando le regole del Sudoku.
*              Controlla che il numero non sia già presente nella stessa
*              riga, colonna o quadrante 3x3.
*
* PARAMETRI:
* int griglia[GRIGLIA_LEN][GRIGLIA_LEN]: La griglia di gioco 9x9
* int riga: L'indice della riga dove inserire il numero (0-8)
* int col: L'indice della colonna dove inserire il numero (0-8)  
* int num: Il numero da verificare (1-9)
*
* RITORNO: Intero, 1 se il numero è valido nella posizione, 0 altrimenti
*
***********************************************************************/
int verificaValiditaNumeroSudoku(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int riga, int col, int num) {
    
    int esito = 1; // Inizializza il risultato come valido

    // Inizializzazione indici
    int x = 0;
    int i = 0;
    int j = 0; 

    // Coordinate del quadrante
    int startRiga = 0;
    int startCol = 0; 
    
    // Verifica eventuale presenza nella riga nella riga
    x = 0;
    while (x < GRIGLIA_LEN && esito == 1)
    {
        if (griglia[riga][x] == num) { // Se il numero è trovato nella riga
            esito = 0; // Imposta il risultato come NON valido
        }

        x = x + 1;
    }

    // Verifica eventuale presenza nella colonna nella riga
    x = 0;
    while (x < GRIGLIA_LEN && esito == 1)
    {
        if (griglia[x][col] == num) { // Se il numero è trovato nella colonna
            esito = 0; // Imposta il risultato come NON valido
        }
        x = x + 1;
    }
    

    
    // Calcola le coordinate di inizio del quadrante 3x3
    startRiga = riga - calcolaModulo(riga,3); // Riga di inizio del quadrante
    startCol = col - calcolaModulo(col,3); // Colonna di inizio del quadrante
    
    // Verifica se il numero è già presente nel quadrante 3x3
    i = 0;
    while (i < 3 && esito) { // Cicla le righe del quadrante
        j = 0;
        while (j < 3 && esito) { // Cicla le colonne del quadrante
            if (griglia[i + startRiga][j + startCol] == num) { // Se il numero è trovato nel quadrante
                esito = 0; // Imposta il risultato come non valido
            }
            j = j + 1; 
        }
        i = i + 1; 
    }
    
    return esito; // Ritorna il risultato della validazione
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