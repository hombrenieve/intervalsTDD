#include "OpenIntervalBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;


TEST(OpenIntervalTest, isIntersectedOverlappingLeft) {
    OpenInterval one = OpenIntervalBuilder().min(3).max(14).build();
    OpenInterval another = OpenIntervalBuilder().min(1).max(7).build();
    EXPECT_TRUE(one.isIntersected(another));
}

TEST(OpenIntervalTest, isIntersectedOverlappingLeftEqualMin) {
    OpenInterval one = OpenIntervalBuilder().min(3).max(14).build();
    OpenInterval another = OpenIntervalBuilder().min(3).max(7).build();
    EXPECT_TRUE(one.isIntersected(another));
}

TEST(OpenIntervalTest, isIntersectedOverlappingEquals) {
    OpenInterval one = OpenIntervalBuilder().min(3).max(14).build();
    OpenInterval another = OpenIntervalBuilder().min(3).max(14).build();
    EXPECT_TRUE(one.isIntersected(another));
}

TEST(OpenIntervalTest, isIntersectedOverlappingByRight) {
    OpenInterval one = OpenIntervalBuilder().min(3).max(14).build();
    OpenInterval another = OpenIntervalBuilder().min(7).max(17).build();
    EXPECT_TRUE(one.isIntersected(another));
}

TEST(OpenIntervalTest, isIntersectedOverlappingByBoth) {
    OpenInterval one = OpenIntervalBuilder().min(3).max(14).build();
    OpenInterval another = OpenIntervalBuilder().min(0).max(17).build();
    EXPECT_TRUE(one.isIntersected(another));
}

TEST(OpenIntervalTest, isIntersectedOverlappingByInside) {
    OpenInterval one = OpenIntervalBuilder().min(3).max(14).build();
    OpenInterval another = OpenIntervalBuilder().min(5).max(10).build();
    EXPECT_TRUE(one.isIntersected(another));
}
