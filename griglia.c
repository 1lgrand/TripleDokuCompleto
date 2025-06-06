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
* - [generaGrigliaCompleta]: [Genera una griglia Sudoku completa utilizzando backtracking] 
* - [shuffle]: [Mescola gli elementi di un array] 
* - [generaGrigliaVincolata]: [Genera una griglia rispettando i quadranti già popolati] 
* - [generaTripleDoku]: [Genera le tre griglie del Triple Doku con condivisione dei quadranti] 
* - [generaGrigliaDiGioco]: [Genera la griglia di gioco in base alla difficoltà]
* - [ricercaCoordinate]: [Verifica se la coppia (x, y) è già presente nell'array delle coordinate]
* - [inizializzaCoordinate]: [Inizializza un array di Coordinate a valori predefiniti (9,9)]
*
* Lista delle modifiche effettuate:
* [29/05/2025] - [DE MARZO] - [CREAZIONE DEL FILE]
* [30/05/2025] - [DELL'AQUILA] - [IMPLEMENTAZIONE DELLE FUNZIONI: inizializzaGriglia ] - [Implementazione della funzione di inizializzazione per le griglie]
* [31/05/2025] - [DE MARZO] - [IMPLEMENTAZIONE sincronizzaQuadrante]
* [02/06/2025] - [DE MARZO] - [IMPLEMENTAZIONE funzioni utili a generaGrigliaCompleta] - [Implementazione delle funzioni che compongono la struttura di generaGrigliaCompleta]
* [02/06/2025] - [ABBINANTE] - [IMPLEMENTAZIONE generaGrigliaCompleta, shuffle]
* [04/06/2025] - [DE MARZO] - [IMPLEMENTAZIONE generaGrigliaVincolata] - [Implementazione delle funzioni per la generazione vincolata del Triple Doku]
* [04/06/2025] - [DE MARZO] - [CORREZIONE sincronizzaQuadrante] - [I quadranti, venivano copiati da Destra verso sinistra, causando cosi, incongruenze nella griglia]
* [04/06/2025] - [ABBINANTE] - [IMPLEMENTAZIONE generaTripleDoku]
* [05/06/2025] - [DELL'AQUILA] - [IMPLEMENTAZIONE generaGrigliaDiGioco, ricercaCoordinate, inizializzaCoordinate] - [Implementazione della funzione per generare la griglia di gioco e le funzioni ausiliarie per gestire le coordinate]
* [06/06/2025] - [ABBINANTE] - [CORREZIONE ricercaCoordinate] - [Risolto un bug che ciclava all'infinito nell'array]
* [06/06/2025] - [ABBINANTE - DE MARZO] - [OTTIMIZZAZIONE funzioni di generazione della griglia completa] - [Si ottimizzano le funzioni rimuovendo variabili superflue]


*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "griglia.h"
#include "validazione.h"

int inizializzaGriglia(int grigliaSingola[GRIGLIA_LEN][GRIGLIA_LEN]) {
    int y = 0; // Inizializza la variabile y per le righe
    int x = 0; // Inizializza la variabile x per le colonne
    int esito = 0; // Inizializza la variabile di esito

    // ciclo per inizializzare la griglia a 0
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
    
    
    // Trova la colonna e riga d'origine del quadrante
    int rigaInizioOrigine = (qOrigine / 3) * 3;
    int colonnaInizioOrigine = (calcolaModulo(qOrigine,3)) * 3;
    
    // Trova la colonna e riga di destinazione del quadrante
    int rigaInizioDest = (qDestinazione / 3) * 3;
    int colonnaInizioDest = (calcolaModulo(qDestinazione,3)) * 3;

    int y = 0;
    int x = 0;

    while (y < 3) {
        x = 0;
        while (x < 3) {
            // Copia l'elemento corrispondente dal quadrante sorgente al quadrante destinazione
            destinazione[rigaInizioDest + y][colonnaInizioDest + x] = sorgente[rigaInizioOrigine + y][colonnaInizioOrigine + x];
            x = x + 1;
        }
        y = y + 1;
    }
    // Esito operazione
    return 1;
}


int risolviSudoku(int griglia[GRIGLIA_LEN][GRIGLIA_LEN]) {
    int riga = 0;
    int col = 0;
    int numeri[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // array di numeri da provare
    int num = 0;
    int i = 0;
    int cellaVuotaTrovata = 0;
    int esito = 0;

    // Trova la prima cella vuota
    while (riga < GRIGLIA_LEN && cellaVuotaTrovata == 0) { // trova la prima cella vuota scorrendo sulla riga
        col = 0;
        while (col < GRIGLIA_LEN && cellaVuotaTrovata == 0) { // trova la prima cella vuota scorrendo sulla colonna
            if (griglia[riga][col] == 0) {
                cellaVuotaTrovata = 1; // cella vuota trovata
            } else {
                col = col + 1;
            }
        }
        if (cellaVuotaTrovata == 0) { 
            riga = riga + 1;
        }
    }

    if (cellaVuotaTrovata == 0) { // se non sono state trovate celle vuote la griglia è completa
        esito = 1;
    } else { // mescola l'array dei numeri per introdurre casualità nella ricerca
        shuffle(numeri, 9);
        i = 0;
        while (i < 9 && esito == 0) {
            num = numeri[i];
            if (checkPosizionamento(griglia, riga, col, num) == 1) { // controlla se è possibile inserire il numero in quella posizione
                griglia[riga][col] = num;
                if (risolviSudoku(griglia) == 1) {
                    esito = 1;  // griglia risolta con successo
                } else {
                    griglia[riga][col] = 0; // reimposta griglia a 0 e prova con un altro valore
                }
            }
            i = i + 1;
        }
    }

    return esito;
}

int shuffle(int array[], int lunghezza) { // Applica lo shuffle (mescolamento casuale) a un array di interi
    int i = lunghezza - 1; // Parte dall'ultima posizione dell'array
    int j = 0;
    int temp = 0;
    int esito = 1; // Valore di ritorno per indicare il successo dell'operazione

    while (i > 0) { // Esegue il mescolamento finché non arriva all'inizio dell'array
        j = rand() % (i + 1); // Genera un indice casuale compreso tra 0 e i
        temp = array[i]; // Scambia array[i] con array[j]
        array[i] = array[j];
        array[j] = temp;
        i = i - 1; // Passa alla posizione precedente
    }

    return esito; // Restituisce 1 per indicare che lo shuffle è stato eseguito
}

int generaGrigliaCompleta(int griglia[GRIGLIA_LEN][GRIGLIA_LEN]) {
    int riga = 0;  // Indice della riga corrente
    int col = 0;  // Indice della colonna corrente
    int numeri[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  // Numeri da provare nelle celle
    int num = 0;  // Numero corrente da tentare
    int i = 0;  // Indice per scorrere l'array dei numeri
    int cellaVuotaTrovata = 0;  // Flag per indicare se è stata trovata una cella vuota
    int esito = 0;  // 1 se completamento riuscito, 0 altrimenti

    while (riga < GRIGLIA_LEN && cellaVuotaTrovata == 0) {  // Cerca la prima cella vuota
        col = 0;
        while (col < GRIGLIA_LEN && cellaVuotaTrovata == 0) {
            if (griglia[riga][col] == 0) {
                cellaVuotaTrovata = 1;  // Trovata cella da riempire
            } else {
                col = col + 1;  // Passa alla colonna successiva
            }
        }
        if (cellaVuotaTrovata == 0) {
            riga = riga + 1;  // Passa alla riga successiva
        }
    }

    if (cellaVuotaTrovata == 0) {
        esito = 1;  // Nessuna cella vuota, griglia completata
    } else {
        shuffle(numeri, 9);  // Mischia i numeri da provare
        i = 0;
        while (i < 9 && esito == 0) {
            num = numeri[i];  // Prende il numero corrente
            if (checkPosizionamento(griglia, riga, col, num) == 1) {  // Verifica se il numero è valido
                griglia[riga][col] = num;  // Inserisce il numero
                if (generaGrigliaCompleta(griglia) == 1) {
                    esito = 1;  // Griglia completata ricorsivamente
                } else {
                    griglia[riga][col] = 0;  
                }
            }
            i = i + 1;  // Passa al numero successivo
        }
    }

    return esito;  // Ritorna 1 se la generazione è andata a buon fine
}


int generaGrigliaVincolata(int griglia[GRIGLIA_LEN][GRIGLIA_LEN], int quadrantiBloccati[9]) {
    int riga = 0; // Indice della riga corrente
    int col = 0; // Indice della colonna corrente
    int numeri[9] = {1,2,3,4,5,6,7,8,9}; // Numeri da provare nelle celle
    int num = 0; // Numero corrente da provare
    int i = 0; // Indice per l'array dei numeri
    int cellaVuotaTrovata = 0; // Flag che indica se è stata trovata una cella modificabile
    int indiceQuadrante = 0; // Indice del quadrante corrente (0-8)
    int esito = 0; // 1 se la generazione va a buon fine, 0 altrimenti

    while (riga < GRIGLIA_LEN && cellaVuotaTrovata == 0) { // Scorri righe finché non trovi una cella vuota valida
        col = 0;
        while (col < GRIGLIA_LEN && cellaVuotaTrovata == 0) {
            indiceQuadrante = (riga / 3) * 3 + (col / 3); // Calcola indice quadrante
            if (griglia[riga][col] == 0 && quadrantiBloccati[indiceQuadrante] == 0) {
                cellaVuotaTrovata = 1; // Trovata cella libera e non bloccata
            } else {
                col = col + 1; // Passa alla colonna successiva
            }
        }
        if (cellaVuotaTrovata == 0) {
            riga = riga + 1; // Passa alla riga successiva
        }
    }

    if (cellaVuotaTrovata == 0) {
        esito = 1; // Nessuna cella da riempire, griglia completa
    } else {
        shuffle(numeri, 9); // Mischia i numeri da provare
        i = 0;
        while (i < 9 && esito == 0) {
            num = numeri[i]; // Prende un numero casuale
            if (checkPosizionamento(griglia, riga, col, num) == 1) { // Verifica se il numero è valido
                griglia[riga][col] = num; // Inserisce il numero nella posizione della griglia
                if (generaGrigliaVincolata(griglia, quadrantiBloccati) == 1) {
                    esito = 1; 
                } else {
                    griglia[riga][col] = 0; 
                }
            }
            i = i + 1; // Prova il numero successivo
        }
    }

    return esito; // Ritorna 1 se la griglia è completa, 0 altrimenti
}

int generaTripleDoku(Griglia * grigliaDiGioco) {
    int quadrantiBloccati[9] = {1, 1, 0, 0, 0, 0, 0, 0, 0};  // Blocca i quadranti 0 e 1 (già occupati)
    int esito = 0;  // Variabile di ritorno, indica successo o fallimento

    if (generaGrigliaCompleta(grigliaDiGioco->grigliaA) == 1) {  // Genera prima griglia completa
        sincronizzaQuadrante(grigliaDiGioco->grigliaA, grigliaDiGioco->grigliaB, 7, 0);  // Copia quadrante 7 in 0
        sincronizzaQuadrante(grigliaDiGioco->grigliaA, grigliaDiGioco->grigliaB, 8, 1);  // Copia quadrante 8 in 1

        if (generaGrigliaVincolata(grigliaDiGioco->grigliaB, quadrantiBloccati) == 1) {  // Genera seconda griglia con vincoli
            sincronizzaQuadrante(grigliaDiGioco->grigliaB, grigliaDiGioco->grigliaC, 7, 0);  // Copia quadrante 7 in 0
            sincronizzaQuadrante(grigliaDiGioco->grigliaB, grigliaDiGioco->grigliaC, 8, 1);  // Copia quadrante 8 in 1

            if (generaGrigliaVincolata(grigliaDiGioco->grigliaC, quadrantiBloccati) == 1) {  // Genera terza griglia con vincoli
                esito = 1;  // Tutto andato a buon fine
            }
        }
    }

    return esito;  // Ritorna 1 se riuscito, altrimenti 0
}


int generaGrigliaDiGioco(Griglia * grigliaCompleta, Griglia * grigliaDiGioco, int difficolta){
    
    /*
    
    1) Generiamo una coordinata
    2) Controlliamo se è presente
    2.1) Se è PRESENTE ne generiamo un altra (2)
    3) Memorizziamo la coordinata
    4) Copiamo il valore della cella in grigliaCompleta corrispondente alla coordinata generata, nella stessa cella della grigliadigioco
    
    */

    Coordinate coordinate[MAX_COORDINATE_MEMORIZZABILI];
    int i = 0; // contatore
    int j = 0;  
    int nCelle = 0;
    int xGenerata = 0;
    int yGenerata = 0;

    if(difficolta == 1){
        nCelle = C_FACILE; // Facile
    } else if(difficolta == 2){
        nCelle = C_INTERMEDIO; // Medio
    } else if(difficolta == 3){
        nCelle = C_DIFFICLE; // Difficile
    }

    // ====  Generazione Griglia A ====

    while (i < nCelle){
        do{
            xGenerata = rand() % 9;
            yGenerata = rand() % 9; 
        }while (ricercaCoordinate(coordinate, xGenerata, yGenerata) != 0);
        coordinate[i].x = xGenerata;
        coordinate[i].y = yGenerata;
        i = i + 1;
    }

    do{
        grigliaDiGioco->grigliaA[coordinate[j].x][coordinate[j].y] = grigliaCompleta->grigliaA[coordinate[j].x][coordinate[j].y];
        j = j + 1;
    }while(j < i);

    inizializzaCoordinate(coordinate);

    
    // ====  Generazione Griglia B ====
    i = 0;
    j = 0;

    while (i < nCelle){
        do{
            xGenerata = rand() % 9; 
            yGenerata = rand() % 9; 
        }while (ricercaCoordinate(coordinate, xGenerata, yGenerata) != 0);
        coordinate[i].x = xGenerata;
        coordinate[i].y = yGenerata;
        i = i + 1;
    }

    do{
        grigliaDiGioco->grigliaB[coordinate[j].x][coordinate[j].y] = grigliaCompleta->grigliaB[coordinate[j].x][coordinate[j].y];
        j = j + 1;
    }while(j < i);

    inizializzaCoordinate(coordinate);

    // ====  Generazione Griglia C ====
    i = 0;
    j = 0;

    while (i < nCelle){
        do{
            xGenerata = rand() % 9; 
            yGenerata = rand() % 9; 
        }while (ricercaCoordinate(coordinate, xGenerata, yGenerata) != 0);
        coordinate[i].x = xGenerata;
        coordinate[i].y = yGenerata;
        i = i + 1;
    }

    do{
        grigliaDiGioco->grigliaC[coordinate[j].x][coordinate[j].y] = grigliaCompleta->grigliaC[coordinate[j].x][coordinate[j].y];
        j = j + 1;
    }while(j < i);
}

int ricercaCoordinate(Coordinate * coordinate, int x, int y ){ // Verifica se la coppia (x, y) è già presente nell'array delle coordinate
    int i = 0;
    int trovato = 0; // Flag che indica se è stato trovato un duplicato (1) o no (0)

    while (i < MAX_COORDINATE_MEMORIZZABILI) // Scorre tutte le coordinate salvate
    {
        if(coordinate[i].x == x && coordinate[i].y == y){ // Confronta la coordinata attuale con quella cercata
            trovato = 1; // Se la coordinata è già presente, imposta trovato a 1
        }

        i = i + 1; // Passa alla coordinata successiva
    }
    
    return trovato; // Restituisce 1 se duplicato trovato, altrimenti 0

    /* Se trovato = 1 ALLORA rigenera, altrimenti niente */
}

int inizializzaCoordinate(Coordinate * coordinate){ // Inizializza un array di Coordinate a valori predefiniti (9,9)
    int i = 0;
    while (i < MAX_COORDINATE_MEMORIZZABILI){ // Itera per ogni posizione fino al limite massimo

        coordinate[i].x = 9; // Imposta la coordinata x a 9
        coordinate[i].y = 9; // Imposta la coordinata y a 9

        i = i + 1; // Incrementa l'indice per passare alla coordinata successiva
    }
    return 1; // Restituisce 1 per indicare il successo dell'operazione
}

