#include <iostream>
#include <vector>
using namespace std;

class LFG {
private:
    int K;
    int J;
    int M;
    double X0;
    int N;
    char OP;
public:
    LFG()
    {
        K = 0;
        J = 0;
        M = 0;
        X0 = 0.0;
        N = 0;
        OP = ' ';
    }
    LFG(int K, int J, int M, double X0, int N ,char OP) {
        this->K = K;
        this->J = J;
        this->M = M;
        this->X0 = X0;
        this->N = N;
        this->OP = OP;


    }
    void get() {
        cout << "Enter the value of j:" << endl;
        cin >> J;
        do {
            if (J > 0)
            {
                cout << "Enter the value of k:" << endl;
                cin >> K;
                if (J >= K)
                {
                    cout << "k must be greater than j" << endl;
                    //////////////////////////////
                    cout << "Enter the value of k:" << endl;
                    cin >> K;
                    break;
                }
                break;
            }

            else {

                cout << "j must be greater than zero" << endl;

                cout << "Enter the value of j:" << endl;
                cin >> J;
            }

        } while (true);
        ///////////////////
        cout << "Enter the value of modulus:" << endl;
        cin >> M;
        while(M <= 0) {
            cout << "Invalid modulus.Please enter a positive Number"  << endl;
            cin >> M;
        }
        //////////////////////////
        for (int i = 0; i < K; i++) {
            cout << "Enter the value of x" << i <<":" << endl;
            cin >> X0;
            x.push_back(X0);
        }

        ////////////////////////////
        cout << "Enter the number of generated numbers:" << endl;
        cin >> N;
        while (N <= 0) {
            cout << "Invalid modulus.Please enter a positive Number" << endl;
            cin >> N;
        }
        ///////////////////////
        cout << "Enter the operator:" << endl;
        cin >> OP;
        while (OP != '+' && OP != '+' && OP != '*' && OP != '^') {
            cout<<"Enter '+' OR '-' OR '*' OR '^' " << endl;
            cin >> OP;
        }
    }
    
    vector<double>x;
    void generate()
    {
        for (int i = K; i <= N; ++i) {
            int a = x[i - J], b = x[i - K], ab;
            if (OP == '+') {
                ab = a + b;
            }
            else if (OP == '-') {
                ab = a - b;
            }
            else if (OP == '^') {
                ab = a ^ b;
            }
            else if (OP == '*') {
                ab = a * b;
            }
            while (ab >= M) {
                ab -= M;
            }
            while (ab < 0) {
                ab += M;
            }
            x.push_back(ab);
        }
        for (int i = 0; i < x.size(); i++) {
            cout << "X" << i << " = " << x[i] << " " << "R" << i << " = " << x[i] / M << endl;
        }
    }
};
