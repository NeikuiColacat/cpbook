-- 检查是否在 VSCode 中运行
if vim.g.vscode then
    -- 在 VSCode 中，禁用 lazy.nvim
else
    vim.opt.termguicolors = true
    vim.opt.rtp:prepend('~/.local/share/nvim/lazy/lazy.nvim')

    -- 确保安装 lazy.nvim
    require('lazy').setup({
        -- 安装 Catppuccin 主题
        { 'catppuccin/nvim', name = 'catppuccin' },
        -- 安装 nvim-treesitter 用于语法高亮
        { 'nvim-treesitter/nvim-treesitter', run = ':TSUpdate' },
        {
        'windwp/nvim-autopairs',
        config = function()
            require('nvim-autopairs').setup{}
        end
        },
    })

    -- 启用 Catppuccin 主题
    require("catppuccin").setup({
        flavour = "macchiato", -- 选择颜色风格
        background = { light = "latte", dark = "macchiato" },
        transparent_background = false,
    })

    vim.cmd([[colorscheme catppuccin]])

    -- Treesitter 配置
    require('nvim-treesitter.configs').setup {
        ensure_installed = { "c", "cpp", "lua", "python", "javascript", "html", "css" }, -- 确保安装所需的解析器
        highlight = {
            enable = true,              -- 启用高亮
            additional_vim_regex_highlighting = false, -- 是否使用额外的 Vim 正则高亮
        },
    }

    -- 其他常用配置
    vim.opt.encoding = 'utf-8'  -- 设置编码为 UTF-8
    vim.opt.fileencoding = 'utf-8'  -- 文件编码
    vim.opt.tabstop = 4  -- Tab 宽度
    vim.opt.shiftwidth = 4  -- 自动缩进宽度
    vim.opt.expandtab = true  -- 使用空格代替 Tab
    vim.opt.number = true  -- 显示行号
    vim.opt.relativenumber = true  -- 显示相对行号
    vim.opt.smartindent = true  -- 智能缩进
    vim.opt.cursorline = true  -- 高亮当前行
    vim.opt.showmode = false  -- 不显示模式
    vim.opt.guifont = "Cascadia Code:h20"
end

