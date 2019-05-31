#include "ClosedOpenInterval.h"
#include "IntervalBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class ClosedOpenIntervalTest : public Test {
protected:
    Interval* one;
    Interval* another;

    ClosedOpenIntervalTest() : 
        one(nullptr),
        another(nullptr)
    { }

    ~ClosedOpenIntervalTest() {
        if(this->one)
            delete one;
        if(this->another)
            delete another;
    }
};

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingLeft) {
    one = IntervalBuilder().min(3).max(14).closedOpen().build();
    another = IntervalBuilder().min(1).max(7).closedOpen().build();
    EXPECT_TRUE(one->isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingLeftEqualMin) {
    one = IntervalBuilder().min(3).max(14).closedOpen().build();
    another = IntervalBuilder().min(3).max(7).closedOpen().build();
    EXPECT_TRUE(one->isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingEquals) {
    one = IntervalBuilder().min(3).max(14).closedOpen().build();
    another = IntervalBuilder().min(3).max(14).closedOpen().build();
    EXPECT_TRUE(one->isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingByRight) {
    one = IntervalBuilder().min(3).max(14).closedOpen().build();
    another = IntervalBuilder().min(7).max(17).closedOpen().build();
    EXPECT_TRUE(one->isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingByBoth) {
    one = IntervalBuilder().min(3).max(14).closedOpen().build();
    another = IntervalBuilder().min(0).max(17).closedOpen().build();
    EXPECT_TRUE(one->isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedOverlappingByInside) {
    one = IntervalBuilder().min(3).max(14).closedOpen().build();
    another = IntervalBuilder().min(5).max(10).closedOpen().build();
    EXPECT_TRUE(one->isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedNotOverlappingByLeft) {
    one = IntervalBuilder().min(3).max(14).closedOpen().build();
    another = IntervalBuilder().min(0).max(2).closedOpen().build();
    EXPECT_FALSE(one->isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedNotOverlappingByRight) {
    one = IntervalBuilder().min(3).max(14).closedOpen().build();
    another = IntervalBuilder().min(16).max(22).closedOpen().build();
    EXPECT_FALSE(one->isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedNotOverlappingByLeftSamePoint) {
    one = IntervalBuilder().min(3).max(14).closedOpen().build();
    another = IntervalBuilder().min(0).max(3).closedOpen().build();
    EXPECT_FALSE(one->isIntersected(another));
}

TEST_F(ClosedOpenIntervalTest, isIntersectedNotOverlappingByRightSamePoint) {
    one = IntervalBuilder().min(3).max(14).closedOpen().build();
    another = IntervalBuilder().min(14).max(19).closedOpen().build();
    EXPECT_FALSE(one->isIntersected(another));
}