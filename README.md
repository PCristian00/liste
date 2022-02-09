# liste
Esercitazione su utilizzo liste in C++.
Il programma presenta varie funzioni:
* INSERIMENTO ELEMENTO
    - IN TESTA
    - IN CODA
    - IN ORDINE CRESCENTE
* ESTRAZIONE ELEMENTO
    - DA TESTA
    - DA CODA
    - SCELTO DA UTENTE
* ORDINAMENTO CRESCENTE LISTA
* SALVATAGGIO SU FILE LISTA
* STATISTICHE LISTA
    - SOMMA ELEMENTI
    - CONTEGGIO ELEMENTI
    - MEDIA ELEMENTI

## Errore
NON rimuovere la variabile
```c++
/*
     * rimuovere questo fstream crea problemi alle funzioni
     *
     * -var-create: unable to create variable object
     * SIGSEGV (Segmentation fault)
     *
     */
    fstream broken;
    return 0;
```
Nonostante questo flusso non venga usato da nessuna funzione, rimuoverlo causa problemi di segmentation fault.
Sto cercando la causa del problema, per adesso basta non rimuoverla.
