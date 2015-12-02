package inspix.sorting;

import java.util.Comparator;

/**
 * Created by Inspix on 02/12/2015.
 */
public class Algorithms {

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

}
