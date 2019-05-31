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

TEST_F(FromEndPointTest, isLeftEqualsAnotherIncluded) {
    one = EndPointBuilder().point(3).notIncluded().from().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftEqualsNoneIncluded) {
    one = EndPointBuilder().point(3).notIncluded().from().build();
    another = EndPointBuilder().point(3).notIncluded().from().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isRightTrueBothIncluded) {
    one = EndPointBuilder().point(6).included().from().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(FromEndPointTest, isRightFalseBothIncluded) {
    one = EndPointBuilder().point(3).included().from().build();
    another = EndPointBuilder().point(6).included().from().build();

    EXPECT_FALSE(one->isRightOf(another));
}

TEST_F(FromEndPointTest, isRightTrueOneIncluded) {
    one = EndPointBuilder().point(6).included().from().build();
    another = EndPointBuilder().point(3).notIncluded().from().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(FromEndPointTest, isRightTrueAnotherIncluded) {
    one = EndPointBuilder().point(6).notIncluded().from().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(FromEndPointTest, isRightTrueNoneIncluded) {
    one = EndPointBuilder().point(6).notIncluded().from().build();
    another = EndPointBuilder().point(3).notIncluded().from().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(FromEndPointTest, isRightEqualsBothIncluded) {
    one = EndPointBuilder().point(3).included().from().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_FALSE(one->isRightOf(another));
}

TEST_F(FromEndPointTest, isRightEqualsOneIncluded) {
    one = EndPointBuilder().point(3).included().from().build();
    another = EndPointBuilder().point(3).notIncluded().from().build();

    EXPECT_FALSE(one->isRightOf(another));
}

TEST_F(FromEndPointTest, isRightEqualsAnotherIncluded) {
    one = EndPointBuilder().point(3).notIncluded().from().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_TRUE(one->isRightOf(another));
}



TEST_F(FromEndPointTest, isLeftOfUntilEndPointTrueBothIncluded) {
    one = EndPointBuilder().point(3).included().from().build();
    another = EndPointBuilder().point(6).included().until().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftOfUntilFalseBothIncluded) {
    one = EndPointBuilder().point(6).included().from().build();
    another = EndPointBuilder().point(3).included().until().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftOfUntilTrueOneIncluded) {
    one = EndPointBuilder().point(3).included().from().build();
    another = EndPointBuilder().point(6).notIncluded().until().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftOfUntilTrueAnotherIncluded) {
    one = EndPointBuilder().point(3).notIncluded().from().build();
    another = EndPointBuilder().point(6).included().until().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftOfUntilTrueNoneIncluded) {
    one = EndPointBuilder().point(3).notIncluded().from().build();
    another = EndPointBuilder().point(6).notIncluded().until().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftOfUntilEqualsBothIncluded) {
    one = EndPointBuilder().point(3).included().from().build();
    another = EndPointBuilder().point(3).included().until().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(FromEndPointTest, isLeftOfUntilEqualsOneIncluded) {
    one = EndPointBuilder().point(3).included().from().build();
    another = EndPointBuilder().point(3).notIncluded().until().build();

    EXPECT_FALSE(one->isLeftOf(another));
}
