#include <algorithm>

namespace Sorting {

	template <typename T>
	void selection(T* arr, size_t length) {
		selection(arr, arr + length);
	}

	template <typename rIter>
	void selection(rIter begin, rIter end) {
		int count = end - begin;


		for (int i = 0; i < count; i++)
		{
			int min = i;

			for (int j = i; j < count; j++)
			{
				if (begin[j] < begin[min])
				{
					min = j;
				}
			}

			if (min != i)
			{
				std::swap(begin[min], begin[i]);
			}
		}
	}

	template<typename T>
	void bubble(T* arr, size_t length) {
		bubble(arr, arr + length);
	}

	template<typename rIter>
	void bubble(rIter begin, rIter end) {
		size_t count = end - begin;
		for (size_t i = count - 1; i >= 1; i--)
		{
			bool swapped = false;
			for (size_t j = 0; j < i; j++)
			{
				if (begin[j + 1] < begin[j])
				{
					swapped = true;
					std::swap(begin[j + 1], begin[j]);
				}
			}

			if (!swapped)
			{
				return;
			}
		}
	}

	template<typename T>
	void insertion(T* arr, size_t length) {
		insertion(arr, arr + length);
	}

	template<typename rIter>
	void insertion(rIter begin, rIter end) {
		size_t length = end - begin;
		for (size_t i = 1; i < length; i++)
		{
			auto temp = begin[i];
			int j = i;
			while (j > 0 && begin[j - 1] > temp)
			{
				begin[j] = begin[j - 1];
				j--;
			}
			begin[j] = temp;
		}
	}

	template<typename T>
	void cocktail(T* arr, size_t length) {
		cocktail(arr, arr + length);
	}

	template<typename rIter>
	void cocktail(rIter begin, rIter end) {
		int iStart = -1;
		int iEnd = (end - begin) - 1;
		bool hasChange;

		do
		{
			hasChange = false;
			++iStart;
			for (int i = iStart; i < iEnd; i++)
			{
				if (begin[i] > begin[i + 1])
				{
					hasChange = true;
					std::swap(begin[i + 1], begin[i]);
				}
			}

			if (!hasChange)
			{
				return;
			}

			hasChange = false;
			--iEnd;
			for (int i = iEnd; i >= iStart; i--)
			{
				if (begin[i] > begin[i + 1])
				{
					hasChange = true;
					std::swap(begin[i + 1] , begin[i]);
				}
			}


		} while (hasChange);

	}


	template<typename T>
	void shell(T* arr, size_t length) {
		shell(arr, arr + length);
	}

	template<typename rIter>
	void shell(rIter begin, rIter end) {
		int length = end - begin;

		int interval = 1;
		while (interval <= length / 3) {
			interval = interval * 3 + 1;
		}


		while (interval > 0) {
			for (int i = interval; i < length; i++)
			{
				auto temp = begin[i];
				int j = i;
				while (j > interval - 1 && begin[j - interval] > temp)
				{
					std::swap(begin[j], begin[j - interval]);
					j -= interval;
				}

				begin[j] = temp;
			}
			interval = (interval - 1) / 3;
		}
	}

	template<typename T>
	void comb(T* arr, int length) {
		comb(arr, arr + length);
	}

	template<typename rIter>
	void comb(rIter begin, rIter end) {
		int length = end - begin;
		int interval = length;
		float divider = 1.3f;
		bool hasChanged;
		do
		{
			interval = (int)(interval / divider);
			if (interval < 1)
			{
				interval = 1;
			}

			hasChanged = false;
			int i = 0;

			while (i + interval < length) {
				if (begin[i + interval] < begin[i])
				{
					std::swap(begin[i], begin[interval + i]);
					hasChanged = true;
				}
				i++;
			}


		} while (interval != 1 || hasChanged);

	}

	template <typename T>
	void quick(T* arr, int length) {
		quick(arr, arr + length);
	}

	template<typename rIter>
	void quick(rIter begin, rIter end) {
		int length = end - begin;

		if (length <= 1)
		{
			return;
		}
		_quick(begin, 0, length - 1);
	}

	template<typename rIter>
	void _quick(rIter begin, int low, int high) {
		if (low < high)
		{
			int pivot = _getPivotAndPartition(begin, low, high);
			_quick(begin, low, pivot);
			_quick(begin, pivot + 1, high);
		}
	}

	template<typename rIter>
	int _getPivotAndPartition(rIter begin, int low, int high) {
		auto p = begin[low];
		int iLow = low - 1;
		int iHigh = high + 1;

		while (true)
		{
			do
			{
				--iHigh;
			} while (begin[iHigh] > p);
			do
			{
				++iLow;
				
			}while (begin[iLow] < p);

			if (iLow < iHigh)
			{
				std::swap(begin[iLow], begin[iHigh]);
			}
			else
			{
				return iHigh;
			}
		}
	}

	template<typename T>
	void merge(T* arr, size_t length)
	{
		T* temp = new T[length];
		TopDownSplitMerge(arr, 0, length, temp);
		delete temp;
	}


	// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
	template<typename rIter>
	void TopDownSplitMerge(rIter src, int iStart, int iEnd, rIter work)
	{
		if (iEnd - iStart < 2)                       // if run size == 1
			return;                                 //   consider it sorted
													// recursively split runs into two halves until run size == 1,
													// then merge them and return back up the call chain
		int iMiddle = (iEnd + iStart) / 2;              // iMiddle = mid point
		TopDownSplitMerge(src, iStart, iMiddle, work);  // split / merge left  half
		TopDownSplitMerge(src, iMiddle, iEnd, work);  // split / merge right half
		TopDownMerge(src, iStart, iMiddle, iEnd, work);  // merge the two half runs
		_copyArrays(work, src, iStart, iEnd);
	}

	template<typename rIter>
	void _copyArrays(rIter src, rIter destination, int start, int end) {
		for (int i = start; i < end; i++)
		{
			destination[i] = src[i];
		}
	}

	template<typename rIter>
	void TopDownMerge(rIter src, int iStart, int iMiddle, int iEnd, rIter work)
	{
		int begin = iStart;
		int mid = iMiddle;

		for (int k = iStart; k < iEnd; k++) {
			if (begin < iMiddle && (mid >= iEnd || src[begin] < src[mid])) {
				work[k] = src[begin];
				begin++;
			}
			else {
				work[k] = src[mid];
				mid++;
			}
		}
	}

}