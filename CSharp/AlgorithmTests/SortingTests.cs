using System;

namespace AlgorithmTests
{
    using System.Collections;

    using NUnit.Framework;

    [TestFixture]
    public class SortingTests
    {
        [Test, TestCaseSource(typeof(Factory), "TestCases")]
        public void ShellSort(int[] data)
        {
            SortingAlgorithms.Sorting.Shell(data);
            CollectionAssert.IsOrdered(data);
        }

        [Test, TestCaseSource(typeof(Factory),"TestCases")]
        public void SelectionSort(int[] data)
        {
            SortingAlgorithms.Sorting.Selection(data);
            CollectionAssert.IsOrdered(data);
        }

        [Test, TestCaseSource(typeof(Factory), "TestCases")]
        public void BubbleSort(int[] data)
        {
            SortingAlgorithms.Sorting.Bubble(data);
            CollectionAssert.IsOrdered(data);
        }

        [Test, TestCaseSource(typeof(Factory), "TestCases")]
        public void BucketSort(int[] data)
        {
            SortingAlgorithms.IntegerSorting.Bucket(data);
            CollectionAssert.IsOrdered(data);
        }
        
        [Test, TestCaseSource(typeof(Factory), "TestCases")]
        public void InsertionSort(int[] data)
        {
            SortingAlgorithms.Sorting.Insertion(data);
            CollectionAssert.IsOrdered(data);
        }

        [Test, TestCaseSource(typeof(Factory), "TestCases")]
        public void CocktailSort(int[] data)
        {
            SortingAlgorithms.Sorting.Cocktail(data);
            CollectionAssert.IsOrdered(data);
        }

        [Test, TestCaseSource(typeof(Factory), "TestCases")]
        public void CombSort(int[] data)
        {
            SortingAlgorithms.Sorting.Comb(data);
            CollectionAssert.IsOrdered(data);
        }

        [Test, TestCaseSource(typeof(Factory), "TestCases")]
        public void QuickSort(int[] data)
        {
            SortingAlgorithms.Sorting.Quick(data);
            CollectionAssert.IsOrdered(data);
        }

        [Test, TestCaseSource(typeof(Factory), "TestCases")]
        public void Merge(int[] data)
        {
            SortingAlgorithms.Sorting.Merge(data);
            CollectionAssert.IsOrdered(data);
        }
    }

    public static class Factory
    {
        private static readonly int[] aLotOfValues;
        private static readonly int[] aLotMoreValues;

        static Factory()
        {
            aLotOfValues = GenerateArray(50000);
            aLotMoreValues = GenerateArray(100000);
        }

        public static IEnumerable TestCases
        {
            get
            {
                yield return new int[] { 5, 4, 3, 7, 6, 5, 123, 43, 25 };
                yield return new int[] { 9,8,7,6,5,4,3,2,1,19,18,17,16,15,14,13,12,11,10 };
                yield return CopyArray(aLotOfValues);
                yield return CopyArray(aLotMoreValues);
            }
        }

        public static int[] CopyArray(int[] array)
        {
            int[] newArray = new int[array.Length];
            Array.Copy(array,newArray,array.Length);
            return newArray;
        }

        public static int[] GenerateArray(int count)
        {
            Random rng = new Random();
            int[] toReturn = new int[count];
            for (int i = 0; i < count; i++)
            {
                toReturn[i] = rng.Next(int.MaxValue);
            }

            return toReturn;
        }
    }
}
