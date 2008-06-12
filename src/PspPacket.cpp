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
*	Holds some packet info and makes easy access some packet structures
*Special Notes:
*	TODO: none yet
*
*Copyright Stuff:
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
* 
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
* 
*  You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "PspPacket.h"

PspPacket::PspPacket() {
	packet = new packet_container;
	packet->header[0] = 'M';
	packet->header[1] = 'H';
	packet->counter = 0;
	packet->size = 1490;
}
int PspPacket::getPacketCounter() {
	return packet->counter;
}
int PspPacket::getPacketSize() {
	return packet->size + 10;
}
void PspPacket::setPayloadSize(int size) {
	packet->size = size;
}
int PspPacket::getPayloadSize() {
	return packet->size;
}
const u_char *PspPacket::getSrcMAC() {
	return packet->data.src_mac;
}
const char *PspPacket::getScrMACstr() {
	char *mac_str = new char[18];
	u_char *mac = packet->data.src_mac;
	sprintf(mac_str,"%.2x:%.2x:%.2x:%.2x:%.2x:%.2x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	return mac_str;
}
const u_char *PspPacket::getDstMAC() {
	return packet->data.dst_mac;
}
const char *PspPacket::getDstMACstr() {
	char *mac_str = new char[18];
	u_char *mac = packet->data.dst_mac;
	sprintf(mac_str,"%.2x:%.2x:%.2x:%.2x:%.2x:%.2x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	return mac_str;
}
const u_char *PspPacket::getPayload() {
	return packet->data.data;
}
void PspPacket::setPayload(const u_char *data, size_t size) {
	memcpy(&packet->data, data, size);
	packet->size = size;
}
void PspPacket::setSrcMAC(const u_char *mac) {
	memcpy(packet->data.src_mac, mac, 6);
}
void PspPacket::setDstMAC(const u_char *mac) {
	memcpy(packet->data.dst_mac, mac, 6);
}
void PspPacket::setPacketCounter(int count) {
	packet->counter = count;
}
u_char *PspPacket::getPacketData() {
	return (u_char *)packet;
}
bool PspPacket::checkHeader() {
	return packet->header[0] == 'M' && packet->header[1] == 'H';
}
PspPacket::~PspPacket() {
	delete packet;
}
