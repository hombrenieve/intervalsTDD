#include "IntervalBuilder.h"
#include "EndPointBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class NonConflictingEndPointsIntervalTest: public ::testing::TestWithParam<std::tuple<bool, bool, bool, bool>> {
protected:
    IntervalBuilder intervalBuilder;
    EndPointBuilder endPointBuilder;
};

TEST_P(NonConflictingEndPointsIntervalTest, isIntersectedOverlappingLeft) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included(std::get<0>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(14).included(std::get<1>(this->GetParam())).buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(1).included(std::get<2>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(7).included(std::get<3>(this->GetParam())).buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_P(NonConflictingEndPointsIntervalTest, isIntersectedOverlappingByRight) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included(std::get<0>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(14).included(std::get<1>(this->GetParam())).buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(7).included(std::get<2>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(7).included(std::get<3>(this->GetParam())).buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_P(NonConflictingEndPointsIntervalTest, isIntersectedOverlappingByBoth) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included(std::get<0>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(14).included(std::get<1>(this->GetParam())).buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).included(std::get<2>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(7).included(std::get<3>(this->GetParam())).buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_P(NonConflictingEndPointsIntervalTest, isIntersectedOverlappingByInside) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included(std::get<0>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(14).included(std::get<1>(this->GetParam())).buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(5).included(std::get<2>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(10).included(std::get<3>(this->GetParam())).buildUntil()).build());
    EXPECT_TRUE(one.isIntersected(another));
}

TEST_P(NonConflictingEndPointsIntervalTest, isIntersectedNotOverlappingByLeft) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included(std::get<0>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(14).included(std::get<1>(this->GetParam())).buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(0).included(std::get<2>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(2).included(std::get<3>(this->GetParam())).buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

TEST_P(NonConflictingEndPointsIntervalTest, isIntersectedNotOverlappingByRight) {
    Interval one(intervalBuilder.from(endPointBuilder.point(3).included(std::get<0>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(14).included(std::get<1>(this->GetParam())).buildUntil()).build());
    Interval another(intervalBuilder.from(endPointBuilder.point(16).included(std::get<2>(this->GetParam())).buildFrom())
        .until(endPointBuilder.point(22).included(std::get<3>(this->GetParam())).buildUntil()).build());
    EXPECT_FALSE(one.isIntersected(another));
}

INSTANTIATE_TEST_SUITE_P(IntervalTest,
                        NonConflictingEndPointsIntervalTest,
                        Combine(Bool(), Bool(), Bool(), Bool()));
