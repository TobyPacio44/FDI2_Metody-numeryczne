#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double g = 9.81;
    double H = 230.0;
    double m = 2.0;
    double dt = 0.1;

    ofstream MyFile("wyniki.txt");

    MyFile << std::fixed << std::setprecision(2);
    MyFile << "t [s] \t \t y [m] \t \t vy [m/s] \t Ec [J] \t Ek [J] \t Ep [J]" << std::endl;
    
    double t = 0.0;
    while (true) {
        double vy = g * t;
        double y = H - 0.5 * g * t * t;


        double Ek = 0.5 * m * vy * vy;
        double Ep = m * g * y;
        double Ec = Ek + Ep;

        MyFile << t << "\t\t" << y << "\t\t" << vy << "\t\t" << Ec << "\t\t" << Ek << "\t\t" << Ep << "\n";

        t += dt;

        if (y < 0) { break; }
    }

    return 0;
}
