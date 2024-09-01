#include "[[name]]/[[name]].hpp"
#include <gtest/gtest.h>
#include <string>

TEST(LibTests, TestNameIsRight_Zero)
{
  auto const exported = exported_class {};
  ASSERT_EQ(exported.name(), std::string("[[name]]")); // teehee
}

TEST(LibTests, TestNameIsRight_One)
{
  auto const exported = exported_class {};
  ASSERT_NE(exported.name(), std::string("not [[name]]"));
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}