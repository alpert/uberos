# UberOS

Experimental operation system for learning purposes. Started by following: [The little book about OS development](http://littleosbook.github.io)

Unlike the tutorial I use [qemu](https://www.qemu.org/) as emulator because my working environment is a remote box and I could not make Bochs work with it.

### Installation
For Ubuntu 16.04.4 LTS:
```sh
$ sudo apt-get install build-essential nasm genisoimage qemu
$ cd uberos
$ make run
```
### Status
Writes "Wellcome to uberOS!" to screen.



