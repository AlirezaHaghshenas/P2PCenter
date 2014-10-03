IE to P2PService the URL specified: 
Get file interface: 
Format: http: // host: port / filename.rmvb serveraddr = serverhost & tcpport = tcpport & updoort = 3344 & agent = agentname & upuserid = 1 & userid = 111 & nodename = nodename (char [32]) & filehash = char [32] & filesize = DWORD [4] & filepath = D? : \ xxx 
Example: http: //127.0.0.1: 81 / test.rmvb serveraddr = p2p.kan8888.com & tcpport = 8902 & udpport = 3344 & agent = shengcong & upuserid = 1 & userid = 999 & nodename = KevinTestNode & filehash = ABCD3458934759834753479857349444 & filesize = 333654321 & filename = FileName.rmvb & filepath = C:? \\ Ttt \ test.rmvb 
Required parameters: nodename node HASH, that directory, an agent can have multiple directories can also be called a constituency group 
filehash corresponding directory file MD5 HASH code standard, 32-byte file as a criterion for distinguishing 
Actual filesize file length in bytes 
filepath file path, valid only for source 
Optional parameters: serveraddr (default: p2p.kan8888.com), tcpport (default: 8902), udpport (default: 3344), agent, upuserid, userid 
The current version serveraddr tcpport udpport still in the server configuration on hold .P2PNetwork connection is provided by P2PNetwork.ini 

Obtain monitoring data interface: 
Format: http: // host:? Port / monitor.js channelhash = char [32] 
Example: http: // host:? Port / monitor.js channelhash = ABCD3458934759834753479857349444 
Optional parameters: channelhash length must be 32 bytes of the file encoding standard MD5 HASH code, get all the channels for air monitoring 

URL provisions App to P2PNetwork of: 
Format: kp2p: // tcpserver: tcpport / .... 
IE to URL parameters specified P2PService of similar, less tcpserver and tcpport 
Note: UDP holes UDPSERVER: UPDPORT by connecting tcpserver: After tcpport, login to return