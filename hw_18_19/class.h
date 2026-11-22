#ifndef CLIONPROJECTS_CLASS_H
#define CLIONPROJECTS_CLASS_H

#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class Function {
public:
    enum class TermKind {
        Power,
        Cos,
        Sqrt,
        Log
    };

    struct Term {
        TermKind kind;
        double coeff = 1.0;
        double param1 = 1.0;
        double param2 = 0.0;
    };

private:
    double left_ = 0.0;
    double right_ = 1.0;
    std::vector<Term> terms_;

    double eval_term(const Term& t, double x) const {
        switch (t.kind) {
            case TermKind::Power: {
                double int_part = 0.0;
                if (x < 0.0 && std::modf(t.param1, &int_part) != 0.0) {
                    throw std::domain_error("Negative base with non-integer power");
                }
                return t.coeff * std::pow(x, t.param1);
            }
            case TermKind::Cos:
                return t.coeff * std::cos(t.param1 * x + t.param2);
            case TermKind::Sqrt: {
                double arg = t.param1 * x + t.param2;
                if (arg < 0.0) {
                    throw std::domain_error("Square root argument must be non-negative");
                }
                return t.coeff * std::sqrt(arg);
            }
            case TermKind::Log: {
                double arg = t.param1 * x + t.param2;
                if (arg <= 0.0) {
                    throw std::domain_error("Logarithm argument must be positive");
                }
                return t.coeff * std::log(arg);
            }
        }
        return 0.0;
    }
    static void validate_bounds(double a, double b) {
        if (!std::isfinite(a) || !std::isfinite(b) || a >= b) {
            throw std::invalid_argument("Invalid interval: require finite a < b");
        }
    }
    static void validate_steps(std::size_t n) {
        if (n == 0) {
            throw std::invalid_argument("Number of subintervals must be greater than 0");
        }
    }
public:
    Function(double left = 0.0, double right = 1.0) {
        set_interval(left, right);
    }
    void set_interval(double left, double right) {
        validate_bounds(left, right);
        left_ = left;
        right_ = right;
    }
    double left() const noexcept { return left_; }
    double right() const noexcept { return right_; }

    void clear_terms() noexcept {
        terms_.clear();
    }
    Function& add_power(double coeff, double exponent) {
        terms_.push_back(Term{TermKind::Power, coeff, exponent, 0.0});
        return *this;
    }
    Function& add_cos(double coeff = 1.0, double freq = 1.0, double phase = 0.0) {
        terms_.push_back(Term{TermKind::Cos, coeff, freq, phase});
        return *this;
    }
    Function& add_sqrt(double coeff = 1.0, double scale = 1.0, double shift = 0.0) {
        terms_.push_back(Term{TermKind::Sqrt, coeff, scale, shift});
        return *this;
    }
    Function& add_log(double coeff = 1.0, double scale = 1.0, double shift = 0.0) {
        terms_.push_back(Term{TermKind::Log, coeff, scale, shift});
        return *this;
    }
    double operator()(double x) const {
        double sum = 0.0;
        for (const auto& term : terms_) {
            sum += eval_term(term, x);
        }
        return sum;
    }
    double find_root(double tol = 1e-9, std::size_t max_iter = 1000) const {
        double a = left_;
        double b = right_;
        double fa = (*this)(a);
        double fb = (*this)(b);

        if (std::abs(fa) <= tol) return a;
        if (std::abs(fb) <= tol) return b;
        if (fa * fb > 0.0) {
            throw std::runtime_error("Function values at interval endpoints do not bracket a root (f(a)*f(b) > 0)");
        }
        for (std::size_t iter = 0; iter < max_iter; ++iter) {
            double mid = a + (b - a) / 2.0;
            double fmid = (*this)(mid);
            if (std::abs(fmid) <= tol || (b - a) / 2.0 < tol) {
                return mid;
            }
            if (fa * fmid <= 0.0) {
                b = mid;
                fb = fmid;
            } else {
                a = mid;
                fa = fmid;
            }
        }

        return a + (b - a) / 2.0;
    }
    double left_rectangles(std::size_t n) const {
        validate_steps(n);
        double h = (right_ - left_) / static_cast<double>(n);
        double sum = 0.0;
        for (std::size_t i = 0; i < n; ++i) {
            double x_i = left_ + static_cast<double>(i) * h;
            sum += (*this)(x_i);
        }
        return h * sum;
    }
    double right_rectangles(std::size_t n) const {
        validate_steps(n);
        double h = (right_ - left_) / static_cast<double>(n);
        double sum = 0.0;
        for (std::size_t i = 1; i <= n; ++i) {
            double x_i = left_ + static_cast<double>(i) * h;
            sum += (*this)(x_i);
        }
        return h * sum;
    }
    double midpoint_rectangles(std::size_t n) const {
        validate_steps(n);
        double h = (right_ - left_) / static_cast<double>(n);
        double sum = 0.0;
        for (std::size_t i = 0; i < n; ++i) {
            double x_mid = left_ + (static_cast<double>(i) + 0.5) * h;
            sum += (*this)(x_mid);
        }
        return h * sum;
    }
    double trapezoidal(std::size_t n) const {
        validate_steps(n);
        double h = (right_ - left_) / static_cast<double>(n);
        double sum = 0.5 * ((*this)(left_) + (*this)(right_));
        for (std::size_t i = 1; i < n; ++i) {
            double x_i = left_ + static_cast<double>(i) * h;
            sum += (*this)(x_i);
        }
        return h * sum;
    }
    double simpson(std::size_t n) const {
        validate_steps(n);
        if (n % 2 != 0) {
            ++n;
        }
        double h = (right_ - left_) / static_cast<double>(n);
        double sum = (*this)(left_) + (*this)(right_);

        for (std::size_t i = 1; i < n; ++i) {
            double x_i = left_ + static_cast<double>(i) * h;
            sum += (i % 2 == 0 ? 2.0 : 4.0) * (*this)(x_i);
        }
        return (h / 3.0) * sum;
    }
    std::vector<std::pair<double, double>> sample(
        double start,
        double end,
        std::size_t num_samples,
        std::ostream& os = std::cout
    ) const {
        validate_bounds(start, end);
        if (num_samples < 2) {
            throw std::invalid_argument("num_samples must be at least 2");
        }
        std::vector<std::pair<double, double>> table;
        table.reserve(num_samples);

        double step = (end - start) / static_cast<double>(num_samples - 1);
        for (std::size_t i = 0; i < num_samples; ++i) {
            double x = (i == num_samples - 1) ? end : (start + static_cast<double>(i) * step);
            double y = (*this)(x);
            table.emplace_back(x, y);
        }
        os << "\n+--------------+----------------+\n";
        os << "|      x       |      f(x)      |\n";
        os << "+--------------+----------------+\n";
        os << std::fixed << std::setprecision(6);
        for (const auto& [x, y] : table) {
            os << "| " << std::setw(12) << x << " | " << std::setw(14) << y << " |\n";
        }
        os << "+--------------+----------------+\n";

        return table;
    }
};

#endif //CLIONPROJECTS_CLASS_H
