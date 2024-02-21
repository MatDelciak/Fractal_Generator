#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include <string>
#include <vector>

struct Transformation {
    double a, b, c, d, e, f;
};

std::vector<Transformation> read_transformations(const std::string& file_name);
std::pair<double, double> apply_transformation(double x, double y, const Transformation& t);
std::vector<std::pair<double, double>> generate_fractal(const std::vector<Transformation>& transformations, const std::vector<double>& probabilities, int iterations);
void save_fractal(const std::vector<std::pair<double, double>>& points, const std::string& output_file);

#endif
