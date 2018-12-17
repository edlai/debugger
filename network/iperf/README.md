# Network

## iperf

## Requirements

- iperf `apt install iperf`
- speedometer `apt install speedometer` (Optional)
- [Public iPerf3 servers](https://iperf.fr/iperf-servers.php) (Optional)

## Usage

### TCP

- Server

```
$ sudo iperf -s
```

- Client 

``` sh
$ sudo iperf -c iperf.biznetnetworks.com -t 10 -i 1 -p 5203
------------------------------------------------------------
Client connecting to iperf.biznetnetworks.com, TCP port 5203
TCP window size: 85.0 KByte (default)
------------------------------------------------------------
[  3] local 45.77.13.97 port 59548 connected with 117.102.109.186 port 5203
[ ID] Interval       Transfer     Bandwidth
[  3]  0.0- 1.0 sec  13.6 KBytes   112 Kbits/sec
[  3]  1.0- 2.0 sec  16384 PBytes  147574 Pbits/sec
[  3]  2.0- 3.0 sec  16384 PBytes  147574 Pbits/sec
[  3]  3.0- 4.0 sec  16384 PBytes  147574 Pbits/sec
[  3]  4.0- 5.0 sec  16384 PBytes  147574 Pbits/sec
[  3]  5.0- 6.0 sec  16384 PBytes  147574 Pbits/sec
[  3]  6.0- 7.0 sec  16384 PBytes  147574 Pbits/sec
[  3]  7.0- 8.0 sec  16384 PBytes  147574 Pbits/sec
[  3]  8.0- 9.0 sec  16384 PBytes  147574 Pbits/sec
[  3]  9.0-10.0 sec  16384 PBytes  147574 Pbits/sec
[  3]  0.0-10.0 sec  16384 PBytes  14751 Pbits/sec`
```

### UDP

- Server

```
$ sudo iperf -s -p 9005 -u  -w 2048K
```

- Client

```
# sudo iperf -c iperf.biznetnetworks.com -u -t 10 -i 1 -p 5203 -w 2048K -b 17400M -l 20700
------------------------------------------------------------
Client connecting to iperf.biznetnetworks.com, UDP port 5203
Sending 20700 byte datagrams
UDP buffer size:  416 KByte (WARNING: requested 2.00 MByte)
------------------------------------------------------------
[  3] local 45.77.13.97 port 38337 connected with 117.102.109.186 port 5203
[ ID] Interval       Transfer     Bandwidth
[  3]  0.0- 1.0 sec   659 MBytes  5.53 Gbits/sec
[  3]  1.0- 2.0 sec   639 MBytes  5.36 Gbits/sec
[  3]  2.0- 3.0 sec   675 MBytes  5.66 Gbits/sec
[  3]  3.0- 4.0 sec   658 MBytes  5.52 Gbits/sec
[  3]  4.0- 5.0 sec   684 MBytes  5.74 Gbits/sec
[  3]  5.0- 6.0 sec   663 MBytes  5.56 Gbits/sec
[  3]  6.0- 7.0 sec   669 MBytes  5.61 Gbits/sec
[  3]  7.0- 8.0 sec   661 MBytes  5.54 Gbits/sec
[  3]  8.0- 9.0 sec   672 MBytes  5.64 Gbits/sec
[  3]  9.0-10.0 sec   676 MBytes  5.67 Gbits/sec
[  3]  0.0-10.0 sec  6.50 GBytes  5.58 Gbits/sec
[  3] Sent 337102 datagrams
read failed: No route to host
[  3] WARNING: did not receive ack of last datagram after 1 tries.
```

### Monitor

- speedometer `speedometer -r ens0 -t ens0`

### Reference
