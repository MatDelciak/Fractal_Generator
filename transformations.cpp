#include "transformations.h"
#include <fstream>
#include <sstream>
#include <random>
#include <ctime>
#include <iostream>

std::vector<Transformation> read_transformations(const std::string& file_name) {
    std::ifstream file(file_name);
    std::vector<Transformation> transformations;

    if (file.is_open()) {
        double p;
        Transformation t;
        while (file >> p >> t.a >> t.b >> t.c >> t.d >> t.e >> t.f) {
            transformations.push_back(t);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file " << file_name << std::endl;
    }

    return transformations;
}

std::pair<double, double> apply_transformation(double x, double y, const Transformation& t) {
    double x_new = t.a * x + t.b * y + t.c;
    double y_new = t.d * x + t.e * y + t.f;
    return std::make_pair(x_new, y_new);
}

std::vector<std::pair<double, double>> generate_fractal(const std::vector<Transformation>& transformations, const std::vector<double>& probabilities, int iterations) {
    std::vector<std::pair<double, double>> points = {{0, 0}};
    std::default_random_engine generator(time(nullptr));
    std::discrete_distribution<int> distribution(probabilities.begin(), probabilities.end());

    for (int i = 0; i < iterations; ++i) {
        int index = distribution(generator);
        auto selected_transformation = transformations[index];
        auto [x, y] = points[rand() % points.size()];
        auto [x_new, y_new] = apply_transformation(x, y, selected_transformation);
        points.push_back(std::make_pair(x_new, y_new));
    }

    return points;
}

void save_fractal(const std::vector<std::pair<double, double>>& points, const std::string& output_file) {
    std::ofstream file(output_file);
    if (file.is_open()) {
        for (const auto& point : points) {
            file << point.first << " " << point.second << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file " << output_file << " for writing" << std::endl;
    }
}
