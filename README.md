# Previous

Previous is a NeXT Computer emulator that can boot NeXTStep 0.x to 4.0 beta and OpenStep 4.2 For Mach.

## About Previous

Previous is a NeXT Computer emulator based on the Atari emulator Hatari. It 
uses the latest m68k emulation core from WinUAE and the i860 emulator from 
Jason Eckhardt. Previous is confirmed to compile and run on Linux, Mac OS X 
and Windows. It may also work on other Systems which are supported by the SDL2 
library, like FreeBSD, NetBSD and BeOS.

Previous emulates the following machines:

* NeXT Computer (original 68030 Cube)
* NeXTcube
* NeXTcube Turbo
* NeXTstation
* NeXTstation Turbo
* NeXTstation Color
* NeXTstation Turbo Color
* NeXTdimension Graphics Board

## Compiling and installing

For using Previous, you need to have installed the following libraries:

Required:

* The SDL library v2.0.5 or later (http://www.libsdl.org)
* The libpng PNG reference library (http://www.libpng.org)
* The zlib compression library (http://www.gzip.org/zlib/)

Don't forget to also install the header files of these libraries for compiling
Previous (some Linux distributions use separate development packages for these
header files)!

For compiling Previous, you need a C compiler (preferably GNU C), and a working
CMake installation (see http://www.cmake.org/ for details).

CMake can generate makefiles for various flavors of "Make" (like GNU-Make)
and various IDEs like Xcode on Mac OS X. To run CMake, you've got to pass the
path to the sources of Previous as parameter, for example run the following if
you are in the topmost directory of the Previous source tree:

```
cmake .
```

If you're tracking Previous version control, it's preferable to do
the build in a separate build directory as above would overwrite
the (non-CMake) Makefiles coming with Previous:

```
mkdir -p build
cd build
cmake ..
```

Have a look at the manual of CMake for other options. Alternatively, you can
use the "cmake-gui" program to configure the sources with a graphical
application.

After cmake finished the configuration successfully, you can compile Previous
by typing "make". If all works fine, you'll get the executable "Previous" in 
the src/ subdirectory of the build tree.


## Status

Previous is stable, but some parts are still work in progress. Some hardware 
is not yet emulated. Status of the individual components is as follows:

```
CPU		good (but not cycle-exact)
MMU		good
FPU		good
DSP		good
DMA		good
NextBus		good
Memory		good
2-bit graphics	good
Color graphics	good
RTC		good
Timers		good
SCSI drive	good
MO drive	good
Floppy drive	good
Ethernet	good
Serial		dummy
Printer		good
Sound		good
Keyboard	good
Mouse		good
ADB		dummy
Nitro		dummy
Dimension	partial (no video I/O)
```

There are remaining problems with the host to emulated machine interface for
input devices.

## Known issues

* Un-emulated hardware may cause problems when attempted to being used.
* NeXTdimension emulation does not work on hosts with big endian byte order.
* The MO drive causes slow downs and hangs when both drives are connected, but 
  only one disk is inserted. This is no emulation issue but a bug in NeXTstep.
* DSP sound has timing related issues. playscore under NeXTstep 0.9 sometimes 
  produces bad audio in variable speed mode. ScorePlayer under NeXTstep 2.x 
  produces distorted sound in normal CPU mode.
* Shortcuts do not work properly or overlap with host commands on some 
  platforms.
* CPU timings are not correct. You may experience performance differences 
  compared to real hardware.
* 68882 transcendental FPU instructions produce results identical to 68040 FPSP.
  The results are slightly different from real 68882 results.
* Changing network connection settings while a guest system is running sometimes
  causes permanently lost connections, especially under NeXTstep 2.2.

## Release notes

```
  Previous v1.0:
  > Initial release.

  Previous v1.1:
  > Adds Turbo chipset emulation.
  > Improves DSP interrupt handling.
  > Improves hardclock timing.

  Previous v1.2:
  > Adds support for running Mac OS via Daydream.
  > Improves mouse movement handling.
  > Adds dummy Nitro emulation.
  > Improves dummy SCC emulation.

  Previous v1.3:
  > Adds Laser Printer emulation.
  > Introduces option for swapping cmd and alt key.

  Previous v1.4:
  > Adds NeXTdimension emulation, including emulated i860 CPU.
  > Improves timings and adds a mode for higher than real speed.
  > Improves emulator efficiency through optimizations and threads.
  > Improves mouse movement handling.
  > Improves Real Time Clock. Time is now handled correctly.

  Previous v1.5:
  > Adds emulation of soundbox microphone to enable sound recording.
  > Fixes bug in SCSI code. Images greater than 4 GB are now supported.
  > Fixes bug in Real Time Clock. Years after 1999 are now accepted.
  > Fixes bug that prevented screen output on Linux.
  > Fixes bug that caused NeXTdimension to fail after disabling thread.

  Previous v1.6:
  > Adds SoftFloat FPU emulation. Fixes FPU on non-x86 host platforms.
  > Adds emulation of FPU arithmetic exceptions.
  > Adds support for second magneto-optical disk drive.
  > Fixes bug that caused a crash when writing to an NFS server.
  > Fixes bug that prevented NeXTdimension from stopping in rare cases.
  > Fixes bug that caused external i860 interrupts to be delayed.
  > Fixes bug that prevented sound input under NeXTstep 0.8.
  > Fixes bug that caused temporary speed anomalies after pausing.
  > Improves dummy RAMDAC emulation.

  Previous v1.7:
  > Adds support for twisted-pair Ethernet.
  > Adds SoftFloat emulation for 68882 transcendental FPU instructions.
  > Adds SoftFloat emulation for i860 floating point instructions.
  > Improves 68040 FPU emulation to support resuming of instructions.
  > Improves Ethernet connection stability.
  > Improves efficiency while emulation is paused.
  > Improves device timings to be closer to real hardware.
  > Fixes bug in timing system. MO drive now works in variable speed mode.
  > Fixes bug in 68040 MMU that caused crashes and kernel panics.
  > Fixes bug in 68040 FPU that caused crashes due to unnormal zero.
  > Fixes bug in FMOVEM that modified wrong FPU registers.
  > Fixes bug that sometimes caused hangs if sound was disabled.
  > Fixes bug that caused lags in responsiveness during sound output.
  > Fixes bug that caused a crash when using write protected image files.

Previous v1.8:
  > Removes support for host keyboard repeat because it became useless.
  > Fixes bug that caused FMOVECR to return wrong values in some cases.
  > Fixes bug in timing system that caused hangs in variable speed mode.

Previous v1.9:
  > PCAP networking support
  > Improved CPU emulation accuracy (from WinUAE)

Previous 2.0:
  > Adds support for adding multiple (up to 3) NeXTdimension boards to your emulated Cube (thanks to Simon Schubiger for adding this).
  > It also slows down NeXTdimesion a bit to reduce host CPU load.

Previous 2.1:
  > This version improves emulation efficiency and fixes some bugs in FPU and DSP emulation. You should notice quite some improvement in emulation speed or host CPU usage. Thanks go again to Simon Schubiger for these refinements.

Previous v2.2:
  > Adds support for using custom MAC address.
  > Improves accuracy of tables programmed to DSP data ROM.
  > Fixes bug that prevented reset warning after changing preferences.

Previous v2.3:
  > Adds internal NFS server for easier file sharing with host system.
  > Improves DSP, CPU and FPU emulation accuracy.
  > Fixes bug that caused sporadic power-on test failures and crashes.
  > Fixes bug that prevented Previous from starting with SDL > 2.0.12.

Previous v2.4 (unreleased):
  > Improves performance and accuracy of FSINCOS.
  > Fixes bug that caused slow disk access when running Mac OS.
```

## Running Previous

For running the emulator, you need an image of the boot ROM of the emulated 
machine.

While the emulator is running, you can open the configuration menu by
pressing F12, toggle between fullscreen and windowed mode by pressing F11 
and initiate a clean shut down by pressing F10 (emulates the power button).

## Contributors

Previous was written by Andreas Grabher, Simon Schubiger and Gilles Fetis.

Many thanks go to the members of the NeXT International Forums for their
help. Special thanks go to Gavin Thomas Nicol, Piotr Twarecki, Toni Wilen,
Michael Bosshard, Thomas Huth, Olivier Galibert, Jason Eckhardt, Jason 
Stevens, Daniel L'Hommedieu, Vaughan Kaufman and Peter Leonard!
This emulator would not exist without their help.

## Contact

If you want to contact the authors of Previous, please have a look at the 
NeXT International Forums (http://www.nextcomputers.org/forums).