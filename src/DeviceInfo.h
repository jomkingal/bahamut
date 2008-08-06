/*
 *  Project Bahamut: full ad-hoc tunneling software to be used by the
 *  Playstation Portable (PSP) to emulate online features.
 *
 *  Copyright (C) 2008  Codestation
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * File Description:
 *     Holds the MAC address of the device and provide some util functions
 * Special Notes:
 *     TODO: none yet
 */

#ifndef DEVICEINFO_H_
#define DEVICEINFO_H_

#ifdef _WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


class DeviceInfo {
private:
	u_char mac[6];
	//temporary buffer to hold the MAC string
	char mac_str[18];
public:
	DeviceInfo(const u_char *psp_mac);
	const u_char *getMAC();
	char *getMACstr();
	void setMAC(const u_char *mac);
	int compareMAC(const u_char *mac);
	virtual ~DeviceInfo();
};

#endif /*DEVICEINFO_H_*/