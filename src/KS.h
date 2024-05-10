#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include<iomanip>

using namespace std;
class Ks {

private:
    float a;
    float D;
    float D_alpha;
public:
    void generate() {
        vector<double> D0_10 = { 0.950, 0.776, 0.642, 0.564, 0.510, 0.470, 0.438, 0.411, 0.388, 0.368, 0.352, 0.338,
                                0.325, 0.314, 0.304, 0.295, 0.286, 0.278, 0.272, 0.264, 0.24, 0.22, 0.21 };
        vector<double> D0_05 = { 0.975, 0.842, 0.708, 0.624, 0.565, 0.521, 0.486, 0.457, 0.432, 0.410, 0.391, 0.375,
                                0.361, 0.349, 0.338, 0.328, 0.318, 0.309, 0.301, 0.294, 0.27, 0.24, 0.23 };
        vector<double> D0_01 = { 0.995, 0.929, 0.828, 0.733, 0.669, 0.618, 0.577, 0.543, 0.514, 0.490, 0.468, 0.450,
                                0.433, 0.418, 0.404, 0.392, 0.381, 0.371, 0.363, 0.356, 0.32, 0.29, 0.27 };

        float D1 = 0.0, D2 = 0.0;
        float size;
        cout << "enter the size of numbers :" << endl;
        cin >> size;
        vector<float >X((int)size);
        cout << "enter " << size << " genereted numbers:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> X[i];
        }
        cout << "Enter the value of alpha ..." << endl;
        int a;
        cin >> a;
        sort(X, X + int(size));
        cout << "X" << "        i/n " << "     (i/n)-x " << "    x-((i-1)/n)" << endl;
        for (int i = 0; i < size; i++) {
            cout << fixed << setprecision(3);
            cout << X[i] << "   " << (i + 1) / size << "    ";

            if (float((i + 1) / size) - X[i] < 0)
                cout << " - ";
            else {
                cout << float((i + 1) / size) - X[i] << "    ";
                D1 = max(float((i + 1) / size) - X[i], D1);
            }

            if (X[i] - float(i / size) < 0)
                cout << " - ";
            else {
                cout << X[i] - float(i / size);
                D2 = max(X[i] - float(i / size), D2);
            }
            cout << endl;
        }
        D = max(D1, D2);
        cout << endl << "D= " << D1 << endl << endl;


        if (a == 0.05) {
            D_alpha = D0_05[size];
        }
        else if (a == 0.10) {
            D_alpha = D0_10[size];
        }
        else {
            D_alpha = D0_01[size];
        }
        if (D < D_alpha) {
            cout << "Accepted" << endl;
        }
        else {
            cout << "Rejected" << endl;
        }

    }


};