#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main(){
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    sort(v.begin(),v.end());
    long long count = 0;

    for(int i = 0; i < v.size(); i++){
		if( v[i] > 0 ){
			break;
		}
        for(int j = v.size()-1; j > i; j--){
			if( v[j] < 0 ){
				break;
			}
            int find_val = -(v[i]+v[j]);

            int left = distance(v.begin(), lower_bound(v.begin()+i+1,v.begin()+j,find_val));
            int right = distance(v.begin(), upper_bound(v.begin()+i+1,v.begin()+j,find_val));
            count += right - left;
        }
    }
    cout << count;
}