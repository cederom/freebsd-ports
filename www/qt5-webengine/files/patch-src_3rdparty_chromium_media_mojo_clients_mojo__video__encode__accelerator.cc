--- src/3rdparty/chromium/media/mojo/clients/mojo_video_encode_accelerator.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/media/mojo/clients/mojo_video_encode_accelerator.cc
@@ -124,7 +124,7 @@ void MojoVideoEncodeAccelerator::Encode(scoped_refptr<
             frame->layout().num_planes());
   DCHECK(vea_.is_bound());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (frame->storage_type() == VideoFrame::STORAGE_DMABUFS) {
     DCHECK(frame->HasDmaBufs());
     vea_->Encode(
