# Exercises for Wednesday Dec 04, 2019

## Socket Programming Preparatory Session

Today you need to read and understand the code snippets for network programming in BOH. Some of the code snippets have been covered previously (rio functions) and some (socket interface) will be covered in the lecture today. 

* Refresh your understanding of rio functions which were covered earlier in the course
  * rio_readn, rio_writen (Fig 10.4 BOH page 935)
  * rio_read (Fig 10.7 BOH page 937)
  * rio_readlineb, rio_readnb (Fig 10.8 BOH page 938)
  * Read and understand Section 10.11 (especially directives G1,G2,G3) in BOH page 947-948
  * Using rio functions are not strictly necessary you can use UNIX I/O functions but they simplify programming a lot

* Understand socket interface
  * Read man pages of socket, bind, connect, listen, accept, read and write. 
  * hostinfo example code (Fig 11.17 BOH page 977)
  * open_clientfd code (Fig 11.18 BOH page 979)
  * open_listenfd code (Fig 11.19 BOH page 981)
  * Echo client/iterative server example code (Fig 11.20 - 11.22 BOH page 982-983)
  * Using the wrapper functions is optional but they simplify programming a lot

* You can find the source refs for the BOH book [here](http://csapp.cs.cmu.edu/3e/code.html)

## Wireshark lab

See the HTTP protocol in action (message types and details).

* Do the "HTTP" [Wireshark lab](https://www-net.cs.umass.edu/wireshark-labs/). Ask your TA for help if you have trouble understanding anything. 
