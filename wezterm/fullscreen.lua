local wezterm = require("wezterm")
local config = dofile(os.getenv("HOME") .. "/.config/wezterm/wezterm.lua")

wezterm.on("gui-startup", function(cmd)
    local tab, pane, window = wezterm.mux.spawn_window(cmd or {})
    window:gui_window():toggle_fullscreen()
end)

return config
