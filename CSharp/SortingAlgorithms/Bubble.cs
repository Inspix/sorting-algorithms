namespace SortingAlgorithms
{
    using System;

    public static partial class Sorting<T> where T : IComparable<T>
    {
        public static void Bubble(T[] array)
        {
            int n = array.Length;
            bool hasChanged;
            do
            {
                hasChanged = false;
                for (int j = 1; j < n; j++)
                {
                    if (array[j-1].CompareTo(array[j]) > 0)
                    {
                        hasChanged = true;
                        T temp = array[j-1];
                        array[j-1] = array[j];
                        array[j] = temp;
                    }
                }
                n--;

            } while (hasChanged);
        }
    }
}
