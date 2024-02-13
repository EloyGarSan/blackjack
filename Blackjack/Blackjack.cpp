// Blackjack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función para obtener un valor aleatorio de una carta (entre 2 y 10)
int obtenerValorCarta() {
    return rand() % 6 + 2; // Cartas del 2 al 10
}

// Función para determinar si un valor es un AS
bool esAs(int valor) {
    return valor == 1;
}

// Función para mostrar las cartas y el total
void mostrarEstado(int totalJugador, int totalCroupier, bool mostrarTodo, string paloJugador, string paloCroupier) {
    cout << "\nTu carta es: " << totalJugador << " " << paloJugador << endl;

    if (mostrarTodo) {
        cout << "Carta del croupier: " << totalCroupier << " " << paloCroupier << endl;
    }
    else {
        cout << "La Carta del croupier: " << (esAs(totalCroupier) ? 1 : totalCroupier) << " " << paloCroupier << endl;
    }
}

int main() {
    srand(time(0)); // Semilla para la generación de números aleatorios

    string palos[] = { "Corazon", "Diamante", "Trebol", "Pica" };

    int tamano = sizeof(palos) / sizeof(palos[0]);

    // Inicialización de variables
    int totalJugador = 0;
    int totalCroupier = 0;

    // Repartir cartas al jugador
    int indiceJugador = rand() % tamano;
    totalJugador += obtenerValorCarta();
    totalJugador += obtenerValorCarta();
    string paloJugador = palos[indiceJugador];

    // Repartir carta al croupier
    int indiceCroupier = rand() % tamano;
    totalCroupier += obtenerValorCarta();
    string paloCroupier = palos[indiceCroupier];

    // Mostrar las cartas iniciales
    mostrarEstado(totalJugador, totalCroupier, false, paloJugador, paloCroupier);

    // Turno del jugador
    char eleccion;
    do {
        indiceJugador = rand() % tamano; // Generar un nuevo índice en cada iteración
        cout << "Quieres una nueva carta? (s/n): ";
        cin >> eleccion;

        if (eleccion == 's') {
            int nuevaCarta = obtenerValorCarta();
            totalJugador += (esAs(nuevaCarta) ? 11 : nuevaCarta);
            paloJugador = palos[indiceJugador];
            mostrarEstado(totalJugador, totalCroupier, false, paloJugador, paloCroupier);
        }

    } while (eleccion == 's' && totalJugador < 21);

    // Turno del croupier
    while (totalCroupier < 17) {
        indiceCroupier = rand() % tamano;
        int nuevaCarta = obtenerValorCarta();
        totalCroupier += (esAs(nuevaCarta) ? 11 : nuevaCarta);
        paloCroupier = palos[indiceCroupier];
    }

    // Mostrar resultados
    mostrarEstado(totalJugador, totalCroupier, true, paloJugador, paloCroupier);

    // Determinar el resultado del juego
    if (totalJugador == 21 && totalCroupier != 21) {
        cout << "Has ganado BLACKJACK!" << endl;
    }
    else if (totalJugador <= 21 && totalCroupier > 21) {
        cout << "La banca se ha pasado del blackjack. HAS GANADO!" << endl;
    }
    else if (totalJugador == totalCroupier && totalJugador <= 21) {
        cout << "Ambos tienen la misma puntuacion. EMPATE!" << endl;
    }
    else if (totalJugador > 21) {
        cout << "Te has pasado del blackjack. HAS PERDIDO!" << endl;
    }
    else if (totalCroupier <= 21 && totalCroupier >= totalJugador) {
        cout << "La banca tiene una puntuacion mayor. HAS PERDIDO!" << endl;
    }
    else {
        cout << "La banca se ha pasado de blackjack. HAS GANADO!" << endl;
    }

    return 0;
}




// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
