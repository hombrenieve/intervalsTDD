#include "ClosedInterval.h"
#include "IntervalBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class ClosedIntervalTest : public Test {
protected:
    Interval* one;
    Interval* another;

    ClosedIntervalTest() : 
        one(nullptr),
        another(nullptr)
    { }

    ~ClosedIntervalTest() {
        if(this->one)
            delete one;
        if(this->another)
            delete another;
    }
};

TEST_F(ClosedIntervalTest, isIntersectedOverlappingLeft) {
    one = IntervalBuilder().min(3).max(14).closed().build();
    another = IntervalBuilder().min(1).max(7).closed().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(ClosedIntervalTest, isIntersectedOverlappingLeftEqualMin) {
    one = IntervalBuilder().min(3).max(14).closed().build();
    another = IntervalBuilder().min(3).max(7).closed().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(ClosedIntervalTest, isIntersectedOverlappingEquals) {
    one = IntervalBuilder().min(3).max(14).closed().build();
    another = IntervalBuilder().min(3).max(14).closed().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(ClosedIntervalTest, isIntersectedOverlappingByRight) {
    one = IntervalBuilder().min(3).max(14).closed().build();
    another = IntervalBuilder().min(7).max(17).closed().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(ClosedIntervalTest, isIntersectedOverlappingByBoth) {
    one = IntervalBuilder().min(3).max(14).closed().build();
    another = IntervalBuilder().min(0).max(17).closed().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(ClosedIntervalTest, isIntersectedOverlappingByInside) {
    one = IntervalBuilder().min(3).max(14).closed().build();
    another = IntervalBuilder().min(5).max(10).closed().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(ClosedIntervalTest, isIntersectedNotOverlappingByLeft) {
    one = IntervalBuilder().min(3).max(14).closed().build();
    another = IntervalBuilder().min(0).max(2).closed().build();
    EXPECT_FALSE(one->isIntersected(*another));
}

TEST_F(ClosedIntervalTest, isIntersectedNotOverlappingByRight) {
    one = IntervalBuilder().min(3).max(14).closed().build();
    another = IntervalBuilder().min(16).max(22).closed().build();
    EXPECT_FALSE(one->isIntersected(*another));
}

TEST_F(ClosedIntervalTest, isIntersectedNotOverlappingByLeftSamePoint) {
    one = IntervalBuilder().min(3).max(14).closed().build();
    another = IntervalBuilder().min(0).max(3).closed().build();
    EXPECT_TRUE(one->isIntersected(*another));
}

TEST_F(ClosedIntervalTest, isIntersectedNotOverlappingByRightSamePoint) {
    one = IntervalBuilder().min(3).max(14).closed().build();
    another = IntervalBuilder().min(14).max(19).closed().build();
    EXPECT_TRUE(one->isIntersected(*another));
}