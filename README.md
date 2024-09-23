# prng.h
### Single-header fast 32-bit insecure pseudo-random number generator
---

This is a non-cryptographically secure pseudo-random number generator which uses
very basics Linear Congruential Generators. It is dependency free (even from the
standard library) which makes it very portable. It operates on and generates 32-
bits numbers which also make it good for a category of small embedded devices.

# Usage
---

Include the header file in every file you want to use it.
```c
#include "prng.h"
```

In **ONE** file, define `PRNG_IMPL` **before** including the header file.
```c
#define PRNG_IMPL
#include "prng.h"
```

# Documentation
---

```c
void prng_config(uint32_t seed1, uint32_t seed2);
```
Configure the PRNG with two 32-bit seeds.

```c
uint32_t prng_rand(void)
```
Returns a 32-bit pseudo-random number.
