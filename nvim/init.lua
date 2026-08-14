local file = vim.env.CPBOX_FILE

if not file then
    return
end

local function send(command)
    vim.fn.jobstart({
        "tmux",
        "send-keys",
        "-t",
        vim.env.CPBOX_OUTPUT_PANE,
        command,
        "C-m",
    })
end

local function build()
    vim.cmd("write")
    send("g++ " .. vim.fn.shellescape(file))
end

local function run()
    vim.cmd("write")
    send("./a.out")
end

local function build_run()
    vim.cmd("write")
    send("g++ " .. vim.fn.shellescape(file) .. " && ./a.out")
end

vim.keymap.set("n", "<F13>", build)
vim.keymap.set("n", "<F14>", run)
vim.keymap.set("n", "<F15>", build_run)
