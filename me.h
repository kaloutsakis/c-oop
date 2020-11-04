#ifndef ME_ME_H
#define ME_ME_H

typedef struct TRequest {
    enum {
        STOCK_NAME_LEN = (15UL + 1UL)
    } stock;
    
    struct {
        int type;
        int size;
    } header;
    
    struct {
        float price;
        char  stock[STOCK_NAME_LEN];
    } payload;
} TRequest;

extern const char *VERSION;

extern struct {
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