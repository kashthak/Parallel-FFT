#include <cmath>
#include <iostream>
#include <vector>

#ifdef _OPENMP
#include <omp.h>
#endif

double now_seconds() {
#ifdef _OPENMP
    return omp_get_wtime();
#else
    return 0.0;
#endif
}

double sequential_reduction(const std::vector<double>& values) {
    double sum = 0.0;

    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        sum += values[i];
    }

    return sum;
}

double parallel_reduction(const std::vector<double>& values) {
    double sum = 0.0;

    // TODO: Implement the parallel reduction version.
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
        sum = values[i];
    }

    return sum;
}

bool results_match(double a, double b) {
    const double tolerance = 1e-6;
    return std::abs(a - b) <= tolerance;
}

int main() {
    const int n = 10'000'000;

    std::vector<double> values(n);

    for (int i = 0; i < n; i++) {
        values[i] = 1.0;
    }

    double start = now_seconds();
    double sequential_result = sequential_reduction(values);
    double sequential_time = now_seconds() - start;

    start = now_seconds();
    double parallel_result = parallel_reduction(values);
    double parallel_time = now_seconds() - start;

    std::cout << "Sequential result: " << sequential_result << "\n";
    std::cout << "Parallel result:   " << parallel_result << "\n";
    std::cout << "Sequential time:   " << sequential_time << " seconds\n";
    std::cout << "Parallel time:     " << parallel_time << " seconds\n";
    std::cout << "Results match:     "
              << (results_match(sequential_result, parallel_result) ? "yes" : "no")
              << "\n";

    return 0;
}
