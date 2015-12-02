package inspix.sorting;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;

/**
 * Created by Inspix on 02/12/2015.
 */
public class Algorithms {

    /**************************************************************
     *   Selection SORT
     * *************************************************************/
    public static <T extends Comparable<T>> void Selection(T[] array){

        for (int i = 0; i < array.length; i++) {
            int min = i;
            for (int j = i; j < array.length; j++) {
                if (array[j].compareTo(array[min]) < 0){
                    min = j;
                }
            }
            if (min != i){
                T temp = array[min];
                array[min] = array[i];
                array[i] = temp;
            }
        }

    }

    /**************************************************************
     *   Bubble SORT
     * *************************************************************/
    public static <T extends Comparable<T>> void Bubble(T[] array){
        int end = array.length;
        while(end != 0){
            boolean hasChanged = false;
            for (int i = 1; i < end; i++) {
                if (array[i-1].compareTo(array[i]) > 0){
                    T temp = array[i-1];
                    array[i-1] = array[i];
                    array[i] = temp;
                    hasChanged = true;
                }
            }
            end--;
            if (!hasChanged)
                break;
        }
    }

    /**************************************************************
     *   Insertion SORT
     * *************************************************************/
    public static <T extends Comparable<T>> void Insertion(T[] array){
        for (int i = 0; i < array.length; i++) {
            T temp = array[i];
            int j = i;
            while(j > 0 && array[j - 1].compareTo(temp) > 0){
                array[j] = array[j -1];
                j--;
            }
            array[j] = temp;
        }
    }

    /**************************************************************
     *   Cocktail SORT
     * *************************************************************/
    public static <T extends Comparable<T>> void Cocktail(T[] array){
        int start = -1;
        int end = array.length -1;
        boolean hasChanged;

        do {
            hasChanged = false;
            start++;
            for (int i = start; i < end; i++) {
                if (array[i].compareTo(array[i + 1]) > 0){
                    hasChanged = true;
                    T temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                }
            }

            if (!hasChanged)
                break;

            hasChanged = false;
            end--;
            for (int i = end; i >= start ; i--) {
                if (array[i].compareTo(array[i + 1]) > 0){
                    hasChanged = true;
                    T temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                }
            }
        }while(hasChanged);
    }

    /**************************************************************
     *   Shell SORT
     * *************************************************************/
    public static <T extends Comparable<T>> void Shell(T[] array){
        int step = 1;
        while(step <= array.length/3){
            step = step * 3 + 1;
        }

        while (step > 0){
            for (int i = step; i < array.length; i++) {
                T temp = array[i];
                int j = i;
                for (;j > step - 1 && array[j - step].compareTo(temp) >= 0; j -= step){
                    array[j] = array[j - step];
                }
                array[j] = temp;
            }
            step = (step - 1) /3;
        }
    }

    /**************************************************************
    *   Comb SORT
    * *************************************************************/
    public static <T extends Comparable<T>> void Comb(T[] array){
        int step = array.length;
        double factor = 1.3;
        boolean hasChanged;

        do {
            step = (int)(step/factor);
            if (step < 1)
                step = 1;
            hasChanged = false;
            int i = 0;
            while (step + i < array.length){
                if (array[i].compareTo(array[i + step]) > 0){
                    T temp = array[i];
                    array[i] = array[i + step];
                    array[i + step] = temp;
                    hasChanged = true;
                }
                i++;
            }
        }while(step != 1 || hasChanged);
    }

    /**************************************************************
     *   Quick SORT
     * *************************************************************/
    public static <T extends Comparable<T>> void Quick(T[] array){
        if (array.length <= 1)
            return;

        quickSort(array,0,array.length-1);
    }

    private static <T extends Comparable<T>> void quickSort(T[] array,int low, int high){
        if (low < high){
            int pivot = getPivot(array,low,high);
            quickSort(array,low,pivot);
            quickSort(array,pivot+1,high);
        }
    }

    private static <T extends Comparable<T>> int getPivot(T[] array,int low,int high){
        T pivot = array[low];
        int i = low -1;
        int j = high +1;
        while(true){
            do {
                j--;
            }while(array[j].compareTo(pivot) > 0);
            do {
                i++;

            }while(array[i].compareTo(pivot) < 0);

            if (i < j){
                T temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }else{
                return j;
            }
        }
    }

    /**************************************************************
     *   Merge SORT
     * *************************************************************/

    public static <T extends Comparable<T>> void Merge(T[] array){
        if (array.length <=1)
            return;
        @SuppressWarnings("unchecked")
        T[] workArray = (T[])Array.newInstance(array.getClass().getComponentType(),array.length);
        int length = array.length;
        for (int size = 1; size < length; size = 2 * size)
        {

            for (int i = 0; i < array.length; i = i + 2 * size)
            {
                mergeSort(array, i, Math.min(i + size, length), Math.min(i + 2 * size, length), workArray);
            }

            System.arraycopy(workArray, 0, array, 0, array.length);
        }

    }

    private static <T extends Comparable<T>> void mergeSort(T[] array,int min, int middle,int max,T[] work){
        int left = min;
        int right = middle;
        int index;

        for (index = min; index < max; index++)
        {
            if (left < middle && (right >= max || array[left].compareTo(array[right]) <= 0))
            {
                work[index] = array[left];
                left = left + 1;
            }
            else
            {
                work[index] = array[right];
                right = right + 1;
            }
        }

    }

 }
