public class quick_sort {
  private long auxSpace;
  private long comps;
  private long elapsed;
  public results sort(long[] array, int len) {
    auxSpace = 0;
    comps = 0;
    long start = System.nanoTime();
    quickSort(array, 0, (len - 1));
    elapsed = System.nanoTime() - start;
    return new results(elapsed, auxSpace, comps);
  }
  private void quickSort(long[] array, int start, int end) {
    auxSpace++;
    if (start >= end) return;
    int mid = partition(array, start, end);
    quickSort(array, start, mid - 1);
    quickSort(array, mid + 1, end);
  }
  private int partition(long[] a, int low, int high) {
    long x = a[low];
    boolean highTurn = true;
    while (low < high) {
      if (highTurn) {
        comps++;
        if (a[high] >= x)
          high--;
        else {
          a[low++] = a[high];
          highTurn = false;
        }
      } else {
        comps++;
        if (a[low] <= x)
          low++;
        else {
          a[high--] = a[low];
          highTurn = true;
        }
      }
    }
    a[low] = x;
    return low;
  }
}
