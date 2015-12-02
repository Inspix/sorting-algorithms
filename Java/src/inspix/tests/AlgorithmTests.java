package inspix.tests;

import inspix.sorting.Algorithms;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.util.Arrays;
import java.util.Random;

public class AlgorithmTests {

    private Integer[] testOne;
    private Integer[] testTwo;
    private Integer[] bigArray;

    public Integer[] getTestOne(){
        return Arrays.copyOf(testOne,testOne.length);
    }
    public Integer[] getTestTwo(){
        return Arrays.copyOf(testTwo,testTwo.length);
    }
    public Integer[] getTestThree(){
        return Arrays.copyOf(bigArray,bigArray.length);
    }

    private boolean isInOrder(Integer[] array){
        for (int i = 0; i < array.length-1; i++) {
            if (array[i].compareTo(array[i+1]) > 0){
                return false;
            }
        }
        return true;
    }

    @Before
    public void setUp(){
        testOne = new Integer[]{50,30,24,150,3,5,4,100,23};
        testTwo = new Integer[]{20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
        bigArray = new Integer[5000];
        Random rng = new Random();
        for (int i = 0; i < bigArray.length; i++) {
            bigArray[i] = rng.nextInt(Integer.MAX_VALUE);
        }
    }

    @Test
    public void selectionSortRandom(){
        Integer[] testData = getTestOne();
        Algorithms.Selection(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void selectionSortReversed(){
        Integer[] testData = getTestTwo();
        Algorithms.Selection(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void selectionSortBig(){
        Integer[] testData = getTestThree();
        Algorithms.Selection(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void bubbleSortRandom(){
        Integer[] testData = getTestOne();
        Algorithms.Bubble(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void bubbleSortReversed(){
        Integer[] testData = getTestTwo();
        Algorithms.Bubble(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void bubbleSortBig(){
        Integer[] testData = getTestThree();
        Algorithms.Bubble(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void insertionSortRandom(){
        Integer[] testData = getTestOne();
        Algorithms.Insertion(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void insertionSortReversed(){
        Integer[] testData = getTestTwo();
        Algorithms.Insertion(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void insertionSortBig(){
        Integer[] testData = getTestThree();
        Algorithms.Insertion(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void coctailSortRandom(){
        Integer[] testData = getTestOne();
        Algorithms.Cocktail(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void coctailSortReversed(){
        Integer[] testData = getTestTwo();
        Algorithms.Cocktail(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void coctailSortBig(){
        Integer[] testData = getTestThree();
        Algorithms.Cocktail(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void shellSortRandom(){
        Integer[] testData = getTestOne();
        Algorithms.Shell(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void shellSortReversed(){
        Integer[] testData = getTestTwo();
        Algorithms.Shell(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

    @Test
    public void shellSortBig(){
        Integer[] testData = getTestThree();
        Algorithms.Shell(testData);
        Assert.assertEquals("Array not sorted!",true,isInOrder(testData));
    }

}
