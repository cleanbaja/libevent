#ifndef IOURING_INTERNAL_H_INCLUDED_
#define IOURING_INTERNAL_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef EVENT__HAVE_IOURING

#include <liburing.h>

struct event_io_ring {
    struct io_uring ring;
};

/** Wrappers around `event_iouring_create_`/`event_iouring_shutdown_`.
   
    Internal use only.
 */
EVENT2_EXPORT_SYMBOL
int event_base_start_iouring_(struct event_base *base);
void event_base_stop_iouring_(struct event_base *base);

/** Create an IO Uring.  Internal use only.

    This interface is unstable, and will change.
 */
EVENT2_EXPORT_SYMBOL
struct event_io_ring *event_iouring_create_(void);

/** Destroy an IO Uring.  Internal use only.

    This interface is unstable, and will change.
 */
EVENT2_EXPORT_SYMBOL
int event_iouring_shutdown_(struct event_io_ring *uring);

#endif

#ifdef __cplusplus
}
#endif

#endif
