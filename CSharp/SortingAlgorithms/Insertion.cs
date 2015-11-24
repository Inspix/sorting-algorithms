namespace SortingAlgorithms
{
    using System;

    public static partial class Sorting
    {
        public static void Insertion<T>(T[] array) where T : IComparable<T>
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
