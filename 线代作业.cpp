#include <iostream>
#include <vector>
#include <cmath>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

// 函数：构造 13 阶方阵
Matrix<int, 13, 13> construct_matrix(const string& student_id) {
    Matrix<int, 13, 13> A;
    vector<int> digits;
    for (char c : student_id) {
        digits.push_back(c - '0');
    }

    // 第一行填充学号的每一位
    for (int i = 0; i < digits.size(); ++i) {
        A(0, i) = digits[i];
    }

    // 后续行填充对应的平方、立方等
    for (int i = 1; i < 13; ++i) {
        int col_idx = 0;
        for (int digit : digits) {
            stringstream ss;
            ss << pow(digit, i + 1);
            string result = ss.str();
            for (char c : result) {
                if (col_idx < 13) {
                    A(i, col_idx) = c - '0';  // 拆分成每一位
                    col_idx++;
                }
            }
        }
    }
    return A;
}

// 计算行列式
double compute_determinant(const Matrix<int, 13, 13>& A) {
    MatrixXd A_double = A.cast<double>();
    return A_double.determinant();
}

// 高斯消元法求阶梯型矩阵与解空间
void gauss_jordan_elimination(Matrix<int, 13, 13>& A) {
    int m = 13, n = 13;
    for (int i = 0; i < m; ++i) {
        if (A(i, i) == 0) {
            for (int j = i + 1; j < m; ++j) {
                if (A(j, i) != 0) {
                    swap(A.row(i), A.row(j));
                    break;
                }
            }
        }

        for (int j = i + 1; j < m; ++j) {
            double ratio = A(j, i) / double(A(i, i));
            for (int k = i; k < n; ++k) {
                A(j, k) -= A(i, k) * ratio;
            }
        }
    }
}

// 施密特正交化
MatrixXd gram_schmidt_orthogonalization(const MatrixXd& A) {
    int m = A.rows(), n = A.cols();
    MatrixXd Q = MatrixXd::Zero(m, n);
    for (int i = 0; i < n; ++i) {
        VectorXd v = A.col(i);
        for (int j = 0; j < i; ++j) {
            double r = Q.col(j).dot(v);
            v -= r * Q.col(j);
        }
        Q.col(i) = v.normalized();
    }
    return Q;
}

// 计算矩阵 A + A^T 的正负惯性系数
void compute_inertia(const Matrix<int, 13, 13>& A) {
    MatrixXd A_double = A.cast<double>();
    MatrixXd symmetric = A_double + A_double.transpose();
    EigenSolver<MatrixXd> solver(symmetric);
    VectorXd eigenvalues = solver.eigenvalues().real();

    int positive = 0, negative = 0, zero = 0;
    for (int i = 0; i < eigenvalues.size(); ++i) {
        if (eigenvalues(i) > 0) positive++;
        else if (eigenvalues(i) < 0) negative++;
        else zero++;
    }

    cout << "Inertia of A + A^T: " << endl;
    cout << "Positive eigenvalues: " << positive << endl;
    cout << "Negative eigenvalues: " << negative << endl;
    cout << "Zero eigenvalues: " << zero << endl;
}

int main() {
    string student_id = "1234567890123";  // 输入学号

    // 构造矩阵 A
    Matrix<int, 13, 13> A = construct_matrix(student_id);
    cout << "Matrix A:" << endl;
    cout << A << endl;

    // (1) 计算行列式
    double det_A = compute_determinant(A);
    cout << "Determinant of A: " << det_A << endl;

    // (2) 求阶梯型矩阵与解空间
    Matrix<int, 13, 13> A_copy = A;
    gauss_jordan_elimination(A_copy);
    cout << "Row reduced echelon form of A:" << endl;
    cout << A_copy << endl;

    // (3) 施密特正交化
    MatrixXd A_double = A.cast<double>();
    MatrixXd Q = gram_schmidt_orthogonalization(A_double);
    cout << "Orthogonalized matrix Q:" << endl;
    cout << Q << endl;

    // (4) 计算 A + A^T 的正负惯性系数
    compute_inertia(A);

    return 0;
}

