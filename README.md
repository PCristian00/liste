# liste
Esercitazione su utilizzo liste in C++.

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
