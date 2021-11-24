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
  -x , --xor              XOR the payload
  -p , --preview          Preview the created format
  -pp, --payload_preview  Preview the payload prior to C formatting
  --list                  List all the available masks
```

Written by:
- [Michael Ranaldo](https://twitter.com/michaeljranaldo)
- [Mez0](https://twitter.com/__mez0__)

## Requirements and installation

The following items must be installed prior to using Bluff:

### python3.9 or greater:
```bash
sudo apt install python3.9
```

### rich:
```bash
sudo pip3 install rich
````

### pcre2.8:

Depending on whether its going to be ran on Kali, Ubuntu 18, 19, 20, and so on, the process of getting and building with `pcre2.8` may be different.

For us on Ubuntu, it was developed on:
```
$ lsb_release -a
No LSB modules are available.
Distributor ID: Ubuntu
Description:  Ubuntu 21.04
Release:  21.04
Codename: hirsute
```

In order to link `libpcre2-8.a`, the `.a` file had to be included within:
```
/usr/lib/gcc/x86_64-w64-mingw32/10-win32
```

As for obtaining the header and lib files, [MSYS2](https://packages.msys2.org/base/mingw-w64-pcre2) was used. But if you're smarter than us, then just do it from source for Mingw64: https://pcre.org/.


The simplest way to thus acquire and install is to run the following commands (after double checking your architecture etc.):

```bash
sudo apt install mingw-64
sudo wget https://packages.msys2.org/package/mingw-w64-x86_64-pcre2?repo=mingw64 -P /usr/lib/gcc/x86_64-w64-mingw32/10-win32
```

## Using Bluffy

To build a payload, get your binary file. For this example, we used calc.bin, which just loads calc.exe as a proof of concept. As Bluffy only seeks to evade _static_ analysis using steganography, by hiding the binary within an otherwise innocuous file, you will need to do further research to ensure that your payload also evades _dynamic_ detection.

Run `bluffy`, choosing a mask of your choice and providing your .bin file:
```bash
python ./bluffy.py -b calc.bin -m css -x
```

Check your payload, then build it. To build your payload, copy the .h file bluffy creates, rename it css.c, run make to build it to an executable, then test using the included examples directory:

```
mv css.h examples/css/css.h
cd examples/css
make
```

This will use the included "main.c" to build an Windows executable. Test this to confirm. If you have also used calc.bin, you should be greeted by a new Calc window opening. If so, congratulations!

For more details on using Bluffy and a walkthrough of how it works and what the output looks like, check out our [blog](https://ad-995.group/posts/bluffy/bluffy.html)

Here is a full example:

![example](/images/bluffy.gif)
