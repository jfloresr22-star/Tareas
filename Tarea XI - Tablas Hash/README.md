## Descripción

El programa permite la administración automatizada de estudiantes
utilizando estructuras Hash para almacenamiento y búsqueda eficiente.

La implementación en C++ utiliza una tabla hash manual con
resolución de colisiones mediante Separate Chaining utilizando
listas enlazadas.

La implementación en Java utiliza la estructura nativa HashMap
para gestionar estudiantes de forma automática.

Cada estudiante almacena:

- student_id
- full_name
- career
- semester
- gpa
- skill_score

Además el sistema permite:

- Cargar estudiantes desde un archivo CSV
- Buscar estudiantes por student_id
- Eliminar estudiantes
- Mostrar estadísticas
- Visualizar la estructura hash

## Funcionamiento

El usuario debe cargar un archivo CSV desde el menú principal.

El sistema leerá automáticamente cada línea del archivo
e insertará los estudiantes dentro de la estructura Hash.

En C++ los estudiantes se almacenan dentro de buckets
utilizando listas enlazadas para resolver colisiones.

En Java los estudiantes se almacenan utilizando HashMap<Integer, Estudiante>.

El sistema valida automáticamente que no existan
student_id duplicados.

## Formato del archivo CSV

El archivo CSV debe contener la siguiente estructura:

student_id,full_name,career,semester,gpa,skill_score  
1001,Juan Perez,Ingenieria en Sistemas,5,85.50,120  
1002,Ana Lopez,Ingenieria Industrial,7,91.20,200  
1003,Carlos Ruiz,Ingenieria Civil,3,78.30,95  

## Reglas de inserción

1. El student_id se utiliza como clave principal  
2. No se permiten estudiantes duplicados  
3. Las colisiones en C++ se resuelven mediante Separate Chaining  
4. Cada bucket puede almacenar múltiples estudiantes enlazados  

## Opciones del programa

1. Cargar archivo CSV  
2. Buscar estudiante  
3. Eliminar estudiante  
4. Mostrar estructura Hash  
5. Mostrar estadísticas  
6. Salir  

## Ejemplo

Carga CSV:

estudiantes.csv

Busqueda:

student_id: 1002

Resultado:

ID: 1002  
Nombre: Ana Lopez  
Carrera: Ingenieria Industrial  

Eliminación:

student_id: 1003

Resultado:

Estudiante eliminado

## Estadísticas Hash

Cantidad de estudiantes cargados: 7  
Colisiones generadas: 2  
Factor de carga: 0.7  

## Diferencia entre C++ y Java

La implementación en C++ utiliza una tabla hash creada manualmente
utilizando arreglos y listas enlazadas.

La implementación en Java utiliza HashMap, una estructura
ya implementada dentro del framework del lenguaje.

C++ ofrece mayor control interno sobre la estructura,
mientras que Java simplifica el manejo utilizando
estructuras nativas.

## Arquitectura

El código fue diseñado de forma modular para permitir
su integración posterior dentro del proyecto final.

La implementación en C++ encapsula la tabla hash
dentro de una clase reutilizable.

La implementación en Java separa la lógica en:

- Main.java
- Estudiante.java

## Estructura del repositorio

tarea-hash-csv/

├── cpp-hash/  
│   ├── main.cpp  
│   └── estudiantes.csv  
│  
├── java-hashmap/  
│   ├── Main.java  
│   ├── Estudiante.java  
│   └── estudiantes.csv  
│  
├── evidencias/  
│   └── evidencia.pdf  
│  
└── README.md  

## Ejecutar programa en C++

Compilar:

g++ main.cpp -o programa  

Ejecutar:

programa.exe  

o

./programa  

## Ejecutar programa en Java

Compilar:

javac Main.java Estudiante.java  

Ejecutar:

java Main  

## Autor

Josue Flores  
Carnet: 9941 24 7857