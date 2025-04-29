#include <iostream>
#include <fstream> 
using namespace std;
int main()
{
    //Program oblicza metodę Eulera dla obiektu rzuconego w górę
    //dt ustawić na 0.00001 dla lepszej dokładności
    double dt = 0.1;
    double h = 100;
    double g = -9.81;
    double v = 0;
    double t = 0;

    ofstream MyFile("wyniki.txt");

    MyFile << "t [s] \t \t y [m] \t \t \t vy [m/s]" << std::endl;
    
    while (h > 0) {
        MyFile << "t = " << t << ", h = " << h << ", v = " << v << " m/s" << std::endl;

        v += g * dt;
        h += v * dt;
        t += dt;

    }

    MyFile << "Obiekt udezyl w ziemie po: " << t << "sekundach;";

    MyFile.close();
    return 0;
}
