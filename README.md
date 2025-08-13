# srchit
srchit (Search It) is a small tool that grabs the selected text and searches it using the first available browser.
After installation, you can create a shortcut and use your browser like a bookmark manager!

**NOTE: This tool is designed for X11, not Wayland.**

Adding Wayland support is planned for the future.

# Installation
## From source
```plaintext
# make install
# make uninstall
```

# Better solution!
This code is actually useless untill you can utilize BASH and `xclip`. Install `xclip` and save 40 lines of C codes.
Following code definitely is simpler and better than srchit.

```bash
firefox "https://www.google.com/search?q=$(xclip -selection primary -out)"
```
