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
}