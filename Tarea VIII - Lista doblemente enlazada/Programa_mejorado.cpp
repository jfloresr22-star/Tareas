#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void insertarInicio(Nodo* &head, Nodo* &tail, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = head;
    nuevo->anterior = NULL;

    if (head != NULL) {
        head->anterior = nuevo;
    } else {
        tail = nuevo;
    }

    head = nuevo;
}

void insertarFinal(Nodo* &head, Nodo* &tail, int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = tail;

    if (tail == NULL) {
        head = tail = nuevo;
        return;
    }

    tail->siguiente = nuevo;
    tail = nuevo;
}

void mostrarAdelante(Nodo* head) {
    Nodo* temp = head;

    if (temp == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    cout << "\nLista hacia adelante: ";
    while (temp != NULL) {
        cout << temp->dato << " <-> ";
        temp = temp->siguiente;
    }
    cout << "NULL\n";
}

void mostrarAtras(Nodo* tail) {
    Nodo* temp = tail;

    if (temp == NULL) {
        cout << "Lista vacia\n";
        return;
    }

    cout << "\nLista hacia atras: ";
    while (temp != NULL) {
        cout << temp->dato << " <-> ";
        temp = temp->anterior;
    }
    cout << "NULL\n";
}

bool buscar(Nodo* head, int valor) {
    Nodo* temp = head;

    while (temp != NULL) {
        if (temp->dato == valor) {
            return true;
        }
        temp = temp->siguiente;
    }

    return false;
}

void eliminar(Nodo* &head, Nodo* &tail, int valor) {
    if (head == NULL) {
        cout << "Lista vacia.\n";
        return;
    }

    Nodo* actual = head;

    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        cout << "Dato no encontrado.\n";
        return;
    }

    if (actual == head) {
        head = head->siguiente;
        if (head != NULL) head->anterior = NULL;
        else tail = NULL;

        delete actual;
        cout << "Nodo eliminado.\n";
        return;
    }

    if (actual == tail) {
        tail = tail->anterior;
        if (tail != NULL) tail->siguiente = NULL;

        delete actual;
        cout << "Nodo eliminado.\n";
        return;
    }

    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;

    delete actual;
    cout << "Nodo eliminado.\n";
}

int contarNodos(Nodo* head) {
    int contador = 0;
    Nodo* temp = head;

    while (temp != NULL) {
        contador++;
        temp = temp->siguiente;
    }

    return contador;
}

int main() {
    Nodo* head = NULL;
    Nodo* tail = NULL;

    int opcion, valor;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Mostrar hacia adelante\n";
        cout << "4. Mostrar hacia atras\n";
        cout << "5. Buscar\n";
        cout << "6. Eliminar\n";
        cout << "7. Contar nodos\n";
        cout << "8. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor: ";
                cin >> valor;
                insertarInicio(head, tail, valor);
                break;

            case 2:
                cout << "Valor: ";
                cin >> valor;
                insertarFinal(head, tail, valor);
                break;

            case 3:
                mostrarAdelante(head);
                break;

            case 4:
                mostrarAtras(tail);
                break;

            case 5:
                cout << "Valor a buscar: ";
                cin >> valor;
                cout << (buscar(head, valor) ? "Encontrado\n" : "No encontrado\n");
                break;

            case 6:
                cout << "Valor a eliminar: ";
                cin >> valor;
                eliminar(head, tail, valor);
                break;

            case 7:
                cout << "Total nodos: " << contarNodos(head) << endl;
                break;
        }

    } while (opcion != 8);

    return 0;
}