package inspix.sorting;

import java.util.Arrays;
import java.util.Random;
import java.util.Timer;

public class Main {

    public static void main(String[] args) {
        Integer[] testArray = new Integer[]{1,50,43,2,20,13,10,9};
        Integer[] testArray2 = new Integer[]{10,9,8,7,6,5,4,3,2,1};

        Random rng = new Random();

        Integer[] hugeArray = new Integer[50000];
        for (int i = 0; i < hugeArray.length; i++) {
            hugeArray[i] = rng.nextInt(Integer.MAX_VALUE);
        }


        System.out.println("Test array one - " + Arrays.toString(testArray));
        Algorithms.Selection(testArray);
        System.out.println("Test array one sorted - " + Arrays.toString(testArray));
        System.out.println("Test array two - " + Arrays.toString(testArray2));
        Algorithms.Selection(testArray2);
        System.out.println("Test array two sorted - " + Arrays.toString(testArray2));


        System.out.println("Big array 50k values - " + Arrays.toString(hugeArray));
        long start = System.nanoTime();
        Algorithms.Selection(hugeArray);
        long end = System.nanoTime();

        System.out.println("Big array 50k values sorted - " + Arrays.toString(hugeArray));
        System.out.println("Time used:" + ((end - start) / 1000000L) + "ms");


    }
}
