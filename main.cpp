#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int numbers[9] = {1,2,3,4,5,6,7,8,9},
        player1[5] = {},
        player2[5] = {},
        players[5] = {};
    int A = 0,
            number = 0,
            counter = 0,
            index = 0,
            len = 0,
            checker1 = 0,
           checker2 = 0,
            * s  = 0;
    bool over = false,
    draw = false;
    while (true) {
        for (int player = 1; player<3; player++) {
            for(int x = 0; x < 9; x++ ) {
                cout << "[ " << numbers[x] << " ]";
            }
            cout << "" <<endl;
            cout << "Player " << player << " : ";
            cin >> number;
            cout << "" << endl;
            index = counter / 2;
            if (player == 1) {
                player1[index] = number;
                for(int i = 0; i<5; i++){
                    players[i] = player1[i];
                }

            } else {

                player2[index] = number;
                for(int i = 0; i<5; i++){
                    players[i] = player2[i];
                }

            }
            //check rounds
            if (counter % 2 == 0) {
                len += 1;
            }
            int sum = 0;
            for (int i = 0; i<5; i++) {
                sum += players[i];
            }
            if (len == 3) {
                if (sum == 15) {
                    over = true;
                }
            }

            checker1 = sum - 15;
            // 9 4 2 1
             // checker 1 == 16 - 1 ==1
            if (len == 4) {
                s = find(players, players+5, checker1);
                if (s != players+5) {
                    over = true;
                }

            }

            if (len == 5) {
                for (int i = 0; i<5; i++) {
                    checker2 = checker1 - players[i];
                    s = find(players, players+5, checker2);
                    if (s != players+5 && checker2 != players[i]) {
                        over = true;
                        break;
                    }
                }

            }
            if (over && player == 1) {
                cout << "Player1 is the winner ";
                break;
            }
            else if (over && player == 2) {
                cout << "Player2  is the winner ";
                break;
            }


            else {
                numbers[number-1] = 0;
            }

            if (A == 4) {
                draw = true;
                break;
            }

            counter += 1;
        }

        A += 1;
        if (over || draw) {
            break;
        }
    }

    if (draw) {
        cout << "Draw" << endl;
    }
}
