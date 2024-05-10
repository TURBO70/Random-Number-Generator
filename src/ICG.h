#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
class ICG {
private:
    double x;
    double a;
    double M;
    int N;

public:
    ICG() {
        x = 0.0;
        a = 0.0;
        M = 0.0;
        N = 0;

    }
    ICG(double x, double a, double m, int N) {
        this->x = x;
        this->a = a;
        this->M = m;
        this->N = N;
    }
    void get() {
        cout << "Enter the value of X:" << endl;
        cin >> x;
        do {
            if (x == 0)
            {
                cout << "X must be Not equal zero" << endl;
                cout << "Enter the value of X:" << endl;
                cin >> x;
            }
            else
            {
                break;
            }
        } while (true);
        //////////////
        cout << "Enter the value of a:" << endl;
        cin >> a;
        ///////////////////
        cout << "Enter the value of modulus:" << endl;
        cin >> M;
        while (M <= 0) {
            cout << "Invalid modulus.Please enter a positive Number" << endl;
            cin >> M;
        }
        //////////////////////////
        cout << "Enter the number of generated numbers:" << endl;
        cin >> N;

    }
    void generate()
    {
        vector<double> xn(N + 1);
        xn[0] = x;
        for (int i = 1; i <= N; ++i) {
            /*while (xn[0] > M) {
                xn[0] -= M;
            }*/
            xn[i] = (a / xn[i - 1]);

            while (xn[i] >= M) {
                xn[i] -= M;
            }
            while (xn[i] < 0) {
                xn[i] -= M;
            }
        }
        for (int i = 1; i < xn.size(); i++) {
            cout << "X" << i << "= " << xn[i] << " " << "R" << i << "=" << xn[i] / M << endl;
        }
    }
};