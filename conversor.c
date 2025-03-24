#include <stdio.h>

// Tasas de cambio (puedes actualizarlas según el mercado)
#define USD_TO_GTQ 7.80
#define EUR_TO_GTQ 8.50
#define GTQ_TO_USD (1/USD_TO_GTQ)
#define GTQ_TO_EUR (1/EUR_TO_GTQ)
#define USD_TO_EUR 0.90
#define EUR_TO_USD (1/USD_TO_EUR)

// Función para convertir monedas
double convertir(double cantidad, int de, int a) {
    if (de == a) return cantidad; // Si es la misma moneda, no hay conversión

    switch (de) {
        case 1: // Quetzales
            if (a == 2) return cantidad * GTQ_TO_USD; // GTQ a USD
            if (a == 3) return cantidad * GTQ_TO_EUR; // GTQ a EUR
            break;
        case 2: // Dólares
            if (a == 1) return cantidad * USD_TO_GTQ; // USD a GTQ
            if (a == 3) return cantidad * USD_TO_EUR; // USD a EUR
            break;
        case 3: // Euros
            if (a == 1) return cantidad * EUR_TO_GTQ; // EUR a GTQ
            if (a == 2) return cantidad * EUR_TO_USD; // EUR a USD
            break;
    }
    return 0; // Retorna 0 si hay un error
}

int main() {
    int opcion_origen, opcion_destino;
    double cantidad, resultado;

    printf("=== Conversor de Monedas ===\n");
    printf("1. Quetzales (GTQ)\n");
    printf("2. Dólares (USD)\n");
    printf("3. Euros (EUR)\n");

    // Solicitar moneda de origen
    printf("Seleccione la moneda de origen (1-3): ");
    scanf("%d", &opcion_origen);
    
    // Verificar opción válida
    if (opcion_origen < 1 || opcion_origen > 3) {
        printf("Opción inválida. Intente nuevamente.\n");
        return 1;
    }

    // Solicitar moneda de destino
    printf("Seleccione la moneda de destino (1-3): ");
    scanf("%d", &opcion_destino);
    
    if (opcion_destino < 1 || opcion_destino > 3) {
        printf("Opción inválida. Intente nuevamente.\n");
        return 1;
    }

    // Solicitar cantidad a convertir
    printf("Ingrese la cantidad a convertir: ");
    scanf("%lf", &cantidad);

    if (cantidad < 0) {
        printf("La cantidad no puede ser negativa.\n");
        return 1;
    }

    // Realizar conversión
    resultado = convertir(cantidad, opcion_origen, opcion_destino);
    
    // Mostrar resultado
    printf("Resultado: %.2f\n", resultado);

    return 0;
}
