/* Auto-generated by genfincode_stat.sh - DO NOT EDIT! */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "rtpp_types.h"
#include "rtpp_debug.h"
#include "rtpp_timed.h"
#include "rtpp_timed_fin.h"
static void rtpp_timed_schedule_fin(void *pub) {
    fprintf(stderr, "Method rtpp_timed@%p::schedule (rtpp_timed_schedule) is invoked after destruction\x0a", pub);
    RTPP_AUTOTRAP();
}
static void rtpp_timed_schedule_rc_fin(void *pub) {
    fprintf(stderr, "Method rtpp_timed@%p::schedule_rc (rtpp_timed_schedule_rc) is invoked after destruction\x0a", pub);
    RTPP_AUTOTRAP();
}
static void rtpp_timed_shutdown_fin(void *pub) {
    fprintf(stderr, "Method rtpp_timed@%p::shutdown (rtpp_timed_shutdown) is invoked after destruction\x0a", pub);
    RTPP_AUTOTRAP();
}
static const struct rtpp_timed_smethods rtpp_timed_smethods_fin = {
    .schedule = (rtpp_timed_schedule_t)&rtpp_timed_schedule_fin,
    .schedule_rc = (rtpp_timed_schedule_rc_t)&rtpp_timed_schedule_rc_fin,
    .shutdown = (rtpp_timed_shutdown_t)&rtpp_timed_shutdown_fin,
};
void rtpp_timed_fin(struct rtpp_timed *pub) {
    RTPP_DBG_ASSERT(pub->smethods->schedule != (rtpp_timed_schedule_t)NULL);
    RTPP_DBG_ASSERT(pub->smethods->schedule_rc != (rtpp_timed_schedule_rc_t)NULL);
    RTPP_DBG_ASSERT(pub->smethods->shutdown != (rtpp_timed_shutdown_t)NULL);
    RTPP_DBG_ASSERT(pub->smethods != &rtpp_timed_smethods_fin &&
      pub->smethods != NULL);
    pub->smethods = &rtpp_timed_smethods_fin;
}
#if defined(RTPP_FINTEST)
#include <assert.h>
#include <stddef.h>
#include "rtpp_mallocs.h"
#include "rtpp_refcnt.h"
#include "rtpp_linker_set.h"
#define CALL_TFIN(pub, fn) ((void (*)(typeof(pub)))((pub)->smethods->fn))(pub)

void
rtpp_timed_fintest()
{
    int naborts_s;

    struct {
        struct rtpp_timed pub;
    } *tp;

    naborts_s = _naborts;
    tp = rtpp_rzmalloc(sizeof(*tp), offsetof(typeof(*tp), pub.rcnt));
    assert(tp != NULL);
    assert(tp->pub.rcnt != NULL);
    static const struct rtpp_timed_smethods dummy = {
        .schedule = (rtpp_timed_schedule_t)((void *)0x1),
        .schedule_rc = (rtpp_timed_schedule_rc_t)((void *)0x1),
        .shutdown = (rtpp_timed_shutdown_t)((void *)0x1),
    };
    tp->pub.smethods = &dummy;
    CALL_SMETHOD(tp->pub.rcnt, attach, (rtpp_refcnt_dtor_t)&rtpp_timed_fin,
      &tp->pub);
    RTPP_OBJ_DECREF(&(tp->pub));
    CALL_TFIN(&tp->pub, schedule);
    CALL_TFIN(&tp->pub, schedule_rc);
    CALL_TFIN(&tp->pub, shutdown);
    assert((_naborts - naborts_s) == 3);
}
const static void *_rtpp_timed_ftp = (void *)&rtpp_timed_fintest;
DATA_SET(rtpp_fintests, _rtpp_timed_ftp);
#endif /* RTPP_FINTEST */
