# danGdbTest


# Building

    type 'make'

# Run

    type './stupid'

# Gdb

    type 'gdb ./stupid'

## Sample GDB Debugging session

    testGdb> gdb stupid
    GNU gdb (Ubuntu 7.7.1-0ubuntu5~14.04.2) 7.7.1
    Copyright (C) 2014 Free Software Foundation, Inc.
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-linux-gnu".
    Type "show configuration" for configuration details.
    For bug reporting instructions, please see:
    <http://www.gnu.org/software/gdb/bugs/>.
    Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.
    For help, type "help".
    Type "apropos word" to search for commands related to "word"...
    Reading symbols from stupid...done.
    (gdb) break Stupid::square
    Breakpoint 1 at 0x4009cb: file testGdb.cc, line 5.
    (gdb) run
    Starting program: /home/codemonkey/Work/testGdb/stupid
    Traceback (most recent call last):
          File "/usr/share/gdb/auto-load/usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.19-gdb.py", line 63, in <module>
              from libstdcxx.v6.printers import register_libstdcxx_printers
          ImportError: No module named 'libstdcxx'

          Breakpoint 1, Stupid::square (this=0x602010, arg=6) at testGdb.cc:5
          5        return arg*arg;
          (gdb) bt
    #0  Stupid::square (this=0x602010, arg=6) at testGdb.cc:5
    #1  0x00000000004009f7 in Stupid::addOneAndSquare (this=0x602010, arg=5) at testGdb.cc:9
    #2  0x0000000000400a1a in Stupid::DoMath (this=0x602010) at testGdb.cc:13
    #3  0x0000000000400920 in main () at main.cc:8
          (gdb) w
          Ambiguous command "w": watch, wh, whatis, where, while, while-stepping, winheight, ws.
          (gdb) where
    #0  Stupid::square (this=0x602010, arg=6) at testGdb.cc:5
    #1  0x00000000004009f7 in Stupid::addOneAndSquare (this=0x602010, arg=5) at testGdb.cc:9
    #2  0x0000000000400a1a in Stupid::DoMath (this=0x602010) at testGdb.cc:13
    #3  0x0000000000400920 in main () at main.cc:8
          (gdb) frame 3
    #3  0x0000000000400920 in main () at main.cc:8
          8        int ret = sp->DoMath();
          (gdb) print sp->data
          $1 = 5
          (gdb) frame 2
    #2  0x0000000000400a1a in Stupid::DoMath (this=0x602010) at testGdb.cc:13
          13        return addOneAndSquare(data);
          (gdb) print data
          $2 = 5
          (gdb) frame 3
    #3  0x0000000000400920 in main () at main.cc:8
          8        int ret = sp->DoMath();
          (gdb) print arg
          No symbol "arg" in current context.
          (gdb) frame 1
    #1  0x00000000004009f7 in Stupid::addOneAndSquare (this=0x602010, arg=5) at testGdb.cc:9
          9        return square(arg+1);
          (gdb) print arg
          $3 = 5
          (gdb) quit
