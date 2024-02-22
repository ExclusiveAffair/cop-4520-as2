#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <fstream>
using namespace std;
using namespace std::chrono;
using ll = long long;

const int GUESTS = 10;
mutex m;
int guestsEntered, cupcake, checker;
vector<bool> eaten(GUESTS);

void enterMaze(int currentGuest) {
    m.lock();
    cout << "guest " << currentGuest << " enters" << endl;
    if (checker == -1) {
        checker = currentGuest;
        guestsEntered++;
        eaten[checker] = true;
    }

    // if the cupcake was eaten, this indicates that at least one new person
    // has entered the maze. update the count and replace the cupcake.
    else if (!cupcake && currentGuest == checker) {
        guestsEntered++;
        cupcake = 1;
    }
    else if (cupcake && !eaten[currentGuest]) {
        cupcake = 0;
        eaten[currentGuest] = true;
    }
    m.unlock();
}

void solve() {
    vector<thread> threads;

    guestsEntered = 0;
    cupcake = 1;
    checker = -1;
    for (int i = 0; i < GUESTS; i++) eaten[i] = false;

    while (guestsEntered < GUESTS) {
        int currentGuest = rand() % GUESTS;
        thread th(enterMaze, currentGuest);
        threads.push_back(move(th));
    }

    for (auto& th : threads) {
        th.join();
    }

    cout << "everyone has entered" << endl;
}

int main() {
    srand(time(0));
    solve();
}