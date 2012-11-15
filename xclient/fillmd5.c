/* File:
 * ---------------
 * 调用openssl提供的MD5函数
 */

#include <stdint.h>
#include <assert.h>
#include <string.h>

//from md5.c
extern void MD5Calc(unsigned char *data, unsigned int len, unsigned char *output);

void FillMD5Area(uint8_t digest[], uint8_t id, const char passwd[], const uint8_t srcMD5[])
{
	uint8_t	msgbuf[128]; // msgbuf = ‘id‘ + ‘passwd’ + ‘srcMD5’

	int	passlen = strlen(passwd);
	int msglen = 1 + passlen + 16;
	assert(sizeof(msgbuf) >= msglen);

	msgbuf[0] = id;
	memcpy(msgbuf+1, passwd, passlen);
	memcpy(msgbuf+1+passlen, srcMD5, 16);

	//(void)MD5(msgbuf, msglen, digest);
	MD5Calc(msgbuf, msglen, digest);
}

