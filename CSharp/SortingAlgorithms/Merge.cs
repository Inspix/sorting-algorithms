namespace SortingAlgorithms
{
    using System;

    public static partial class Sorting
    {
       public static void Merge<T>(T[] array) where T : IComparable<T>
        {
            if (array.Length <= 1)
            {
                return;
            }

            T[] work = new T[array.Length];
            int length = array.Length;
            for (int size = 1; size < length; size = 2 * size)
            {

                for (int i = 0; i < array.Length; i = i + 2 * size)
                {
                    MergeSort(array, i, Math.Min(i + size, length), Math.Min(i + 2 * size, length), work);
                }

                Array.Copy(work, array, length);
            }
        }

        private static void MergeSort<T>(T[] array, int iLeft, int iRight, int iEnd, T[] work) where T : IComparable<T>
        {
           
            int left = iLeft;
            int right = iRight;
            int index;

            for (index = iLeft; index < iEnd; index++)
            {
                if (left < iRight && (right >= iEnd || array[left].CompareTo(array[right]) <= 0))
                {
                    work[index] = array[left];
                    left = left + 1;
                }
                else
                {
                    work[index] = array[right];
                    right = right + 1;
                }
            }
        }
    }
}
