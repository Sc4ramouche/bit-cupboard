# [IP, TCP, and HTTP](https://www.objc.io/issues/10-syncing-data/ip-tcp-http/)

## IP

Internet Protocol. Introduces the concept of **hosts** - machines actually. IP protocol specifies how packets are sent between hosts.

Packet turns out to be binary data that has source host and destination host. Packets are delivered using *best effort* - packet may be lost along the way. Or it may get duplicated and arrive several times at the destination.

Each host has **IP address**. As each packet has source and destination address, IP is responsible for routing datagrams (packets). As the IP packet travels through the network, each host (node) checks packet destination address to figure out in which direction to forward the packet.

IPv4 - Internet Protocol version 4.