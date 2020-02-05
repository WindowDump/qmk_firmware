#pragma once

#include "quantum.h"

#define LAYOUT( \
	K00, K01, K02, K03, K04, \
	     K11, K12, K13, K14 \
)  { \
	{ K00, K01, K02, K03, K04 }, \
	{ KC_NO, K11, K12, K13, K14 } \
}
