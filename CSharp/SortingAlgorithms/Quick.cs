namespace SortingAlgorithms
{
    using System;

    public static partial class Sorting
    {
        public static void Quick<T>(T[] array) where T : IComparable<T>
        {
            if (array.Length < 1)
            {
                return;
            }
            QuickSort(array,0,array.Length-1);
           
        }

        private static void QuickSort<T>(T[] array, int low, int high) where T : IComparable<T>
        {
            if (low < high)
            {
                int pivot = GetPivotAndPartition(array, low, high);
                QuickSort(array,low, pivot);
                QuickSort(array,pivot + 1, high);
            }
        }

        private static int GetPivotAndPartition<T>(T[] array, int low, int high) where T : IComparable<T>
        {
            T p = array[low];
            int i = low - 1;
            int j = high + 1;
            while (true)
            {
                do
                {
                    j--;
                }
                while (array[j].CompareTo(p) > 0);
                do
                {
                    i++;
                }
                while (array[i].CompareTo(p) < 0);

                if (i < j)
                {
                    T temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
                else
                {
                    return j;
                }
            }
        }
    }
}