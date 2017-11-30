#include <iostream>
#include <vector>

using namespace std;

struct Prize{
  int cash;
  int numStickers;
  vector<int> stickers;
};

int main(){
  int testCases;
  cin >> testCases;
  for(int t=0;t<testCases;t++){
    int n;
    int m;
    cin >> n;
    cin >> m;

    vector<Prize> prizes;
    for(int i = 0;i< n; i++){
      int numStickers;
      cin >> numStickers;
      Prize prize;
      prize.numStickers = numStickers;
      for(int j = 0; j< numStickers; j++){
        int sticker;
        cin >> sticker;
        prize.stickers.push_back(sticker);
      }
      cin >> prize.cash;
      prizes.push_back(prize);
    }

    vector<int> stickerCounts;
    for(int i =0;i<m;i++){
      int sticker;
      cin >> sticker;
      stickerCounts.push_back(sticker);
    }

    int totalCash = 0;
    for(int i = 0;i< n; i++){
      Prize prize = prizes[i];
      bool givePrize = true;
      vector<int> stickerCountsCopy = stickerCounts;
      while(givePrize == true){
        for(int j=0;j<prize.numStickers;j++){
          int sticker = prize.stickers[j];
          // cout << "sticker: " << sticker << "\n";
          // cout << "total: " << totalCash << "\n";
          stickerCountsCopy[sticker-1] -= 1;
          if(stickerCountsCopy[sticker-1] < 0){
            givePrize = false;
            break;
          }
        }
        if(givePrize){
          totalCash += prize.cash;
        }
      }
    }

    cout << totalCash << "\n";

  }
}
