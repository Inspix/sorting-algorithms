#include <gtest/gtest.h>
#include "Sorting.h"
#include <stdio.h>

static int testArraySimple[10] = { 6,4,19,643,43,2,1,99,5,49 };
static int testArrayReversed[10] = { 10,9,8,7,6,5,4,3,2,1 };

template<typename rItr>
static testing::AssertionResult arraySorted(rItr begin, size_t size) {
	for (size_t i = 0; i < size - 1; ++i) {
		if (begin[i] > begin[i + 1]) {
			return testing::AssertionFailure() << "Array[" << i << "] expected to be lesser than Array[" << i + 1 << "]";
		}
	}
	return testing::AssertionSuccess();
}

struct SimpleArrayTest : testing::Test {
	int* arr;
	int length = 10;
	void SetUp() {
		arr = new int[length]{ 6,4,19,643,43,2,1,99,5,49 };
	}
	void TearDown() {
		delete arr;
	}
};

struct ReversedSmallArrayTest : testing::Test {
	int* arr;
	int length = 100;
	void SetUp() {

		arr = new int[length];
		int index = 0;
		for (size_t i = 0; i < length; i++)
		{
			arr[i] = length - i;
		}
	}
	void TearDown() {
		delete arr;
	}
};


static bool hugeArrayInitialized = false;
static int hugeArraySize = 10000;
static int* hugeArray = new int[hugeArraySize];

struct RandomHugeArrayTest : testing::Test {
	int* arr;
	int length = hugeArraySize;
	void SetUp() {
		if (!hugeArrayInitialized)
		{
			hugeArray = new int[length];
			int index = 0;
			for (size_t i = 0; i < length; i++)
			{
				hugeArray[i] = rand();
			}
			hugeArrayInitialized = true;
		}
		arr = new int[length];
		memcpy(arr, hugeArray, length);
		
	}
	void TearDown() {
		delete arr;
	}
};

TEST_F(SimpleArrayTest, SelectionSortSimpleArray) {
	Sorting::selection(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(SimpleArrayTest, BubbleSortSimpleArray) {
	Sorting::bubble(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(SimpleArrayTest, CocktailSortSimpleArray) {
	Sorting::cocktail(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(SimpleArrayTest, InsertionSortSimpleArray) {
	Sorting::insertion(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(SimpleArrayTest, ShellSortSimpleArray) {
	Sorting::shell(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

/*------------------------------------------------------------------------*/

TEST_F(ReversedSmallArrayTest, SelectionSortReversedArray) {
	Sorting::selection(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(ReversedSmallArrayTest, BubbleSortReversedArray) {
	Sorting::bubble(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(ReversedSmallArrayTest, CocktailSortReversedArray) {
	Sorting::cocktail(arr, length);
	
	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(ReversedSmallArrayTest, InsertionSortReversedArray) {
	Sorting::insertion(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(ReversedSmallArrayTest, ShellSortReversedArray) {
	Sorting::shell(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

/*------------------------------------------------------------------------------*/

TEST_F(RandomHugeArrayTest, BubbleSortHugeArray) {
	Sorting::bubble(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(RandomHugeArrayTest, SelectionSortHugeArray) {
	Sorting::selection(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(RandomHugeArrayTest, CocktailSortHugeArray) {
	Sorting::cocktail(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(RandomHugeArrayTest, InsertionSortHugeArray) {
	Sorting::insertion(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}

TEST_F(RandomHugeArrayTest, ShellSortHugeArray) {
	Sorting::shell(arr, length);

	EXPECT_TRUE(arraySorted(arr, length));
}
