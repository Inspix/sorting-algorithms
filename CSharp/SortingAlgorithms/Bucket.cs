namespace SortingAlgorithms
{
    using System;
    using System.Collections.Generic;

    public static partial class IntegerSorting
    {
        // TODO: Add alternative bucket sorting methods

        public static void Bucket(int[] array,int min = int.MinValue, int max = int.MaxValue)
        {
            int numberOfBuckets = array.Length / 30;
            if (numberOfBuckets <= 0)
            {
                numberOfBuckets = 1;
            }
            LinkedList<int>[] buckets = new LinkedList<int>[numberOfBuckets];

            for (int i = 0; i < array.Length; i++)
            {
                int index = GetBucketNumber(array[i], min, max, buckets.Length);
                if (buckets[index] == null)
                {
                    buckets[index] = new LinkedList<int>();
                    buckets[index].AddFirst(array[i]);
                }
                else
                {
                    LinkedListNode<int> temp = buckets[index].First;
                    while (temp != null)
                    {
                        int arrayInt = array[i];
                        if (temp.Value >= arrayInt)
                        {
                            buckets[index].AddBefore(temp, array[i]);
                            break;
                        }
                        if (temp.Next == null)
                        {
                            buckets[index].AddLast(array[i]);
                            break;
                        }
                        temp = temp.Next;
                    }
                    
                }
            }
            int currentIndex = 0;
            foreach (var linkedList in buckets)
            {
                if (linkedList == null)
                {
                    continue;
                }
                foreach (var value in linkedList)
                {
                    array[currentIndex] = value;
                    currentIndex++;
                }
            }
        }

        private static int GetBucketNumber(int number, int min, int max, int numberOfBuckets)
        {
            if (numberOfBuckets == 1)
            {
                return 0;
            }
            long diff = (long)max - min;
            int interval = (int)Math.Ceiling((decimal)diff / numberOfBuckets);
            int bucket = number / interval <= 0 ? 1 : interval;
            if (bucket >= numberOfBuckets)
            {
                bucket = numberOfBuckets - 1;

            }else if (bucket < 0)
            {
                bucket = 0;
            }
            return bucket;
        }
    }
}
