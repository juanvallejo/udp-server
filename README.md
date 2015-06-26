UDP Server
==========

Simple udp server in c. Listens on all addresses on port 14552.

###Compiling

To compile using gcc, simply type

```
gcc -o udp udp.c
```

This will compile to a file named `udp`.

###Running

On unix-based environments, simply type

```
./udp
```

###Testing

This program comes with a `node.js` test client. You must have [Node.js](https://nodejs.org/) installed and configured. To run, make sure the udp server has been started, and type

```
node udp.js sample message here
```

You can replace &lt;sample message here&gt; with any message of your choice.
