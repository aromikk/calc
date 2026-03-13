#include "calc.hpp"

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

namespace {

void PrintUsage(const char* program_name) {
    std::cerr << "Usage: " << program_name << " <a> <operation> <b>\n";
    std::cerr << "Supported operations: + - * /\n";
    std::cerr << "Example: " << program_name << " 10 + 5\n";
    std::cerr << "Example: " << program_name << " 10 / 4\n";
}

bool TryParseDouble(const std::string& text, double& value) {
    try {
        std::size_t pos = 0;
        value = std::stod(text, &pos);
        return pos == text.size();
    } catch (const std::exception&) {
        return false;
    }
}

}  // namespace

int main(int argc, char* argv[]) {
    if (argc != 4) {
        PrintUsage(argv[0]);
        return 1;
    }

    double a = 0.0;
    double b = 0.0;

    if (!TryParseDouble(argv[1], a) || !TryParseDouble(argv[3], b)) {
        PrintUsage(argv[0]);
        return 1;
    }

    const std::string operation = argv[2];
    double result = 0.0;

    try {
        if (operation == "+") {
            result = add(a, b);
        } else if (operation == "-") {
            result = sub(a, b);
        } else if (operation == "*") {
            result = mul(a, b);
        } else if (operation == "/") {
            result = div_safe(a, b);
        } else {
            PrintUsage(argv[0]);
            return 1;
        }
    } catch (const std::runtime_error&) {
        std::cerr << "Error: division by zero\n";
        return 1;
    }

    std::cout << std::setprecision(15) << result << '\n';
    return 0;
}
