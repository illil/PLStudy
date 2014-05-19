#include "crc8.h"

unsigned char Crc8(const void *vptr, int len)
{
	const unsigned char *data = (unsigned char*)vptr;
	unsigned crc = 0;
	int i, j;
	for (j = len; j; j--, data++) {
		crc ^= (*data << 8);
		for (i = 8; i; i--) {
			if (crc & 0x8000)
				crc ^= (0x1070 << 3);
			crc <<= 1;
		}
	}
	return (unsigned char)(crc >> 8);
}