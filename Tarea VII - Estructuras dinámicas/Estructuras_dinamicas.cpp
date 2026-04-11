#include <iostream>
#include <limits>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

Nodo* pila = NULL;
Nodo* lista = NULL;
Nodo* frente = NULL;
Nodo* final = NULL;

int pares = 0;
int impares = 0;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void push(Nodo*& tope, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;
}

int pop(Nodo*& tope) {
    if (tope == NULL) {
        return 0;
    }

    Nodo* temp = tope;
    int valor = temp->dato;
    tope = tope->siguiente;
    delete temp;

    return valor;
}

void enqueue(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
}

int dequeue() {
    if (frente == NULL) {
        return 0;
    }

    Nodo* temp = frente;
    int valor = temp->dato;
    frente = frente->siguiente;

    if (frente == NULL) {
        final = NULL;
    }

    delete temp;
    return valor;
}

void insertarLista(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = lista;
    lista = nuevo;
}

void ordenarLista() {
    if (lista == NULL) return;

    Nodo* i;
    Nodo* j;

    for (i = lista; i != NULL; i = i->siguiente) {
        for (j = i->siguiente; j != NULL; j = j->siguiente) {
            if (i->dato > j->dato) {
                int temp = i->dato;
                i->dato = j->dato;
                j->dato = temp;
            }
        }
    }
}

void mostrar(Nodo* nodo) {
    if (nodo == NULL) {
        cout << "Vacio\n";
        return;
    }

    Nodo* actual = nodo;
    while (actual != NULL) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL\n";
}

void mostrarCola() {
    if (frente == NULL) {
        cout << "Vacio\n";
        return;
    }

    Nodo* actual = frente;
    while (actual != NULL) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL\n";
}

void liberar(Nodo*& nodo) {
    while (nodo != NULL) {
        Nodo* temp = nodo;
        nodo = nodo->siguiente;
        delete temp;
    }
}

void liberarCola() {
    while (frente != NULL) {
        dequeue();
    }
}

int main() {

    cout << "Josue David Flores Roldan\n";

    int opcion;
    int numero;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Ingresar numero\n";
        cout << "2. Mostrar pila\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Mostrar lista\n";
        cout << "5. Eliminar pila\n";
        cout << "6. Eliminar cola\n";
        cout << "7. Salir\n";
        cout << "Seleccione: ";

        cin >> opcion;

        if (cin.fail()) {
            cout << "Error\n";
            limpiarBuffer();
            continue;
        }

        switch (opcion) {

            case 1:
                cout << "Numero (-1 para salir): ";
                cin >> numero;

                if (cin.fail()) {
                    cout << "Error\n";
                    limpiarBuffer();
                    break;
                }

                if (numero == -1) {
                    break;
                }

                if (numero < 0) {
                    insertarLista(numero);
                } else if (numero % 2 == 0) {
                    enqueue(numero);
                    pares++;
                } else {
                    push(pila, numero);
                    impares++;
                }
                break;

            case 2:
                mostrar(pila);
                break;

            case 3:
                mostrarCola();
                break;

            case 4:
                ordenarLista();
                mostrar(lista);
                break;

            case 5:
                if (pila == NULL) {
                    cout << "Pila vacia\n";
                } else {
                    cout << "Eliminado: " << pop(pila) << endl;
                }
                break;

            case 6:
                if (frente == NULL) {
                    cout << "Cola vacia\n";
                } else {
                    cout << "Eliminado: " << dequeue() << endl;
                }
                break;

            case 7:
                cout << "Pares: " << pares << endl;
                cout << "Impares: " << impares << endl;

                liberar(pila);
                liberar(lista);
                liberarCola();

                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 7);

    return 0;
}