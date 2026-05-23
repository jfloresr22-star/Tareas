## Descripción

El programa permite el procesamiento masivo de clientes
utilizando estructuras eficientes para mejorar el manejo
de memoria y el rendimiento del sistema.

La implementación original cargaba todos los clientes
en memoria utilizando listas y realizaba búsquedas lineales
para agrupar campañas, lo que provocaba mayor consumo
de memoria y menor rendimiento.

La implementación optimizada utiliza HashMap para
gestionar campañas de forma más eficiente y procesa
los clientes línea por línea sin almacenar todos
los registros en memoria.

Cada cliente almacena:

- id
- nombre
- ingreso
- segmento
- region
- score
- deuda
- jsonData

Además el sistema permite:

- Generar clientes automáticamente
- Procesar grandes volúmenes de registros
- Agrupar clientes por campañas
- Mostrar estadísticas de memoria
- Comparar rendimiento del procesamiento

## Funcionamiento

El sistema genera automáticamente un archivo CSV
con millones de clientes simulados.

Posteriormente el programa procesa cada línea
del archivo utilizando BufferedReader para evitar
cargar todos los clientes en memoria.

Las campañas son agrupadas utilizando
HashMap<String, Integer> para mejorar
la velocidad de búsqueda e inserción.

El sistema genera automáticamente un resumen
final mostrando todas las campañas encontradas.

## Formato del archivo CSV

El archivo CSV contiene la siguiente estructura:

id,nombre,ingreso,segmento,region,score,deuda,jsonData  
1,Cliente_1,15000,PREPAGO,NORTE,850,2000,"JSON"  
2,Cliente_2,30000,POSTPAGO,SUR,900,5000,"JSON"  
3,Cliente_3,10000,PYME,CENTRO,400,8000,"JSON"  

## Reglas de procesamiento

1. El archivo CSV se procesa línea por línea  
2. No se cargan todos los clientes en memoria  
3. Las campañas se agrupan utilizando HashMap  
4. El sistema genera campañas automáticamente  
5. El programa soporta grandes volúmenes de registros  

## Opciones del programa

1. Generar archivo CSV  
2. Procesar clientes  
3. Mostrar campañas generadas  
4. Mostrar memoria utilizada  
5. Mostrar tiempo de procesamiento  
6. Finalizar programa  

## Ejemplo

Generación:

clientes.csv

Procesamiento:

Procesando clientes con HashMap

Resultado:

PREPAGO_NORTE_INGRESO_ALTO_SCORE_BUENO_DEUDA_MEDIA : 2500  

POSTPAGO_SUR_INGRESO_MEDIO_SCORE_EXCELENTE_DEUDA_BAJA : 1800  

## Estadísticas

Cantidad de campañas generadas: 120  

Tiempo de procesamiento optimizado: 3200 ms  

Memoria utilizada: 250 MB  

## Diferencia entre versión original y optimizada

La implementación original utilizaba listas
y búsquedas lineales para agrupar campañas.

Además cargaba todos los clientes en memoria,
incrementando considerablemente el consumo
de RAM.

La implementación optimizada utiliza HashMap,
permitiendo búsquedas e inserciones mucho
más rápidas.

También procesa los clientes directamente
desde el archivo CSV evitando almacenar
millones de registros simultáneamente.

## Arquitectura

El código fue diseñado de forma modular para permitir
un mejor mantenimiento y organización del sistema.

La lógica del procesamiento fue separada
en diferentes clases reutilizables.

La implementación en Java separa la lógica en:

- Main.java
- Cliente.java
- GeneradorClientes.java
- ProcesadorOptimizado.java

## Estructura del repositorio

tarea-procesamiento-masivo-java/

├── src/  
│   ├── Main.java  
│   ├── Cliente.java  
│   ├── GeneradorClientes.java  
│   └── ProcesadorOptimizado.java  
│  
├── evidencia/  
│   └── capturas.png  
│  
└── README.md  

## Ejecutar programa en Java

Compilar:

javac Main.java Cliente.java GeneradorClientes.java ProcesadorOptimizado.java  

Ejecutar:

java Main  

## Evidencia requerida

La carpeta evidencia debe incluir:

- Ejecución del programa base  
- Ejecución del programa optimizado  
- Memoria utilizada  
- Tiempo de procesamiento  
- Nombre completo visible en consola  
- Repositorio GitHub actualizado  

## Conclusión

El uso de estructuras eficientes como HashMap
permite mejorar significativamente el rendimiento
del procesamiento masivo de datos.

Procesar archivos línea por línea reduce el
consumo de memoria y permite trabajar con
grandes volúmenes de información sin afectar
gravemente el rendimiento del sistema.

## Autor

Josue David Flores Roldan  
Carnet: 9941 24 7857