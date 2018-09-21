// Java implementation.
// Can be run on:
// https://www.jdoodle.com/online-java-compiler


import java.util.Arrays;

public class MyClass {
    private static void exch(int[] a, int i, int j)
    {
        int tmp;
        tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
    }

    private static boolean less(int i, int j)
    {
        return i < j;
    }

    private static int partition(int[] a, int lo, int hi)
    {
        int i = lo, j = hi+1;
        while (true)
        {
            while (less(a[++i], a[lo]))
                if (i == hi) break;
            while (less(a[lo], a[--j]))
                if (j == lo) break;
            if (i >= j) break;

            exch(a, i, j);
        }
        exch(a, lo, j);
        return j;
    }

    public static void main(String[] args)
    {
        int[] data = {11, 10};
        System.out.println(Arrays.toString(data));
        partition(data, 0, 1);
        System.out.println(Arrays.toString(data));
        return;
    }
}
