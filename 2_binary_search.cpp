#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;
// the value of array must be sorted in order to apply binary search
// worst case element not found , best case element found in the middle

int BinarySearch(vector<int> &arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return BinarySearch(arr, l, mid - 1, x);

        return BinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void generate(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}
// best case number found in the first iteration in middle itself
void input_generator1(vector<pair<int, int>> &store)
{
    for (int i = 10; i <= 1e6; i *= 10)
    {
        vector<int> arr(i);
        generate(arr, i);

        // clock_t time_req ;
        int t = 0;
        for (int m = 1; m <= 10; m++)
        {
            // time_req = clock();
            auto start = high_resolution_clock::now();
            BinarySearch(arr, 0, i - 1, i / 2); // l and r and x
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);

            // time_req = clock() - time_req;
            t += duration.count();
        }
        t = (t / 10);
        store.push_back({t, i});
    }
}
// worst case :- number not found
void input_generator2(vector<pair<int, int>> &store)
{
    for (int i = 10; i <= 1e6; i *= 10)
    {
        vector<int> arr(i);
        generate(arr, i);

        clock_t time_req;
        int t = 0;
        for (int m = 1; m <= 10; m++)
        {
            time_req = clock();
            BinarySearch(arr, 0, i - 1, i + 1); // l and r and x
            time_req = clock() - time_req;
            t += (time_req);
        }
        t = (t / 10);
        store.push_back({t, i});
    }
}
int main()
{
    vector<pair<int, int>> store1;
    input_generator1(store1);

    cout << "Time taken\tNumber of Inputs " << endl;

    for (auto i : store1)
    {
        cout << i.first << "\t" << i.second << endl;
    }

    cout << endl
         << endl
         << "Worst case complexity " << endl
         << endl;

    vector<pair<int, int>> store2;
    input_generator2(store2);
    cout << "Time taken\tNumber of Inputs " << endl;
    for (auto i : store2)
    {
        cout << i.first << "\t" << i.second << endl;
    }
    return 0;
}