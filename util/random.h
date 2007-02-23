/*
 * util/random.h - thread safe random generator, which is reasonably secure.
 * 
 * Copyright (c) 2007, NLnet Labs. All rights reserved.
 * 
 * This software is open source.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * 
 * Neither the name of the NLNET LABS nor the names of its contributors may
 * be used to endorse or promote products derived from this software without
 * specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef UTIL_RANDOM_H
#define UTIL_RANDOM_H

/**
 * \file
 * Thread safe random functions. Similar to random(3) and initstate(3).
 */

/**
 * random state structure.
 */
struct ub_randstate {
	long int* state;
	long int* fptr;
	long int* rptr;
	int rand_type;
	int rand_deg;
	int rand_sep;
	long int* end_ptr;
};

/**
 * Initialize a random generator state for use 
 * @param seed: seed value to create state contents.
 * @param state: struct allocated by caller.
 * @param n: size of state->state. 8, 32, 64, 128, or 256 bytes.
 * @return false alloc failure.
 */
int ub_initstate(unsigned int seed, struct ub_randstate* state, 
	unsigned long n);

/**
 * Generate next random number from the state passed along.
 * Thread safe, so random numbers are repeatable.
 * @param state: must have been initialised with ub_initstate.
 * @return: random 31 bit value.
 */
long int ub_random(struct ub_randstate* state);

#endif /* UTIL_RANDOM_H */
