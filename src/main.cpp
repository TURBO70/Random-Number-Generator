#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include "ICG.h"
#include "LFG.h"
#include "MSM.h"
#include "MRG.h"
#include <windows.h>
using namespace std;
int main()
{
	int choice;
	ICG x;
	MRG y;
	LFG z;
	MSM v;
	//KS w;
	char c;
	do {
		cout << "(1) ICG " << endl;
		cout << "(2) Ks " << endl;
		cout << "(3) MRG" << endl;
		cout << "(4) LFG " << endl;
		cout << "(5) MSM " << endl;
		cout << "Enter Number of Algorithm: ";
		cin >> choice;
		system("cls");
		if (choice == 1) {
			x.get();
			x.generate();
		}
		else if (choice == 2) {
			//W.get();
			//W.generate();
		}
		else if (choice == 3) {
			y.get();
			y.generate();
		}
		else if (choice == 4) {
			z.get();
			z.generate();
		}
		else if (choice == 5) {
			v.get();
			v.generate();
		}
		else {
			cout << "Please Enter 1 or 2 or 3 or 4 or 5";
		}
		cout << "if you want choose anther algorithm exp Y OR y else N OR n :";
		cin >> c;
		system("cls");
	} while (c=='Y'||c=='y');
}
