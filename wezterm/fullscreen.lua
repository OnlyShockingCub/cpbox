local wezterm = require("wezterm")
local config = dofile(os.getenv("HOME") .. "/.config/wezterm/wezterm.lua")

config.native_macos_fullscreen_mode = true

config.keys = config.keys or {}

table.insert(config.keys, {
    key = "b",
    mods = "CMD",
    action = wezterm.action.SendKey {
        key = "F13",
    },
})

table.insert(config.keys, {
    key = "r",
    mods = "CMD",
    action = wezterm.action.SendKey {
        key = "F14",
    },
})

table.insert(config.keys, {
    key = "b",
    mods = "CMD|SHIFT",
    action = wezterm.action.SendKey {
        key = "F15",
    },
})

wezterm.on("gui-startup", function(cmd)
    local tab, pane, window = wezterm.mux.spawn_window(cmd or {})
    window:gui_window():toggle_fullscreen()
end)

return config
