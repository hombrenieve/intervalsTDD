#include "IntervalBuilder.h"
#include "EndPointBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class OpenIntervalTest : public Test {
protected:
    IntervalBuilder intervalBuilder;
    EndPointBuilder endPointBuilder;
};


TEST_F(OpenIntervalTest, isIntersectedOverlappingLeft) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(1).notIncluded().buildFrom())
        .until(endPointBuilder.point(7).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenIntervalTest, isIntersectedOverlappingLeftEqualMin) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(7).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenIntervalTest, isIntersectedOverlappingEquals) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenIntervalTest, isIntersectedOverlappingByRight) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(7).notIncluded().buildFrom())
        .until(endPointBuilder.point(17).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenIntervalTest, isIntersectedOverlappingByBoth) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).notIncluded().buildFrom())
        .until(endPointBuilder.point(17).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenIntervalTest, isIntersectedOverlappingByInside) {
   Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(5).notIncluded().buildFrom())
        .until(endPointBuilder.point(10).notIncluded().buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_F(OpenIntervalTest, isIntersectedNotOverlappingByLeft) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).notIncluded().buildFrom())
        .until(endPointBuilder.point(2).notIncluded().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_F(OpenIntervalTest, isIntersectedNotOverlappingByRight) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(16).notIncluded().buildFrom())
        .until(endPointBuilder.point(22).notIncluded().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_F(OpenIntervalTest, isIntersectedNotOverlappingByLeftSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).notIncluded().buildFrom())
        .until(endPointBuilder.point(3).notIncluded().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_F(OpenIntervalTest, isIntersectedNotOverlappingByRightSamePoint) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).notIncluded().buildFrom())
        .until(endPointBuilder.point(14).notIncluded().buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(14).notIncluded().buildFrom())
        .until(endPointBuilder.point(19).notIncluded().buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}