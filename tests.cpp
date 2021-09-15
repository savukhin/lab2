#include "Lab2.h"
#include <gtest/gtest.h>

const float precisionFloat = 0.1;

TEST(Deltoid1, Functions) {
    Deltoid deltoid(1);
    EXPECT_EQ(deltoid.Len(), 16);
    EXPECT_EQ(deltoid.LenWithTangent(), 4);
    EXPECT_NEAR(deltoid.Square(), 6.28319, precisionFloat);
    EXPECT_NEAR(deltoid.Square(), 6.28, precisionFloat);
    EXPECT_NEAR(deltoid.Square(), 6.28319111, precisionFloat);

    std::pair<float, float> par2Ans = deltoid.Parameter(2);
    EXPECT_NEAR(par2Ans.first, -1.48594, precisionFloat);
    EXPECT_NEAR(par2Ans.second, 2.5754, precisionFloat);
    EXPECT_STREQ(deltoid.GetEqualation(), "(x^2 + y^2)^2 + 8.000000x(x^2 - 3y^2) + 18.000000(x^2+y^2) = 27.000000");
    EXPECT_EQ(deltoid.ToString(), "Smaller round radius: 1.000000\nBigger round radius: 3.000000\n");
}

TEST(Deltoid1dot5, Functions) {
    Deltoid deltoid(1.5);
    EXPECT_EQ(deltoid.Len(), 24);
    EXPECT_EQ(deltoid.LenWithTangent(), 6);
    EXPECT_NEAR(deltoid.Square(), 14.1372, precisionFloat);

    std::pair<float, float> par2Ans = deltoid.Parameter(2);
    EXPECT_NEAR(par2Ans.first, -2.22891, precisionFloat);
    EXPECT_NEAR(par2Ans.second, 3.8631, precisionFloat);

    std::pair<float, float> par10Ans = deltoid.Parameter(10);
    EXPECT_NEAR(par10Ans.first, -1.90509, precisionFloat);
    EXPECT_NEAR(par10Ans.second, -3.00148, precisionFloat);

    std::pair<float, float> parMinus4Ans = deltoid.Parameter(-4);
    EXPECT_NEAR(parMinus4Ans.first, -2.17918, precisionFloat);
    EXPECT_NEAR(parMinus4Ans.second, 3.75444, precisionFloat);

    EXPECT_STREQ(deltoid.GetEqualation(), "(x^2 + y^2)^2 + 12.000000x(x^2 - 3y^2) + 40.500000(x^2+y^2) = 136.687500");
    EXPECT_EQ(deltoid.ToString(), "Smaller round radius: 1.500000\nBigger round radius: 4.500000\n");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}