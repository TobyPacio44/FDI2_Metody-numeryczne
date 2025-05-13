#include <iostream>
#include <cmath>
#include <fstream> 
#include <iomanip>

using namespace std;
int main()
{
    double V = 25.0;
    double angle = 50;
    double H = 5.0;
    double g = 9.81;
    double dt = 0.1;

    double angleRad = angle * 3.141592 / 180.0;

    double v_x = V * cos(angleRad);
    double v_y = V * sin(angleRad);

    double x = 0;
    double y = H;

    double vy = v_y;

    double t = 0.0;

    ofstream MyFile("wyniki.txt");

    MyFile << std::fixed << std::setprecision(2);
    MyFile << "t(s)\txf(m)\tyf(m)\tvx(m/s)\tvy(m/s)\n";

    while (y > 0) {
        t += dt;

        x = v_x * t;
        y = H * v_y * t - 0.5 * g * t * t;

        vy = v_y - g * t;


        MyFile << t << "\t" << x << "\t" << y << "\t" << v_x << "\t" << vy << "\n";
    }

}
