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

void sequential_scan(const std::vector<int>& input, std::vector<int>& output) {
    if (input.empty()) {
        return;
    }

    output[0] = input[0];

    for (int i = 1; i < static_cast<int>(input.size()); i++) {
        output[i] = output[i - 1] + input[i];
    }
}

void parallel_scan(const std::vector<int>& input, std::vector<int>& output) {
    // TODO: Implement the parallel scan version.
    // Think carefully about the dependency between neighboring outputs.
    for (int i = 0; i < static_cast<int>(input.size()); i++) {
        output[i] = 0;
    }
}

bool results_match(const std::vector<int>& a, const std::vector<int>& b) {
    for (int i = 0; i < static_cast<int>(a.size()); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    const int n = 1'000'000;

    std::vector<int> input(n);
    std::vector<int> sequential_output(n);
    std::vector<int> parallel_output(n);

    for (int i = 0; i < n; i++) {
        input[i] = 1;
    }

    double start = now_seconds();
    sequential_scan(input, sequential_output);
    double sequential_time = now_seconds() - start;

    start = now_seconds();
    parallel_scan(input, parallel_output);
    double parallel_time = now_seconds() - start;

    std::cout << "Sequential time: " << sequential_time << " seconds\n";
    std::cout << "Parallel time:   " << parallel_time << " seconds\n";
    std::cout << "Last value:      " << parallel_output.back() << "\n";
    std::cout << "Results match:   "
              << (results_match(sequential_output, parallel_output) ? "yes" : "no")
              << "\n";

    return 0;
}
