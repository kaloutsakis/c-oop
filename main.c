#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "me.h"

#define MODULE_NAME_HASH (0xfda129b2ce76da89UL)
#define print printf

struct namespace {
    struct {
        const uintmax_t ID; 
        const char      *NAME;
    } module;
    struct {
        int             args;
        const char      **ARGV;
        enum {
          DEBUG, INFO, WARN, ERROR, FATAL, LEVELS
          
        }               trace_level;
        bool            is_trace_enabled;
        const char      *TRACE_TAG[LEVELS];
    } io;
};

typedef struct namespace namespace;

namespace local = {
    {
        MODULE_NAME_HASH,
        "MAIN"
    },
    {
        0,
        NULL,
        DEBUG,
        true,
        {"DEBUG", "INFO", "WARN", "ERROR", "FATAL"},
    }
};


#define using(target, alias) typeof(target) alias = target

int main(int argc, char *argv[]) {
    using(local.io, io);
    using(local.module, mod);
    
    local.io.args = argc;
    local.io.ARGV = (const char **)argv;
    print("[%s] [%s] %s\n", mod.NAME, io.TRACE_TAG[io.trace_level], "Application started");
    print("[%s] [%s] %s %u\n", mod.NAME, io.TRACE_TAG[io.trace_level], "arguments:", io.args);
    
    me.controller.Load("me.conf");
    TRequest request = {
        .header = {
            
        },
        
        .payload = {
            
        }
    };
    
    me.controller.Dispatch(&request);
    me.module.Run(argv);
    me.controller.Unload();
}