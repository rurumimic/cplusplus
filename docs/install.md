# Install

## CMake

- cmake [install](https://cmake.org/install/)

```bash
# mac
sudo port install cmake
```

## SpaceVim

- [c](https://spacevim.org/layers/lang/c/)
- [gtags](https://spacevim.org/layers/gtags/)
- [cmake](https://spacevim.org/layers/lang/cmake/)

```toml
[[layers]]
name = "lang#c"
enable_clang_syntax_highlight = true

[[layers]]
name = "gtags"
auto_update = false
ctags_bin = "global"

[[layers]]
name = "lang#cmake"
```

