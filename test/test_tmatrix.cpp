#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> a(5);
	a[0][0] = 1;
	TMatrix<int> b(a);
	ASSERT_EQ(a, b);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> a(5), b(a);
	b[0][0] = 1;
	EXPECT_EQ(true, a != b);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> a(2);
	ASSERT_EQ(a.GetSize(), 2);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> a(3);
	a[1][1] = 100;
	ASSERT_EQ(a[1][1], 100);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int>a(5);
	ASSERT_ANY_THROW(a[-1][1] = 0);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> a(5);
	ASSERT_ANY_THROW(a[5][5] = 1);

}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int>a(5);
	TMatrix<int>tmp(a);
	a = a;
	ASSERT_EQ(a, tmp);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int>a(5);
	TMatrix<int>b(5);
	a[1][2] = 1;
	b = a;
	EXPECT_EQ(a, b);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int>a(5), b(3);
	a = b;
	EXPECT_EQ(a.GetSize(), 3);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix <int> a(5);
	TMatrix <int> b(3);
	a[0][0] = 1;
	b = a;
	EXPECT_EQ(a, b);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> a(5);
	TMatrix<int> b(5);
	a[0][0] = 1;
	b = a;
	EXPECT_EQ(a == b, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix <int> a(5);
	EXPECT_EQ(a == a, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> a(5);
	TMatrix<int> b(3);
	EXPECT_EQ(a != b, true);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix <int> a(2);
	TMatrix <int> b(2);
	TMatrix <int> c(2);
	a[0][0] = 1;
	b[0][0] = 1;
	c[0][0] = 2;
	EXPECT_EQ(a + b, c);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int>a(5);
	TMatrix<int>b(3);
	ASSERT_ANY_THROW(a + b);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int>a(5);
	TMatrix<int>b(5);
	TMatrix<int>c(5);
	c[0][0] = -1;
	a[0][0] = 1;
	EXPECT_EQ(b - a, c);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int>a(5);
	TMatrix<int>b(3);

	ASSERT_ANY_THROW(a - b);
}


