import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

public class ProcesadorOptimizado {

    public static HashMap<String, Integer>
    procesarClientes(String archivo) {

        HashMap<String, Integer> campanias =
                new HashMap<>();

        try {

            BufferedReader br =
                    new BufferedReader(
                            new FileReader(archivo));

            String linea;

            br.readLine();

            while ((linea = br.readLine()) != null) {

                String[] datos =
                        linea.split(",", 8);

                Cliente cliente =
                        new Cliente(
                                Integer.parseInt(datos[0]),
                                datos[1],
                                Double.parseDouble(datos[2]),
                                datos[3],
                                datos[4],
                                Integer.parseInt(datos[5]),
                                Double.parseDouble(datos[6]),
                                datos[7]
                        );

                String campania =
                        determinarCampania(cliente);

                if (campanias.containsKey(campania)) {

                    int cantidad =
                            campanias.get(campania);

                    campanias.put(
                            campania,
                            cantidad + 1
                    );

                } else {

                    campanias.put(campania, 1);
                }
            }

            br.close();

        } catch (IOException e) {

            System.out.println("Error leyendo archivo.");
        }

        return campanias;
    }

    public static String determinarCampania(
            Cliente cliente) {

        String nivelIngreso;

        if (cliente.getIngreso() >= 25000) {

            nivelIngreso = "INGRESO_ALTO";

        } else if (cliente.getIngreso() >= 15000) {

            nivelIngreso = "INGRESO_MEDIO";

        } else if (cliente.getIngreso() >= 10000) {

            nivelIngreso = "INGRESO_BAJO";

        } else {

            nivelIngreso = "NO_APLICA";
        }

        String nivelScore;

        if (cliente.getScore() >= 800) {

            nivelScore = "SCORE_EXCELENTE";

        } else if (cliente.getScore() >= 600) {

            nivelScore = "SCORE_BUENO";

        } else if (cliente.getScore() >= 400) {

            nivelScore = "SCORE_REGULAR";

        } else {

            nivelScore = "SCORE_RIESGO";
        }

        String nivelDeuda;

        if (cliente.getDeuda() >= 7000) {

            nivelDeuda = "DEUDA_ALTA";

        } else if (cliente.getDeuda() >= 3000) {

            nivelDeuda = "DEUDA_MEDIA";

        } else {

            nivelDeuda = "DEUDA_BAJA";
        }

        return cliente.getSegmento()
                + "_"
                + cliente.getRegion()
                + "_"
                + nivelIngreso
                + "_"
                + nivelScore
                + "_"
                + nivelDeuda;
    }
}