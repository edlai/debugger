# Network

## iperf

## Requirements

- iperf `apt install iperf`
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

- Client

### Reference
