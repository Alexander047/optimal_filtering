#include "stochastic.h"


//============================================================================//
//                                                                            //
//                          Моментные характеристики :                        //
//                                                                            //

double Mean (const Array< double > &X)
{
    size_t N  = X.size();
    double MX = 0.0;
    for (size_t i = 0; i < N; ++i) {
        MX += X[i];
    }
    return MX / double(N);
}

Vector Mean (const Array< Vector > &X)
{
    Vector MX = X[0];
    size_t N = X.size();
    for (size_t i = 1; i < N; ++i) {
        MX += X[i];
    }
    return MX / double(N);
}

double Cov (const Array< double > &X, const Array< double > &Y)
{
    size_t N     = X.size() < Y.size() ? X.size() : Y.size();
    double sumXY = 0;
    double sumX  = 0;
    double sumY  = 0;

    for (size_t i = 0; i < N; ++i) {
        sumXY += X[i] * Y[i];
        sumX += X[i];
        sumY += Y[i];
    }

    return (sumXY / double(N)) - (sumX / double(N)) * (sumY / double(N));
}

double Cov (const Array< double > &X, double MX)
{
    size_t N     = X.size();
    double sumXX = 0;

    for (size_t i = 0; i < N; ++i) {
        sumXX += X[i] * X[i];
    }
    return (sumXX / double(N)) - MX * MX;
}

Matrix Cov (const Array< Vector > &x, const Array< Vector > &y)
{
    size_t SS = x.size() < y.size() ? x.size() : y.size();

    size_t N = x[0].size();
    size_t M = y[0].size();
    Matrix Dxy (N, M);

    Vector mx = Mean (x);
    Vector my = Mean (y);

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            double sum_xy = 0;
            for (size_t s = 0; s < SS; ++s) {
                sum_xy += x[s][i] * y[s][j];
            }
            Dxy (i, j) = (sum_xy / double(SS)) - mx[i] * my[j];
        }
    }

    return Dxy;
}

Matrix Cov (const Array< Vector > &X, const Vector &MX)
{
    size_t K = X.size();

    size_t N = X[0].size();
    Matrix DX (N, N);

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j <= i; ++j) {
            double sumXY = 0;
            for (size_t k = 0; k < K; ++k) {
                sumXY += X[k][i] * X[k][j];
            }
            DX (i, j) = DX (j, i) = (sumXY / double(K)) - MX[i] * MX[j];
        }
    }

    return DX;
}

//                                                                            //
//============================================================================//
