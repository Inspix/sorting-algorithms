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

}
