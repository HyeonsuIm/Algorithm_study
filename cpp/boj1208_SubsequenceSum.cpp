    #include <iostream>
    #include <vector>
    #include <unordered_map>

    using namespace std;

    void MakeSumResult(
        const vector<int>& val,
        int current,
        int depth,
        int sum,
        unordered_map<int,int>& result)
    {
        if( current > depth )
        {
            result[sum] += 1;
        }
        else
        {
            MakeSumResult(val, current+1,depth,sum,result);
            MakeSumResult(val, current+1,depth,sum+val[current],result);
        }
    }

    int main()
    {
        int N, S;
        cin >> N >> S;

        vector<int> val(N);
        for(int i=0;i<N;i++)
        {
            cin >> val[i];
        }

        unordered_map<int,int> sumResultLeft;
        unordered_map<int,int> sumResultRight;
        int mid = N/2;
        MakeSumResult(val, 0, mid, 0, sumResultLeft);
        MakeSumResult(val, mid+1, N-1, 0, sumResultRight);

        long long result = 0;
        for(const pair<int,int>& leftResult : sumResultLeft)
        {
            result+=static_cast<long long>(leftResult.second) * static_cast<long long>(sumResultRight[S-(leftResult.first)]);
        }

        if( S == 0)
        {
            result -= 1;    
        }
        cout << result;
        return 0;
    }