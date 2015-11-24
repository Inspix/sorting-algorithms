namespace SortingAlgorithms
{
    using System;

    public static partial class Sorting <T> where T : IComparable<T>
    {
        public static void Insertion(T[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                T temp = array[i];
                int j = i;
                while (j > 0 && array[j - 1].CompareTo(temp) > 0)
                {
                    array[j] = array[j - 1];
                    j--;
                }
                array[j] = temp;
            }
        }
    }
}
