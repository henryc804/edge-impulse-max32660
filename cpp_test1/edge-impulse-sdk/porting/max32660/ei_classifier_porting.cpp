/*
 * testing...
 */

//#error "PORTING FILE WAS FOUND"

#include "../ei_classifier_porting.h"

#include <stdarg.h>
#include <stdio.h>
#include "mxc_delay.h"

#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C"
#endif
__attribute__((weak)) void DebugLog(const char* s) {
    ei_printf("%s", s);
}

__attribute__((weak)) void *ei_calloc(size_t nitems, size_t size) {
    return calloc(nitems, size);
}

__attribute__((weak)) void ei_free(void *ptr) {
    free(ptr);
}

__attribute__((weak)) void *ei_malloc(size_t size) {
    return malloc(size);
}

__attribute__((weak)) void ei_printf(const char *format, ...) {
  va_list myargs;
  va_start(myargs, format);
  vprintf(format, myargs);  // not clear to me that vprintf will actually work...not sure where printf is even defined for MAX32660 boards
  va_end(myargs);
}

__attribute__((weak)) void ei_printf_float(float f) {
    printf("%.6f", f);
}

uint64_t ei_read_timer_ms() {
//    return millis();
  return 0;
}

uint64_t ei_read_timer_us() {

//  numberOfTicks = SysTick->VAL;
//
////  convert to number of us...
//  ticks = (uint32_t)(((uint64_t)us * (uint64_t)SystemCoreClock) / 1000000);
//
//
//
//    return micros();
  return 0;
}

__attribute__((weak)) EI_IMPULSE_ERROR ei_run_impulse_check_canceled() {
    return EI_IMPULSE_OK;
}

EI_IMPULSE_ERROR ei_sleep(int32_t time_ms) {
  MXC_Delay(time_ms * 1000);
  return EI_IMPULSE_OK;
}
