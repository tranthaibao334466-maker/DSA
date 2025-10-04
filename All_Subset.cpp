// List all the subset of a given set

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    private:
        vector<int> temp;
        vector<vector<int>> V;
    public:
        void Subset(int i,vector <int> nums)
        {
            V.push_back(temp); // Using this syntax to include the empty subset 
            for(int j=i;j<nums.size(); j++)
            {
                temp.push_back(nums[j]);
                Subset(j+1,nums);
                temp.pop_back();

                // using push and pop like this to utilize the power of recursion, especially backtracking
            }
        }
        void Display();
};

void Solution :: Display()
{
    for(int i=0;i<V.size(); i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    int val;
    vector<int>nums;
    cout << "Enter the volumn of the set: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout << "Enter the " << i+1 << " element in the set: ";
        cin >> val;
        nums.push_back(val);
    }
    Solution S;
    S.Subset(0,nums);
    S.Display();
}