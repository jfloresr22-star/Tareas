#include <iostream>
using namespace std;

struct Nodo {
    int carne;
    string nombre;
    string apellido;
    string carrera;
    Nodo* siguiente;
};

int main() {

    cout << "Nombre: Josue David Flores Roldan\n";
    Nodo* head = NULL;
    int opcion;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insertar estudiante al inicio\n";
        cout << "2. Insertar estudiante al final\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Buscar estudiante\n";
        cout << "5. Eliminar estudiante\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if(opcion == 1) {

            Nodo* nuevo = new Nodo;

            cout << "Ingrese carne: ";
            cin >> nuevo->carne;

            Nodo* temp = head;
            bool repetido = false;

            while(temp != NULL) {
                if(temp->carne == nuevo->carne) {
                    repetido = true;
                    break;
                }
                temp = temp->siguiente;
            }

            if(repetido) {
                cout << "ERROR: El carne ya existe\n";
                delete nuevo;
            } else {
                cout << "Ingrese nombre: ";
                cin >> nuevo->nombre;
                cout << "Ingrese apellido: ";
                cin >> nuevo->apellido;
                cout << "Ingrese carrera: ";
                cin >> nuevo->carrera;

                nuevo->siguiente = head;
                head = nuevo;

                cout << "Estudiante insertado al inicio\n";
            }

            cin.ignore(1000, '\n');
            cout << "\nPresione ENTER para continuar...";
            cin.get();
        }

        else if(opcion == 2) {

            Nodo* nuevo = new Nodo;

            cout << "Ingrese carne: ";
            cin >> nuevo->carne;

            Nodo* temp = head;
            bool repetido = false;

            while(temp != NULL) {
                if(temp->carne == nuevo->carne) {
                    repetido = true;
                    break;
                }
                temp = temp->siguiente;
            }

            if(repetido) {
                cout << "ERROR: El carne ya existe\n";
                delete nuevo;
            } else {
                cout << "Ingrese nombre: ";
                cin >> nuevo->nombre;
                cout << "Ingrese apellido: ";
                cin >> nuevo->apellido;
                cout << "Ingrese carrera: ";
                cin >> nuevo->carrera;

                nuevo->siguiente = NULL;

                if(head == NULL) {
                    head = nuevo;
                } else {
                    Nodo* actual = head;

                    while(actual->siguiente != NULL) {
                        actual = actual->siguiente;
                    }

                    actual->siguiente = nuevo;
                }

                cout << "Estudiante insertado al final\n";
            }

            cin.ignore(1000, '\n');
            cout << "\nPresione ENTER para continuar...";
            cin.get();
        }

        else if(opcion == 3) {

            Nodo* temp = head;

            if(temp == NULL) {
                cout << "Lista vacia\n";
            } else {
                while(temp != NULL) {
                    cout << "\nCarné: " << temp->carne << endl;
                    cout << "Nombre: " << temp->nombre << endl;
                    cout << "Apellido: " << temp->apellido << endl;
                    cout << "Carrera: " << temp->carrera << endl;
                    cout << "-----------------------------\n";

                    temp = temp->siguiente;
                }
            }

            cin.ignore(1000, '\n');
            cout << "\nPresione ENTER para continuar...";
            cin.get();
        }

        else if(opcion == 4) {

            int buscar;
            cout << "Ingrese carne a buscar: ";
            cin >> buscar;

            Nodo* temp = head;
            bool encontrado = false;

            while(temp != NULL) {
                if(temp->carne == buscar) {
                    cout << "\nEstudiante encontrado:\n";
                    cout << "Nombre: " << temp->nombre << endl;
                    cout << "Apellido: " << temp->apellido << endl;
                    cout << "Carrera: " << temp->carrera << endl;

                    encontrado = true;
                    break;
                }
                temp = temp->siguiente;
            }

            if(!encontrado) {
                cout << "Estudiante no encontrado\n";
            }

            cin.ignore(1000, '\n');
            cout << "\nPresione ENTER para continuar...";
            cin.get();
        }

        else if(opcion == 5) {

            int eliminar;
            cout << "Ingrese carne a eliminar: ";
            cin >> eliminar;

            bool encontrado = false;

            while(head != NULL && head->carne == eliminar) {

                cout << "\nEstudiante eliminado:\n";
                cout << "Carné: " << head->carne << endl;
                cout << "Nombre: " << head->nombre << endl;
                cout << "Apellido: " << head->apellido << endl;
                cout << "Carrera: " << head->carrera << endl;

                Nodo* temp = head;
                head = head->siguiente;
                delete temp;

                encontrado = true;
            }

            Nodo* actual = head;
            Nodo* anterior = NULL;

            while(actual != NULL) {
                if(actual->carne == eliminar) {

                    cout << "\nEstudiante eliminado:\n";
                    cout << "Carné: " << actual->carne << endl;
                    cout << "Nombre: " << actual->nombre << endl;
                    cout << "Apellido: " << actual->apellido << endl;
                    cout << "Carrera: " << actual->carrera << endl;

                    encontrado = true;

                    anterior->siguiente = actual->siguiente;

                    Nodo* temp = actual;
                    actual = actual->siguiente;
                    delete temp;

                } else {
                    anterior = actual;
                    actual = actual->siguiente;
                }
            }

            if(!encontrado) {
                cout << "No se encontro el estudiante\n";
            }

            cin.ignore(1000, '\n');
            cout << "\nPresione ENTER para continuar...";
            cin.get();
        }

    } while(opcion != 6);

    return 0;
}