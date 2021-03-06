#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct elem {
    double val; //Il contenuto della lista
    elem *succ; //Elemento successivo
};

typedef elem *lista; //Definisce il tipo lista

//Permette d'inserire velocemente n elementi nella lista per crearla
lista creaLista(int n) {
    lista p, p0 = 0;
    for (int i = 1; i <= n; i++) {
        p = new elem; //Crea nuovo elem
        cout << "INSERIRE VALORE " << i << "/" << n << endl;
        cin >> p->val; //Inserisce elem nella lista
        p->succ = p0;
        p0 = p;
    }
    return p0;
}

lista leggiFile(char nomefile[]) {
    fstream in;
    //Cartella in cui viene salvato il file
    char dir[] = "C:\\Users\\Thinkpad User\\CLionProjects\\liste\\";
    char path[200];
    //Il percorso equivale a posizione (dir) + nome del file (nomefile)
    strcat(path, dir);
    strcat(path, nomefile);
    //Crea il file nel percorso scelto e lo prepara per la scrittura
    in.open(path, ios::in);
    if (!in.is_open()){
        cout << "ERRORE APERTURA FILE" << endl;
        return 0;
    }

    lista p, p0 = 0;
    int size = 0;
    double arr[60];

    while (in.good()) {
        in >> arr[size]; //Memorizza in un array i valori letti
        //cout << "Contando elementi..." << size << endl;
        size++; //Contatore di valori letti
    }
    size--; //Esclude valore non compatibile (Ultimo letto)
    cout << "VALORI LETTI CON SUCCESSO: " << size << endl;
    in.close();

    for (int i = size - 1; i >= 0; i--) {
        p = new elem;
        p->val = arr[i]; //Legge al contrario arr escludendo l'ultimo valore
        p->succ = p0;
        p0 = p;
    }
    return p0;
}

//Inserisce un nuovo elemento in testa alla lista
void insTesta(lista &inizio, elem a) {
    lista p = new elem;        //Crea nuovo elem
    p->val = a.val;        //Mette contenuto
    p->succ = inizio;        //Punta al primo
    inizio = p;            //Nuovo primo posto
}

//Estrae l'elemento in testa alla lista
bool estrai_da_testa(lista &inizio, elem &a) {
    lista p = inizio; //p punta al primo
    if (p == 0) return false; //Se la lista ?? vuota restituisce false
    a = *p; //a diventa puntatore del valore del prim
    inizio = p->succ; //Il successivo a p diventa l'inizio
    delete p; //Viene eliminato p, il vecchio primo
    return true;
}

//Inserisce un nuovo elemento in fondo alla lista
void insFondo(lista &inizio, elem a) {
    lista p, q;
    for (q = inizio; q != 0; q = q->succ) p = q; //Tutto q (lista passata come parametro) viene copiato in p
    q = new elem; //Viene aggiunto un nuovo elemento
    q->val = a.val; //Al nuovo elemento viene assegnato il valore di a (parametro)
    q->succ = 0; //Il successivo di q ?? zero (q ?? quindi l'ultimo)
    if (inizio == 0) inizio = q; //Se la lista passata come parametro ?? finita, ripunta all'inizio (q)
    else p->succ = q; //Il successivo di p ?? q
}

//Estrae l'elemento in fondo alla lista
bool estFondo(lista &inizio, elem &a) {
    lista p, q;
    if (inizio == 0) return false; //se vuota esci
    for (q = inizio; q->succ != 0; q = q->succ) p = q; //Tutto q (lista passata come parametro) viene copiato in p
    a.val = q->val; //Copia il valore in fondo a lista in a
    //Controlla se si estrae il primo elemento
    if (q == inizio) inizio = 0;
    else p->succ = 0;
    delete q; //Cancella il fondo della lista
    return true;
}

//Inserisce un nuovo elemento tra l'elemento minore e il maggiore (elementi ordinati in ordine crescente)
void insOrdinato(lista &inz, elem a) {
    lista p = 0, q, r;
    for (q = inz; q != 0 && q->val < a.val; q = q->succ)
        p = q; //Se q < a continua a scorrere e copiare q in p
    r = new elem; //Appena trova a>q crea nuovo elemento in r
    r->val = a.val; //Copia a in r
    r->succ = q; //r punta a q (inserito quindi in mezzo)
//Controlla se si deve inserire in testa
    if (q == inz) inz = r;
    else p->succ = r;
}

//Estrae l'elemento scelto dalla lista
bool estrai_elem_dato(lista &inz, elem &a) {
    lista p, q;
    for (q = inz; q != 0 && q->val != a.val; q = q->succ)
        p = q; //Se q!=a continua a scorrere e copiare q in p
    if (q == 0) return false; //Se non trova restituisce false
    if (q == inz) inz = q->succ; //Se a ?? il primo il nuovo primo ?? il secondo
    else p->succ = q->succ; //Altrimenti il successivo
    a = *q; //Inserisce in a il valore trovato / estratto
    delete q; //Cancella il valore dato dalla lista
    return true;
}

//Ordina la lista in ordine crescente
void ordinaLista(lista &inz) {
    lista q, p;
    double temp; //Variabile di memorizzazione temporanea valore
    for (q = inz; q != 0; q = q->succ) //Ricerca a due indici
        for (p = q; p != 0; p = p->succ)
            if (q->val > p->val) { //Se q > p scambia di posto
                temp = q->val;
                q->val = p->val;
                p->val = temp;
            }
}

//Stampa su file scelto la lista
void stampaFile(lista &inz, char nomefile[]) {
    fstream out;
    //Cartella in cui viene salvato il file
    char dir[] = "C:\\Users\\Thinkpad User\\CLionProjects\\liste\\";
    char path[200];
    //Il percorso equivale a posizione (dir) + nome del file (nomefile)
    strcat(path, dir);
    strcat(path, nomefile);
    //Crea il file nel percorso scelto e lo prepara per la scrittura
    out.open(path, ios::out);
    lista p;
    for (p = inz; p != 0; p = p->succ)
        out << p->val << endl;
    // Chiusura del file
    out.close();
}

//Mostra su schermo la lista e le sue statistiche: conta, somma e media dei suoi elementi
void stats(lista &inz) {
    lista p;
    double sum = 0; //Somma elementi lista
    int c = 0; //Contatore elementi lista
    double mean; //Media

    cout << "STATISTICHE LISTA" << endl;

    //Se la lista ?? vuota non stampa statistiche
    if (inz == 0) {
        cout << "LISTA VUOTA" << endl;
        return;
    }

    for (p = inz; p != 0; p = p->succ) { //Per ogni elemento della lista
        sum += p->val; //Somma ogni elemento
        c++; //Incrementa il contatore
        cout << p->val << '\t'; //Stampa l'elemento
    }
    cout << endl;
    mean = sum / c; //Calcolo media
    //Stampa statistiche
    cout << "NUM ELEM: " << c << '\t';
    cout << "SOMMA: " << sum << '\t';
    cout << "MEDIA: " << mean << endl;
}

int main() {
    int cs = 0; //Scelta creazione
    int s = 0; //Scelta in menu principale
    int sub = 0; //Scelta in menu secondario
    elem a{}; //Elemento
    lista inizio{}; //Lista su cui eseguire tutte le operazioni
    char nomefile[100]; //Nome del file scelto
    int n; //Numero di elementi da inserire alla creazione

    cout << "CREAZIONE LISTA" << endl;
    cout << "1 - INSERIRE MANUALMENTE" << '\t';
    cout << "2 - LETTURA DA FILE" << '\t';
    cout << "altro - PASSA A MENU" << endl;
    cin >> cs;
    switch (cs) {
        case 1:
            cout << "Quanti valori vuoi inserire nella lista per iniziare? (0 per passare al MENU)" << endl;
            cin >> n;
            if (n != 0) { //Possibilit?? di saltare la fase di creazione
                inizio = creaLista(n);
                stats(inizio);
            }
            break;

        case 2:
            cout << "INSERIRE NOME FILE (es. lista.txt)" << endl;
            cin >> nomefile;
            inizio = leggiFile(nomefile);
            if(inizio!=0){
                cout << "FILE LETTO" << endl;
                stats(inizio);
            }
            else cout<<"USCITA MENU CREAZIONE";
            break;


        default:
            cout << "USCITA MENU CREAZIONE";
    }


    cout << endl;

    while (s != 6) {

        cout << "MENU" << endl;
        cout << "1 - INSERIMENTO" << endl;
        cout << "2 - ESTRAZIONE" << endl;
        cout << "3 - ORDINA LISTA" << endl;
        cout << "4 - SALVA SU FILE" << endl;
        cout << "5 - STATISTICHE" << endl;
        cout << "6 - ESCI" << endl;

        cout << endl;
        cout << "SCEGLIERE OPERAZIONE" << endl;
        cin >> s;

        switch (s) {
            //Inserimento di un nuovo elemento
            case 1:
                cout << "INSERIRE VALORE" << endl;
                cin >> a.val;
                cout << "MENU INSERIMENTO" << endl;
                cout << "1 - TESTA" << '\t';
                cout << "2 - FONDO" << '\t';
                cout << "3 - IN ORDINE" << '\t';
                cout << "altro - TORNA A MENU PRINCIPALE" << endl;
                cout << "DOVE INSERIRE?" << endl;

                cin >> sub;

                switch (sub) {
                    case 1:
                        insTesta(inizio, a);
                        cout << a.val << " INSERITO IN TESTA ALLA LISTA" << endl;
                        break;

                    case 2:
                        insFondo(inizio, a);
                        cout << a.val << " INSERITO IN CODA ALLA LISTA" << endl;
                        break;

                    case 3:
                        insOrdinato(inizio, a);
                        cout << a.val << " INSERITO NELLA LISTA" << endl;
                        break;

                        //Torna al menu principale
                    default:
                        cout << "USCITA MENU INSERIMENTO" << endl;
                        break;
                }

                break;

                //Estrazione di un elemento
            case 2:
                cout << "MENU ESTRAZIONE" << endl;
                cout << "1 - TESTA" << '\t';
                cout << "2 - FONDO" << '\t';
                cout << "3 - ELEMENTO SCELTO" << '\t';
                cout << "altro - TORNA A MENU PRINCIPALE" << endl;
                cout << "DOVE ESTRARRE?" << endl;
                cin >> sub;

                switch (sub) {
                    case 1:
                        if (estrai_da_testa(inizio, a)) cout << a.val << " ESTRATTO DALLA LISTA" << endl;
                        else cout << "LISTA VUOTA, ESTRAZIONE FALLITA" << endl;
                        break;

                    case 2:
                        if (estFondo(inizio, a)) cout << a.val << " ESTRATTO DALLA LISTA" << endl;
                        else cout << "LISTA VUOTA, ESTRAZIONE FALLITA" << endl;
                        break;

                    case 3:
                        cout << "INSERIRE VALORE" << endl;
                        cin >> a.val;
                        if (estrai_elem_dato(inizio, a)) cout << a.val << " ESTRATTO DALLA LISTA" << endl;
                        else cout << a.val << " NON PRESENTE NELLA LISTA, ESTRAZIONE FALLITA" << endl;
                        break;

                        //Torna al menu principale
                    default:
                        cout << "USCITA MENU INSERIMENTO" << endl;
                        break;
                }
                break;

                //Ordinamento in ordine crescente lista
            case 3:
                ordinaLista(inizio);
                cout << "ELEMENTI ORDINATI IN ORDINE CRESCENTE" << endl;
                break;

                //Salvataggio su file lista
            case 4:
                cout << "INSERIRE NOME FILE (es. lista.txt)" << endl;
                cin >> nomefile;
                stampaFile(inizio, nomefile);
                cout << "LA LISTA E' STATA SALVATA IN " << nomefile << endl;
                break;

                //Mostra statistiche e lista stessa su schermo
            case 5:
                stats(inizio);
                break;

                //Chiude il programma
            case 6:
                cout << "USCITA" << endl;
                break;

                //Richiede nuovamente d'inserire un valore
            default:
                cout << "VALORE NON AMMESSO" << endl;
                break;
        }
        cout << endl;
    }
    return 0;
}