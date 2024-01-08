/*C/C++ program to find the ith minimum element from a given unsorted array
A[p · · · r] based on the following Divide-and-Conquer paradigms:
1. using randomised select
2. deterministic select */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int partition1(vector<int> &v, int left, int right, int pivot);
int deterministic_select(vector<int> &v, int low, int high, int k);
int medianOfMedians(vector<int> &v, int low, int high);
int randomised_select(vector<int> &v, int low, int high, int k);
int random_partition(vector<int> &v, int low, int high);

int main()
{
    // vector<int> arr = {56, 1, 4, 2, 5, 6, 8, 7};
    // int k = 3;

    // int result = randomised_select(arr, 0, arr.size() - 1, k - 1);
    // cout << "The " << k << "th smallest element is " << result << endl;
    int n,a,k,x,res;
    cout<<"enter size of array: ";
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    cout<<"Enter kth minimum element you want to search: ";
    cin>>k;
    do{

        cout<<"1. using randomised select \n";
        cout<<"2. deterministic select \n";
        cout<<"enter your option: ";
        cin>>x;
        switch(x){
            case 1: res=randomised_select(v,0,n-1,k);
                    cout<<res<<endl;
                    break;
            case 2: res=deterministic_select(v,0,n-1,k-1);
                    cout<<res<<endl;
                    break;
        }
    }while(x<=2);

    return 0;
}

int partition1(vector<int> &v, int left, int right, int pivot)
{
    int i = left;
    for (int j = left; j < right; j++)
    {
        if (v[j] < pivot)
        {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[right]);
    return i;
}

int medianOfMedians(vector<int> &v, int low, int high)
{
    vector<int>median;
    int i = low;
    for (; i <= high; i += 5)
    {
        sort(v.begin() + i, v.begin() + min(i + 5, high + 1));
        median.push_back(v[i + (min(i + 5, high + 1) - i) / 2]);
    }
    if ((high - low + 1) % 5 != 0)
    {
        i -= 5;
        sort(v.begin() + i, v.begin() + high + 1);
        median.push_back(v[i + (high - i) / 2]);
    }
    return deterministic_select(median, 0, median.size() - 1, median.size() / 2);
}

int deterministic_select(vector<int> &v, int low, int high, int k)
{
    if (high - low + 1 <= 6)
    {
        sort(v.begin(), v.end());
        return v[k];
    }

    int pivot = medianOfMedians(v, 0, v.size() - 1);
    int position = partition1(v, 0, v.size() - 1, pivot);
    if (k == position)
        return v[position];
    else if (k < position)
    {
        return deterministic_select(v, 0, position - 1, k);
    }
    else
    {
        return deterministic_select(v, position + 1, high, k - position - 1);
    }
}

int random_partition(vector<int> &arr, int low, int high)
{
    int pivot_index = low + rand() % (high - low + 1);
    int pivot = arr[pivot_index];

    swap(arr[pivot_index], arr[high]);

    int i = low;
    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            ++i;
        }
    }
    swap(arr[i], arr[high]);

    return i;
}

int randomised_select(vector<int> &arr, int low, int high, int k)
{
    if (low == high)
    {
        return arr[low];
    }

    int pivot_index = random_partition(arr, low, high);
    int pivot_rank = pivot_index - low + 1;

    if (k == pivot_rank)
    {
        return arr[pivot_index];
    }
    else if (k < pivot_rank)
    {
        return randomised_select(arr, low, pivot_index - 1, k);
    }
    else
    {
        return randomised_select(arr, pivot_index + 1, high, k - pivot_rank);
    }
}
