#include <iostream>
#include <stdlib.h>
using namespace std;
// Simulates a coin toss where "Bob" bets 50% of his cash on hand on each tosses.
// If the number of dollars is odd, he would bet the smallest integer larger
// than 50% (ex. with 15$, he would make an 8$ bet). If the coin lands heads,
// he wins and doubles the money he bet. Otherwise, he loses the amount he bet.

struct gameResultType{
  unsigned int numToss; // the number of coin tosses until either Bob reaches
                        // or exceeds target dollars on hand, or his cash hits 0
  unsigned int amount;  // the dollar value Bob has on hand at the end of the game
};

gameResultType coinToss(unsigned int initial, unsigned int target) {
  // initial is the number of dollars that Bob has on hand at the start of the game
  // target is the monetary goal expressed in dollars that Bob wants to reach
  int tosses = 0;
  gameResultType a;
  while (initial > 0 && initial < target) {
    int res = rand();
    if (res % 2 == 0) {
      cout << "even" << endl;
      // represents heads which means he won the bet
      initial *= 2;
      cout << initial << endl;
    } else {
      cout << "odd" << endl;
      if (initial % 2 != 0) {
        initial--;
      }
      initial = initial/2;
      cout << initial << endl;
    }
    tosses++;
  }
  a.numToss = tosses;
  a.amount = initial;
  return a;
}

int main() {
  gameResultType y;
  y = coinToss(50, 150);
  cout << y.numToss << endl;
  cout << y.amount << endl;
}
