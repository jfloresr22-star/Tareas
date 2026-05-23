import java.util.HashMap;

public class Main {

    public static void main(String[] args) {

        System.out.println("======================================");
        System.out.println("LABORATORIO: PROCESAMIENTO MASIVO");
        System.out.println("======================================");

        System.out.println("Nombre: Josue David Flores Roldan");
        System.out.println("Carnet: 9941 24 7857");

        String archivo = "clientes.csv";

        int cantidadClientes = 2000000;

        System.out.println("\nGenerando archivo...");

        long inicioGeneracion = System.currentTimeMillis();

        GeneradorClientes.generarArchivo(archivo, cantidadClientes);

        long finGeneracion = System.currentTimeMillis();

        System.out.println("Tiempo de generacion: "
                + (finGeneracion - inicioGeneracion) + " ms");

        mostrarMemoria();

        System.out.println("\nProcesando clientes con HashMap...");

        long inicioProceso = System.currentTimeMillis();

        HashMap<String, Integer> campanias =
                ProcesadorOptimizado.procesarClientes(archivo);

        long finProceso = System.currentTimeMillis();

        System.out.println("\n=== RESUMEN FINAL ===");

        System.out.println("Total campañas: " + campanias.size());

        for (String key : campanias.keySet()) {

            System.out.println(key + " : "
                    + campanias.get(key));
        }

        System.out.println("\nTiempo procesamiento optimizado: "
                + (finProceso - inicioProceso) + " ms");

        mostrarMemoria();

        System.out.println("\nPrograma finalizado.");
    }

    public static void mostrarMemoria() {

        Runtime runtime = Runtime.getRuntime();

        long usada =
                runtime.totalMemory() - runtime.freeMemory();

        long total = runtime.totalMemory();

        long maxima = runtime.maxMemory();

        System.out.println("\n=== MEMORIA JVM ===");

        System.out.println("Usada: "
                + (usada / 1024 / 1024) + " MB");

        System.out.println("Total: "
                + (total / 1024 / 1024) + " MB");

        System.out.println("Maxima: "
                + (maxima / 1024 / 1024) + " MB");
    }
}
