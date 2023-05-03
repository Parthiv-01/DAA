#include <iostream>
using namespace std;

int countCombinations(int change, int coinIndex, int coins[]) {
    if (change == 0) {
        return 1;
    }
    if (change < 0 || coinIndex < 0) {
        return 0;
    }
    int count = 0;
    count += countCombinations(change - coins[coinIndex], coinIndex, coins);
    count += countCombinations(change, coinIndex - 1, coins);
    return count;
}

int main() {
    int coins[] = {1, 1, 1, 1, 2, 2, 5, 5, 10, 10, 20};
    int numCoins = sizeof(coins) / sizeof(int);
    int change = (50-17);
    int combinations = countCombinations(change, numCoins - 1, coins);
    cout << "Number of possible combinations: " << combinations << endl;
    return 0;
}
