#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

Nodo* tope = nullptr;

void push(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;
    cout << "Elemento... " << valor << " Insertado en la pila" << endl;
}

void pop() {
    if (tope == nullptr) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    Nodo* temp = tope;
    cout << "Elemento eliminado... " << temp->dato << endl;
    tope = tope->siguiente;
    delete temp;
}

void peek() {
    if (tope == nullptr) {
        cout << "La pila esta vacia." << endl;
    } else {
        cout << "El elemento en el tope es: " << tope->dato << endl;
    }
}

void mostrar() {
    if (tope == nullptr) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    Nodo* actual = tope;
    cout << "Contenido de la pila: ";
    while (actual != nullptr) {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    cout << "final" << endl;
}

int contarElementos() {
    int contador = 0;
    Nodo* actual = tope;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

void buscarElemento(int valor) {
    if (tope == nullptr) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    Nodo* actual = tope;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->dato == valor) {
            encontrado = true;
            break;
        }
        actual = actual->siguiente;
    }

    if (encontrado)
        cout << "Elemento encontrado." << endl;
    else
        cout << "Elemento no encontrado." << endl;
}

void vaciarPila() {
    if (tope == nullptr) {
        cout << "La pila ya esta vacia." << endl;
        return;
    }
    while (tope != nullptr) {
        pop();
    }
    cout << "Pila vaciada correctamente." << endl;
}

int main() {
    cout << "Josue David Flores Roldan" << endl;

    int O, valor;

    do {
        cout << "\n ******** Menu ******** " << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Eliminar" << endl;
        cout << "3. Ver tope" << endl;
        cout << "4. Mostrar" << endl;
        cout << "5. Contar elementos" << endl;
        cout << "6. Buscar elemento" << endl;
        cout << "7. Vaciar pila" << endl;
        cout << "8. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> O;

        switch (O) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                push(valor);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                mostrar();
                break;
            case 5:
                cout << "Cantidad de elementos: " << contarElementos() << endl;
                break;
            case 6:
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
                buscarElemento(valor);
                break;
            case 7:
                vaciarPila();
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }

    } while (O != 8);

    return 0;
}
