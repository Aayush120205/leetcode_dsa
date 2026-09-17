// Minimal dependency-free unit test framework.
//
//   TEST(suite_name, does_something) {
//       CHECK_EQ(answer, 42);
//   }
//
// Tests self-register at static initialisation time and are executed by
// runAllTests() from main.cpp.
#pragma once

#include <cmath>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace testing {

struct TestCase {
    std::string suite;
    std::string name;
    void (*fn)();
};

inline std::vector<TestCase>& registry() {
    static std::vector<TestCase> tests;
    return tests;
}

inline int& failureCount() {
    static int failures = 0;
    return failures;
}

struct Registrar {
    Registrar(const char* suite, const char* name, void (*fn)()) {
        registry().push_back(TestCase{suite, name, fn});
    }
};

template <typename T>
std::string describe(const T& value) {
    std::ostringstream out;
    out << value;
    return out.str();
}

template <typename T>
std::string describe(const std::vector<T>& values) {
    std::ostringstream out;
    out << '[';
    for (std::size_t i = 0; i < values.size(); i++) {
        if (i > 0) out << ", ";
        out << describe(values[i]);
    }
    out << ']';
    return out.str();
}

inline void reportFailure(const char* file, int line, const std::string& message) {
    failureCount()++;
    std::cout << "    FAIL " << file << ":" << line << ": " << message << "\n";
}

template <typename A, typename B>
void checkEqual(const A& actual, const B& expected, const char* actualExpr,
                const char* file, int line) {
    if (!(actual == expected)) {
        reportFailure(file, line,
                      std::string(actualExpr) + " == " + describe(expected) +
                          " (actual: " + describe(actual) + ")");
    }
}

inline void checkNear(double actual, double expected, double tolerance,
                      const char* actualExpr, const char* file, int line) {
    if (std::fabs(actual - expected) > tolerance) {
        reportFailure(file, line,
                      std::string(actualExpr) + " ~= " + describe(expected) +
                          " (actual: " + describe(actual) + ")");
    }
}

inline void checkTrue(bool value, const char* expr, const char* file, int line) {
    if (!value) {
        reportFailure(file, line, std::string(expr) + " is false");
    }
}

inline int runAllTests() {
    int failedTests = 0;
    for (const TestCase& test : registry()) {
        int before = failureCount();
        std::cout << "[ RUN ] " << test.suite << "." << test.name << "\n";
        test.fn();
        if (failureCount() != before) failedTests++;
    }
    std::cout << "\n"
              << registry().size() << " tests run, " << failedTests << " failed, "
              << failureCount() << " failed assertions\n";
    return failedTests == 0 ? 0 : 1;
}

}  // namespace testing

#define TEST(suite, name)                                                   \
    static void suite##_##name();                                           \
    static ::testing::Registrar suite##_##name##_registrar(#suite, #name,   \
                                                           suite##_##name); \
    static void suite##_##name()

#define CHECK_EQ(actual, expected) \
    ::testing::checkEqual((actual), (expected), #actual, __FILE__, __LINE__)
#define CHECK_NEAR(actual, expected, tolerance)                          \
    ::testing::checkNear((actual), (expected), (tolerance), #actual, \
                         __FILE__, __LINE__)
#define CHECK_TRUE(expr) ::testing::checkTrue((expr), #expr, __FILE__, __LINE__)
