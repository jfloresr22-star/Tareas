## Descripción
El programa permite la administración automatica del ranking académico
de estudiantes por medio de un Árbol AVL ordenado utilizando el
skill_score de cada estudiante.

Cada nodo almacena la información completa del estudiante y el árbol
se balancea automaticamente después de cada inserción.

Además se pueden realizar búsquedas por skill_score y mostrar
estadísticas del árbol AVL.

## Funcionamiento

El usuario debe ingresar estudiantes desde el menu y el sistema
los organiza automaticamente dentro del Árbol AVL utilizando
el skill_score como criterio principal.

Si dos estudiantes poseen el mismo skill_score,
el sistema realiza un desempate utilizando el student_id.

El recorrido InOrden permite mostrar el ranking académico
ordenado de menor a mayor score.

También se pueden realizar búsquedas exactas por skill_score
y visualizar estadísticas del árbol.

## Reglas de inserción

1. El árbol AVL se ordena por skill_score  
2. Si dos estudiantes tienen el mismo score  
   se utiliza el student_id como desempate  
3. El estudiante con menor student_id aparece primero  

Ejemplo:

Juan Perez      -> Score: 120 -> ID: 102  
Sofia Martinez  -> Score: 120 -> ID: 105  

Resultado:

Juan Perez aparece primero porque posee menor student_id.

## Opciones del programa

1. Insertar estudiante  
2. Mostrar ranking academico  
3. Buscar por skill_score  
4. Mostrar estadísticas AVL  
5. Salir  

## Ejemplo

Ingreso:

ID: 101  
Nombre: Ana Lopez  
Score: 200  

ID: 102  
Nombre: Juan Perez  
Score: 120  

ID: 103  
Nombre: Carlos Ruiz  
Score: 95  

Ranking:

1. Carlos Ruiz - Score: 95  
2. Juan Perez - Score: 120  
3. Ana Lopez - Score: 200  

Busqueda:

Skill Score: 120  

Resultado:

ID: 102  
Nombre: Juan Perez  

## Estadísticas AVL

Altura del árbol: 3  
Factor de balance de la raíz: 0  
Cantidad de nodos insertados: 5  

## ¿Por qué un AVL es mejor que un BST normal?

El árbol AVL mantiene el árbol balanceado automaticamente
después de cada inserción.

En un BST normal los datos pueden desordenarse y provocar
búsquedas más lentas.

El AVL mantiene una altura equilibrada permitiendo búsquedas,
inserciones y recorridos más rápidos y eficientes.

Esto mejora el rendimiento del sistema de ranking académico.

## Arquitectura

El código fue diseñado de forma modular para permitir
su integración posterior dentro del proyecto final.

La implementación del Árbol AVL se encuentra encapsulada
dentro de una clase reutilizable e independiente.

## Ejecutar el programa

g++ programa.cpp -o programa  
programa.exe  

## Autor

Josue Flores  
Carnet: 9941 24 7857