# net-dump

**net-dump** provides a simple way to collect usage information about a wireless network. It is much cheaper than a packet capture, since it only saves select information about each packet. Also, unlike a typical packet capture, net-dump can automatically perform WLAN channel hopping.

# Usage

You can use net-dump on OS X or Linux. You must make sure that your wireless chip supports monitor mode. On a Mac, you are pretty much guaranteed that it does.

First, you must compile net-dump. Make sure that you have libpcap installed, and some sort of compiler (clang or GCC work). To build, run the following:

    $ make

Now you should be able to execute the command:

    $ ./build/net-dump
    Usage: ./build/net-dump <interface> [-h hop_interval] <channel> [channel ...]

The first argument is the wireless interface. You can find a list of wireless interfaces on Linux using `iwconfig`. On OS X, it will be listed in the output of `ifconfig`. If you are on Linux, you will need to explicitly place your wireless card in monitor mode before using net-dump:

    $ sudo ifconfig <my interface> down
    $ sudo iwconfig <my interface> mode monitor
    $ sudo ifconfig <my interface> up

Some Linux processes (e.g. Network Manager) will keep messing with your wireless card's settings. If you have problems, I recommend installing `airmon-ng`.

The optional hop_interval argument specifies how frequently net-dump should switch channels. This is an integer representing a number of seconds. By default, the hop interval is set to 5 seconds, meaning that net-dump switches channels every five seconds.

The channel arguments are numerical WLAN channel numbers. You need to specify at least one channel to sniff on. For 2.4GHz, you will probably use numbers between 1 and 11. For 5GHz, the channel numbers are more spread out.

On some Linux distributions, the `iw` command is the only way to set the channel of a wireless interface, and `iwconfig` does not work. On these distributions, you may set the envirovnment variable `USE_IW` to `1` to instruct net-dump to use the `iw` command for channel hopping.
