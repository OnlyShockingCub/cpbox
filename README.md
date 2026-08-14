# cpbox

cpbox is a lightweight and competitive programming workspace build around neovim and tmux.

[![status](https://img.shields.io/badge/status-early%20development-orange)](https://github.com/OnlyShockingCub/cpbox)
[![neovim](https://img.shields.io/badge/neovim-57a143?logo=neovim&logoColor=white)](https://neovim.io/)
[![tmux](https://img.shields.io/badge/tmux-1bb91f?logo=tmux&logoColor=white)](https://github.com/tmux/tmux)
[![wezterm](https://img.shields.io/badge/wezterm-4E49EE?logo=wezterm&logoColor=white)](https://wezterm.org/)
[![countdown](https://img.shields.io/badge/countdown-timer-orange?logo=clockify&logoColor=white)](https://github.com/aldernero/countdown)
[![confetty](https://img.shields.io/badge/confetty-confetti-ff69b4)](https://github.com/maaslalani/confetty)

## requirements
1. g++
2. neovim
3. tmux
4. sudo
5. wezterm

## installation
clone the repo and run the install script:
git clone https://github.com/OnlyShockingCub/cpbox/tree/main
cd cpbox

./install.sh
The install script builds cpbox and installs it to /usr/local/bin

building cpbox... 
installing cpbox... 
cpbox installed successfully!

after installation cpbox can be run from anywhere: cpbox <filename> <time>
for example:
cpbox main.cpp 90


## current features

1. opens neovim for writing solutions
2. uses tmux with 2 panels
3. tracks how long your competition/session has been running
4. designed to start coding quickly

## current layout

cpbox
  tmux window 1
    neovim
  tmux window 2
    comp timer

## planned features

1. problem management
2. test case running
3. compile/run commands
4. submission tracking
5. contest info
6. more useful tmux/nvim integration
7. custom config

## goal

the goal is to make a competitive programming session quick and efficient.

## status

early development

the project is currently focused on getting the core workflow working before adding more features.

## contributing

contributions, ideas, and suggestions are welcome as cpbox develops.

## license

license info will be added later.
