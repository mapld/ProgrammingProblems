#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      map<int,int> searchTree;

      int ALPHABET_LENGTH = 26;

      int curLocation = 0;
      int topLocation = 0;

      int wordSize = words[0].size();

      vector<int> dups = vector<int>(words.size(),1);

      for(int i = 0; i < words.size(); i++){
        string word = words[i];
        curLocation = 0;
        for(int j = 0; j < word.size(); j++){
          int cur = (int)(word[j] - 'a');
          // cout << "    cur: " << cur << ", loc: " << curLocation;
          int searchLocation = curLocation + cur;
          if(searchTree.find(searchLocation) == searchTree.end()){
            if(j == word.size()-1){
              searchTree[searchLocation] = i;
            }
            else{
              topLocation = topLocation + ALPHABET_LENGTH;
              searchTree[searchLocation] = topLocation;
              curLocation = topLocation;
            }
          }
          else{
            if(j == word.size()-1){
              dups[searchTree[searchLocation]]++;
              // cout << " dup: " << i << "loc: " << searchTree[searchLocation];
            }
            curLocation = searchTree[searchLocation];
          }
        }
      }

      vector<int> results;

      int markedCount = 0;
      map<int,int> marked;

      int head = 0;
      int wordHead = 0;
      int search = 0;
      int searchTreeBase = 0;
      while(search < s.size()){
        int c = (int)(s[search] - 'a');
        int location = searchTreeBase + c;
        // cout << "   search: "  << search;
        if(searchTree.find(location) == searchTree.end()){
          // cout << "NN";
          marked.clear();
          markedCount = 0;
          head++;
          wordHead = head;
          search = head;
          searchTreeBase = 0;
        }
        else{
          // found character
          if(search-wordHead+1 == wordSize){
            // found word
            int wordFound = searchTree[location];
            if(marked.find(wordFound) == marked.end() || marked[wordFound] < dups[wordFound]){
              // cout << " FOUND WORD ";
              if(marked.find(wordFound) != marked.end()){
                // cout << "(duplicate)" << ", dups: " << dups[wordFound] << "wf: " << wordFound;
                marked[wordFound]++;
              }
              else{
                marked[wordFound] = 1;
              }
              markedCount++;
              search++;
              wordHead = search;
              searchTreeBase = 0;

              if(markedCount == words.size()){
                // cout << " FOUND WHOLE ";
                results.push_back(head);
                head++;
                search = head;
                wordHead = head;
                marked.clear();
                markedCount = 0;
                searchTreeBase = 0;
              }
            }
            else{
              // cout << " FAIL "; //<< marked[wordFound] << ", dups: " << dups[wordFound] << "wf: " << wordFound;
              marked.clear();
              markedCount = 0;
              head++;
              wordHead = head;
              search = head;
              searchTreeBase = 0;
            }
          }
          else{
            searchTreeBase = searchTree[location];
            search++;
          }
        }
      }
      return results;
    }
};
