--- src/modules/ecore_evas/vnc_server/ecore_evas_vnc_server_fb_keymap.c.orig	2020-05-14 02:37:27.221504000 +0200
+++ src/modules/ecore_evas/vnc_server/ecore_evas_vnc_server_fb_keymap.c	2020-05-14 02:41:59.358400000 +0200
@@ -1,4 +1,8 @@
-#include <linux/input-event-codes.h>
+#if defined(__linux__)
+ #include <linux/input-event-codes.h>
+#elif defined(__FreeBSD__)
+ #include <dev/evdev/input-event-codes.h>
+#endif
 #include <rfb/keysym.h>
 #include <stdlib.h>
 #include <limits.h>
