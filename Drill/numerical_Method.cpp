#include <iostream>
#include <cmath>
#include <iomanip>

// Constants
const double m = 80.0;    // Mass of the parachutist (kg)
const double g = 9.81;    // Acceleration due to gravity (m/s^2)
const double v_target = 36.0; // Target velocity (m/s)
const double t = 4.0;     // Time (s)
const double tolerance = 0.02; // Tolerance for stopping criterion

// Function to calculate the velocity given a drag coefficient
double f(double c) {
    return (m * g / c) * (1 - std::exp(-c * t / m)) - v_target;
}

// Bisection method to find the root
double bisection_method(double xl, double xu, double tolerance) {
    double xr = xl;
    double xr_old;
    double ea = 100.0; // Initial error
    int iter_count = 0;

    while (ea >= tolerance) {
        xr_old = xr;
        xr = (xl + xu) / 2;
        iter_count++;

        // Calculate function values
        double f_xr = f(xr);
        double f_xl = f(xl);

        // Display current step
        std::cout << "Iteration " << iter_count << ":" << std::endl;
        std::cout << "xl = " << xl << ", xu = " << xu << ", xr = " << xr << std::endl;
        std::cout << "f(xr) = " << f_xr << std::endl;

        // Check which side of the interval to update
        if (f_xr * f_xl < 0) {
            xu = xr;
        } else {
            xl = xr;
        }

        // Calculate approximate relative error
        if (xr != 0) {
            ea = std::abs((xr - xr_old) / xr);
        }

        std::cout << "Relative error = " << ea << std::endl << std::endl;
    }

    std::cout << "Total iterations: " << iter_count << std::endl;
    std::cout << "Final relative error: " << ea << std::endl;
    return xr;
}

int main() {
    // Initial guesses
    double xl = 0.1;
    double xu = 0.2;

    // Run bisection method
    double c_result = bisection_method(xl, xu, tolerance);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "The drag coefficient needed is: " << c_result << " kg/s" << std::endl;

    return 0;
}
