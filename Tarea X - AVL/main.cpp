#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    int student_id;
    string full_name;
    string career;
    int semester;
    float gpa;
    int skill_score;
};

struct Nodo {
    Student dato;
    Nodo* izquierdo;
    Nodo* derecho;
    int altura;
};

class ArbolAVL {
private:

    Nodo* crearNodo(Student e) {
        Nodo* nuevo = new Nodo;

        nuevo->dato = e;
        nuevo->izquierdo = NULL;
        nuevo->derecho = NULL;
        nuevo->altura = 1;

        return nuevo;
    }

    int altura(Nodo* n) {
        if (n == NULL)
            return 0;

        return n->altura;
    }

    int balance(Nodo* n) {
        if (n == NULL)
            return 0;

        return altura(n->izquierdo) - altura(n->derecho);
    }

    bool menor(Student a, Student b) {

        if (a.skill_score == b.skill_score)
            return a.student_id < b.student_id;

        return a.skill_score < b.skill_score;
    }

    Nodo* rotarDerecha(Nodo* y) {

        Nodo* x = y->izquierdo;
        Nodo* t = x->derecho;

        x->derecho = y;
        y->izquierdo = t;

        y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;
        x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;

        return x;
    }

    Nodo* rotarIzquierda(Nodo* x) {

        Nodo* y = x->derecho;
        Nodo* t = y->izquierdo;

        y->izquierdo = x;
        x->derecho = t;

        x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;
        y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;

        return y;
    }

    Nodo* insertar(Nodo* raiz, Student e) {

        if (raiz == NULL)
            return crearNodo(e);

        if (menor(e, raiz->dato))
            raiz->izquierdo = insertar(raiz->izquierdo, e);

        else if (menor(raiz->dato, e))
            raiz->derecho = insertar(raiz->derecho, e);

        else
            return raiz;

        raiz->altura = 1 + max(altura(raiz->izquierdo), altura(raiz->derecho));

        int b = balance(raiz);

        if (b > 1 && menor(e, raiz->izquierdo->dato))
            return rotarDerecha(raiz);

        if (b < -1 && menor(raiz->derecho->dato, e))
            return rotarIzquierda(raiz);

        if (b > 1 && menor(raiz->izquierdo->dato, e)) {

            raiz->izquierdo = rotarIzquierda(raiz->izquierdo);

            return rotarDerecha(raiz);
        }

        if (b < -1 && menor(e, raiz->derecho->dato)) {

            raiz->derecho = rotarDerecha(raiz->derecho);

            return rotarIzquierda(raiz);
        }

        return raiz;
    }

    void inOrden(Nodo* raiz, int &contador) {

        if (raiz != NULL) {

            inOrden(raiz->izquierdo, contador);

            cout << contador << ". "
                 << raiz->dato.full_name
                 << " - Score: "
                 << raiz->dato.skill_score
                 << endl;

            contador++;

            inOrden(raiz->derecho, contador);
        }
    }

    void buscar(Nodo* raiz, int score) {

        if (raiz == NULL)
            return;

        buscar(raiz->izquierdo, score);

        if (raiz->dato.skill_score == score) {

            cout << "\nEstudiante encontrado\n";

            cout << "ID: " << raiz->dato.student_id << endl;
            cout << "Nombre: " << raiz->dato.full_name << endl;
            cout << "Carrera: " << raiz->dato.career << endl;
            cout << "Semestre: " << raiz->dato.semester << endl;
            cout << "GPA: " << raiz->dato.gpa << endl;
            cout << "Skill Score: " << raiz->dato.skill_score << endl;
        }

        buscar(raiz->derecho, score);
    }

public:

    Nodo* raiz;
    int cantidad;

    ArbolAVL() {
        raiz = NULL;
        cantidad = 0;
    }

    void insertarEstudiante(Student e) {

        raiz = insertar(raiz, e);

        cantidad++;
    }

    void mostrarRanking() {

        if (raiz == NULL) {

            cout << "Arbol vacio\n";
        }

        else {

            int contador = 1;

            cout << "\n===== RANKING ACADEMICO =====\n";

            inOrden(raiz, contador);
        }
    }

    void buscarScore(int score) {

        if (raiz == NULL) {

            cout << "Arbol vacio\n";
        }

        else {

            buscar(raiz, score);
        }
    }

    void mostrarEstadisticas() {

        cout << "\n===== ESTADISTICAS AVL =====\n";

        cout << "Altura del arbol: " << altura(raiz) << endl;
        cout << "Factor de balance de la raiz: " << balance(raiz) << endl;
        cout << "Cantidad de nodos insertados: " << cantidad << endl;
    }
};

Student crearStudent() {

    Student e;

    cout << "Student ID: ";
    cin >> e.student_id;

    cin.ignore();

    cout << "Nombre completo: ";
    getline(cin, e.full_name);

    cout << "Carrera: ";
    getline(cin, e.career);

    cout << "Semestre: ";
    cin >> e.semester;

    cout << "GPA: ";
    cin >> e.gpa;

    cout << "Skill Score: ";
    cin >> e.skill_score;

    return e;
}

int main() {

    ArbolAVL arbol;

    int opcion;

    do {

        cout << "\n===== MENU =====\n";

        cout << "1. Insertar estudiante\n";
        cout << "2. Mostrar ranking academico\n";
        cout << "3. Buscar por skill_score\n";
        cout << "4. Mostrar estadisticas AVL\n";
        cout << "5. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1: {

                Student e = crearStudent();

                arbol.insertarEstudiante(e);

                cout << "Estudiante insertado\n";

                break;
            }

            case 2:

                arbol.mostrarRanking();

                break;

            case 3: {

                int score;

                cout << "Ingrese el skill_score: ";
                cin >> score;

                arbol.buscarScore(score);

                break;
            }

            case 4:

                arbol.mostrarEstadisticas();

                break;

            case 5:

                cout << "Saliendo...\n";

                break;

            default:

                cout << "Opcion invalida\n";
        }

    } while (opcion != 5);

    return 0;
}