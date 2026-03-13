#include "calc.hpp"

#include <stdexcept>

double add(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

double div_safe(double a, double b) {
    if (b == 0.0) {
        throw std::runtime_error("division by zero");
    }
    return a / b;
}
