namespace SortingAlgorithms
{
    using System;
    using System.Diagnostics;

    class Program
    {
        static void Main(string[] args)
        {
            int[] numbers = new[] { 5, 4, 3, 7, 6, 5, 123, 43, 25 };
            Console.WriteLine(string.Join(", ", numbers));

            Sorting.Quick(numbers);

            Console.WriteLine(string.Join(", ", numbers));

            Random random = new Random();
            int[] bigArray = new int[50000];
            for (int i = 0; i < bigArray.Length; i++)
            {
                bigArray[i] = random.Next(int.MaxValue);
            }
            Console.WriteLine("Array size: {0} | Filled at: {1}", bigArray.Length, DateTime.Now + ":" + DateTime.Now.Millisecond);
            Stopwatch watch = Stopwatch.StartNew();
            Sorting.Quick(bigArray);
            watch.Stop();
            //Console.WriteLine(string.Join("\n", bigArray));
            Console.WriteLine("Array size: {0} | Sorted at: {1}\nTime Elapsed: ~{2}ms", bigArray.Length, DateTime.Now + ":" + DateTime.Now.Millisecond, watch.ElapsedMilliseconds);
        }


    }
}
