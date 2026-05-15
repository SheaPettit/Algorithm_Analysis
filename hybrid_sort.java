public class hybrid_sort {
  private long auxSpace;
  private long comps;
  private long elapsed;
  public results sort(long[] array, int len) {
    comps = 1; //Temp variable from the insertion sort
    long start = System.nanoTime();
    auxSpace = hybridSort(array, 0, (len - 1), 0);
    elapsed = System.nanoTime() - start;
    return new results(elapsed, auxSpace, comps);
  }
  private void insertSort(long[] array, int start, int end) {
    for (int i = start + 1; i <= end; i++) {
      long toInsert = array[i];
      int j;
      for (j = i; j > 0 && array[j - 1] > toInsert; j--) {
        array[j] = array[j - 1];
        comps++;
      }
      comps++;
      array[j] = toInsert;
    }
  }
  private long hybridSort(long[] array, int start, int end, long call) {
    if (start >= end) return (call + 1);
    else if (end - start < 10) {
      insertSort(array, start, end);
      return (call + 1);
    }
    int mid = partition(array, start, end);
    long depth1 = hybridSort(array, start, mid - 1, (call + 1));
    long depth2 = hybridSort(array, mid + 1, end, (call + 1));
    return Math.max(depth1, depth2);
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
