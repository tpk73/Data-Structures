#include <iostream>
#include <fstream>
#include "p2queue.h"
using namespace std;

int main()
{
    Queue<int> p1Hand; 
    Queue<int> p2Hand;
    Queue<int> p1Tie;
    Queue<int> p2Tie;
    initialize(p1Hand);
    initialize(p2Hand);
    initialize(p1Tie);
    initialize(p2Tie);

    int p1Card, p2Card;
    int roundNum = 0; 
    string deck; 
    ifstream finP1, finP2;

    finP1.open("player1");
    finP2.open("player2");

    while(finP1 >> deck) {

        if(deck == "J")
            push(p1Hand, 11);
        else if(deck == "Q")
            push(p1Hand, 12);
        else if(deck == "K")
            push(p1Hand, 13);
        else if(deck == "A")
            push(p1Hand, 14);
        else
            push(p1Hand, stoi(deck));
    }
    while(finP2 >> deck) {

        if(deck == "J")
            push(p2Hand, 11);
        else if(deck == "Q")
            push(p2Hand, 12);
        else if(deck == "K")
            push(p2Hand, 13);
        else if(deck == "A")
            push(p2Hand, 14);
        else
            push(p2Hand, stoi(deck));
    }

    while(!isEmpty(p1Hand)&&!isEmpty(p2Hand) && roundNum<=5000) {

        p1Card = pop(p1Hand); 
        p2Card = pop(p2Hand);

        if(p1Card>p2Card) {
            if(!isEmpty(p1Tie)) {
                while(!isEmpty(p1Tie)) {
                    push(p1Hand, pop(p1Tie));
                }

                push(p1Hand, p1Card);

                while(!isEmpty(p2Tie)) {
                    push(p1Hand, pop(p2Tie));
                }

                push(p1Hand, p2Card);
            }
            else {
            push(p1Hand, p1Card);
            push(p1Hand, p2Card);
            }
        }
        if(p2Card>p1Card) {
            if(!isEmpty(p2Tie)) {
                while(!isEmpty(p2Tie)) {
                    push(p2Hand, pop(p2Tie));
                }

                push(p2Hand, p2Card);

                while(!isEmpty(p1Tie)) {
                    push(p2Hand, pop(p1Tie));
                }

                push(p2Hand, p1Card);
            }
            else {
                push(p2Hand, p2Card);
                push(p2Hand, p1Card);
            }
        }
        if(p1Card == p2Card) {

            push(p1Tie, p1Card);
            push(p2Tie, p2Card);

            for(int i=0; i<3; i++) {

                if(!isEmpty(p1Hand)) {

                    p1Card = pop(p1Hand);
                    push(p1Tie, p1Card);
                }
                if(!isEmpty(p2Hand)) {

                    p2Card = pop(p2Hand);
                    push(p2Tie, p2Card);
                }
            }
        }
        roundNum++;
    }

    if(isEmpty(p1Hand))
    cout << "Player #2 wins after " << roundNum << " battles.";
    else if(isEmpty(p2Hand))
    cout << "Player #1 wins after " << roundNum << " battles.";
    else
    cout << "Nobody wins.";
}
