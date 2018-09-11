#### Considering Propagation Delay


It takes a discrete amount of time for digital binary signals to move through a wire's medium. 
This time depends on the physical medium  and the length of the link. This relationship 
is described in the ratio which is known as the propagation delay. Since this delay is certainly 
not the same thing as the Transmission delay and is too large to be negligable, we must consider it 
in our calculations of end-to-end delay. We add propagation delay to our consideration in this assignment.
We worked out some examples involving the propagation delay in the PDF a2.pdf. 


Also, we devised an expression for the total end to end delay which considers propagation delay 
and transmission delay for an arbitrary number of packets and routers. Here is the formula, 
as a function of number of routers and packets, listed below coupled with a time table justification.

<img src="https://gist.githubusercontent.com/jawardell/58b723cdc0451ac4e9eb2ba577643a8a/raw/ddf3a9f6967c3a0ae8fd22bf3a8dc723902377a9/formula.png">


Here is a time table of the system descirbed.
<img src="https://gist.githubusercontent.com/jawardell/58b723cdc0451ac4e9eb2ba577643a8a/raw/efdd93a61656e0d45fed72af9b3131832f8f4dc4/chart.PNG">

