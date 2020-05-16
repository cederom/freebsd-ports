--- src/lib/eeze/eeze_net.c.orig	2020-02-13 07:40:51 UTC
+++ src/lib/eeze/eeze_net.c
@@ -7,6 +7,9 @@
 #include <net/if.h>
 #include <unistd.h>
 #include <Eeze_Net.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <libifconfig.h>
 
 #include "eeze_udev_private.h"
 #include "eeze_net_private.h"
@@ -177,29 +180,29 @@ eeze_net_scan(Eeze_Net *net)
 #endif
    int sock;
    int ioctls[3] = {SIOCGIFADDR, SIOCGIFBRDADDR, SIOCGIFNETMASK}, *i = ioctls;
-   struct ifreq ifr;
+   struct ifaliasreq ifr;
    struct sockaddr_in *sa;
 
    EINA_SAFETY_ON_NULL_RETURN_VAL(net, EINA_FALSE);
 
    /* ensure that we have the right name, mostly for hahas */
-   if_indextoname((unsigned int)net->index, ifr.ifr_name);
+   if_indextoname((unsigned int)net->index, ifr.ifra_name);
    ifr.ifr_addr.sa_family = AF_INET;
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) return EINA_FALSE;
 
    if (ioctl(sock, *i++, &ifr) < 0) goto error;
-   sa = (struct sockaddr_in*) & (ifr.ifr_addr);
+   sa = (struct sockaddr_in*) & (ifr.ifra_addr);
    inet_ntop(AF_INET, (struct in_addr*)&sa->sin_addr, ip, INET_ADDRSTRLEN);
    eina_stringshare_replace_length(&net->ip, ip, INET_ADDRSTRLEN);
 
    if (ioctl(sock, *i++, &ifr) < 0) goto error;
-   sa = (struct sockaddr_in*) & (ifr.ifr_broadaddr);
+   sa = (struct sockaddr_in*) & (ifr.ifra_broadaddr);
    inet_ntop(AF_INET, (struct in_addr*)&sa->sin_addr, ip, INET_ADDRSTRLEN);
    eina_stringshare_replace_length(&net->broadip, ip, INET_ADDRSTRLEN);
 
    if (ioctl(sock, *i++, &ifr) < 0) goto error;
-   sa = (struct sockaddr_in*) & (ifr.ifr_netmask);
+   sa = (struct sockaddr_in*) & (ifr.ifra_netmask);
    inet_ntop(AF_INET, (struct in_addr*)&sa->sin_addr, ip, INET_ADDRSTRLEN);
    eina_stringshare_replace_length(&net->netmask, ip, INET_ADDRSTRLEN);
 
@@ -211,17 +214,17 @@ eeze_net_scan(Eeze_Net *net)
    if (sock < 0) return EINA_FALSE;
 
    if (ioctl(sock, *i++, &ifr) < 0) goto error;
-   sa6 = (struct sockaddr_in6*) & (ifr.ifr_addr);
+   sa6 = (struct sockaddr_in6*) & (ifr.ifra_addr);
    inet_ntop(AF_INET6, (struct in6_addr*)&sa6->sin6_addr, ip6, INET6_ADDRSTRLEN);
    eina_stringshare_replace_length(&net->ip6, ip6, INET6_ADDRSTRLEN);
 
    if (ioctl(sock, *i++, &ifr) < 0) goto error;
-   sa6 = (struct sockaddr_in6*) & (ifr.ifr_broadaddr);
+   sa6 = (struct sockaddr_in6*) & (ifr.ifra_broadaddr);
    inet_ntop(AF_INET6, (struct in6_addr*)&sa6->sin6_addr, ip6, INET6_ADDRSTRLEN);
    eina_stringshare_replace_length(&net->broadip6, ip6, INET6_ADDRSTRLEN);
 
    if (ioctl(sock, *i++, &ifr) < 0) goto error;
-   sa6 = (struct sockaddr_in6*) & (ifr.ifr_netmask);
+   sa6 = (struct sockaddr_in6*) & (ifr.ifra_netmask);
    inet_ntop(AF_INET6, (struct in6_addr*)&sa6->sin6_addr, ip6, INET6_ADDRSTRLEN);
    eina_stringshare_replace_length(&net->netmask6, ip6, INET6_ADDRSTRLEN);
 
