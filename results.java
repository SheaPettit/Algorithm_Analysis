public class results {
  private double runtime;
  private long space;
  private long comps;
  public results(long run, long space, long comps){
    runtime = (double) run / 1000000.0;
    this.space = space;
    this.comps = comps;
  }
  public double getTime() {return runtime;}
  public long getSpace() {return space;}
  public long getComps() {return comps;}
  public void printResults() {
    System.out.println("Runtime: " + runtime + " ms");
    System.out.println("Space: " + space);
    System.out.println("Comps: " + comps);
  }
}
