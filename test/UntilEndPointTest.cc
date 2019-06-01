#include "EndPointBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class UntilEndPointTest : public Test {
protected:
    EndPoint* one;
    EndPoint* another;

    UntilEndPointTest() : 
        one(nullptr),
        another(nullptr)
    { }

    ~UntilEndPointTest() {
        if(this->one)
            delete one;
        if(this->another)
            delete another;
    }
};

TEST_F(UntilEndPointTest, isLeftTrueBothIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(6).included().until().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftFalseBothIncluded) {
    one = EndPointBuilder().point(6).included().until().build();
    another = EndPointBuilder().point(3).included().until().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftTrueOneIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(6).notIncluded().until().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftTrueAnotherIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(6).included().until().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftTrueNoneIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(6).notIncluded().until().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftEqualsBothIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(3).included().until().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftEqualsOneIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(3).notIncluded().until().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftEqualsAnotherIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(3).included().until().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftEqualsNoneIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(3).notIncluded().until().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isRightTrueBothIncluded) {
    one = EndPointBuilder().point(6).included().until().build();
    another = EndPointBuilder().point(3).included().until().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightFalseBothIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(6).included().until().build();

    EXPECT_FALSE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightTrueOneIncluded) {
    one = EndPointBuilder().point(6).included().until().build();
    another = EndPointBuilder().point(3).notIncluded().until().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightTrueAnotherIncluded) {
    one = EndPointBuilder().point(6).notIncluded().until().build();
    another = EndPointBuilder().point(3).included().until().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightTrueNoneIncluded) {
    one = EndPointBuilder().point(6).notIncluded().until().build();
    another = EndPointBuilder().point(3).notIncluded().until().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightEqualsBothIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(3).included().until().build();

    EXPECT_FALSE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightEqualsOneIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(3).notIncluded().until().build();

    EXPECT_FALSE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightEqualsAnotherIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(3).included().until().build();

    EXPECT_FALSE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightEqualsNoneIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(3).notIncluded().until().build();

    EXPECT_FALSE(one->isRightOf(another));
}


TEST_F(UntilEndPointTest, isLeftOfFromEndPointTrueBothIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(6).included().from().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftOfFromFalseBothIncluded) {
    one = EndPointBuilder().point(6).included().until().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftOfFromTrueOneIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(6).notIncluded().from().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftOfFromTrueAnotherIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(6).included().from().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftOfFromTrueNoneIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(6).notIncluded().from().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftOfFromEqualsBothIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftOfFromEqualsOneIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(3).notIncluded().from().build();

    EXPECT_FALSE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftOfFromEqualsAnotherIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_TRUE(one->isLeftOf(another));
}

TEST_F(UntilEndPointTest, isLeftOfFromEqualsNoneIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(3).notIncluded().from().build();

    EXPECT_TRUE(one->isLeftOf(another));
}


TEST_F(UntilEndPointTest, isRightOfFromTrueBothIncluded) {
    one = EndPointBuilder().point(6).included().until().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightOfFromFalseBothIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(6).included().from().build();

    EXPECT_FALSE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightOfFromTrueOneIncluded) {
    one = EndPointBuilder().point(6).included().until().build();
    another = EndPointBuilder().point(3).notIncluded().from().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightOfFromTrueAnotherIncluded) {
    one = EndPointBuilder().point(6).notIncluded().until().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightOfFromTrueNoneIncluded) {
    one = EndPointBuilder().point(6).notIncluded().until().build();
    another = EndPointBuilder().point(3).notIncluded().from().build();

    EXPECT_TRUE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightOfFromEqualsBothIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_FALSE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightOfFromEqualsOneIncluded) {
    one = EndPointBuilder().point(3).included().until().build();
    another = EndPointBuilder().point(3).notIncluded().from().build();

    EXPECT_FALSE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightOfFromEqualsAnotherIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(3).included().from().build();

    EXPECT_FALSE(one->isRightOf(another));
}

TEST_F(UntilEndPointTest, isRightOfFromEqualsNoneIncluded) {
    one = EndPointBuilder().point(3).notIncluded().until().build();
    another = EndPointBuilder().point(3).notIncluded().from().build();

    EXPECT_FALSE(one->isRightOf(another));
}