namespace SortingAlgorithms
{
    using System;

    public static partial class Sorting<T> where T : IComparable<T>
    {
        public static void Selection(T[] array)
        {
            for (int i = 0; i < array.Length - 1; i++)
            {
                int min = i;
                for (int j = i+1; j < array.Length; j++)
                {
                    if (array[j].CompareTo(array[min]) < 0)
                    {
                        min = j;
                    }
                }

                if (min != i)
                {
                    T temp = array[i];
                    array[i] = array[min];
                    array[min] = temp;
                }
            }
        }
    }
}