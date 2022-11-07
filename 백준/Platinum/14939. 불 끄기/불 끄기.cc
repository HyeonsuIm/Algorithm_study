#include <iostream>
#include <vector>
using namespace std;

#define SIZE 10
int dx[5] = {0,0,1,-1, 0};
int dy[5] = {1,-1,0,0, 0};
int minimum;

void TurnOn(vector<string>& map, int j, int i)
{
	for(int temp=0;temp<5;temp++)
	{
		int x = i+dx[temp];
		int y = j+dy[temp];
		if(y >= 0 && y<SIZE && x >= 0 && x < SIZE)
		{
			if( map[y][x] == '#' ) map[y][x]='O';
			else map[y][x] = '#';
		}
	}
}

void CheckBestCases(vector<string>& map, int which, int j, int i, int count)
{
	if( count >= minimum )
	{
		return;
	}
	if( j == SIZE || j == -1)
	{
		bool isTurnOff = true;
		for(int x=0;x<SIZE && isTurnOff;x++)
		{
			for(int y=0;y<SIZE && isTurnOff;y++)
			{
				if( map[y][x] == 'O' )
				{
					isTurnOff = false;
				}
			}
		}
		if( isTurnOff == true ) minimum = min(minimum, count);
		return;
	}
	int nextI = i+1;
	int nextJ = j;
	if(i == SIZE-1)
	{
		nextI = 0;
		nextJ = j+which;
	}

	if( j == 0)
	{
		CheckBestCases(map, which, nextJ, nextI, count);
		TurnOn(map,j,i);
		CheckBestCases(map, which, nextJ, nextI, count+1);
		TurnOn(map,j,i);
	}
	else
	{
		if(map[j-which][i] == 'O')
		{
			TurnOn(map,j,i);
			CheckBestCases(map, which, nextJ, nextI, count+1);
			TurnOn(map,j,i);
		}
		else
		{
			CheckBestCases(map, which, nextJ, nextI, count);
		}
	}
}

int main()
{
	vector<string> map(SIZE);
	for(int i=0;i<SIZE;i++)
	{
		cin >> map[i];
	}
	minimum = 0x7fffffff;
	CheckBestCases(map, 1, 0, 0, 0);
	cout << minimum << endl;
}