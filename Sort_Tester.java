import java.util.Random;
public class Sort_Tester {
  private static Random rand;
  public static void main(String[] args) {
    rand = new Random();
    long[] array = createRandomArray(1000);
    System.out.println("Quick sort:");
    long[] a = createDeepCopy(array, 1000);
    //System.out.println("Unsorted:");
    //printArray(a, a.length);
    quick_sort quickSort = new quick_sort();
    results r1 = quickSort.sort(a, a.length);
    //System.out.println("Sorted:");
    //printArray(a, a.length);
    r1.printResults();

    System.out.println("Insertion Sort:");
    long[] b = createDeepCopy(array, 1000);
    //System.out.println("Unsorted:");
    //printArray(b, b.length);
    insert_sort insertSort = new insert_sort();
    results r2 = insertSort.sort(b, b.length);
    //System.out.println("Sorted:");
    //printArray(b, b.length);
    r2.printResults();
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
