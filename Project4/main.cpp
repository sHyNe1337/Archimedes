#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const string TAG = "sHyNe1337";      // Dein persönlicher Tag
#define PRECISION 12             // Nachkommastellen zentral einstellbar
#define MAX_ITER 20              // Anzahl Iterationen (Polygon-Verdoppelungen)

int main() {
    cout << "=============================================================\n";
    cout << " Berechnung der Kreiszahl PI nach Archimedes (287-212 v. Chr.)\n";
    cout << "=============================================================\n\n";

    cout << "Tag: " << TAG << "\n";
    cout << "Referenzwert: PI = "
        << fixed << setprecision(PRECISION) << M_PI << "\n\n";

    cout << setw(15) << "Anzahl Ecken"
        << setw(20) << "PI-Naeherung" << endl;
    cout << string(35, '-') << endl;

    int anzahlEcken = 6;          // Start: Hexagon
    double seitenlaenge = 1.0;    // Seite des einbeschriebenen 6-Ecks

    for (int i = 0; i < MAX_ITER; i++) {
        // Archimedes: π ≈ (Umfang des Polygons) / (2 * Radius)
        double pi_approx = (anzahlEcken * seitenlaenge) / 2.0;

        cout << setw(15) << anzahlEcken
            << setw(20) << fixed << setprecision(PRECISION) << pi_approx << endl;

        // Neue Seitenlänge für das Polygon mit verdoppelter Eckenzahl
        double seitenlaengeNeu = sqrt(2.0 - sqrt(4.0 - seitenlaenge * seitenlaenge));
        seitenlaenge = seitenlaengeNeu;
        anzahlEcken *= 2;
    }

    cout << "\n-- Ende der Berechnung | Tag: " << TAG << " --" << endl;
    return 0;
}
