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
* [02/06/2025] - [DE MARZO] - [Prototipo e implementazone calcolaModulo,checkRiga, checkColonna]
* [04/06/2025] - [CILLO] - [Prototipi di funzione: checkQuadrante, checkPosizionamento] 
* 
*/

#include "gioco.h"
#include "griglia.h"
#include "validazione.h"
#include <stdio.h>

/*     X CILLO ( CANCELLAMI DOPO CHE HAI FINITO )


    - checkRiga:
        Controlla se il numero 'num' è già presente nella riga specificata.
        Esempio: se la riga 0 contiene [5, 3, 0, 0, 7, 0, 0, 0, 0] e num è 5, restituisce 0 (già presente).
                 Se num è 4, restituisce 1 (non presente → posizionabile in quella riga).

    - checkColonna:
        Stessa logica della riga, ma applicata alla colonna.
        Esempio: se la colonna 1 contiene [3, 0, 9, 0, 0, 0, 6, 0, 0] e num è 9, restituisce 0.

    - checkQuadrante:
        Controlla se il numero è già presente nel quadrante 3x3 che contiene la cella.
        Per trovare il quadrante corretto, si passa l’indice della prima riga e colonna del blocco.
        Esempio: se voglio controllare la cella (4,4), il quadrante inizia da (3,3), quindi si passa (3,3).
                 La funzione esamina la sottogriglia da (3,3) a (5,5). Se il numero è presente lì, restituisce 0.

    - checkPosizionamento:
        Verifica se è lecito inserire il numero 'num' nella posizione (riga, col), controllando:
        - Se il numero non è nella stessa riga
        - Se il numero non è nella stessa colonna
        - Se il numero non è nel quadrante 3x3 corrispondente

        Pseudocodice:
            rigaQuadrante = (riga / 3) * 3
            colQuadrante = (col / 3) * 3

            se checkRiga(riga, num) è OK
               e checkColonna(col, num) è OK
               e checkQuadrante(rigaQuadrante, colQuadrante, num) è OK
            allora
               restituisci 1 (posizionamento valido)
            altrimenti
               restituisci 0 (non valido)

        Esempio: per posizionare il numero 2 nella cella (0,2):
            - controlla la riga 0
            - controlla la colonna 2
            - controlla il quadrante in alto a sinistra (rigaInizio = 0, colInizio = 0)
            Se 2 non è presente in nessuna di queste tre aree → restituisce 1.
*/



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