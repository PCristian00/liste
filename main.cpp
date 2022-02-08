#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct elem {
    double val; //Il contenuto della lista
    elem *succ; //Elemento successivo
};

typedef elem *lista; //Definisce il tipo lista

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
    if (p == 0) return false; //Se la lista è vuota restituisce false
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
    q->succ = 0; //Il successivo di q è zero ( q è quindi l'ultimo)
    if (inizio == 0) inizio = q; //Se la lista passata come parametro è finita, ripunta all'inizio (q)
    else p->succ = q; //Il successivo di p è q
}

//Estrae l'elemento in fondo alla lista
bool estFondo(lista &inizio, elem &a) {
    lista p, q;
    if (inizio == 0) return false;
    for (q = inizio; q->succ != 0; q = q->succ) p = q;
    a.val = q->val;
    //controlla se si estrae il primo elemento
    if (q == inizio) inizio = 0;
    else p->succ = 0;
    delete q;
    return true;
}

//Inserisce un nuovo elemento tra l'elemento minore e il maggiore (elementi ordinati in ordine crescente)
void insOrdinato(lista &inz, elem a) {
    lista p = 0, q, r;
    for (q = inz; q != 0 && q->val < a.val; q = q->succ)
        p = q;
    r = new elem;
    r->val = a.val;
    r->succ = q;
// controlla se si deve inserire in testa
    if (q == inz) inz = r;
    else p->succ = r;
}

//Estrae l'elemento scelto dalla lista
bool estrai_elem_dato(lista &inz, elem &a) {
    lista p, q;
    for (q = inz; q != 0 && q->val != a.val; q = q->succ)
        p = q;
    if (q == 0) return false;
    if (q == inz) inz = q->succ;
    else p->succ = q->succ;
    a = *q;
    delete q;
    return true;
}

//Ordina la lista in ordine crescente
void ordinaLista(lista &inz) {
    lista q, p;
    double temp;
    for (q = inz; q != 0; q = q->succ)
        for (p = q; p != 0; p = p->succ)
            if (q->val > p->val) {
                temp = q->val;
                q->val = p->val;
                p->val = temp;
            }
}

//Stampa su file scelto la lista
void stampaFile(lista &inz, char nomefile[]) {
    fstream out;
    //cartella in cui viene salvato il file
    char dir[] = "C:\\Users\\Thinkpad User\\CLionProjects\\liste\\";
    char path[200];
    //Il percorso equivale a posizione (dir) + nome del file (nomefile)
    strcat(path, dir);
    strcat(path, nomefile);

    out.open(path, ios::out);

    lista p;

    for (p = inz; p != 0; p = p->succ)
        out << p->val << endl;

    out.close();
}

//Mostra su schermo la lista e le sue statistiche: conta, somma e media dei suoi elementi
void stats(lista &inz) {
    lista p;
    double sum = 0;
    int c = 0;
    double mean = 0;

    cout << endl;

    for (p = inz; p != 0; p = p->succ) {
        sum += p->val;
        c++;
        cout << p->val << '\t';
    }
    cout << endl << endl;
    mean = sum / c;

    cout << "NUM ELEM: " << c << endl;
    cout << "SOMMA: " << sum << endl;
    cout << "MEDIA: " << mean << endl;
}

int main() {
    int s = 0;
    int sub = 0;
    elem a{};
    lista inizio;
    fstream out;
    char nomefile[100];

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

            case 1:
                cout << "INSERIRE VALORE" << endl;
                cin >> a.val;
                cout << "MENU INSERIMENTO" << endl;
                cout << "1 - TESTA" << endl;
                cout << "2 - FONDO" << endl;
                cout << "3 - IN ORDINE" << endl;
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

                    default:
                        cout << "VALORE NON AMMESSO" << endl;
                        break;
                }

                break;

            case 2:
                cout << "MENU ESTRAZIONE" << endl;
                cout << "1 - TESTA" << endl;
                cout << "2 - FONDO" << endl;
                cout << "3 - ELEMENTO SCELTO" << endl;
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

                    default:
                        cout << "VALORE NON AMMESSO" << endl;
                        break;
                }
                break;

            case 3:
                ordinaLista(inizio);
                cout << "ELEMENTI ORDINATI IN ORDINE CRESCENTE" << endl;
                break;

            case 4:
                cout << "INSERIRE NOME FILE (es. lista.txt)" << endl;
                cin >> nomefile;
                stampaFile(inizio, nomefile);
                cout << "LA LISTA E' STATA SALVATA IN " << nomefile << endl;
                break;

            case 5:
                cout << "STATISTICHE LISTA" << endl;
                stats(inizio);
                break;

            case 6:
                cout << "USCITA" << endl;
                break;

            default:
                cout << "VALORE NON AMMESSO" << endl;
                break;
        }
        cout << endl;
    }
    return 0;
}