#include <bits/stdc++.h>
using namespace std;

#include "session.hpp"

void start_session(string filename, int time) {
    string time_str = to_string(time) + "m";

    string cmd_str = "tmux new-session -d -s cpp_workspace && "
                     "tmux send-keys -t cpp_workspace 'nvim " + filename + "' C-m && "
                     "tmux split-window -h -t cpp_workspace && "
                     "tmux send-keys -t cpp_workspace:0.1 'countdown " + time_str + "' C-m && "
                     "tmux select-pane -t cpp_workspace:0.0 && "
                     "tmux attach-session -t cpp_workspace";

    system(cmd_str.c_str());
}
