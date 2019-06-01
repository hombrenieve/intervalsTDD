#include "IntervalBuilder.h"
#include "EndPointBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class ClosedIntervalTest : public Test {
protected:
    IntervalBuilder intervalBuilder;
    EndPointBuilder endPointBuilder;
};

TEST_F(ClosedIntervalTest, isIntersectedOverlappingLeft) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(1).included().buildFrom())
        .until(endPointBuilder.point(7).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedIntervalTest, isIntersectedOverlappingLeftEqualMin) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(7).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedIntervalTest, isIntersectedOverlappingEquals) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedIntervalTest, isIntersectedOverlappingByRight) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(7).included().buildFrom())
        .until(endPointBuilder.point(17).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedIntervalTest, isIntersectedOverlappingByBoth) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).included().buildFrom())
        .until(endPointBuilder.point(17).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedIntervalTest, isIntersectedOverlappingByInside) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(5).included().buildFrom())
        .until(endPointBuilder.point(10).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedIntervalTest, isIntersectedNotOverlappingByLeft) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).included().buildFrom())
        .until(endPointBuilder.point(2).included().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_F(ClosedIntervalTest, isIntersectedNotOverlappingByRight) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(16).included().buildFrom())
        .until(endPointBuilder.point(22).included().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_F(ClosedIntervalTest, isIntersectedNotOverlappingByLeftSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).included().buildFrom())
        .until(endPointBuilder.point(3).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(ClosedIntervalTest, isIntersectedNotOverlappingByRightSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included().buildFrom())
        .until(endPointBuilder.point(14).included().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(14).included().buildFrom())
        .until(endPointBuilder.point(19).included().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}