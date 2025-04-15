#include <iostream>
#include <fstream> 
using namespace std;
int main()
{
    double dt = 0.1;
    double h = 100;
    double g = -9.81;
    double v = 0;
    double t = 0;

    ofstream MyFile("wyniki.txt");

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
