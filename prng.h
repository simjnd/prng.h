// -- HEADER -------------------------------------------------------------------

#ifndef PRNG_H
#define PRNG_H

#ifndef A1
  #define A1 1664525
#endif

#ifndef A2
  #define A2 22935477
#endif

#ifndef C1
  #define C1 101390422
#endif

#ifndef C2
  #define C2 39284392
#endif

void prng_config(uint32_t seed1, uint32_t seed2);
uint32_t prng_rand(void);

#endif

// -- IMPLEMENTATION -----------------------------------------------------------

#ifdef PRNG_IMPL

static uint32_t seed1 = 2147482647;
static uint32_t seed2 = 4294967292;

void prng_config(uint32_t seed1, uint32_t seed2) {
  seed1 = seed1 ^ 0x5A5A5A5A;
  seed2 = seed2 ^ 0xA5A5A5A5;
}

uint32_t prng_rand(void) {
  seed1 = seed1 * A1 + C1;
  seed2 = seed2 * A2 + C2;
  return (seed1 ^ (seed2 >> 16)) ^ ((seed1 << 5) | (seed2 >> 3));
}

#endif
