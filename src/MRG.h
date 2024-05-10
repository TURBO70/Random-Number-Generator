#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
class MRG {
private:
    long long n, m;
    vector<double>x, a;
public:
    MRG()
    {
        n = 0;
        m = 1;
    }
    MRG(long long n, long long m )
    {
        this->n = n;
        this->m = m;
    }
    
    void get()
    {
        cout << "Enter number of random number\n";
        cin >> n;
        while (n <= 0) {
            cout << "Invalid modulus.Please enter a positive Number" << endl;
            cin >> n;
        }
        /// //////////////
        cout << "Enter the length of a and x on single integer\n";
        long long s;
        cin >> s;
        cout << "Enter a vector\n";
        for (int i = 0; i < s; ++i)
        {
            double num;
            cin >> num;
            a.push_back(num);
        }
        cout << "Enter x vector\n";
        for (int i = 0; i < s; ++i)
        {
            double num;
            cin >> num;
            x.push_back(num);
        }
        cout << "Enter modulus\n";
        cin >> m;
        while (m <= 0) {
            cout << "Invalid modulus.Please enter a positive Number" << endl;
            cin >> m;
        }
    }
    void generate()
    {
        vector<double>xn;

        for (int i = 0; i < x.size(); i++) {
            xn.push_back(x[i]);
        }

        int size_a = a.size();
        double ans = 0;

        for (int i = xn.size(); i <= n; i++) {

            int idx = 0;

            for (int j = i - size_a; j < i; ++j, idx++) {
                ans += (a[idx] * xn[j]);
            }

            while (ans >= m) {
                ans -= m;
            }

            xn.push_back(ans);
            ans = 0;
        }
        for (int i = 0; i < xn.size(); i++) {
            if (i > n)break;
            cout << "X" << i << " = " << xn[i] << " " << "R" << i << " = " << xn[i] / m << endl;
        }
    }
};

