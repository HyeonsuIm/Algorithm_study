#include <iostream>
#include <vector>

using namespace std;

int N;

vector<vector<int>> multiple(vector<vector<int>>& val, vector<vector<int>>& val2)
{
    vector<vector<int>> result(N);
    for(int i=0;i<N;i++)
    {
        result[i].assign(N, 0);
    }
    for(int x=0;x<N;x++)
    {
        for(int y=0;y<N;y++)
        {
            for(int z=0;z<N;z++)
            {
                result[y][x] += val[y][z] * val2[z][x];
            }
            result[y][x] %= 1000;
        }
    }
    return result;
}

vector<vector<int>> multiply(vector<vector<int>>& val, long long multi)
{
    if(multi == 1)
    {
        vector<vector<int>> temp = val;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                temp[i][j] %= 1000;
            }
        }
        return temp;
    }
    else
    {
        vector<vector<int>> temp = multiply(val, multi/2);
        temp = multiple(temp, temp);
        if(multi %2 == 1)
        {
            temp = multiple(temp, val);
        }
        return temp;
    }
}

int main()
{
    long long B;
    vector<vector<int>> matrix;
    cin >> N >> B;
    matrix.resize(N);
    for(int i=0;i<N;i++)
    {
        matrix[i].resize(N);
        for(int j=0;j<N;j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> result = multiply(matrix, B);
    for(int y=0;y<N;y++)
    {
        for(int x=0;x<N;x++)
        {
            cout << result[y][x] << " ";
        }
        cout << endl;
    }
}