#include <iostream>
#include <limits>
using namespace std;

struct Nodo {
    string accion;
    Nodo* siguiente;
};

Nodo* pilaAcciones = NULL;
Nodo* pilaRehacer = NULL;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void push(Nodo*& tope, string accion) {
    Nodo* nuevo = new Nodo();
    nuevo->accion = accion;
    nuevo->siguiente = tope;
    tope = nuevo;
}

string pop(Nodo*& tope) {
    if (tope == NULL) {
        return "";
    }

    Nodo* temp = tope;
    string accion = temp->accion;
    tope = tope->siguiente;
    delete temp;

    return accion;
}

void mostrar(Nodo* tope) {
    if (tope == NULL) {
        cout << "La pila esta vacia.\n";
        return;
    }

    Nodo* actual = tope;
    while (actual != NULL) {
        cout << actual->accion << " -> ";
        actual = actual->siguiente;
    }
    cout << "NULL\n";
}

void vaciarPila(Nodo*& tope) {
    while (tope != NULL) {
        pop(tope);
    }
}

void realizarAccion() {
    string accion;

    limpiarBuffer();

    cout << "Ingrese accion (max 50 caracteres): ";
    getline(cin, accion);

    if (accion.length() > 50) {
        cout << "Error: accion demasiado larga\n";
        return;
    }

    push(pilaAcciones, accion);
    vaciarPila(pilaRehacer);

    cout << "Accion realizada\n";
}

void deshacer() {
    if (pilaAcciones == NULL) {
        cout << "No hay acciones para deshacer\n";
        return;
    }

    string accion = pop(pilaAcciones);
    push(pilaRehacer, accion);

    cout << "Accion deshecha: " << accion << endl;
}

void rehacer() {
    if (pilaRehacer == NULL) {
        cout << "No hay acciones para rehacer\n";
        return;
    }

    string accion = pop(pilaRehacer);
    push(pilaAcciones, accion);

    cout << "Accion rehecha: " << accion << endl;
}

int main() {

    cout << "Josue David Flores Roldan\n";

    int opcion;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Realizar accion\n";
        cout << "2. Deshacer\n";
        cout << "3. Rehacer\n";
        cout << "4. Mostrar acciones\n";
        cout << "5. Mostrar rehacer\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        if (cin.fail()) {
            cout << "Opcion invalida\n";
            limpiarBuffer();
            continue;
        }

        switch (opcion) {

            case 1:
                realizarAccion();
                break;

            case 2:
                deshacer();
                break;

            case 3:
                rehacer();
                break;

            case 4:
                mostrar(pilaAcciones);
                break;

            case 5:
                mostrar(pilaRehacer);
                break;

            case 6:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 6);

    return 0;
}