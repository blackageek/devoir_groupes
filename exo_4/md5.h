#ifndef MD5_H
#define MD5_H

#include <sys/types.h>
#ifdef __amigaos4__
#include <machine/endian.h>
#endif

/*  On machines where "long" is 64 bits, we need to declare
    uint32 as something guaranteed to be 32 bits.  */

typedef unsigned int uint32;

typedef struct MD5Context {
  uint32 buf[4];
  uint32 bits[2];
  unsigned char in[64];
} MD5_CTX;

extern void MD5Init(struct MD5Context *ctx);
extern void MD5Update(struct MD5Context *ctx, unsigned char *buf,
                      unsigned int len);
extern void MD5Final(unsigned char digest[16], struct MD5Context *ctx);
extern void MD5Transform(uint32 buf[4], uint32 in[16]);
extern char *MD5File( char *, char *);
extern char *MD5FileChunk(const char *, char *, off_t, off_t);

#endif /* !MD5_H */
