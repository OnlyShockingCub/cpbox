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

    string executable_dir = get_executable_dir();
    string root = fs::path(executable_dir).parent_path().string();

    string wezterm_config = root + "/wezterm/fullscreen.lua";
    string nvim_config = root + "/nvim/init.lua";

    string cmd =
        "wezterm "
        "--config-file \"" + wezterm_config + "\" "
        "start --always-new-process "
        "--cwd \"" + cur_dir + "\" -- "
        "sh -c \""
        "touch \\\"" + filename + "\\\" && "
        "tmux new-session -d -s cpp_workspace 'sh' \\; "
        "split-window -h -t cpp_workspace:0.0 \\; "
        "split-window -v -t cpp_workspace:0.1 \\; "
        "send-keys -t cpp_workspace:0.0 "
        "'CPBOX=1 "
        "CPBOX_FILE=\\\"" + filename + "\\\" "
        "CPBOX_OUTPUT_PANE=cpp_workspace:0.2 "
        "nvim \\\"" + filename + "\\\" "
        "-c \\\"luafile " + nvim_config + "\\\"' C-m \\; "
        "send-keys -t cpp_workspace:0.1 "
        "'countdown " + time_str + " && confetty' C-m \\; "
        "select-pane -t cpp_workspace:0.0 \\; "
        "attach-session -t cpp_workspace"
        "\"";

    system(cmd.c_str());
}
