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

void sequential_map(const std::vector<double>& input, std::vector<double>& output) {
    for (int i = 0; i < static_cast<int>(input.size()); i++) {
        output[i] = input[i] * input[i] + 3.0;
    }
}

void parallel_map(const std::vector<double>& input, std::vector<double>& output) {
    // TODO: Implement the parallel map version.
    for (int i = 0; i < static_cast<int>(input.size()); i++) {
        output[i] = 0.0;
    }
}

bool results_match(const std::vector<double>& a, const std::vector<double>& b) {
    const double tolerance = 1e-6;

    for (int i = 0; i < static_cast<int>(a.size()); i++) {
        if (std::abs(a[i] - b[i]) > tolerance) {
            return false;
        }
    }

    return true;
}

int main() {
    const int n = 10'000'000;

    std::vector<double> input(n);
    std::vector<double> sequential_output(n);
    std::vector<double> parallel_output(n);

    for (int i = 0; i < n; i++) {
        input[i] = static_cast<double>(i % 100);
    }

    double start = now_seconds();
    sequential_map(input, sequential_output);
    double sequential_time = now_seconds() - start;

    start = now_seconds();
    parallel_map(input, parallel_output);
    double parallel_time = now_seconds() - start;

    std::cout << "Sequential time: " << sequential_time << " seconds\n";
    std::cout << "Parallel time:   " << parallel_time << " seconds\n";
    std::cout << "Results match:   "
              << (results_match(sequential_output, parallel_output) ? "yes" : "no")
              << "\n";

    return 0;
}
