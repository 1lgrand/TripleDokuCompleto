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
int verificaValiditaGenerazione(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int riga, int col, int num);

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

#endif