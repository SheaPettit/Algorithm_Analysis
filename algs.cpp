#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

const int MAXSIZE = 120000000; // you might need to set this to a lower value
const int DATASIZE = 1;     // a bigger value will emphasize the cost of assignments vs. comparisons




struct record {
    unsigned long long int key;
    //  char value[DATASIZE]; // uncomment to vary the cost of item assignments
};

record     buf1[MAXSIZE],  // orig. list of random numbers
buf2[MAXSIZE];             // copy of the numbers to pass to sortX

unsigned long long int  sort0(record  nums[], int len);   // slowsort
unsigned long long int  sort1(record  nums[], int len);   // "optimized" slowsort
unsigned long long int  sort2(record  nums[], int len);   // bubblesort
unsigned long long int  sort3(record  nums[], int len);   // opt bubblesort
// unsigned long long int  sort4(record  nums[], int len);   // recursive bubblesort
unsigned long long int  sort4(record  nums[], int len);   // selection sort
unsigned long long int  sort5(record  nums[], int len);   // insertion sort
unsigned long long int  sort6(record  nums[], int len);   // mergesort
unsigned long long int  sort7(record  nums[], int len);   // quicksort
unsigned long long int  sort8(record  nums[], int len);   // heapsort
unsigned long long int  sort9(record nums[], int len);    // radixsort


void print(record  nums[], int len, bool newLine);
void fill(record   nums[], int len, char orderCode);
void copyTo(record from[], record to[], int len);
double timeIt(unsigned long long int(*sort)(record[], int), int len, int loops, bool printIt, int ocode,
    unsigned long long int& compares);

string sortNames[] = {
"reg. slowsort",
"opt. slowsort",
"bubblesort",
"opt bubblesort",
"selection sort",
"insertion sort",
"mergesort",
"quicksort",
"heapsort",
"radixsort" };
unsigned long long int comps;
unsigned long long int counter;





int main()
{
    cout << boolalpha;
 
    //cout << "Welcome to the sort tester." << endl;
    //cout << "To get more accurate results use multiple calls per test." << endl << endl;
    //cout << "Press Enter to start." << endl;
    //cin.get();
    srand((unsigned int)time(0));
    unsigned long long int (*sorts[]) (record[], int) = {
                 sort0, sort1, sort2, sort3, sort4,
                 sort5, sort6, sort7, sort8, sort9
    };
    int numSorts = 10, startId, endId, loops;
    char response, ocode;

    for (int i = 0; i < numSorts; i++) {
        cout << i << ": " << sortNames[i] << endl;
    }
    cout << "What is the start ID ? ";
    cin >> startId;
    startId = max(0, startId);
    cout << "What is the end ID ? ";
    cin >> endId;
    endId = min(numSorts - 1, endId);

    //cout << "Select fill type" << endl;
    cout << "Ascending, shuffled, descending or random('a', 's', 'd', 'r') ? ";
    // "ascending (a)\nshuffled  (s)\ndescending(d)\nrandom   (r)\nzigzag   (z)\n";
    //cout << "-->";
    cin >> ocode;
    bool printIt = false;
    cout << "Print the arrays (y/n) ? ";
    cin >> response;
    printIt = response == 'y';

    bool done = false;
    while (!done) {
        int size;
        cout << "What is the array size (0 to quit)? ";
        cin >> size;
        if (size <= 0) done = true;

        else {
            if (size > MAXSIZE) {
                cout << "Too big...setting size to " << MAXSIZE << "." << endl;
                size = MAXSIZE;
            }
            cout << "How many calls per test? ";
            cin >> loops;
            loops = max(1, loops);
            for (int i = startId; i <= endId; i++) {
                cout << "Starting sort" << i << " (" << sortNames[i] << ") ... " << flush;
                //counter = 0;
                unsigned long long int cp = 0;
                double time = timeIt(*sorts[i], size, loops, printIt, ocode, cp);

                //cout << "counter = " << counter << endl;
                cout << "Done. " << endl;
                cout << fixed << setprecision(3);
                cout << "Elapsed Time  = " << setw(9) << time << "ms. ,   \tcomparisons = "
                    << cp << endl << endl;
                if (loops > 1) cout << "Time per call = " << setw(9) << time / loops << "ms.,   \tcomps /call = "
                    << cp / loops << flush;
                cout << endl << endl;
            }
        }
    }
    return 0;

}


//  slowsort
void slowsort(record  nums[], int len) {
    if (len <= 1) return;
    slowsort(nums + 1, len - 1);  // If nums is {32, 23, 11} (so len == 3) we will sort nums+1: {23, 11}
    // which give {11, 23}. So the original array nums is now {32, 11, 23}
    comps++;
    //cout << comps << endl;
    if (nums[0].key > nums[1].key) // since 32 >  11 
        swap(nums[0], nums[1]);    // we do the swap, which gives {11, 32, 23}
    slowsort(nums + 1, len - 1);  // After this recursive call the subarray {32,23} will end up as {23, 32}
    // So the whole array is now {11, 23, 32}
}
unsigned long long int sort0(record  nums[], int len) {
    comps = 0;
    slowsort(nums, len);
    return comps;
}

// Optimized Slowsort 
// Avoids second recursive call when nums[0].key <= nums[1].key after first call.
void optimizedSlowsort(record  nums[], int len) {
    if (len <= 1) return;
    optimizedSlowsort(nums + 1, len - 1);
    counter++;
    comps++;
    if (nums[0].key > nums[1].key) {
        record temp = nums[0];
        nums[0] = nums[1];
        nums[1] = temp;
        //swap(nums[0], nums[1]);
        optimizedSlowsort(nums + 1, len - 1);
    }
    return;
}
unsigned long long int sort1(record  nums[], int len) {
    comps = 0;
    optimizedSlowsort(nums, len);
    return comps;
}

// bubble sort 
void bubbleSort(record* nums, int n) {
    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++) {
            comps++;
            if (nums[j].key > nums[j + 1].key) {
                record temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
}
unsigned long long int sort2(record* nums, int len) {
    comps = 0;
    bubbleSort(nums, len);
    return comps;
}














// bubble sort  "optimized"
unsigned long long int  sort3(record* nums, int len) {
    comps = 0;
    for (int i = len - 1; i > 0; i--) {
        bool didSwap = false;
        for (int j = 0; j < i; j++) {
            comps++;
            if (nums[j].key > nums[j + 1].key) {
                swap(nums[j], nums[j + 1]);
                didSwap = true;
            }
        }
        if (!didSwap) return comps;
    }
    return comps;
}

/*
void moveBiggestToEnd(record* nums, int len) {
    for (int j = 0; j < len - 1; j++) {
        comps++;
        if (nums[j].key > nums[j + 1].key) {
            record temp = nums[j];
            nums[j] = nums[j + 1];
            nums[j + 1] = temp;
        }
    }
}














void  bubbleSortRecursive(record* nums, int len) {
    if (len <= 1) return;
    moveBiggestToEnd(nums, len);
    bubbleSortRecursive(nums, len - 1);
}

// recursive version of bubblesort
unsigned long long int  sort4(record a[], int len) {
    comps = 0;
    bubbleSortRecursive(a, len);
    return comps;
}


*/


// Alternate versions of selectionsort
/*
void getIndexOfSmallest(record nums[], int length, int startingIndex, int& iSmallest)
{
    iSmallest = startingIndex;
    for (int i = startingIndex + 1; i < length; i++)
    {
        comps++;
        if (nums[i].key < nums[iSmallest].key) {
            iSmallest = i;
        }
    }
}

unsigned long long int sort5(record nums[], int length) {
    comps = 0;
    for (int i = 0; i < length - 1; i++)
    {
        int iS;
        getIndexOfSmallest(nums, length, i, iS);
        swap(nums[iS], nums[i]);
    }
    return comps;
}
*/


// selection sort (this is a minsort)
unsigned long long int sort4(record  nums[], int len) {
    comps = 0;
    for (int start = 0; start < len; start++) {
        int minIndex = start;
        for (int i = start + 1; i < len; i++) {
            comps++;
            if (nums[minIndex].key > nums[i].key)
                minIndex = i;
        }
        swap(nums[start], nums[minIndex]);
    }
    return comps;
}


// insertion sort
unsigned long long int  sort5(record nums[], int length) {
    comps = 0;
    for (int i = 1; i < length; i++) {
        record toInsert = nums[i];
        int j;
        for (j = i; j > 0 && ++comps && nums[j - 1].key > toInsert.key; j--)
            nums[j] = nums[j - 1];
        nums[j] = toInsert;
    }
    return comps;
}

// helper for mergeSort1
record* merge(record* p1, int length1, record* p2, int length2, record* buff) {

    for (int i = 0, j = 0, k = 0; k < length1 + length2;) {
        if (i < length1 &&
            (j >= length2 || ++comps && p1[i].key < p2[j].key))
            buff[k++] = p1[i++];
        if (j < length2 &&
            (i >= length1 || ++comps && p2[j].key <= p1[i].key))
            buff[k++] = p2[j++];
    }
    return buff;
}

// helper for sort7 (mergesort)
void mergeSort1(record* first, record* last, record* buff) {
    if (first >= last) return;
    int length = (int)(last - first + 1), len1 = (int)(length / 2);
    mergeSort1(first, first + len1 - 1, buff);
    mergeSort1(first + len1, last, buff);
    merge(first, len1, first + len1, length - len1, buff);

    while (first <= last)
        *first++ = *buff++;  // copy back to original array
}


// mergesort
unsigned long long int sort6(record nums[], int length) {
    comps = 0;
    record* buff = new record[length];  // O(n) extra memory 
    mergeSort1(nums, nums + length - 1, buff);
    delete[] buff;
    return comps;
}



void fixheap(int a[], int left, int right) {
    int x = a[left], i, j;

    for (i = left, j = 2 * i + 1; j <= right; i = j, j = 2 * i + 1)
    {
        if (j < right && a[j + 1] > a[j]) j++;
        if (x > a[j])
            break;

        a[i] = a[j];

    }
    a[i] = x;
}

void heapSort(int  a[], int n) {
    if (n > 1) {
        // PHASE 1
        for (int left = n / 2 - 1; left >= 0; left--) {
            fixheap(a, left, n - 1);
        }

        // PHASE 2
        swap(a[0], a[n - 1]);
        for (int right = n - 2; right >= 1; right--) {
            fixheap(a, 0, right);
            swap(a[0], a[right]);
        }
    }
}



// same version as we'll study.
int partition(record a[], int low, int high)
{
    record x = a[low];
    bool highTurn = true;
    while (low < high)
    {
        // counter++;
        if (highTurn) {
            comps++;
            if (a[high].key >= x.key)
                high--;
            else
            {
                a[low++] = a[high];
                highTurn = false;
            }
        }
        else {
            comps++;
            if (a[low].key <= x.key)
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

void quickSort1(record nums[], int start, int end) {

    if (start >= end) return;
    int mid = partition(nums, start, end);
    quickSort1(nums, start, mid - 1);
    quickSort1(nums, mid + 1, end);
}

// quicksort
unsigned long long int  sort7(record  nums[], int len) {
    comps = 0;
    quickSort1(nums, 0, len - 1);
    return comps;
}



int comparisonCount = 0;

bool gt(long long int x, long long int y) {
    comps++;
    //comparisonCount++;
    return x > y;
}

bool gte(long long int x, long long int y) {
    comps++;
    //comparisonCount++;
    return x >= y;
}

void fixheap(record a[], int left, int right) {
    record x;

    x = a[left];

    int i, j;
    for (i = left, j = 2 * i + 1; j <= right; i = j, j = 2 * i + 1) {
        if (j < right && gt(a[j + 1].key, a[j].key)) j++;
        if (gte(x.key, a[j].key))
            break;

        a[i] = a[j];

    }
    a[i] = x;
}
void heapSort(record  a[], int n) {
    if (n > 1) {
        //  comparisonCount = 0;
        for (int left = n / 2 - 1; left >= 0; left--) {
            fixheap(a, left, n - 1);
            //print(a, n, 1);
        }
        //cout << "Phase 1: " << comparisonCount << endl;
        //print(a, n, 1);
        swap(a[0], a[n - 1]);
        //   comparisonCount = 0;
        for (int right = n - 2; right >= 1; right--) {
            fixheap(a, 0, right);
            //    cout << "Phase 2: " << comparisonCount << endl;
                //print(a, n, 1);

            swap(a[0], a[right]);
        }
        //  cout << "Phase 2: " << comparisonCount << endl;
    }
}
// heapsort
unsigned long long int  sort8(record a[], int len) {
    comps = 0;
    heapSort(a, len);
    return comps;
}

// radix sort
unsigned long long int  sort9(record* nums, int len) {
    //comps = 0;
    const int BASE = 10000;
    vector<record> bucket[BASE];

    unsigned long long int maxi = nums[0].key;
    for (int j = 1; j < len; j++) {
        //comps++;
        if (nums[j].key > maxi)        maxi = nums[j].key; // find maximum
    }

    int i;
    // iterate through each radix until n>maxi
    for (unsigned long long int n = 1; maxi >= n; n *= BASE) {
        // sort list of numbers into buckets
        for (i = 0; i < len; i++) {
            // comps++;
            bucket[(nums[i].key / n) % BASE].push_back(nums[i]);
        }

        // merge buckets back to list
        for (int k = i = 0; i < BASE; bucket[i++].clear())
            for (vector<record>::iterator j = bucket[i].begin(); j != bucket[i].end(); nums[k++] = *(j++));
    }

    return comps;
    // 
}
void print(record nums[], int len, bool newLine) {
    if (newLine) cout << endl;
    for (int i = 0; i < len; i++)
        cout << nums[i].key << " ";
    cout << endl << endl;
}

unsigned long long int random10(int powOf10) {
    if (powOf10 > 13) {
        cout << "Limit is 10^13" << endl;
        powOf10 = 13;
    }
    unsigned long long int num = 0;
    while (powOf10-- > 0)
        num = num * 10 + rand() % 10;
    return num;
}

// to fill the array with values, ascending, descending, random or shuffled
void fill(record nums[], int len, char orderCode) {
    int digits = int(log10(len + 0.5)); // will give # of digits in len 
    for (int i = 0; i < len; i++) {
        if (orderCode == 'a' || orderCode == 's') nums[i].key = i + 1;

        else if (orderCode == 'd') nums[i].key = len - i;
        else if (orderCode == 'z') {
            if (i % 2 == 0)
                nums[i].key = len - i / 2;
            else nums[i].key = (i + 1) / 2;
        }
        else {
            nums[i].key = random10(digits + 2);  // random
        }
    }
    if (orderCode == 's') { // close to ascending with a minimal shuffle
        for (int i = 0; i <= len / 12; i++) {
            int loc1 = random10(digits + 1);
            int loc2 = random10(digits + 1);
            swap(nums[loc1 % len], nums[loc2 % len]);
        }
    }
}

void copyTo(record from[], record to[], int len) {
    for (int i = 0; i < len; i++)
        to[i] = from[i];
}

double timeIt(unsigned long long int (*sort)(record[], int), int size, int loops, bool printIt, int ocode,
    unsigned long long int& compares)
{
    int minCounter = 100000;
    unsigned int tfine = 0;
    compares = 0;
    for (int i = 0; i < loops; i++) {
        fill(buf1, size, ocode);   // we don't count this in the time
        copyTo(buf1, buf2, size); // nor this
        if (printIt) print(buf1, size, true);
        unsigned int clockStart = clock();

        //counter = 0;
        compares += sort(buf2, size);
        // if (counter < minCounter) minCounter = counter;
        tfine += clock() - clockStart;
        if (printIt) print(buf2, size, false);

    }
    //  cout << "Min Counter = " << minCounter << endl;
    return   (int)(tfine * 1000.0 / CLOCKS_PER_SEC + 0.5001);  // elapsed time in milliseconds
}
