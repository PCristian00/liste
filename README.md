# liste
Esercitazione su utilizzo liste in C++.

All'apertura del file, il programma offre la possibilità di:
* Inserire rapidamente un numero scelto di elementi da tastiera.
* Leggere i valori da un file di testo creato in precedenza.

Il resto delle operazioni viene eseguito tramite un menu.

# Menu
Il menu presenta varie funzioni:
1. INSERIMENTO ELEMENTO
    - IN TESTA
    - IN CODA
    - IN ORDINE CRESCENTE
2. ESTRAZIONE ELEMENTO
    - DA TESTA
    - DA CODA
    - SCELTO DA UTENTE
3. ORDINAMENTO CRESCENTE LISTA
4. SALVATAGGIO SU FILE LISTA
5. STATISTICHE LISTA
    - SOMMA ELEMENTI
    - CONTEGGIO ELEMENTI
    - MEDIA ELEMENTI
## Menu
```
MENU
1 - INSERIMENTO
2 - ESTRAZIONE
3 - ORDINA LISTA
4 - SALVA SU FILE
5 - STATISTICHE
6 - ESCI
```
## Inserimento
```
SCEGLIERE OPERAZIONE
1
INSERIRE VALORE
25
MENU INSERIMENTO
1 - TESTA       2 - FONDO       3 - IN ORDINE   altro - TORNA A MENU PRINCIPALE
DOVE INSERIRE?
1
25 INSERITO IN TESTA ALLA LISTA
```
## Estrazione
```
SCEGLIERE OPERAZIONE
2
MENU ESTRAZIONE
1 - TESTA       2 - FONDO       3 - ELEMENTO SCELTO     altro - TORNA A MENU PRINCIPALE
DOVE ESTRARRE?
2
77.8 ESTRATTO DALLA LISTA
```
## Ordinamento
```
SCEGLIERE OPERAZIONE
3
ELEMENTI ORDINATI IN ORDINE CRESCENTE
```
## Salvataggio su File
```
SCEGLIERE OPERAZIONE
4
INSERIRE NOME FILE (es. lista.txt)
lista_ord.txt
LA LISTA E' STATA SALVATA IN lista_ord.txt
```
## Statistiche
```
SCEGLIERE OPERAZIONE
5
STATISTICHE LISTA
25      49.7    64      25      24
NUM ELEM: 5     SOMMA: 187.7    MEDIA: 37.54
```
## Uscita
```
SCEGLIERE OPERAZIONE
6
USCITA
```
