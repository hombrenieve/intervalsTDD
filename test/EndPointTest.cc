#include "EndPointBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(EndPointTest, isLeftTrueBothIncluded) {
    EndPoint one = EndPointBuilder().point(3).included().build();
    EndPoint another = EndPointBuilder().point(6).included().build();

    EXPECT_TRUE(one.isLeftOf(another));
}