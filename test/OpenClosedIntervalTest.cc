#include "IntervalBuilder.h"
#include "EndPointBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class OpenClosedIntervalTest : public Test {
protected:
    IntervalBuilder intervalBuilder;
    EndPointBuilder endPointBuilder;
};

TEST_F(OpenClosedIntervalTest, isIntersectedOverlappingLeft) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(1).notIncluded().buildFrom())
        .until(endPointBuilder.point(7).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenClosedIntervalTest, isIntersectedOverlappingLeftEqualMin) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(7).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenClosedIntervalTest, isIntersectedOverlappingEquals) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenClosedIntervalTest, isIntersectedOverlappingByRight) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(7).notIncluded().buildFrom())
        .until(endPointBuilder.point(17).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenClosedIntervalTest, isIntersectedOverlappingByBoth) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).notIncluded().buildFrom())
        .until(endPointBuilder.point(17).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenClosedIntervalTest, isIntersectedOverlappingByInside) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(5).notIncluded().buildFrom())
        .until(endPointBuilder.point(10).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenClosedIntervalTest, isIntersectedNotOverlappingByLeft) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).notIncluded().buildFrom())
        .until(endPointBuilder.point(2).included().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_F(OpenClosedIntervalTest, isIntersectedNotOverlappingByRight) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(16).notIncluded().buildFrom())
        .until(endPointBuilder.point(22).included().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_F(OpenClosedIntervalTest, isIntersectedNotOverlappingByLeftSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).notIncluded().buildFrom())
        .until(endPointBuilder.point(3).included().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_F(OpenClosedIntervalTest, isIntersectedNotOverlappingByRightSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(14).notIncluded().buildFrom())
        .until(endPointBuilder.point(19).included().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}