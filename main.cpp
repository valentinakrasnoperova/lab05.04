//lab_5.
#include <iostream>
#include <cmath>
#include "func.h"

using namespace std;


double S1(const int K, const int N, const int i, double t) {
    t = t + (1.0 * K / i + i * 1.0 / N);
    if (i >= N)
        return t;
    else
        return S1(K, N, i + 1, t);
}

double S2(const int K, const int N, const int i) {
    if (i > N)
        return 0;
    else
        return (1.0*K / i + i * 1.0 / N) + S2(K, N, i + 1);
}

double S3(const int K, const int N, const int i) {
    if (i < K)
        return 0;
    else
        return (1.0 * K / i + i * 1.0 / N) + S3(K, N, i - 1);
}

double S4(const int K, const int N) {
    double s = 0;
    for (int i = K; i <= N; i++)
        s += K * 1.0 / i + i * 1.0 / N;
    return s;
}

int main() {
    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;

    cout << "(rec down --) S0 = " << S0(K, N, N, 0) << endl;
    cout << "(rec down ++) S1 = " << S1(K, N, K, 0) << endl;
    cout << "(rec up ++) S2 = " << S2(K, N, K) << endl;
    cout << "(rec up --) S3 = " << S3(K, N, N) << endl;
    cout << "(iter) S4 = " << S4(K, N) << endl;

    return 0;
}