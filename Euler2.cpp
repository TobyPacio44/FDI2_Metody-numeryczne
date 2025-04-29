#include <iostream>
#include <fstream> 
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
    //Program oblicza metodę Euldera obiektu rzuconego pod kątem

    double dt = 0.1;
    double h = 0;
    double g = 9.81;
    double v0 = 20;
    double angle = 60;
    double angle_rad = angle * 3.141592653 / 180;

    double v0x = v0 * cos(angle_rad);
    double v0y = v0 * sin(angle_rad);


    double t_max = 2 * v0y / g;

    ofstream MyFile("wyniki.txt");

    MyFile << std::fixed << std::setprecision(2);
    MyFile << "t(s)\tx(m)\ty(m)\tvx(m/s)\tvy(m/s)\n";


    for (double t = 0; t <= t_max; t += dt) {
        double x = v0x * t;
        double y = v0y * t - 0.5 * g * t * t;

        double vx = v0x;
        double vy = v0y - (g * t);

        if (y < 0) { y = 0; }
        MyFile << t << "\t" << x << "\t" << y << "\t" << vx << "\t" << vy << "\n";
    }

    return 0;
}
