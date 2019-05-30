#include "OpenIntervalBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;


TEST(OpenIntervalTest, isIntersectedOverlappingLeft) {
    OpenInterval one = OpenIntervalBuilder().min(3).max(14).build();
    OpenInterval another = OpenIntervalBuilder().min(1).max(7).build();
    EXPECT_TRUE(one.isIntersected(another));
}