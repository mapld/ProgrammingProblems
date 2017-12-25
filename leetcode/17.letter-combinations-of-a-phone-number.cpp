#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {

public:
    vector<string> letterCombinations(string digits) {
      vector<string> results;
      results.push_back("");
      for(int i = 0; i < digits.size(); i++){
        char dig = digits[i];
        vector<string> newResults;
        int resultStepSize = results.size();
        for(int j = 0; j < resultStepSize; j++){
          string cur = results[j];
          if(dig == '2'){
            newResults.push_back(cur+'a');
            newResults.push_back(cur+'b');
            newResults.push_back(cur+'c');
          }
          else if(dig == '3'){
            newResults.push_back(cur+'d');
            newResults.push_back(cur+'e');
            newResults.push_back(cur+'f');
          }
          else if(dig == '4'){
            newResults.push_back(cur+'g');
            newResults.push_back(cur+'h');
            newResults.push_back(cur+'i');
          }
          else if(dig == '5'){
            newResults.push_back(cur+'j');
            newResults.push_back(cur+'k');
            newResults.push_back(cur+'l');
          }
          else if(dig == '6'){
            newResults.push_back(cur+'m');
            newResults.push_back(cur+'n');
            newResults.push_back(cur+'o');
          }
          else if(dig == '7'){
            newResults.push_back(cur+'p');
            newResults.push_back(cur+'q');
            newResults.push_back(cur+'r');
            newResults.push_back(cur+'s');
          }
          else if(dig == '8'){
            newResults.push_back(cur+'t');
            newResults.push_back(cur+'u');
            newResults.push_back(cur+'v');
          }
          else if(dig == '9'){
            newResults.push_back(cur+'w');
            newResults.push_back(cur+'x');
            newResults.push_back(cur+'y');
            newResults.push_back(cur+'z');
          }
          else{
            vector<string> empt;
            return empt;
          }
        }
        results = newResults;
      }
      if(results.size() == 1){
        vector<string> empt;
        return empt;
      }
      return results;
    }
};
