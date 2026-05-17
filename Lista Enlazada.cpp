#include <iostream>
#include <string>

using namespace std;

// ==========================================
// CLASE ALUMNO
// ==========================================
class Alumno {
private:
    string carne;
    string nombres;
    string apellidos;
    string email;
    string telefono;
    double nota1;
    double nota2;
    double promedio;

public:
    // Constructor vacío
    Alumno() {
        carne = "";
        nombres = "";
        apellidos = "";
        email = "";
        telefono = "";
        nota1 = 0.0;
        nota2 = 0.0;
        promedio = 0.0;
    }

    // Método para ingresar los datos con validación de notas (0 a 10)
    void ingresarDatos() {
        cin.ignore(); // Limpiar el buffer de entrada antes de usar getline
        
        cout << "Ingrese el carne del alumno: ";
        getline(cin, carne);
        
        cout << "Ingrese los nombres del alumno: ";
        getline(cin, nombres);
        
        cout << "Ingrese los apellidos del alumno: ";
        getline(cin, apellidos);
        
        cout << "Ingrese el correo electronico (Email): ";
        getline(cin, email);
        
        cout << "Ingrese el numero de telefono: ";
        getline(cin, telefono);
        
        // Validación para la Nota 1
        do {
            cout << "Ingrese la nota 1 (Rango 0 - 10): ";
            cin >> nota1;
            if (nota1 < 0 || nota1 > 10) {
                cout << "[ERROR] La nota debe estar entre 0 y 10. Intente de nuevo.\n";
            }
        } while (nota1 < 0 || nota1 > 10);
        
        // Validación para la Nota 2
        do {
            cout << "Ingrese la nota 2 (Rango 0 - 10): ";
            cin >> nota2;
            if (nota2 < 0 || nota2 > 10) {
                cout << "[ERROR] La nota debe estar entre 0 y 10. Intente de nuevo.\n";
            }
        } while (nota2 < 0 || nota2 > 10);
        
        // Cálculo del promedio basado en el nuevo rango
        promedio = (nota1 + nota2) / 2.0;
    }

    // Método para mostrar toda la información
    void mostrarInformacion() {
        cout << "Carne: " << carne 
             << " | Alumno: " << apellidos << ", " << nombres << "\n"
             << "   Email: " << email 
             << " | Tel: " << telefono << "\n"
             << "   Nota 1: " << nota1 
             << " | Nota 2: " << nota2 
             << " | Promedio: " << promedio << "\n"
             << "---------------------------------------------\n";
    }
};

// ==========================================
// ESTRUCTURA NODO
// ==========================================
struct Nodo {
    Alumno objetoAlumno;
    Nodo* siguiente;
};

// ==========================================
// FUNCIONES DE LA LISTA ENLAZADA
// ==========================================

// Función para insertar un alumno al final de la lista
void insertarAlFinal(Nodo*& cabeza) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->objetoAlumno.ingresarDatos();
    nuevoNodo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        // Recorrer con un while hasta llegar al último nodo
        Nodo* auxiliar = cabeza;
        while (auxiliar->siguiente != nullptr) {
            auxiliar = auxiliar->siguiente;
        }
        // Enlazar el último nodo con el nuevo
        auxiliar->siguiente = nuevoNodo;
    }
    cout << "\n¡Alumno agregado exitosamente a la lista!\n";
}

// Función para mostrar la lista de alumnos
void mostrarLista(Nodo* cabeza) {
    if (cabeza == nullptr) {
        cout << "\nLa lista esta vacia.\n";
        return;
    }

    cout << "\n=============================================";
    cout << "\n        INFORMACION DE LOS ALUMNOS          ";
    cout << "\n=============================================\n";

    Nodo* auxiliar = cabeza;
    
    // Recorrido obligatorio con ciclo while
    while (auxiliar != nullptr) {
        auxiliar->objetoAlumno.mostrarInformacion(); 
        auxiliar = auxiliar->siguiente;             
    } 

    cout << "=============================================\n";
}

// Función para liberar la memoria dinámica al terminar el programa
void liberarMemoria(Nodo*& cabeza) {
    while (cabeza != nullptr) {
        Nodo* auxiliar = cabeza;
        cabeza = cabeza->siguiente;
        delete auxiliar;
    }
    cout << "\nMemoria dinamica liberada correctamente.\n";
}

// ==========================================
// FUNCIÓN PRINCIPAL (MENÚ)
// ==========================================
int main() {
    Nodo* listaAlumnos = nullptr;
    int opcion;

    do {
        cout << "\n--- MENU GESTION DE ALUMNOS ---\n";
        cout << "1. Insertar Alumno al Final\n";
        cout << "2. Mostrar Lista de Alumnos\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                insertarAlFinal(listaAlumnos);
                break;
            case 2:
                mostrarLista(listaAlumnos);
                break;
            case 3:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 3);

    // Liberar la memoria antes de cerrar el programa
    liberarMemoria(listaAlumnos);

    return 0;
}