#include <stdio.h>

#include "me.h"
#include "controller.h"

static void me_init(void) __attribute__((constructor)); 

const char *VERSION = "1.0.0.0";

static int Run(const char **params) {
    printf("[API] [DEBUG] Initializing ME Module\n");
    return 0;
}

typeof(me) me = {
    {
        NULL,
        NULL,
        NULL
    },
    {
        Run,
        NULL,
        NULL,
        NULL
    }
};

#if 0
struct {
    struct {
        int (*Load)    (const char     *path);
        int (*Unload)  (void);
        int (*Dispatch)(const TRequest *request);
    } controller;
    
    struct {
        int (*Run)     (const char     **params);
        int (*Reset)   (const char     **params);
        int (*Pause)   (void);
        int (*Continue)(void);
    } module;
} me;
#endif

void me_init(void) {
    printf("[API] [DEBUG] Initializing ME\n");
    
    me.controller = controller;
}