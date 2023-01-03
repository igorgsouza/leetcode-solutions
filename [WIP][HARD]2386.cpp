//RUNTIME n/a
//MEMORY n/a
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
        bool* selection = new bool[nums.size()]();
        vector<long long> possible;
        long long significant = 0;
        while(significant < nums.size())
        {
            vector<int> subsequence;
            for(int i = 0; i <= significant; i++)
            {
                if(*(selection + i))
                    subsequence.push_back(nums[i]);
            }
            possible.push_back(get_sum(subsequence));
            ///

            for(int i = 0; i <= significant; ++i)
            {
                cout << *(selection + i);
            }       
            cout << endl;     

            ///
            for(int i = 0; i <= significant; ++i)
            {
                if(!*(selection + i))
                {
                    *(selection + i) = true;
                    break;
                }
                *(selection + i) = false;
            }
            if(!*(selection + significant))
            {
                significant++;
                if(significant < nums.size())
                    *(selection + significant) = true;
            }
        }
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