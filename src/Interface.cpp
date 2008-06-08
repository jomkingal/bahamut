/*
*Project Name: Bahamut
* 
*Programmers: Codestation, ZackVixACD
* 
*Project Descrption: The project bahamut is a full ad-hoc tunneling
*	software to be used by the Playstation Portable (PSP) to emulate 
*	online features.
*
*File Description:
*	Network interface functions
*Special Notes:
*	TODO: use the native functions for every platform
* 		: make a tun/tap alternative
*
*Copyright Stuff:
* 	TODO: put GPLv3 header
*/

#include "Interface.h"

/*
 * Default constructor
 * Parameters:
 * 		dev: name of the network device to open
 * Returns: void
*/
Interface::Interface(const char *dev) {
	handle = NULL;
	this->dev = strdup(dev);
}
/*
 * Default destructor
 * Parameters:
 * 		none
 * Returns: void
*/
Interface::~Interface() {
	//make sure that we close the interface before destroy the object
	close();
}

/*
 * Tries to open the given interface on promiscuous
 * Parameters:
 * 		none
 * Returns: true if the interface is open, false otherwise
*/
bool Interface::open() {
	return (handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf)) != NULL;
}

/*
 * Register a function callback and enter in a loop (this function doesnt
 * come back until breakLoop is called from another thread)
 * Parameters:
 * 		packet_func: a pointer of a function specified by pcap_handler
 * Returns: -1 if an error occurs, -2 if breakLoop was called 
*/
int Interface::captureLoop(pcap_handler packet_func) {
	return pcap_loop ( handle, -1, packet_func, (u_char *)dev);
}

/*
 * Puts the specified packet in the interface
 * Parameters:
 * 		packet_data: a pointer to the packet data
 * 		size: size of data to read
 * Returns: 0 if the packet was sent, -1 on error
*/
int Interface::inject(const u_char *packet_data, size_t size) {
	return pcap_sendpacket (handle, packet_data, size);
}

/*
 * Breaks the current captureLoop
 * Parameters:
		none
 * Returns: void
*/
void Interface::breakLoop() {
	pcap_breakloop(handle);
}

/*
 * Compiles a filter to be used at interface level (see pcap documentation)
 * 		If the result of the filter is true, the packet is captured, else
 * 		the packet is dropped.
 * Parameters:
		filter: filter sentence
 * Returns: 0 on success, -1 on erroneous filtering string
*/
int Interface::compileFilter(char *filter) {
	bpf_u_int32 pcap_netmask;
	bpf_u_int32 pcap_ip;
	if(pcap_lookupnet(dev, &pcap_ip, &pcap_netmask, errbuf) == -1)
		return -1;	
	return pcap_compile(handle, &fp, filter, 1, pcap_netmask);
}

/*
 * Uses the current compiled filter on the interface
 * Parameters:
		none
 * Returns: 0 on success, -1 on error
*/
int Interface::setFilter() {
	return pcap_setfilter(handle, &fp);
}

/*
 * Closes the interface
 * Parameters:
		none
 * Returns: void
*/
void Interface::close() {
	if(handle) {
		pcap_close(handle);
		handle = NULL;
	}
}
