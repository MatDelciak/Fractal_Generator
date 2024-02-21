#include "transformations.h"
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 7) {
        std::cerr << "Usage: " << argv[0] << " -i input_file -o output_file -n iterations " << std::endl;
        return 1;
    }

    std::string input_file, output_file;
    int iterations = 0;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-i" && i + 1 < argc) {
            input_file = argv[++i];
        } else if (arg == "-o" && i + 1 < argc) {
            output_file = argv[++i];
        } else if (arg == "-n" && i + 1 < argc) {
            iterations = std::stoi(argv[++i]);
        }

    }

    if (iterations <= 0) {
        std::cerr << "Number of iterations should be positive " << std::endl;
        return 1;
    }

    auto transformations = read_transformations(input_file);
    std::vector<double> probabilities;
    for (const auto& t : transformations) {
        probabilities.push_back(1.0 / transformations.size());
    }

    auto fractal_points = generate_fractal(transformations, probabilities, iterations);
    save_fractal(fractal_points, output_file);

    return 0;
}
