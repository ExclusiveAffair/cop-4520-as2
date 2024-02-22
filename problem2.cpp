#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <fstream>
using namespace std;
using namespace std::chrono;
using namespace this_thread;
using ll = long long;

const int GUESTS = 10, ITER = 10;
mutex m;
bool showroomAvailable;

void tryToEnterShowroom(int currentGuest) {
    m.lock();
    cout << "guest " << currentGuest << " checks door" << endl;
    if (!showroomAvailable) {
        cout << "showroom is not available" << endl;
    }
    else {
        cout << "guest " << currentGuest << " enters" << endl;
        showroomAvailable = false;
        sleep_for(seconds(rand() % 10));
        cout << "guest " << currentGuest << " leaves" << endl;
        showroomAvailable = true;
    }
    m.unlock();
}

void solve() {
    vector<thread> threads;
    showroomAvailable = true;

    for (int i = 0; i < ITER; i++) {
        sleep_for(seconds(rand() % 10));
        int currentGuest = rand() % GUESTS;
        thread th(tryToEnterShowroom, currentGuest);
        threads.push_back(move(th));
    }

    for (auto& th : threads) {
        th.join();
    }

    cout << "simulation complete" << endl;
}

int main() {
    srand(time(0));
    solve();
}