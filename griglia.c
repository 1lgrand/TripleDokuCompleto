/*
* Autori: 
    - Abbinante Flavio
    - Campobasso Luca
    - Cillo Andrea
    - De Marzo Alessandro
    - Dell'Aquila Giovanni Luca
*
* Data Inizio: [29/05/2025]
* Nome File: [griglia.c]
*
* Scopo delle funzioni:
* - [inizializzaGriglia]: [Inizializza a 0 tutti i valori delle griglie del gioco]
* - [sincronizzaQuadrante]: [Sincronizza un singolo quadrante tra due griglie]
* - [visualizzaGriglia]: [Visualizza una singola griglia 9x9]
* - [checkRiga]: [Verifica se un numero è già presente nella riga specificata]
* - [checkColonna]: [Verifica se un numero è già presente nella colonna specificata]
* - [checkQuadrante]: [Verifica se un numero è già presente nel quadrante 3x3 specificato]
* - [checkPosizionamento]: [Verifica se è possibile inserire un numero in una posizione specifica]
* - [generaGrigliaCompleta]: [Genera una griglia Sudoku completa utilizzando backtracking]
* - [shuffle]: [Mescola gli elementi di un array]
* - [generaGrigliaVincolata]: [Genera una griglia rispettando i quadranti già popolati]
* - [generaTripleDoku]: [Genera le tre griglie del Triple Doku con condivisione dei quadranti]
* 
* Lista delle modifiche effettuate:
* [29/05/2025] - [DE MARZO] - [CREAZIONE DEL FILE]
* [30/05/2025] - [DELL'AQUILA] - [IMPLEMENTAZIONE DELLE FUNZIONI: inizializzaGriglia ] - [Implementazione della funzione di inizializzazione per le griglie]
* [31/05/2025] - [DE MARZO] - [IMPLEMENTAZIONE sincronizzaQuadrante] - [Funzione per sincronizzare i quadranti condivisi delle griglie]
* [02/06/2025] - [DE MARZO] - [IMPLEMENTAZIONE funzioni utili a generaGrigliaCompleta] - [Implementazione delle funzioni che compongono la struttura di generaGrigliaCompleta]
* [02/06/2025] - [ABBINANTE] - [IMPLEMENTAZIONE generaGrigliaCompleta, shuffle]
* [04/06/2025] - [DE MARZO] - [IMPLEMENTAZIONE generazione vincolata] - [Implementazione delle funzioni per la generazione vincolata del Triple Doku]
* [04/06/2025] - [CORREZIONE] - [Correzione sincronizzazione quadranti e un solo ritorno per funzione]
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "griglia.h"
#include "validazione.h"

int inizializzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]) {
    int y = 0;
    int x = 0;
    int esito = 0;
    while (y < GRIGLIA_LEN) {
        x = 0;
        while (x < GRIGLIA_LEN) {
            grigliaSingola[y][x] = 0;
            x = x + 1;
        }
        y = y + 1;
    }
    return esito;
}

int sincronizzaQuadrante(int sorgente[GRIGLIA_LEN][GRIGLIA_LEN], int destinazione[GRIGLIA_LEN][GRIGLIA_LEN], int qOrigine, int qDestinazione) {
    
    int rigaInizioOrigine = (qOrigine / 3) * 3;
    int colonnaInizioOrigine = (calcolaModulo(qOrigine,3)) * 3;

    int rigaInizioDest = (qDestinazione / 3) * 3;
    int colonnaInizioDest = (calcolaModulo(qDestinazione,3)) * 3;

    int y = 0;
    int x = 0;

    while (y < 3) {
        x = 0;
        while (x < 3) {
            destinazione[rigaInizioDest + y][colonnaInizioDest + x] = sorgente[rigaInizioOrigine + y][colonnaInizioOrigine + x];
            x = x + 1;
        }
        y = y + 1;
    }

    return 1;
}

void visualizzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]) {
    int i = 0;
    int j = 0;
    while (i < GRIGLIA_LEN) {
        j = 0;
        while (j < GRIGLIA_LEN) {
            printf(" %d ", grigliaSingola[i][j]);
            j = j + 1;
        }
        printf("\n");
        i = i + 1;
    }
}

int risolviSudoku(int griglia[GRIGLIA_LEN][GRIGLIA_LEN]) {
    int riga = 0;
    int col = 0;
    int numeri[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = 0;
    int i = 0;
    int cellaVuotaTrovata = 0;
    int esito = 0;

    // Trova la prima cella vuota
    while (riga < GRIGLIA_LEN && cellaVuotaTrovata == 0) {
        col = 0;
        while (col < GRIGLIA_LEN && cellaVuotaTrovata == 0) {
            if (griglia[riga][col] == 0) {
                cellaVuotaTrovata = 1;
            } else {
                col = col + 1;
            }
        }
        if (cellaVuotaTrovata == 0) {
            riga = riga + 1;
        }
    }

    if (cellaVuotaTrovata == 0) {
        esito = 1;
    } else {
        shuffle(numeri, 9);
        i = 0;
        while (i < 9 && esito == 0) {
            num = numeri[i];
            if (checkPosizionamento(griglia, riga, col, num) == 1) {
                griglia[riga][col] = num;
                if (risolviSudoku(griglia) == 1) {
                    esito = 1;
                } else {
                    griglia[riga][col] = 0;
                }
            }
            i = i + 1;
        }
    }

    return esito;
}

int shuffle(int array[], int lunghezza) {
    int i = lunghezza - 1;
    int j = 0;
    int temp = 0;
    int esito = 1;
    while (i > 0) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i = i - 1;
    }
    return esito;
}

int generaGrigliaCompleta(int griglia[GRIGLIA_LEN][GRIGLIA_LEN]) {
    int riga = 0;
    int col = 0;
    int numeri[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = 0;
    int i = 0;
    int cellaVuotaTrovata = 0;
    int esito = 0;

    while (riga < GRIGLIA_LEN && cellaVuotaTrovata == 0) {
        col = 0;
        while (col < GRIGLIA_LEN && cellaVuotaTrovata == 0) {
            if (griglia[riga][col] == 0) {
                cellaVuotaTrovata = 1;
            } else {
                col = col + 1;
            }
        }
        if (cellaVuotaTrovata == 0) {
            riga = riga + 1;
        }
    }

    if (cellaVuotaTrovata == 0) {
        esito = 1;
    } else {
        shuffle(numeri, 9);
        i = 0;
        while (i < 9 && esito == 0) {
            num = numeri[i];
            if (checkPosizionamento(griglia, riga, col, num) == 1) {
                griglia[riga][col] = num;
                if (generaGrigliaCompleta(griglia) == 1) {
                    esito = 1;
                } else {
                    griglia[riga][col] = 0;
                }
            }
            i = i + 1;
        }
    }

    return esito;
}

int generaGrigliaVincolata(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int quadrantiBloccati[9]) {
    int riga = 0;
    int col = 0;
    int numeri[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = 0;
    int i = 0;
    int cellaVuotaTrovata = 0;
    int indiceQuadrante = 0;
    int esito = 0;

    while (riga < GRIGLIA_LEN && cellaVuotaTrovata == 0) {
        col = 0;
        while (col < GRIGLIA_LEN && cellaVuotaTrovata == 0) {
            indiceQuadrante = (riga / 3) * 3 + (col / 3);
            if (griglia[riga][col] == 0 && quadrantiBloccati[indiceQuadrante] == 0) {
                cellaVuotaTrovata = 1;
            } else {
                col = col + 1;
            }
        }
        if (cellaVuotaTrovata == 0) {
            riga = riga + 1;
        }
    }

    if (cellaVuotaTrovata == 0) {
        esito = 1;
    } else {
        shuffle(numeri, 9);
        i = 0;
        while (i < 9 && esito == 0) {
            num = numeri[i];
            if (checkPosizionamento(griglia, riga, col, num) == 1) {
                griglia[riga][col] = num;
                if (generaGrigliaVincolata(griglia, quadrantiBloccati) == 1) {
                    esito = 1;
                } else {
                    griglia[riga][col] = 0;
                }
            }
            i = i + 1;
        }
    }

    return esito;
}

int generaTripleDoku(int griglia1[GRIGLIA_LEN][GRIGLIA_LEN], int griglia2[GRIGLIA_LEN][GRIGLIA_LEN], int griglia3[GRIGLIA_LEN][GRIGLIA_LEN]) {
    int quadrantiBloccati[9] = {1, 1, 0, 0, 0, 0, 0, 0, 0};
    int esito = 0;

    inizializzaGriglia(griglia1);
    inizializzaGriglia(griglia2);
    inizializzaGriglia(griglia3);

    if (generaGrigliaCompleta(griglia1) == 1) {
        sincronizzaQuadrante(griglia1, griglia2, 7, 0); // Quadrante 7 → 0
        sincronizzaQuadrante(griglia1, griglia2, 8, 1); // Quadrante 8 → 1

        if (generaGrigliaVincolata(griglia2, quadrantiBloccati) == 1) {
            sincronizzaQuadrante(griglia2, griglia3, 7, 0); // Quadrante 5 → 0
            sincronizzaQuadrante(griglia2, griglia3, 8, 1); // Quadrante 6 → 1

            if (generaGrigliaVincolata(griglia3, quadrantiBloccati) == 1) {
                esito = 1;
            }
        }
    }

    return esito;
}