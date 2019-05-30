#include "ClosedInterval.h"
#include "ClosedIntervalBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;


TEST(ClosedIntervalTest, isIntersectedOverlappingLeft) {
    ClosedInterval one = ClosedIntervalBuilder().min(3).max(14).build();
    ClosedInterval another = ClosedIntervalBuilder().min(1).max(7).build();
    EXPECT_TRUE(one.isIntersected(another));
}

TEST(ClosedIntervalTest, isIntersectedOverlappingLeftEqualMin) {
    ClosedInterval one = ClosedIntervalBuilder().min(3).max(14).build();
    ClosedInterval another = ClosedIntervalBuilder().min(3).max(7).build();
    EXPECT_TRUE(one.isIntersected(another));
}

TEST(ClosedIntervalTest, isIntersectedOverlappingEquals) {
    ClosedInterval one = ClosedIntervalBuilder().min(3).max(14).build();
    ClosedInterval another = ClosedIntervalBuilder().min(3).max(14).build();
    EXPECT_TRUE(one.isIntersected(another));
}

TEST(ClosedIntervalTest, isIntersectedOverlappingByRight) {
    ClosedInterval one = ClosedIntervalBuilder().min(3).max(14).build();
    ClosedInterval another = ClosedIntervalBuilder().min(7).max(17).build();
    EXPECT_TRUE(one.isIntersected(another));
}

TEST(ClosedIntervalTest, isIntersectedOverlappingByBoth) {
    ClosedInterval one = ClosedIntervalBuilder().min(3).max(14).build();
    ClosedInterval another = ClosedIntervalBuilder().min(0).max(17).build();
    EXPECT_TRUE(one.isIntersected(another));
}

TEST(ClosedIntervalTest, isIntersectedOverlappingByInside) {
    ClosedInterval one = ClosedIntervalBuilder().min(3).max(14).build();
    ClosedInterval another = ClosedIntervalBuilder().min(5).max(10).build();
    EXPECT_TRUE(one.isIntersected(another));
}

TEST(ClosedIntervalTest, isIntersectedNotOverlappingByLeft) {
    ClosedInterval one = ClosedIntervalBuilder().min(3).max(14).build();
    ClosedInterval another = ClosedIntervalBuilder().min(0).max(2).build();
    EXPECT_FALSE(one.isIntersected(another));
}

TEST(ClosedIntervalTest, isIntersectedNotOverlappingByRight) {
    ClosedInterval one = ClosedIntervalBuilder().min(3).max(14).build();
    ClosedInterval another = ClosedIntervalBuilder().min(16).max(22).build();
    EXPECT_FALSE(one.isIntersected(another));
}
