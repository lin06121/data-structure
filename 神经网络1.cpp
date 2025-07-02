#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

#define RANDOM (rand() / (double)RAND_MAX)
const int Layer_Max = 5;
const int Neural_Max = 4;
const int InMax = 21;
const double PI = 3.1415927;

const int Layer_number[Layer_Max] = {2, 4, 4, 2, 1};
ofstream Out_W_File("All_W.txt", ios::out);

class BP {
public:
    BP();
    void Train();
    void After_Train_Out();
    void PrintWeights();

private:
    double F(double x);
    double Y(double x1, double x2);
    double Cost(double out, double exp);
    double NetWorkOut(int x1, int x2);
    void AllLayer_D(int x1, int x2);
    void Change_W();

    double W[Layer_Max][Neural_Max][Neural_Max];
    double Input_Net[2][InMax];
    double Out_Exp[InMax][InMax];
    double Layer_Node[Layer_Max][Neural_Max];
    double D[Layer_Max][Neural_Max];
    double Study_Speed;
    double e;
};

BP::BP() {
    srand(time(nullptr));
    // Initialize weights
    for (int i = 1; i < Layer_Max; ++i) {
        for (int j = 0; j < Layer_number[i]; ++j) {
            for (int k = 0; k <= Layer_number[i - 1]; ++k) {
                W[i][j][k] = RANDOM;
            }
        }
    }

    // Initialize input and expected output
    for (int l = 0; l < InMax; ++l) {
        Input_Net[0][l] = l * 0.05;
        Input_Net[1][l] = 1 - l * 0.05;
    }

    for (int i = 0; i < InMax; ++i) {
        for (int j = 0; j < InMax; ++j) {
            Out_Exp[i][j] = Y(Input_Net[0][i], Input_Net[1][j]) / 3.0;
        }
    }

    Study_Speed = 0.5;
    e = 0.0001;
}

double BP::F(double x) {
    return 1.0 / (1 + exp(-x));
}

double BP::Y(double x1, double x2) {
    return pow(x1 - 1, 4) + 2 * pow(x2, 2);
}

double BP::Cost(double out, double exp) {
    return pow(out - exp, 2);
}

double BP::NetWorkOut(int x1, int x2) {
    Layer_Node[0][0] = Input_Net[0][x1];
    Layer_Node[0][1] = Input_Net[1][x2];

    for (int i = 1; i < Layer_Max; ++i) {
        for (int j = 0; j < Layer_number[i]; ++j) {
            double sum = 0.0;
            for (int k = 0; k < Layer_number[i - 1]; ++k) {
                sum += Layer_Node[i - 1][k] * W[i][j][k];
            }
            sum -= W[i][j][Layer_number[i - 1]];  // Bias term
            Layer_Node[i][j] = F(sum);
        }
    }

    return Layer_Node[Layer_Max - 1][0];
}

void BP::AllLayer_D(int x1, int x2) {
    int i, j, k;
    double temp;

    // Calculate error for output layer
    D[Layer_Max - 1][0] = Layer_Node[Layer_Max - 1][0] *
                          (1 - Layer_Node[Layer_Max - 1][0]) *
                          (Layer_Node[Layer_Max - 1][0] - Out_Exp[x1][x2]);

    // Backpropagate error through hidden layers
    for (i = Layer_Max - 1; i > 0; --i) {
        for (j = 0; j < Layer_number[i - 1]; ++j) {
            temp = 0.0;
            for (k = 0; k < Layer_number[i]; ++k) {
                temp += W[i][k][j] * D[i][k];
            }
            D[i - 1][j] = Layer_Node[i - 1][j] * (1 - Layer_Node[i - 1][j]) * temp;
        }
    }
}

void BP::Change_W() {
    for (int i = 1; i < Layer_Max; ++i) {
        for (int j = 0; j < Layer_number[i]; ++j) {
            for (int k = 0; k < Layer_number[i - 1]; ++k) {
                W[i][j][k] -= Study_Speed * D[i][j] * Layer_Node[i - 1][k];
            }
            W[i][j][Layer_number[i - 1]] += Study_Speed * D[i][j];  // Bias adjustment
        }
    }
}

void BP::Train() {
    int i, j;
    int ok = 0;
    long int count = 0;
    double err;

    while (ok < InMax * InMax) {
        ok = 0;
        ++count;
        for (i = 0; i < InMax; ++i) {
            for (j = 0; j < InMax; ++j) {
                double out = NetWorkOut(i, j);
                AllLayer_D(i, j);
                err = Cost(out, Out_Exp[i][j]);
                if (err < e) {
                    ++ok;
                } else {
                    Change_W();
                }
            }
        }

        if (count % 1000 == 0) {
            cout << "Iteration: " << count << ", Error: " << err << endl;
        }
    }

    cout << "Training completed after " << count << " iterations with final error: " << err << endl;
}

void BP::After_Train_Out() {
    ofstream Out_Result("Result.txt", ios::out);

    for (int i = 0; i < InMax; ++i) {
        for (int j = 0; j < InMax; ++j) {
            double result = 3 * NetWorkOut(i, j);
            Out_Result << Input_Net[0][i] << "," << Input_Net[1][j] << "," << result << endl;
        }
    }

    Out_Result.close();
}

void BP::PrintWeights() {
    cout << "Final weights:" << endl;
    for (int i = 1; i < Layer_Max; ++i) {
        for (int j = 0; j < Layer_number[i]; ++j) {
            for (int k = 0; k <= Layer_number[i - 1]; ++k) {
                cout << "W[" << i << "][" << j << "][" << k << "] = " << W[i][j][k] << endl;
            }
        }
    }
}

int main() {
    BP bp;
    bp.Train();
    bp.PrintWeights();
    bp.After_Train_Out();
    return 0;
}

