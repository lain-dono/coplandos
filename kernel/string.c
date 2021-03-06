#include <stdint.h>
#include <string.h>

size_t strlen(const char* string) {
	size_t result = 0;
	while (string[result]) result++;
	return result;
}

void* memmove(void* dstptr, const void* srcptr, size_t size) {
	uint8_t* dst = (uint8_t*) dstptr;
	const uint8_t* src = (const uint8_t*) srcptr;

	if (dst < src) {
		for (size_t i = 0; i < size; i++)
			dst[i] = src[i];
	} else {
		for (size_t i = size; i != 0; i--)
			dst[i-1] = src[i-1];
	}

	return dstptr;
}

int memcmp(const void* aptr, const void* bptr, size_t size) {
	const uint8_t* a = (const uint8_t*) aptr;
	const uint8_t* b = (const uint8_t*) bptr;

	for (size_t i = 0; i < size; i++) {
		if (a[i] < b[i]) return -1;
		else if (b[i] < a[i]) return 1;
	}

	return 0;
}

void* memset(void* bufptr, int value, size_t size) {
	uint8_t* buf = (uint8_t*) bufptr;

	for (size_t i = 0; i < size; i++)
		buf[i] = (unsigned char) value;

	return bufptr;
}

void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size) {
	uint8_t* dst = (uint8_t*) dstptr;
	const uint8_t* src = (const uint8_t*) srcptr;

	for (size_t i = 0; i < size; i++)
		dst[i] = src[i];

	return dstptr;
}

