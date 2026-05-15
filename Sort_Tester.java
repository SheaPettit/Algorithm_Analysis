import java.util.Random;
public class Sort_Tester {
  private static Random rand;
  public static void main(String[] args) {
    rand = new Random();

    long[] array1 = createRandomArray(500);
    long[] array2 = createRandomArray(1000);
    long[] array3 = createRandomArray(2000);
    long[] array4 = createRandomArray(4000);
    long[] array5 = createRandomArray(8000);
    quick_sort quickSort = new quick_sort();
    insert_sort insertSort = new insert_sort();
    hybrid_sort hybridSort = new hybrid_sort();

    for(int i = 0; i < 20000; i++) {
      quickSort.sort(createRandomArray(1000), 1000);
      insertSort.sort(createRandomArray(1000), 1000);
      hybridSort.sort(createRandomArray(1000), 1000);
    }

    quickSort = new quick_sort();
    System.out.println("Quick sort (500):");
    long[] a1 = createDeepCopy(array1, 500);
    results ra1 = quickSort.sort(a1, a1.length);
    ra1.printResults();

    System.out.println();

    quickSort = new quick_sort();
    System.out.println("Quick sort (1000):");
    long[] a2 = createDeepCopy(array2, 1000);
    results ra2 = quickSort.sort(a2, a2.length);
    ra2.printResults();

    System.out.println();

    quickSort = new quick_sort();
    System.out.println("Quick sort (2000):");
    long[] a3 = createDeepCopy(array3, 2000);
    results ra3 = quickSort.sort(a3, a3.length);
    ra3.printResults();

    System.out.println();

    quickSort = new quick_sort();
    System.out.println("Quick sort (4000):");
    long[] a4 = createDeepCopy(array4, 4000);
    results ra4 = quickSort.sort(a4, a4.length);
    ra4.printResults();

    System.out.println();

    quickSort = new quick_sort();
    System.out.println("Quick sort (8000):");
    long[] a5 = createDeepCopy(array5, 8000);
    results ra5 = quickSort.sort(a5, a5.length);
    ra5.printResults();


    System.out.println();
    System.out.println();


    insertSort = new insert_sort();
    System.out.println("Insertion Sort (500):");
    long[] b1 = createDeepCopy(array1, 500);
    results rb1 = insertSort.sort(b1, b1.length);
    rb1.printResults();

    System.out.println();

    insertSort = new insert_sort();
    System.out.println("Insertion Sort (1000):");
    long[] b2 = createDeepCopy(array2, 1000);
    results rb2 = insertSort.sort(b2, b2.length);
    rb2.printResults();

    System.out.println();

    insertSort = new insert_sort();
    System.out.println("Insertion Sort (2000):");
    long[] b3 = createDeepCopy(array3, 2000);
    results rb3 = insertSort.sort(b3, b3.length);
    rb3.printResults();

    System.out.println();

    insertSort = new insert_sort();
    System.out.println("Insertion Sort (4000):");
    long[] b4 = createDeepCopy(array4, 4000);
    results rb4 = insertSort.sort(b4, b4.length);
    rb4.printResults();

    System.out.println();

    insertSort = new insert_sort();
    System.out.println("Insertion Sort (8000):");
    long[] b5 = createDeepCopy(array5, 8000);
    results rb5 = insertSort.sort(b5, b5.length);
    rb5.printResults();    


    System.out.println();
    System.out.println();


    hybridSort = new hybrid_sort();
    System.out.println("Hybrid Quick/Insertion Sort (500):");
    long[] c1 = createDeepCopy(array1, 500);
    results rc1 = hybridSort.sort(c1, c1.length);
    rc1.printResults();

    System.out.println();

    hybridSort = new hybrid_sort();
    System.out.println("Hybrid Quick/Insertion Sort (1000):");
    long[] c2 = createDeepCopy(array2, 1000);
    results rc2 = hybridSort.sort(c2, c2.length);
    rc2.printResults();

    System.out.println();

    hybridSort = new hybrid_sort();
    System.out.println("Hybrid Quick/Insertion Sort (2000):");
    long[] c3 = createDeepCopy(array3, 2000);
    results rc3 = hybridSort.sort(c3, c3.length);
    rc3.printResults();

    System.out.println();

    hybridSort = new hybrid_sort();
    System.out.println("Hybrid Quick/Insertion Sort (4000):");
    long[] c4 = createDeepCopy(array4, 4000);
    results rc4 = hybridSort.sort(c4, c4.length);
    rc4.printResults();

    System.out.println();

    hybridSort = new hybrid_sort();
    System.out.println("Hybrid Quick/Insertion Sort (8000):");
    long[] c5 = createDeepCopy(array5, 8000);
    results rc5 = hybridSort.sort(c5, c5.length);
    rc5.printResults();
 
  }
  private static long[] createRandomArray(int len) {
    long[] a = new long[len];
    for(int i = 0; i < len; i++)
      a[i] = (long) (i + 1);
    for(int i = (len - 1); i > 0; i--) {
      long temp = a[i];
      int randIndex = rand.nextInt(0, i);
      a[i] = a[randIndex];
      a[randIndex] = temp;
    }
    return a;
  }
  private static long[] createDeepCopy(long[] array, int len) {
    long[] a = new long[len];
    for(int i = 0; i < len; i++)
      a[i] = array[i];
    return a;
  }
  private static void printArray(long[] a, int len) {
    System.out.print("(");
    for(int i = 0; i < len; i++) {
      if(i != 0)
        System.out.print(",");
      System.out.print(a[i]);
    }
    System.out.println(")");
  }
}
