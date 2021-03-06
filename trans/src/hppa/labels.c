/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#include <shared/bool.h>

#include <local/out.h>

#include "procrec.h"
#include "addr.h"
#include "regexps.h"
#include "labels.h"


int firstlab=50, labno;

/*
    The count starts at 50 to avoid confusion with registers.
*/


/*
    This rounds the current label number up to the next multiple of 100.
    It is called at the start of each procedure to aid readability.
*/

void
seed_label(void)
{
    firstlab = ( ( firstlab + labno + 100 ) / 100 ) * 100 ;
    labno=0;
}


/*
    CALCULATE NEXT LABEL NUMBER
*/

int
new_label(void)
{
    labno++ ;
    return firstlab+labno;
}

