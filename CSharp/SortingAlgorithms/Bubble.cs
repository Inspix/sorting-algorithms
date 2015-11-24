namespace SortingAlgorithms
{
    using System;

    public static partial class Sorting
    {
        public static void Bubble<T>(T[] array) where T : IComparable<T>
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
