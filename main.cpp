#include <iostream>

struct elem {
    int val;
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
    a = q->val;
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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
