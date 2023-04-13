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

    for (int i = 0; i < count; i++)
    {
        memcpy(l + elsize * stbds_header(l)->length, (void *)(arr + i * elsize), elsize);
        stbds_header(l)->length++;
    }

    return l;
}