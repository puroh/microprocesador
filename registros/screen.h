#ifndef _SCREEN_H_
#define	_SCREEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <curses.h>

#include "colors.h"

void showRegisters(uint32_t *registers, size_t len);

#endif	// _SCREEN_H_ 
