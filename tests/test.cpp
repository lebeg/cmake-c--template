#include <string>
#include <stdint.h>

#include "gtest/gtest.h"

#include "lib.h"

struct TestRow {
    std::string test_case;
    std::int32_t test_result;
};

std::ostream &operator<<(std::ostream &out, const TestRow &c) {
    out << c.test_case << " = " << c.test_result;
    return out;
}

class ArithmeticTest : public ::testing::TestWithParam<TestRow> {

};


TEST_P(ArithmeticTest, ProducesCorrectResults
) {
    auto row = GetParam();
    MyClass myClass;
    auto i = myClass.getI();
    EXPECT_EQ(i, 0);
}

INSTANTIATE_TEST_CASE_P

(CorrectCases, ArithmeticTest,
 ::testing::Values(TestRow{"4", 4}, TestRow{"1+2+3+4+5", 15},
                   TestRow{"3+2", 5},
                   TestRow{"(5-8)*3", -9},
                   TestRow{"  ( 2 + 8) ", 10},
                   TestRow{" ( ( 2 + 4) * 8) ", 10})
);
