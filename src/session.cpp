#include <bits/stdc++.h>
using namespace std;

#include "session.hpp"

void start_session(string filename, int time) {
    string time_str = to_string(time) + "m";
    string cur_dir = filesystem::current_path().string();

    string cmd_str =
        "/opt/homebrew/bin/wezterm "
        "--config-file /Users/tejas/Documents/cpbox/wezterm/fullscreen.lua "
        "start --always-new-process "
        "--cwd " + cur_dir + " -- "
        "sh -c \""
        "touch " + filename + " && "
        "tmux new-session -s cpp_workspace 'nvim " + filename + "' \\; "
        "split-window -h \\; "
        "send-keys -t cpp_workspace:0.1 'countdown " + time_str + "' C-m \\; "
        "select-pane -t cpp_workspace:0.0"
        "\"";

    system(cmd_str.c_str());
}
