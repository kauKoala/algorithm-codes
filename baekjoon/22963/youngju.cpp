#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> arr(n,0);
  vector<int> arr2;
  
  for(int i=0; i<n; i++)
    cin>> arr[i];
  arr2 = arr;
  vector<pair<int, int> > ans;
  vector<pair<int, int> > ans2;

  for(int i=0; i<n; i++){
    // 가능하다면 현재 값을 줄여보기. 
    if( i != n-1 && arr[i+1]<arr[i]){
      if(i ==0){
        arr[i] = 1;
        ans.push_back({i+1, arr[i]});
      }else{
        if(arr[i-1]<=arr[i+1]){
          arr[i] = arr[i-1];
          ans.push_back({i+1, arr[i]});
        }
        // 바꾸지 못했다면 현재 값을 늘리는 방향으로.
      }
    }
    // 현재값을 줄이는 것이 안된다면 현재 값을 늘리기.
    if(i !=0 && arr[i]< arr[i-1]){
      arr[i] = arr[i-1];
      ans.push_back({i+1, arr[i]});
    }
    if(ans.size()>3){
        break;
    }
  }
  for(int i=n-1; i>=0; i--){
    // 자신을 늘려본다.
    if(i != 0  && arr2[i] < arr2[i-1]){
      if(i== n-1){
        arr2[i] = 1000000000;
        ans2.push_back({i+1, arr2[i]});
      }else{
        if( arr2[i+1]>= arr2[i-1]){
          arr2[i] = arr2[i+1];
          ans2.push_back({i+1, arr2[i]});
        }
      }
    }
    // 자신을 줄인다.
    if(i != n-1 && arr2[i]> arr2[i+1]){
      arr2[i] = arr2[i+1];
      ans2.push_back({i+1, arr2[i]});
    }
    if(ans2.size()>3){
      break;
    }
  }
  if(ans.size()>3 && ans2.size()>3){
    cout << "NO"<<endl;
  }else{
    if(ans.size()<=3){
      cout <<"YES"<<endl;
      cout <<ans.size()<<endl;
      for(int i=0; i<ans.size(); i++){
        cout << ans[i].first <<" "<<ans[i].second<<endl;
      }
    }else if( ans2.size() <=3){
      cout <<"YES"<<endl;
      cout <<ans2.size()<<endl;
      for(int i=0; i<ans2.size(); i++){
        cout << ans2[i].first <<" "<<ans2[i].second<<endl;
      }

    }
  }
  return 0;
}