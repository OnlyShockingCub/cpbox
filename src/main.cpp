#include <bits/stdc++.h>
using namespace std;

#include "session.hpp"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string filename;
    int time;

    cin >> filename >> time;

    start_session(filename, time);

    return 0;
}
