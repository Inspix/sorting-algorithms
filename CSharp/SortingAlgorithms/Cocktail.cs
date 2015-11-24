namespace SortingAlgorithms
{
    using System;

    public static partial class Sorting<T> where T : IComparable<T>
    {
        public static void Cocktail(T[] array)
        {
            int startIndex = -1;
            int endIndex = array.Length - 1;
            bool hasChanged;

            do
            {
                hasChanged = false;
                startIndex++;

                for (int i = startIndex; i < endIndex; i++)
                {
                    if (array[i].CompareTo(array[i + 1]) > 0)
                    {
                        hasChanged = true;
                        T temp = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = temp;
                    }
                }

                if (!hasChanged)
                {
                    break;
                }

                hasChanged = false;
                endIndex--;

                for (int i = endIndex; i >= startIndex; i--)
                {
                    if (array[i].CompareTo(array[i + 1]) > 0)
                    {
                        hasChanged = true;
                        T temp = array[i];
                        array[i] = array[i + 1];
                        array[i + 1] = temp;
                    }
                }
            }
            while (hasChanged);
        }
    }
}
