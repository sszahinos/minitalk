<h1 align="center">minitalk</h1>
<h2>42Barcelona, level 2</h2>
<h3><u>Description</u></h3>
<p>Communication between server and client, sending a message (string).</p>
<p>The communication must use only SIGUSR1 and SIGUSR2 signals. The server will confirm each signal sending another to the client. UNICODE is supported.</p>
<p>When the server starts, signal listener is activated and waits until a signal is received. When this occurs, transforms each signal into bits (1 or 0) until 8 bits has been received (1 byte). Then, prints the character. This process will continue until the character '\0' is received. Then the server will await for another client's message.</p>
<p>The client just transforms each character of the message to the equivalent in binary and sends each bit one by one. It will wait from one bit to another until a signal SIGUSR1 is received by the server. If the communication is lost, the client will abort in 10s.</p>
