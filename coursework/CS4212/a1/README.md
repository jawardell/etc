#### Analyzing How Transmission Delay Depends on Packet Size
##### Packet Switching

What if we have a message of 16kb which we want to send using packet switching? Obviously the message of 16kb will take longer to transmit as a unit than if we divided it up into let's say 4 packets. <br>

Does message segmentation always solve the problem of transmission delay?<br>

The answer is no because of the overhead caused by header bits. Since every packet has header bits, if we make too many divisions, the number of header bits causes even more transmission delay than what we started with. <br>

We explored this concept in the following way. Suppose that we have a message of 16kb. Analyze the variation of the transmission delay with 0, 10, and 20 header bits while segementing the message in half down to 125 bits. We ignore the other nodal delays.<br>

One approch to this problem is to draw a time table for a general number of packets. Here is the model of the system generalized an arbitrary number of packets: <br><br><img src="https://gist.githubusercontent.com/jawardell/58b723cdc0451ac4e9eb2ba577643a8a/raw/7c06af7e81874b8169676fe9ae557613a53f8cda/Program.png"><br><br>

We see that the number of blocks that it takes for the first packet to reach the destintion is 2 (where each block is a unit of transmission delay), which is coincidentally the number of routers in our system. Since this gap size is constant for our system, the variation occurs in the number of packets that the message is divided into and the transmission rate of each packet. We can compose an algorithmic formula for calculating the delay in the system: <br> `d_trans = msg_len/((pkt_len - header_bits) + gap) * (pkt_len/trans_rate)`<br><br>

Another approach is to use the definition of transmission delay to devise a close form formula for calulating the general delay time in seconds: <br><br>
<img src="https://gist.githubusercontent.com/jawardell/58b723cdc0451ac4e9eb2ba577643a8a/raw/7ae81e7efae754d52157da0a60b04dbce25537e2/Screen%2520Shot%25202018-08-21%2520at%25206.04.05%2520PM.png"><br><br>

Plotting the data reveals a spike in delay times as the number of packets grows (i.e. the packet sizes get smaller) <br>
<img src="https://gist.githubusercontent.com/jawardell/58b723cdc0451ac4e9eb2ba577643a8a/raw/7ae81e7efae754d52157da0a60b04dbce25537e2/img2.png"><br><br>

If we use logarithmic scaling to express the packet sizes (since they cut in half every iteration), the graph becomes easier to interpret.<br><img src="https://gist.githubusercontent.com/jawardell/58b723cdc0451ac4e9eb2ba577643a8a/raw/7ae81e7efae754d52157da0a60b04dbce25537e2/img1.png"><br><br>



Of course, this system is completely hypothetical and is not realistic because we ignored three of the four nodal delays. 
The purpose of this was to see how end to end delay depends on transmission delay and message segmentation.
