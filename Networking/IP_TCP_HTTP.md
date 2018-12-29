# [IP, TCP, and HTTP](https://www.objc.io/issues/10-syncing-data/ip-tcp-http/)

## IP — Internet Protocol

Introduces the concept of **hosts** - machines actually. IP protocol specifies how packets are sent between hosts.

Packet turns out to be binary data that has source host and destination host. Packets are delivered using _best effort_ - packet may be lost along the way. Or it may get duplicated and arrive several times at the destination.

Each host has **IP address**. As each packet has source and destination address, IP is responsible for routing datagrams (packets). As the IP packet travels through the network, each host (node) checks packet destination address to figure out in which direction to forward the packet.

### IPv4 & IPv6

IPv4 - Internet Protocol version 4. Each IPv4 address is 32 bits long (example: `198.51.100.42`). IPv6 is 128 bits long. They are represented in hexadecimal system and divided into eight groups separated by colons (example: `2001:0db8:85a3:0042:1000:8a2e:0370:7334`).

### IP Packet

An IP packet consists of a header (metadata) and a payload (data to be transmitted).

An IPv4 header is 20 bytes long. It looks like this:

```IPv4
IPv4 Header Format
Offsets  Octet    0                       1                       2                       3
Octet    Bit      0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31|
 0         0     |Version    |IHL        |DSCP            |ECN  |Total Length                                   |
 4        32     |Identification                                |Flags   |Fragment Offset                       |
 8        64     |Time To Live           |Protocol              |Header Checksum                                |
12        96     |Source IP Address                                                                             |
16       128     |Destination IP Address                                                                        |
20       160     |Options (if IHL > 5)                                                                          |
```

Most viable fields here are source IP, destination IP, version (4 for IPv4), protocol (6 for TCP) and total length (header + payload).

IPv6 header is 40 bytes long. It looks like this:

```IPv6
Offsets  Octet    0                       1                       2                       3
Octet    Bit      0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31|
 0         0     |Version    |Traffic Class         |Flow Label                                                 |
 4        32     |Payload Length                                |Next Header            |Hop Limit              |
 8        64     |Source Address                                                                                |
12        96     |                                                                                              |
16       128     |                                                                                              |
20       160     |                                                                                              |
24       192     |Destination Address                                                                           |
28       224     |                                                                                              |
32       256     |                                                                                              |
36       288     |                                                                                              |
```

It's simpler than IPv4 header - lessons learned from experience with IPv4. Here the _next header_ field specifies what data follows the header. IPv6 allows chaining of headers inside the packet. Each subsequent IPv6 header will also have a _next header_ field until the actual payload is reached. When the _next header_ field, for example, is 6 (TCP's protocol number), the rest of the packet will be TCP data.

### Fragmentation

IPv4 packets (datagrams) can get fragmented: it's the process of dividing packet into smaller pieces (fragments). The fragments are reassembled by the **receiving** host. This technique can be used to pass packets through a link with a smaller maximum transmission unit than the original packet size. The sender can disallow fragmentation, in which case router will return a _Packet Too Big_ ICMP (Internet Control Message Protocol).

In IPv6, a router will always drop the packet and send back a Packet Too Big ICMP message to the sender. The end points use this to do a path MTU discovery to figure out what the optimal _maximum transfer unit_ (MTU) along the path between the two hosts is. This is used to avoid fragmentation. Only when the upper layer has a minimum payload size that is too big for this MTU will IPv6 use fragmentation.

## TCP – Transmission Control Protocol

One of the most common protocols to run on top of IP. Often referred to as TCP/IP.

TCP is built on top of IP. It provides reliable, ordered, error-checked delivery of a stream of data between programs (while IP is used for sending _single_ packets). With TCP, an application running on one device can send data to an app on another device and be sure that the data arrives in the same way it was sent.

TCP connection is duplex and guarantees that the data will arrive at the other end in pristine condition. A typical use case of TCP is HTTP. Browser (app 1) connects to a server (app 2). Once connection is made, the browser can send a request and a server can send a response back through the same connection.

Multiple apps can use TCP simultaneously on the same host. To uniquely identify an app, TCP has a concept of _ports_. A connection between two apps has a source IP address and a source port on one end, and a destination IP address and a destination port on other end. These uniquely identifies the connection.

A web server using HTTPS will listen on port 443 by default (it's 80 for HTTP). The browser will use a so-called ephemeral port as the source port and then use TCP to establish a connection between the two address-port pairs.

### TCP Segments

The data stream is cut into chunks, which are turned into TCP segments, which becomes the payload of an IP packet. Each TCP segment has a header and payload. Header contains source and destination port number – the source and destination address is already present in the IP header. There are other fields in TCP header which are all used to manage the connection, like _sequence_ and _acknowledgment_ numbers.

### Sequence and acknowledgment numbers

**Sequence** number is basically mechanism to give a unique identifier to each segment. The first segment has a random number, e.g. 1721092979, and subsequent segments just increase it by 1. **Acknowledgment** numbers allow the other end to communicate back to the sender regarding which segments it has received so far. This happens in both directions.

## TCP Connections

Connection management is crucial for TCP. The protocol needs to pull a lot of tricks to hide the complexities of the unreliable IP layer.

### Connection Setup

In TCP connection is established form one host to another, so one end (server) is listening for connections, while the other end (e.g. app/client) connects to the listening application (server mentioned earlier). Server performs so-called _passive open_ – it starts listening. The client performs _active open_ toward the server.

Setup happens through three-way handshake:

1. The client sends **SYN** (synchronize sequence numbers) to the server with a random sequence number `A`
2. The server replies with a **SYN-ACK** with an acknowledgment number of `A + 1` and a random sequence number `B`
3. The client sends an **ACK** to the server with an acknowledgment number of `B + 1` and a sequence number of `A + 1`

Once data flows between both ends, each TCP segments has a sequence number – that's how TCP makes sure that all parts arrive at the other end, and they're put together in the right order. So setup is synchronizing sequence number of the first segment between both ends.

When a segment arrives at one of the ends, that end will acknowledge the receipt of that segment by sending an acknowledgment for the sequence number of the received segment.

### Options

Consider this log as example of connection setup:

```
% sudo tcpdump -c 3 -i en3 -nS host 23.63.125.15
18:31:29.140787 IP 10.0.1.6.52181 > 23.63.125.15.80: Flags [S], seq 1721092979, win 65535, options [mss 1460,nop,wscale 4,nop,nop,TS val 743929763 ecr 0,sackOK,eol], length 0
18:31:29.150866 IP 23.63.125.15.80 > 10.0.1.6.52181: Flags [S.], seq 673593777, ack 1721092980, win 14480, options [mss 1460,sackOK,TS val 1433256622 ecr 743929763,nop,wscale 1], length 0
18:31:29.150908 IP 10.0.1.6.52181 > 23.63.125.15.80: Flags [.], ack 673593778, win 8235, options [nop,nop,TS val 743929773 ecr 1433256622], length 0◊
```

Here you can see how the ends establish three handshakes. But there are additional information which represents _options_. The `TS val` / `ecr` are used to estimate the round-trip time (RTT). `TS val` is the _time stamp_ of the sender, and the `erc` is the timestamp _echo reply_, which is the last timestamp that the sender has received. This is used for congestion-control algorithms.

`mss` specifies the `Maximum Segment Size`, which is the maximum number of bytes that this end is willing to receive in a single segment. `wscale` is the window scale factor.

### Connection Data Flow

When the connection is created, both ends can send data to the other end. The receiving end will acknowledge packets as they are received by sending back segments with the corresponding **ACK** in the header. This looks something like this:

```
host A sends segment with seq 10
host A sends segment with seq 20
host A sends segment with seq 30    host B sends segment with ack 10
host A sends segment with seq 35    host B sends segment with ack 20
                                    host B sends segment with ack 30
                                    host B sends segment with ack 35
```

Host A will keep sending packets. As they arrive at host B, host B will send acknowledgements for these packets back to host A. But host A will keep sending packets without waiting for host B to acknowledge them.

There are flow control mechanisms for congestion control. They are about figuring out if segments got lost and need to be retransmitted and if it's needed to adjust the rate at which segments are sent, thus making sure we are not sending data faster then the receiver could process. Receiver can send a _receive window_, which tells the sender how much more data the receiver can buffer. In the log presented above in **options** section we see `win 65535` – window size, and a `wscale 4` – scale factor. As a result, host says it has receive window of _4 \* 64_ kB. As either side receives data, it will send an updated receive window of the other end.

Congestion control is quite complex. It's obvious desire to send packages as fast as possible, but it could result in drastic performance drop. It's called congestive collapse and it's inherent to packet-switched networks. When too many packets are sent, they will collide with other packets and the packet loss rate will climb dramatically.

### another example:

```
18:31:29.150955 IP 10.0.1.6.52181 > 23.63.125.15.80: Flags [P.], seq 1721092980:1721093065, ack 673593778, win 8235, options [nop,nop,TS val 743929773 ecr 1433256622], length 85
18:31:29.161213 IP 23.63.125.15.80 > 10.0.1.6.52181: Flags [.], ack 1721093065, win 7240, options [nop,nop,TS val 1433256633 ecr 743929773], length 0
```

The client `10.0.1.6` sends the first segment with data `length 85` (the HTTP request, 85 bytes). The **ACK** number is left at the same value, because no data has been received from the other end since the last segment.

The server at `23.63.125.15` then acknowledges the receipt of that data (but doesn't send any data): `length 0`. The sequence number and acknowledgment numbers are byte ranges: 1721092980 to 1721093065 is 85 bytes. When the other end sends `ack` 1721093065, that means: I have everything up to byte 1721093065.

### Connection Termination

Each end sends a **FIN** flag to the other end. This **FIN** is then acknowledged.

```
18:31:29.199029 IP 10.0.1.6.52181 > 23.63.125.15.80: Flags [F.], seq 1721093065, ack 673608401, win 8192, options [nop,nop,TS val 743929819 ecr 1433256660], length 0
18:31:29.208416 IP 23.63.125.15.80 > 10.0.1.6.52181: Flags [F.], seq 673608401, ack 1721093066, win 7240, options [nop,nop,TS val 1433256680 ecr 743929819], length 0
18:31:29.208493 IP 10.0.1.6.52181 > 23.63.125.15.80: Flags [.], ack 673608402, win 8192, options [nop,nop,TS val 743929828 ecr 1433256680], length 0
```

Note how on the second line host sends its **FIN**, and at the same time acknowledges the other end's **FIN** with an **ACK** (dot), all in a single segment.

## HTTP – Hypertext Transfer Protocol

HTTP uses a simple request/response mechanism. There is always a single request and a single response, both following the same format. See more on HTTP in dedicated notes.

## HTTPS – HTTP Secure

Transport Layer Security is cryptographic protocol that runs on top of TCP. It allows for two things: both ends can verify the identity of the other end and data sent between both ends is encrypted.

## Common Issues

There are two big issues with TCP connection: setup and end of data transfer. Setup is costly cause of three handshakes and could become even more costly in case of HTTPS, cause TLS connection needs another three-way handshake.

When we do an HTTP request, server will keep sending TCP fragments to client host, and the host will respond with **ACK** messages as it receives the data. If a segment is lost along the way, the server will not receive **ACK** for that segment. In such case server will do fast retransmit: when the packet is lost, the following packet will cause the receiver to send an **ACK** identical to the last **ACK** it sent. The sender will fast retransmit packet if it receives three duplicate ACKs (as there are other cases when **ACK** could get duplicated).

At the end of data transmission the sender stops sending segments, the receiver stops sending ACKs back, so there's no way to fast retransmit algorithm to detect if a packet is lost within the last four segments (~ 5.7 kB) being sent.

HTTP has two strategies for resolving above issues, the first one is persistent connection (keep-alive). HTTP will simply reuse the same connection once single request-response cycle is done. TLS connection is also stays alive in case of HTTPS.

HTTP pipelining is the second strategy which allows sending multiple requests without waiting for response. This could be done in parallel. But from the server side it's still first-in first-out.

These techniques allow us to use TCP in a more efficient way. We don't need to do handshake for every request-response. TCP congestion algorithm performs in a better way. Fast retransmit problem will persist only for last four segments of the entire **connection**, not for every request-response.

## Caching

"The fastest request is one never made". Use caching (HTTP ETag). Cache resources whenever you think that they'll stay valid for some time.

### Note on mobile phones

When you switch to Wi-Fi from 3G and vice versa you have to establish new connection, as you IP changes and the server now needs to send segments to the new address.