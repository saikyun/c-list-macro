#include <stdarg.h>
#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

#define list(...)                                                                  \
    (typeof(__VA_ARGS__)*)(init_list( \
        sizeof(typeof(__VA_ARGS__)), \
        sizeof((typeof(__VA_ARGS__)[]){ __VA_ARGS__ }) / sizeof(typeof(__VA_ARGS__)), \
    (typeof(__VA_ARGS__)[]){ __VA_ARGS__ }))

void *init_list(size_t elsize, int count, void *arr)
{
    void *l = NULL;
    l = stbds_arrgrowf_wrapper(l, elsize, 0, count);

    memcpy(l + elsize * stbds_header(l)->length, (void *)arr, elsize * count);
    stbds_header(l)->length += count;

    return l;
}