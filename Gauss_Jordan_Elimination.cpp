#include<iostream>
#include<vector>

using namespace std;

void printMatrix( vector<vector<double>>& aM) {
    for (int i=0;i<3;i++) {
        for (int j=0;j<4;j++) {
            cout << aM[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}


void gaussJordanElimination(vector<vector<double>>& aM) {
    int n = aM.size();

    for (int i = 0; i < n; i++) {
        
        //Every element of the main diagonal will be 1
        double p = aM[i][i];
        for (int j = 0; j <= n; j++) {
            aM[i][j] /= p;
        }

        //printMatrix(aM);
        
        //Every other element will be 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double f = aM[k][i];
                for (int j = 0; j <= n; j++) {
                    aM[k][j] -= f * aM[i][j];
                }
            }
        }

       //printMatrix(aM);
    }
}

void print(const vector<double>& c) {
    cout << "a1 = " << c[0] << endl;
    cout << "a2 = " << c[1] << endl;
    cout << "a3 = " << c[2] << endl;
}

int main() {
    //initializing the augmented matrix
    vector<vector<double>> aM = {{25, 5, 1, 106.8},
                                 {64, 8, 1, 177.2},
                                 {144, 12, 1, 279.2}};
    
    gaussJordanElimination(aM);
    

    vector<double> c(3);
    for (int i = 0; i < 3; i++) {
        c[i] = aM[i][3];
    }

    print(c);
    
    //calculating the velocity at time 6
    double t = 6.0;
    double velocity = c[0] * t * t + c[1] * t + c[2];
    cout << "velocity: " << velocity << " m/s" << endl;

    return 0;
}
