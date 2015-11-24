namespace SortingAlgorithms
{
    using System;

    public static partial class Sorting
    {
        public static void Shell<T>(T[] array) where T : IComparable<T>
        {
            int interval = 1;
            while (interval <= array.Length / 3)
            {
                interval = interval * 3 + 1;
            }

            while (interval > 0)
            {
                for (int i = interval; i < array.Length; i++)
                {
                    var temp = array[i];
                    var j = i;
                    for (; j > interval - 1 && array[j - interval].CompareTo(temp) >= 0; j -= interval)
                    {
                        array[j] = array[j - interval];
                    }

                    array[j] = temp;
                }
                interval = (interval - 1) / 3;
            }
        }
    }
}
