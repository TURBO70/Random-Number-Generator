#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
class MSM
{
    long long seed;
    int n;
public:
    MSM() {
        seed = 0;
        n = 0;
    }

    MSM(long long seed,int n) {
        this->seed = seed;
        this->n=n;
    }

    void setSeed(long long seed) {
        this->seed = seed;
    }
    void get()
    {
        cout << "Enter number of random number\n";
        cin >> n;
        cout << "Enter the seed\n";
        cin >> seed;
    }
    vector<double> v2;
    void generate() {
        for (int i = 0; i <= n; i++) {
            long long new_seed = seed * seed;
            string str_new_seed = to_string(new_seed);
            while (str_new_seed.length() < 8) {
                str_new_seed = "0" + str_new_seed;
            }
            string the_middle_4 = str_new_seed.substr(2, 4);
            double next_seed = stoull(the_middle_4);
            seed = next_seed;
            v2.push_back(next_seed);
        }
        for (int i = 0; i < v2.size(); i++) {
            cout << "X" << i << " = " << v2[i] << " " << "R" << i << " = " << v2[i]/10000 << endl;
        }
    }
    /*void generate() {
        for (int i = 0; i <= n; i++) {
            long long new_seed = seed * seed;
            string str_new_seed = to_string(new_seed);
            while (str_new_seed.length() < 8) {
                str_new_seed = "0" + str_new_seed;
            }
            string the_middle_4 = str_new_seed.substr(2, 4);
            double next_seed = stoull(the_middle_4);
            seed = next_seed;
            v2.push_back(next_seed);
        }
    }*/
};

