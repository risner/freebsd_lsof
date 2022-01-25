--- dialects/freebsd/dlsof.h.orig	2021-12-19 10:07:12 UTC
+++ dialects/freebsd/dlsof.h
@@ -551,7 +551,11 @@ struct	namecache {
 #   else
 	LIST_ENTRY(namecache) nc_src;   /* source vnode list */
 	TAILQ_ENTRY(namecache) nc_dst;  /* destination vnode list */
+#   if  __FreeBSD_version >= 1300000
+	SLIST_ENTRY(namecache) nc_hash;  /* hash chain */
+#   else
 	LIST_ENTRY(namecache) nc_hash;  /* hash chain */
+#   endif
 #   endif
 	struct	vnode *nc_dvp;		/* vnode of parent of name */
 	struct	vnode *nc_vp;		/* vnode the name refers to */
