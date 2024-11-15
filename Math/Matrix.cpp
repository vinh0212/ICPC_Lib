// Matrix, which works for both double and int {{{
// Copied partially from https://judge.yosupo.jp/submission/54653
//
// Tested:
// - (mat mul): https://judge.yosupo.jp/problem/matrix_product
// - (mat pow): https://oj.vnoi.info/problem/icpc21_mt_k
// - (mat pow): https://oj.vnoi.info/problem/icpc21_mb_h
// - (gauss): https://oj.vnoi.info/problem/vmrook
// - (inverse): https://oj.vnoi.info/problem/dtl_lsr
// - (inverse): https://judge.yosupo.jp/problem/inverse_matrix
// - (det): https://judge.yosupo.jp/problem/matrix_det

#include <bits/stdc++.h>
using namespace std;

// Define a type alias for clarity
typedef long long ll;

// Matrix Class
template<typename T>
struct Matrix {
    int n_row, n_col;
    vector<vector<T>> mat;

    // Constructor: Initialize n_row x n_col matrix with all elements as zero
    Matrix(int _n_row, int _n_col) : n_row(_n_row), n_col(_n_col), mat(_n_row, vector<T>(_n_col, 0)) {}

    // Constructor: Initialize from a 2D vector
    Matrix(const vector<vector<T>>& d) : n_row(d.size()), n_col(d.empty() ? 0 : d[0].size()), mat(d) {}

    // Static method to create an identity matrix
    static Matrix identity(int size) {
        Matrix I(size, size);
        for(int i = 0; i < size; ++i) {
            I.mat[i][i] = 1;
        }
        return I;
    }

    // Matrix multiplication
    Matrix operator* (const Matrix& other) const {
        assert(n_col == other.n_row);
        Matrix result(n_row, other.n_col);
        for(int i = 0; i < n_row; ++i) {
            for(int k = 0; k < n_col; ++k) {
                if (mat[i][k] == 0) continue; // Optimization for sparse matrices
                for(int j = 0; j < other.n_col; ++j) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    // Matrix exponentiation
    Matrix pow(long long power) const {
        assert(n_row == n_col); // Only square matrices can be exponentiated
        Matrix result = Matrix::identity(n_row);
        Matrix base = *this;
        long long p = power;
        while(p > 0) {
            if(p & 1) {
                result = result * base;
            }
            base = base * base;
            p >>= 1;
        }
        return result;
    }

    // Determinant using Gaussian Elimination
    T determinant() const {
        assert(n_row == n_col);
        int N = n_row;
        Matrix<T> mat_copy = *this;
        T det = 1;
        for(int i = 0; i < N; ++i){
            // Find pivot
            int pivot = i;
            for(int j = i; j < N; ++j){
                if(abs(mat_copy.mat[j][i]) > abs(mat_copy.mat[pivot][i])){
                    pivot = j;
                }
            }
            if(mat_copy.mat[pivot][i] == 0){
                return 0;
            }
            if(pivot != i){
                swap(mat_copy.mat[i], mat_copy.mat[pivot]);
                det *= -1;
            }
            det *= mat_copy.mat[i][i];
            // Eliminate below
            for(int j = i + 1; j < N; ++j){
                T factor = mat_copy.mat[j][i] / mat_copy.mat[i][i];
                for(int k = i; k < N; ++k){
                    mat_copy.mat[j][k] -= factor * mat_copy.mat[i][k];
                }
            }
        }
        return det;
    }

    // Inversion using Gaussian Elimination (for floating points)
    // Returns true if inverse exists, false otherwise
    bool inverse(Matrix& inv) const {
        assert(n_row == n_col);
        int N = n_row;
        Matrix<T> mat_copy = *this;
        inv = Matrix<T>::identity(N);

        for(int i = 0; i < N; ++i){
            // Find pivot
            int pivot = i;
            for(int j = i; j < N; ++j){
                if(abs(mat_copy.mat[j][i]) > abs(mat_copy.mat[pivot][i])){
                    pivot = j;
                }
            }
            if(mat_copy.mat[pivot][i] == 0){
                return false; // Singular matrix
            }
            if(pivot != i){
                swap(mat_copy.mat[i], mat_copy.mat[pivot]);
                swap(inv.mat[i], inv.mat[pivot]);
            }
            // Normalize pivot row
            T factor = mat_copy.mat[i][i];
            for(int k = 0; k < N; ++k){
                mat_copy.mat[i][k] /= factor;
                inv.mat[i][k] /= factor;
            }
            // Eliminate other rows
            for(int j = 0; j < N; ++j){
                if(j == i) continue;
                T factor = mat_copy.mat[j][i];
                for(int k = 0; k < N; ++k){
                    mat_copy.mat[j][k] -= factor * mat_copy.mat[i][k];
                    inv.mat[j][k] -= factor * inv.mat[i][k];
                }
            }
        }
        return true;
    }
};
