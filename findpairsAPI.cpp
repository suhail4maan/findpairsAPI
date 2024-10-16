#include <bits/stdc++.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std; 

vector<vector<int>> findPairs(vector<int> numbers , int target){

      vector<vector<int> ans;
      unordered_map<int , int> map;
       
       for(int i=0 ; i<numbers.size() ; i++){
            int temp=target - numbers[i];
            if(m.find(temp) != m.end()){
                ans.push_back({map[temp] , i});  
            }
            map[temp[i]]=i;
       }
       return ans;
}
int main()
{
 json requestData = R"({
        "numbers": [1, 2, 3, 4, 5],
        "target": 6
    })"_json;
 if (!requestData.contains("numbers") || !requestData.contains("target")) {
        cout << "wrong input  " << endl;
        return 1;
    }
    vector<int> numbers = requestData["numbers"].get<vector<int>>();
    int target = requestData["target"];
    vector<vector<int>> solutions = findPairs(numbers, target);
    requestData["solutions"] = solutions;

    cout<<requestData.solutions<<endl;
}