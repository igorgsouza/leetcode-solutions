class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        vector<long long> possible;
        possible = get_possible_sums(nums);
        sort(possible.begin(), possible.end(), greater<long long>());
        for(int i = 0; i < possible.size(); i++)
            cout << possible[i] << " ";
        return possible[k-1];
    }

    vector<long long> get_possible_sums(vector<int>& nums)
    {
        vector<long long> possible;
        long long size = nums.size();
        for(long long pivot = 0; pivot < size; pivot++)
        {
            //cout << "pivot: " << pivot<< endl; 
            for(long long count = 0; count < size - pivot; count++)
            {
                //cout << "count: " << count<< endl; 
                for(long long add_pivot = pivot+1; add_pivot <= size - count; add_pivot++)
                {
                    //cout << "add_pivot: " << add_pivot<< endl; 
                    vector<int> subsequence;
                    subsequence.push_back(nums[pivot]);
                    for(long long iterator = 0; iterator < count; iterator++)
                    {
                        //cout << "iterator: " << iterator << endl; 
                        subsequence.push_back(nums[add_pivot + iterator]);
                    }
                    for(int i = 0; i < subsequence.size(); ++i)
                    {
                        cout<<subsequence[i] << " ";
                    }
                    cout << "=" <<get_sum(subsequence);
                    cout << endl;

                    possible.push_back(get_sum(subsequence));
                    if(count == 0)
                        break;
                }
            }
        }
        possible.push_back(0);
        return possible;
    }

    long long get_sum(const vector<int>& nums)
    {
        long long sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
        }
        return sum;
    }
};