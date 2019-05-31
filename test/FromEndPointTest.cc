#include "EndPointBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class FromEndPointTest : public Test {
protected:
    EndPoint* one;
    EndPoint* another;

    FromEndPointTest() : 
        one(nullptr),
        another(nullptr)
    { }

    ~FromEndPointTest() {
        if(this->one)
            delete one;
        if(this->another)
            delete another;
    }
};

TEST_F(FromEndPointTest, isLeftTrueBothIncluded) {
    one = EndPointBuilder().point(3).included().from().build();
    another = EndPointBuilder().point(6).included().from().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftFalseBothIncluded) {
    one = EndPointBuilder().point(6).included().from().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftTrueOneIncluded) {
    one = EndPointBuilder().point(3).included().from().build();
    another = EndPointBuilder().point(6).notIncluded().from().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftTrueAnotherIncluded) {
    one = EndPointBuilder().point(3).notIncluded().from().build();
    another = EndPointBuilder().point(6).included().from().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftTrueNoneIncluded) {
    one = EndPointBuilder().point(3).notIncluded().from().build();
    another = EndPointBuilder().point(6).notIncluded().from().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftEqualsBothIncluded) {
    one = EndPointBuilder().point(3).included().from().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftEqualsOneIncluded) {
    one = EndPointBuilder().point(3).included().from().build();
    another = EndPointBuilder().point(3).notIncluded().from().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

