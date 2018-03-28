/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <stdlib.h>

#include "../util.h"

const char *
load_avg(const char *fmt)
{
	double avgs[3];

	if (getloadavg(avgs, 3) < 0) {
		fprintf(stderr, "Failed to get the load avg");
		return NULL;
	}

	return bprintf(fmt, avgs[0], avgs[1], avgs[2]);
}
