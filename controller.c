#include <stdio.h>
#include "controller.h"

static int Load    (const char     *path);
static int Unload  (void);
static int Dispatch(const TRequest *request);

typeof(me.controller) controller = {
    .Load = Load,
    .Unload = Unload,
    .Dispatch = Dispatch
};

int Load    (const char *path) {
    printf("[%s] [%s] %s\n", "CONTROLLER", "DEBUG", "Loading controller...");
    return 0;
}

int Unload  (void) {
    printf("[%s] [%s] %s\n", "CONTROLLER", "DEBUG", "Unloading controller...");
    return 0;
}

int Dispatch(const TRequest *request) {
    printf("[%s] [%s] %s\n", "CONTROLLER", "DEBUG", "Dispatching request...");
    return 0;
}
