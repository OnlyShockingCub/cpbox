#include <bits/stdc++.h>
using namespace std;

#include "session.hpp"

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string filename = argv[1];
    int time = stoi(argv[2]);

    start_session(filename, time);

    return 0;
}
