#include "EndPointBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class EndPointTest : public Test {
protected:
    EndPointBuilder endPointBuilder;
};

TEST_F(EndPointTest, isLeftOfUntilEndPointTrueBothIncluded) {
    FromEndPoint from(EndPointBuilder().point(3).included().buildFrom());
    UntilEndPoint until(EndPointBuilder().point(6).included().buildUntil());

    EXPECT_TRUE(from.isLeftOf(until));
}

TEST_F(EndPointTest, isLeftOfUntilFalseBothIncluded) {
    FromEndPoint from(EndPointBuilder().point(6).included().buildFrom());
    UntilEndPoint until(EndPointBuilder().point(3).included().buildUntil());

    EXPECT_FALSE(from.isLeftOf(until));
}

TEST_F(EndPointTest, isLeftOfUntilTrueOneIncluded) {
    FromEndPoint from(EndPointBuilder().point(3).included().buildFrom());
    UntilEndPoint until(EndPointBuilder().point(6).notIncluded().buildUntil());

    EXPECT_TRUE(from.isLeftOf(until));
}

TEST_F(EndPointTest, isLeftOfUntilTrueAnotherIncluded) {
    FromEndPoint from(EndPointBuilder().point(3).notIncluded().buildFrom());
    UntilEndPoint until(EndPointBuilder().point(6).included().buildUntil());

    EXPECT_TRUE(from.isLeftOf(until));
}

TEST_F(EndPointTest, isLeftOfUntilTrueNoneIncluded) {
    FromEndPoint from(EndPointBuilder().point(3).notIncluded().buildFrom());
    UntilEndPoint until(EndPointBuilder().point(6).notIncluded().buildUntil());

    EXPECT_TRUE(from.isLeftOf(until));
}

TEST_F(EndPointTest, isLeftOfUntilFalseNoneIncluded) {
    FromEndPoint from(EndPointBuilder().point(6).notIncluded().buildFrom());
    UntilEndPoint until(EndPointBuilder().point(3).notIncluded().buildUntil());

    EXPECT_FALSE(from.isLeftOf(until));
}

TEST_F(EndPointTest, isLeftOfUntilEqualsBothIncluded) {
    FromEndPoint from(EndPointBuilder().point(3).included().buildFrom());
    UntilEndPoint until(EndPointBuilder().point(3).included().buildUntil());

    EXPECT_TRUE(from.isLeftOf(until));
}

TEST_F(EndPointTest, isLeftOfUntilEqualsOneIncluded) {
    FromEndPoint from(EndPointBuilder().point(3).included().buildFrom());
    UntilEndPoint until(EndPointBuilder().point(3).notIncluded().buildUntil());

    EXPECT_FALSE(from.isLeftOf(until));
}

TEST_F(EndPointTest, isLeftOfUntilEqualsAnotherIncluded) {
    FromEndPoint from(EndPointBuilder().point(3).notIncluded().buildFrom());
    UntilEndPoint until(EndPointBuilder().point(3).included().buildUntil());

    EXPECT_FALSE(from.isLeftOf(until));
}

TEST_F(EndPointTest, isLeftOfUntilEqualsNoneIncluded) {
    FromEndPoint from(EndPointBuilder().point(3).notIncluded().buildFrom());
    UntilEndPoint until(EndPointBuilder().point(3).notIncluded().buildUntil());

    EXPECT_FALSE(from.isLeftOf(until));
}
