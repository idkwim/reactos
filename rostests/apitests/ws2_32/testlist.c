#define WIN32_LEAN_AND_MEAN
#define __ROS_LONG64__
#include <windows.h>

#define STANDALONE
#include "wine/test.h"

extern void func_getaddrinfo(void);
extern void func_ioctlsocket(void);
extern void func_recv(void);
extern void func_WSAStartup(void);

const struct test winetest_testlist[] =
{
    { "getaddrinfo", func_getaddrinfo },
    { "ioctlsocket", func_ioctlsocket },
    { "recv", func_recv },
    { "WSAStartup", func_WSAStartup },

    { 0, 0 }
};

