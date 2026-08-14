#include <bits/stdc++.h>
#include <mach-o/dyld.h>
using namespace std;
namespace fs = filesystem;

#include "session.hpp"

string get_executable_dir() {
    uint32_t size = 0;
    _NSGetExecutablePath(nullptr, &size);
    vector<char> buffer(size);
    _NSGetExecutablePath(buffer.data(), &size);
    return fs::path(buffer.data()).parent_path().string();
}

void start_session(string filename, int time) {
    string time_str = to_string(time) + "m";
    string cur_dir = fs::current_path().string();
    string root = fs::path(get_executable_dir()).parent_path().string();
    string config = root + "/wezterm/fullscreen.lua";

    string cmd =
        "wezterm "
        "--config-file \"" + config + "\" "
        "start --always-new-process "
        "--cwd \"" + cur_dir + "\" -- "
        "sh -c \""
        "touch \\\"" + filename + "\\\" && "
        "tmux new-session -s cpp_workspace 'nvim \\\"" + filename + "\\\"' \\; "
        "split-window -h \\; "
        "send-keys -t cpp_workspace:0.1 "
        "'countdown " + time_str + " && confetty' C-m \\; "
        "select-pane -t cpp_workspace:0.0"
        "\"";

    system(cmd.c_str());
}
