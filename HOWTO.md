
- [Introduction](#introduction)
- [Recipes](#recipes)
  - [Ensure a function is not called](#function-not-called)

# Introduction
This goal of this document is to provide a "cookbook" for common testing strategies that can occur in unit tests (or during Test Driven Development).
The examples will leverage the Google Test framework which uses functions like `EXPECT_EQ(a, b)` to check that the values `a` and `b` are equal.
It is assumed that these constructs will be relatively self evident and little or no explanation will be provided for them.

Each "recipe" in the "cookbook" should provide a brief description of the test strategy/construct desired, sample code to achieve that goal, and potentially addtional verbiage to explain and point out possible extensions.

Much of the "code under test" in the examples is substandard.
The code is likely reduced to the simplest thing that can be used to demonstrate the problem.
Similarly, some of the test code is substandard in that it lacks checking key condtions.
This substandard code is to avoid details that are not pertinent to the problem being discussed.


# Recipes
## Ensure a Function Is Not Called
### Desired Test Strategy
You may have code like:
`````
void *get_storage(int size)
{
  if (size > 0) {
     ptr = malloc(size);
  } else {
     ptr = NULL;
  }

  return ptr;
}
`````
and you would like to ensure your test case does not call `malloc()`.
### Sample Code
`````
TEST_F(FooTests, getStorage_SizeZero_DoesNotCallMalloc) {
  Mocks->NeverCallFunc (malloc);
  x = get_storage(0);
}
`````
