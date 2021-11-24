# Bluffy

<p align="center">
  <img alt="bluffy" src="https://media.giphy.com/media/11Mj6P6WqWnnuU/giphy.gif" height="140" />
  <p align="center">
    <a href="https://github.com/ad-995/bluffy/releases/latest"><img alt="Release" src="https://img.shields.io/github/release/ad-995/bluffy.svg?style=flat-square"></a>
    <a href="https://github.com/ad-995/bluffy/blob/master/LICENSE"><img alt="Software License" src="https://img.shields.io/badge/license-MIT-brightgreen.svg?style=flat-square"></a>
    <a href="https://github.com/ad-995/bluffy/issues"><img alt="GitHub issues" src="https://img.shields.io/github/issues/ad-995/bluffy.svg?style=flat-square"></a>
    </p>
</p>

<h5 align="center"><i>Convert shellcode into ✨ different ✨ formats!</i></h5>

Bluffy is a utility which was used in experiments to bypass Anti-Virus products (statically) by formatting shellcode into realistic looking data formats.

Proof-of-concept tools, such as [0xBoku](https://twitter.com/0xBoku)'s [Ninja_UUID_Runner](https://github.com/boku7/Ninja_UUID_Runner) and [ChoiSG](https://github.com/ChoiSG)'s [UuidShellcodeExec](https://github.com/ChoiSG/UuidShellcodeExec), inspired the initial concept for Bluffy.

So far, we implemented:

1. UUID
2. CLSID
3. SVG
4. CSS

## Help

```
$ python3 bluffy.py -h

  ⣇⣿⠘⣿⣿⣿⡿⡿⣟⣟⢟⢟⢝⠵⡝⣿⡿⢂⣼⣿⣷⣌⠩⡫⡻⣝⠹⢿⣿⣷
  ⡆⣿⣆⠱⣝⡵⣝⢅⠙⣿⢕⢕⢕⢕⢝⣥⢒⠅⣿⣿⣿⡿⣳⣌⠪⡪⣡⢑⢝⣇
  ⡆⣿⣿⣦⠹⣳⣳⣕⢅⠈⢗⢕⢕⢕⢕⢕⢈⢆⠟⠋⠉⠁⠉⠉⠁⠈⠼⢐⢕⢽
  ⡗⢰⣶⣶⣦⣝⢝⢕⢕⠅⡆⢕⢕⢕⢕⢕⣴⠏⣠⡶⠛⡉⡉⡛⢶⣦⡀⠐⣕⢕
  ⡝⡄⢻⢟⣿⣿⣷⣕⣕⣅⣿⣔⣕⣵⣵⣿⣿⢠⣿⢠⣮⡈⣌⠨⠅⠹⣷⡀⢱⢕
  ⡝⡵⠟⠈⢀⣀⣀⡀⠉⢿⣿⣿⣿⣿⣿⣿⣿⣼⣿⢈⡋⠴⢿⡟⣡⡇⣿⡇⡀⢕
  ⡝⠁⣠⣾⠟⡉⡉⡉⠻⣦⣻⣿⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣦⣥⣿⡇⡿⣰⢗⢄
  ⠁⢰⣿⡏⣴⣌⠈⣌⠡⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣬⣉⣉⣁⣄⢖⢕⢕⢕
  ⡀⢻⣿⡇⢙⠁⠴⢿⡟⣡⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣵⣵⣿
  ⡻⣄⣻⣿⣌⠘⢿⣷⣥⣿⠇⣿⣿⣿⣿⣿⣿⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
  ⣷⢄⠻⣿⣟⠿⠦⠍⠉⣡⣾⣿⣿⣿⣿⣿⣿⢸⣿⣦⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟
  ⡕⡑⣑⣈⣻⢗⢟⢞⢝⣻⣿⣿⣿⣿⣿⣿⣿⠸⣿⠿⠃⣿⣿⣿⣿⣿⣿⡿⠁⣠
  ⡝⡵⡈⢟⢕⢕⢕⢕⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠿⠋⣀⣈⠙
  ⡝⡵⡕⡀⠑⠳⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢉⡠⡲⡫⡪⡪⡣

Convert shellcode into ✨ different ✨ formats!

Written by:
  ~ Mez0
  ~ Michael Ranaldo

usage: Bluffy [-h] -b  -o  -m

optional arguments:
  -h, --help              show this help message and exit
  -b , --bin              Specify bin file to load
  -m , --mask             Specify the mask for the shellcode
  -p , --preview          Preview the created format
  -pp, --payload_preview  Preview the payload prior to C formatting
  --list                  List all the available masks
```

Written by:
- [Michael Ranaldo](https://twitter.com/michaeljranaldo)
- [Mez0](https://twitter.com/__mez0__)

## Requirements

python3.9 or greater:
```bash
sudo apt install python3.9
```

rich:
```bash
sudo pip3 install rich
````

pcre2.8:

Depending on whether its going to be ran on Kali, Ubuntu 18, 19, 20, and so on, it may be different.

For us, it was developed on:
```
$ lsb_release -a
No LSB modules are available.
Distributor ID: Ubuntu
Description:  Ubuntu 21.04
Release:  21.04
Codename: hirsute
```

In order to link `libpcre2-8.a`, the `.a` file had to be in:
```
/usr/lib/gcc/x86_64-w64-mingw32/10-win32
```

As for obtaining the header and lib files, [MSYS2](https://packages.msys2.org/base/mingw-w64-pcre2) was used. But if you're smarter than us, then just do it from source for Mingw64: https://pcre.org/