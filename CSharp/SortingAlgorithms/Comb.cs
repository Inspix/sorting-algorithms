namespace SortingAlgorithms
{
    using System;

    public static partial class Sorting<T> where T : IComparable<T>
    {
        public static void Comb(T[] array)
        {
            int interval = array.Length;
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

                while (i + interval < array.Length)
                {
                    if (array[i].CompareTo(array[i + interval]) > 0)
                    {
                        T temp = array[i];
                        array[i] = array[i + interval];
                        array[i + interval] = temp;
                        hasChanged = true;
                    }
                    i++;
                }
            }
            while (interval != 1 || hasChanged);
        }
    }
}
