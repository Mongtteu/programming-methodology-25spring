#include "calculator.h"
#include <stdexcept>         
#include <limits>            
#include <cstdint>           

int Calculator::add(int a, int b) {
    if ((b > 0) && (a > std::numeric_limits<int>::max() - b)) {
        throw std::overflow_error("Overflow in add");
    }
    if ((b < 0) && (a < std::numeric_limits<int>::min() - b)) {
        throw std::overflow_error("Underflow in add");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    if ((b < 0) && (a > std::numeric_limits<int>::max() + b)) {
        throw std::overflow_error("Overflow in sub");
    }
    if ((b > 0) && (a < std::numeric_limits<int>::min() + b)) {
        throw std::overflow_error("Underflow in sub");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    int64_t result = static_cast<int64_t>(a) * static_cast<int64_t>(b);
    if (result > std::numeric_limits<int>::max() ||
        result < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Overflow in mul");
    }
    return static_cast<int>(result);
}

int Calculator::div(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (a == std::numeric_limits<int>::min() && b == -1) {
        throw std::overflow_error("Overflow in div");
    }
    return a / b;
}
