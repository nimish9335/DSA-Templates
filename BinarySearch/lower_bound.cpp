// Lower Bound
// Returns first index i such that a[i] >= x
// If all elements < x, returns n

int lowerBound(vector<int>& a, int x) {
    int l = 0, r = a.size();   // [l, r)
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
