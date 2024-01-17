#include<iostream>
#include<vector>

using namespace std;

void forwarding(vector<vector<double>>& aM) {
    int n = aM.size();

    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double f = aM[i][k] / aM[k][k];
            for (int j = k; j < n + 1; j++) {
                aM[i][j] -= f * aM[k][j];
            }
        }
    }
}

void sub(vector<vector<double>>& aM, vector<double>& c) {
    int n = aM.size();

    for (int i = n - 1; i >= 0; i--) {
        c[i] = aM[i][n];
        for (int j = i + 1; j < n; j++) {
            c[i] -= aM[i][j] * c[j];
        }
        c[i] /= aM[i][i];
    }
}

void print(const vector<double>& c) {
    cout << "a1 = " << c[0] << endl;
    cout << "a2 = " << c[1] << endl;
    cout << "a3 = " << c[2] << endl;
}

int main() {

    vector<vector<double>> aM = {{25, 5, 1, 106.8},
                                             {64, 8, 1, 177.2},
                                             {144, 12, 1, 279.2}};

    
    forwarding(aM);

    vector<double> c(3);
    sub(aM, c);

    print(c);

    double t = 6.0;
    double velocity = c[0] * t * t + c[1] * t + c[2];
    cout << "velocity: " << velocity << " m/s" << endl;

    return 0;
}