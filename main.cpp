#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct elem {
    double val;
    elem *succ;
};

typedef elem *lista;

void insTesta(lista &inizio, elem a) {
    lista p = new elem;        // crea nuovo elem
    p->val = a.val;        // mette contenuto
    p->succ = inizio;        // punta al primo
    inizio = p;            // nuovo primo posto
}

bool estrai_da_testa(lista &inizio, elem &a) {
    lista p = inizio;
    if (p == 0) return false;
    a = *p;
    inizio = p->succ;
    delete p;
    return true;
}


void insFondo(lista &inizio, elem a) {
    lista p, q;
    for (q = inizio; q != 0; q = q->succ) p = q;
    q = new elem;
    q->val = a.val;
    q->succ = 0;
    if (inizio == 0) inizio = q;
    else p->succ = q;
}

bool estFondo(lista &inizio, elem &a) {
    lista p, q;
    if (inizio == 0) return false;
    for (q = inizio; q->succ != 0; q = q->succ) p = q;
    //TODO Teoria diceva a=q->val;
    a.val = q->val;
    //controlla se si estrae il primo elemento
    if (q == inizio) inizio = 0;
    else p->succ = 0;
    delete q;
    return true;
}


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

bool stampaFile(lista &inz,char path[]) {
    fstream out;

    out.open(path, ios::out);


    if (!out.is_open()) return false;

    for (lista p = inz; p != 0; p = p->succ)
        out << p->val << endl;

    out.close();
    return true;
}

int main() {

    int s = 0;

    elem a{};
    lista inizio;


    while (s != 8) {

        cout << "MENU" << endl;
        cout << "1 - INS IN TESTA" << endl;
        cout << "2 - EST DA TESTA" << endl;
        cout << "3 - INS IN FONDO" << endl;
        cout << "4 - EST DA FONDO" << endl;
        cout << "5 - INS ORDINATO" << endl;
        cout << "6 - EST ELEM DATO" << endl;
        cout << "7 - STAMPA SU FILE" << endl;
        cout << "8 - ESCI" << endl;
        cout << endl;
        cout << "SCEGLIERE OPERAZIONE" << endl;

        cin >> s;

        char nf[20];
        char path[]="C:\\Users\\Thinkpad User\\CLionProjects\\liste\\";

        switch (s) {

            case 1:
                cout << "INSERIRE VALORE" << endl;
                cin >> a.val;
                insTesta(inizio, a);
                cout << a.val << " INSERITO IN TESTA ALLA LISTA" << endl;
                break;

            case 2:

                if (estrai_da_testa(inizio, a)) cout << a.val << " ESTRATTO DALLA LISTA" << endl;
                else cout << "LISTA VUOTA, ESTRAZIONE FALLITA" << endl;
                break;

            case 3:
                cout << "INSERIRE VALORE" << endl;
                cin >> a.val;
                insFondo(inizio, a);
                cout << a.val << " INSERITO IN CODA ALLA LISTA" << endl;
                break;

            case 4:
                if (estFondo(inizio, a)) cout << a.val << " ESTRATTO DALLA LISTA" << endl;
                else cout << "LISTA VUOTA, ESTRAZIONE FALLITA" << endl;
                break;

            case 5:
                cout << "INSERIRE VALORE" << endl;
                cin >> a.val;
                insOrdinato(inizio, a);
                cout << a.val << " INSERITO NELLA LISTA" << endl;
                break;

            case 6:
                cout << "INSERIRE VALORE" << endl;
                cin >> a.val;
                if (estrai_elem_dato(inizio, a)) cout << a.val << " ESTRATTO DALLA LISTA" << endl;
                else cout << a.val << " NON PRESENTE NELLA LISTA, ESTRAZIONE FALLITA" << endl;
                break;

            case 7:

                strcpy(nf,"sally.txt");
                cout<<nf<<endl;



                strcat(path,nf);

                if (stampaFile(inizio,path))
                    cout << "LA LISTA E' STATA SALVATA IN lista.txt" << endl;
                else cout << "ERRORE APERTURA FILE" << endl;
                break;

            case 8:
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
