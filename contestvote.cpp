#include <iostream>
#include "p2map.h"
#include "p2priorityqueue.h"
#include <iomanip>

using namespace std;

int main()
{
    //set variables
    string firstFile, secondFile, phone, contestant;
    string names[1000];
    int x = 0, y = 0;
    float total = 0, vote = 0, answer = 0, final = 0;

    //name Input and Output files
    ifstream fin;
    ofstream fout;

    //setup Map
    Map<string, int> votes;
    initialize(votes);

    //setup PQ for Names
    PriorityQueue<string, float> Name;
    initialize(Name);

    //setup PQ to calculate percentages
    PriorityQueue<float, float> Percentage;
    initialize(Percentage);

    //user Input for firstFile
    cout << "Enter filename containing list of contestants: ";
    cin >> firstFile;

    //user Input for secondFile
    cout << "Enter filename containing list of votes: ";
    cin >> secondFile;

    //open firstFile
    fin.open(firstFile.c_str());

    //beggining #
    fin >> x;

    //reads line if theres a contestant
    while (fin >> contestant) {

        assign(votes, contestant, 0);
        names[y++] = contestant;
    }

    //close firstFile
    fin.close();

    //open secondFile
    fin.open(secondFile.c_str());

    //beggining #
    fin >> x;

    //read line if theres a contestant
    while (fin >> contestant) {

        //read the phone #
        fin >> phone;

        //see how many votes each number has
        if (!has_key(votes, phone)) {

            assign(votes, phone, 1);
            assign(votes, contestant, lookup(votes, contestant) + 1);
            total++;

        //make sure a phone doesn't have more than four votes
        }else if (lookup(votes, phone) < 4) {

            total++;
            assign(votes, phone, lookup(votes, phone) + 1);
            assign(votes, contestant, lookup(votes, contestant) + 1);
        }
    }

    //close file
    fin.close();

    //calculate the percentages of the votes per contestant
    for (int i = 0; i < y; i++) {

        vote = lookup(votes, names[i]);
        answer = ((vote / total) * 100);
        cout << answer;
        push(Name, names[i], answer);
        push(Percentage, answer, answer);
    }

    cout << "Final rankings" << endl;

    //need before the use of setprecision()
    cout << fixed;

    //output the percentages allong with the Name of contestant
    while (!isEmpty(Percentage)) {

        final = pop(Percentage);
        cout << setprecision(1) << final << "% " << pop(Name) << endl;
    }

    //destroy the Map and PQ
    destroy(votes);
    destroy(Name);
    destroy(Percentage);
}