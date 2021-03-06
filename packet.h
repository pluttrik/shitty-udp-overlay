#ifndef PACKET_H
#define PACKET_H

#include <stdio.h>
#include <sys/types.h>
#include <netinet/in.h>

// FLAGS
#define SYN 1
#define SYNACK 2 
#define ACK 3
#define FIN 4

struct packet{
	int flags;
	int id;
	int seq;
	int windowsize;
	int crc;
	char *data;
};

// Creating a packet and returning it...
struct packet createPacket(int flags, int id, int seq, int windowsize, int crc, char *data);

/* Waits for a package to be received untill timeout
 * Parameters:
 *	mySocket: socket file descriptor
 *	packet: The received packet
 *	source: The source from the received packet
 *	timeout: time before timeout in milliseconds
 * Returns -1 on error, 0 on timeout or amounts of bytes read */
int waitAndReceivePacket(const int mySocket, struct packet *packet, struct sockaddr_in *source, const int timeout);
int receivePacket(const int mySocket, struct packet *packet, struct sockaddr_in *source); // Blocks until packet received

/* Simply sends a packet to destination
	* Parameters:
 *	mySocket: socket file descriptor
 *	packet: The packet to send
 *	destination: The destination to send the packet
 * Returns -1 on error, 0 on timeout or amounts of bytes read */
int sendPacket(const int mySocket, const struct packet *packet, const struct sockaddr_in *destination);

#endif
