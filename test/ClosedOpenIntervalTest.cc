#include "IntervalBuilder.h"
#include "EndPointBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class ClosedOpenIntervalTest : public Test {
protected:
    IntervalBuilder intervalBuilder;
    EndPointBuilder endPointBuilder;
};

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingLeft) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(1).included().buildFrom())
        .until(endPointBuilder.point(7).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingLeftEqualMin) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(7).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingEquals) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingByRight) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(7).included().buildFrom())
        .until(endPointBuilder.point(17).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingByBoth) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).included().buildFrom())
        .until(endPointBuilder.point(17).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingByInside) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(5).included().buildFrom())
        .until(endPointBuilder.point(10).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedNotOverlappingByLeft) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).included().buildFrom())
        .until(endPointBuilder.point(2).notIncluded().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedNotOverlappingByRight) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(16).included().buildFrom())
        .until(endPointBuilder.point(22).notIncluded().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedNotOverlappingByLeftSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).included().buildFrom())
        .until(endPointBuilder.point(3).notIncluded().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedNotOverlappingByRightSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(14).included().buildFrom())
        .until(endPointBuilder.point(19).notIncluded().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}