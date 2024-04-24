#include "event2/event-config.h"
#include "evconfig-private.h"

#ifdef EVENT__HAVE_IOURING

#include <liburing.h>

#include "event-internal.h"
#include "iouring-internal.h"

struct event_io_ring *
event_iouring_create_(void)
{
    struct event_io_ring *uring = NULL;
    int rv;

    if (!(uring = mm_calloc(1, sizeof(struct event_io_ring))))
		return NULL;

    // TODO: pass in num entries as a configuration option
    rv = io_uring_queue_init(128, &uring->ring, 0);

    if (rv < 0)
        goto err;

    return uring;

err:
    mm_free(uring);

    return NULL;
}


int
event_iouring_shutdown_(struct event_io_ring *uring)
{
    io_uring_queue_exit(&uring->ring);

    return 0;
}

#endif /* EVENT__HAVE_IOURING */