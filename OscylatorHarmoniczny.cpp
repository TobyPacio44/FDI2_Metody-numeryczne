#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

const double g = 9.81;
const double m = 230.0; 
const double k = 10.0;  
const double dt = 0.5;
const double T = 60;

double acceleration(double y) {
    return (-k / m) * y - g;
}

int main() {
    double t = 0.0;   
    double y = 230.0;     
    double vy = 0.0;         

    std::ofstream file("oscylator.csv");
    //std::ofstream file("wyniki.txt");

    file << std::fixed << std::setprecision(2);
    //file << "t [s] \t \t y [m] \t \t vy [m/s] \t Ec [J] \t Ek [J] \t Ep [J]" << std::endl;

    file << "t,y,vy,Ec,Ek,Ep\n";

    while (t <= T) {
        double ky1 = vy * dt;
        double kv1 = acceleration(y) * dt;

        double ky2 = (vy + 0.5 * kv1) * dt;
        double kv2 = acceleration(y + 0.5 * ky1) * dt;

        double ky3 = (vy + 0.5 * kv2) * dt;
        double kv3 = acceleration(y + 0.5 * ky2) * dt;

        double ky4 = (vy + kv3) * dt;
        double kv4 = acceleration(y + ky3) * dt;

        y += (1.0 / 6.0) * (ky1 + 2 * ky2 + 2 * ky3 + ky4);
        vy += (1.0 / 6.0) * (kv1 + 2 * kv2 + 2 * kv3 + kv4);

        double Ek = 0.5 * m * vy * vy;
        double Ep = 0.5 * k * y * y + m * g * y;
        double Ec = Ek + Ep;

        //file << t << "\t\t" << y << "\t\t" << vy << "\t\t" << Ec << "\t\t" << Ek << "\t\t" << Ep << "\n";
        file << t << "," << y << "," << vy << "," << Ec << "," << Ek << "," << Ep << "\n";

        t += dt;
    }

    file.close();
    std::cout << "Symulacja zakonczona. Wyniki zapisane w 'wyniki.txt'.\n";
    return 0;
}

