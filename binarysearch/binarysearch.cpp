#include <iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r > l)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == x)
            return 1;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return 0;
}

int upper_bound(int arr[], int l, int r, int x)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (arr[m] > x)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int lower_bound(int arr[], int l, int r, int x)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (arr[m] >= x)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a[300500];
    int n, c, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> x;
        cout << binarySearch(a, 0, n, x) << " " << lower_bound(a, 0, n, x) << " " << upper_bound(a, 0, n, x) << '\n';
    }
}