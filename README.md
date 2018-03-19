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
Currently it just loads the kernel and call a C function. To see if is working:
```sh
$ gdb
(gdb) target remote localhost:1234
0x0010002f in ?? ()
(gdb) info registers
eax            0x3	3
ecx            0x1	1
edx            0x2	2
ebx            0x2cd80	183680
esp            0x101ff8	0x101ff8
ebp            0x67ee0	0x67ee0
esi            0x2cef0	184048
edi            0x2cef1	184049
eip            0x10002f	0x10002f
eflags         0x6	[ PF ]
cs             0x8	8
ss             0x10	16
ds             0x10	16
es             0x10	16
fs             0x10	16
gs             0x10	16
```
the result of the function which just sums (1 and 2), you can see the parameters on `ecx` and `edx` and the result on `eax`.



