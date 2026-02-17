// Binary Search on Answer
// Find maximum x such that good(x) == true

bool good(long long x) {
    // problem-specific condition
    return true;
}

long long binarySearchOnAnswer(long long lo, long long hi) {
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (good(mid))
            lo = mid + 1;   // try bigger
        else
            hi = mid - 1;   // reduce
    }
    return hi;  // maximum feasible value
}
