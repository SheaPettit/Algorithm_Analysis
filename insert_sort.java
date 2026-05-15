public class insert_sort{
  private long auxSpace;
  private long comps;
  private long elapsed;
  public results sort(long[] array, int len) {
    auxSpace = 1; //The temp var toInsert
    comps = 0;
    long start = System.nanoTime();
    for (int i = 1; i < len; i++) {
      long toInsert = array[i];
      int j;
      for (j = i; j > 0 && array[j - 1] > toInsert; j--) {
        array[j] = array[j - 1];
        comps++;
      }
      comps++;
      array[j] = toInsert;
    }
    elapsed = System.nanoTime() - start;
    return new results(elapsed, auxSpace, comps);
  }
}
