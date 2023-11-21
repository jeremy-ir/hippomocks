#include "hippomocks.h"
#include "gtest/gtest.h"
#include <string>
#include <list>

class INext {
public:
        virtual void f(std::string&& arg) = 0;
        virtual void g(int i, std::list<int>&& j) = 0;
};

TEST (TestMove, checkMoveAccepted)
{
    std::string test1("abcd");

    MockRepository mocks;
    INext *nextMock = mocks.Mock<INext>();
    mocks.ExpectCall(nextMock, INext::f).With(test1);
    nextMock->f("abcd");
}

TEST (TestMove, checkMoveChecked)
{
    std::string test1("abcd");

    MockRepository mocks;
    INext *nextMock = mocks.Mock<INext>();
    mocks.ExpectCall(nextMock, INext::f).With(test1);
    EXPECT_THROW(nextMock->f("bc"), HippoMocks::ExpectationException);
    mocks.reset();
}

std::list<int> makeList()
{
  return { 1, 2, 3 };
}

TEST (TestMove, checkMoveTwoAccepted)
{
    MockRepository mocks;
    INext *nextMock = mocks.Mock<INext>();
    mocks.ExpectCall(nextMock, INext::g).With(1, makeList());
    nextMock->g(1, { 1, 2, 3 });
}
