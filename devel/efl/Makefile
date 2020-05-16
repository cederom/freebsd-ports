# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	efl
DISTVERSION=	1.23.3
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PORTNAME}/
DIST_SUBDIR=	enlightenment

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Enlightenment Foundation Libraries

LICENSE=	BSD2CLAUSE LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	checkmk:devel/check
LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libdbus-1.so:devel/dbus \
		libsndfile.so:audio/libsndfile \
		libibus-1.0.so:textproc/ibus \
		libspectre.so:print/libspectre \
		libraw.so:graphics/libraw

# lib/libeio.so.1
CONFLICTS_INSTALL=	libeio

USES=		compiler:c++14-lang gettext-tools gnome iconv \
		jpeg libtool meson ninja ssl pathfix pkgconfig python:3.6+ shared-mime-info \
		shebangfix tar:xz xorg
SHEBANG_FILES=	examples_checks.py \
		src/scripts/eina/eina-bench-cmp \
		src/scripts/gendoc/gendoc.py \
		src/scripts/pyolian/test_eolian.py \
		src/scripts/pyolian/eolian.py \
		src/scripts/pyolian/generator.py \
		src/scripts/pyolian/eolian_lib.py \
		src/tests/elementary/spec/generator.py
USE_XORG=	x11 xcb xcursor xcomposite xdamage xext xfixes xi xinerama \
		xrandr xrender xtst xscrnsaver
USE_LDCONFIG=	yes

MESON_ARGS=	-Dsystemd=false -Dbluez5=false -Deeze=false \
		-Dlibmount=false -Ddrm=false

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_ICONS=	yes

PLIST_SUB=	BRANCHVERSION=${PORTVERSION:R} PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		AVAHI FRIBIDI HARFBUZZ NLS PHYSICS PULSEAUDIO VNC
OPTIONS_GROUP=		EMOTION INPUT LOADER CRYPTO WAYLAND
OPTIONS_GROUP_EMOTION=	GSTREAMER LIBXINE V4L VLC
OPTIONS_GROUP_INPUT=	IBUS SCIM
OPTIONS_GROUP_LOADER=	OPENJPEG PDF PS RAW SVG WEBP XCF
OPTIONS_GROUP_WAYLAND=	WAYLAND
OPTIONS_RADIO=		CRYPTO ENGINE
OPTINOS_RADIO_CRYPTO=	OPENSSL GNUTLS
OPTIONS_RADIO_ENGINE=	OPENGL OPENGLES SDL
OPTIONS_DEFAULT=	FRIBIDI HARFBUZZ PHYSICS PULSEAUDIO OPENSSL GSTREAMER V4L \
			OPENJPEG PDF PS RAW SVG WEBP XCF OPENGL WAYLAND
OPTIONS_SUB=		yes

HARFBUZZ_DESC=		OpenType text shaping engine
PHYSICS_DESC=		Physics effects
VNC_DESC=		Build with VNC Server support
VLC_DESC=		Multimedia support by VLC
IBUS_DESC=		Intelligent Input Bus
SCIM_DESC=		Smart Common Input Method
XCF_DESC=		Gimp image format support
OPENGLES_DESC=		2D/3D rendering support via OpenGL ES


AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app
AVAHI_MESON_TRUE=	avahi

FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
# this doesnt work for MESON_ARGS - need to add .ifs later
FRIBIDI_MESON_TRUE=	fribidi

HARFBUZZ_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
HARFBUZZ_MESON_TRUE=	harfbuzz

NLS_USES=			gettext-runtime
NLS_MESON_TRUE=			nls

PHYSICS_LIB_DEPENDS=		libBulletDynamics.so:devel/bullet
PHYSICS_MESON_TRUE=		physics

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_TRUE=		pulseaudio

VNC_MESON_TRUE=			vnc-server
VNC_LIB_DEPENDS=		libvncserver.so:net/libvncserver

WAYLAND_BUILD_DEPENDS=		wayland-protocols>=1.7:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=		libepoll-shim.so:devel/libepoll-shim \
				libxkbcommon.so:x11/libxkbcommon \
				libwayland-client.so:graphics/wayland \
				libwayland-cursor.so:graphics/wayland
WAYLAND_CFLAGS=			-I${LOCALBASE}/include/libepoll-shim
WAYLAND_LDFLAGS=		-lepoll-shim
# WL BROKEN: ../src/lib/ecore_wl2/ecore_wl2_buffer.c:20:10:
# fatal error: 'linux/dma-buf.h' file not found
# UNTIL FIXED WL-DEPRECATED IS ONLY POSSIBLE
WAYLAND_MESON_TRUE=		wl

GSTREAMER_USE=			GSTREAMER1=core
GSTREAMER_MESON_TRUE=		gstreamer1

XINE_LIB_DEPENDS=		libxine.so:multimedia/libxine
XINE_MESON_TRUE=		xine

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
V4L_MESON_TRUE=			v4l2

VLC_LIB_DEPENDS=		libvlc.so:multimedia/vlc
VLC_MESON_TRUE=			ulc libvlc

IBUS_LIB_DEPENDS=		libibus-1.0.so:textproc/ibus
IBUS_MESON_TRUE=		ibus

SCIM_LIB_DEPENDS=		libscim-1.0.so:textproc/scim
SCIM_MESON_TRUE=		scim

OPENJPEG_LIB_DEPENDS=		libopenjpeg.so:graphics/openjpeg15
OPENJPEG_MESON_TRUE=		jp2k

PDF_LIB_DEPENDS=		libpoppler.so:graphics/poppler
PDF_MESON_TRUE=			pdf

PS_LIB_DEPENDS=			libspectre.so:print/libspectre
PS_MESON_TRUE=			ps

RAW_LIB_DEPENDS=		libraw.so:graphics/libraw
RAW_MESON_TRUE=			raw

SVG_USE=			GNOME=cairo GNOME=librsvg2
SVG_MESON_TRUE=			svg

WEBP_LIB_DEPENDS=		libwebp.so:graphics/webp
WEBP_MESON_TRUE=		webp

XCF_MESON_TRUE=			xcf

OPENGL_USES=			gl
OPENGL_USE=			GL=gl
OPENGL_MESON_ON=		-Dopengl=full
OPENGL_PREVENTS=		OPENGLES

OPENGLES_USES=			gl
OPENGLES_USE=			GL=glesv2
OPENGLES_MESON_ON=		-Dopengl=es-egl
OPENGLES_PREVENTS=		OPENGL

SDL_USES=			sdl
SDL_USE=			SDL=sdl2
SDL_CONFIGURE_ON=		-Dsdl=true

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
PLIST_SUB+=			AUDIO=""
.else
PLIST_SUB+=			AUDIO="@comment "
PULSEAUDIO_CONFIGURE_ON=	-Dpulseaudio=false
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USES+=				ssl
MESON_ARGS+=			-Dcrypto=openssl
.else
MESON_ARGS+=			-Dcrypto=gnutls
.endif

.if ${PORT_OPTIONS:MGNUTLS}
USES+=				gnutls
MESON_ARGS+=			-Dcrypto=gnutls
.else
MESON_ARGS+=			-Dcrypto=openssl
.endif

.if empty(PORT_OPTIONS:MIBUS)
MESON_ARGS+=			-Decore-imf-loaders-disabler=ibus
.endif

.if empty(PORT_OPTIONS:MSCIM)
MESON_ARGS+=			-Decore-imf-loaders-disabler=scim
.endif

.if empty(PORT_OPTIONS:MOPENGL) && empty(PORT_OPTIONS:MOPENGLES)
MESON_ARGS+=			-Dopengl=none
.endif

.if ${PORT_OPTIONS:MOPENGLES} && ${PORT_OPTIONS:MWAYLAND}
WAYLAND_LIB_DEPENDS+=		libwayland-egl.so:graphics/wayland
WAYLAND_MESON_ARGS=		-Degl=true
WAYLAND_USE=			GL=egl
.endif

# keep in sync with all platforms where libunwind is available
.if (${ARCH} == amd64 || ${ARCH} == i386)
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

.if ${ARCH:Mpowerpc*} || ${ARCH} == "sparc64"
USES+=				lua
MESON_ARGS+=			-Dlua-interpreter=lua
PLIST_SUB+=			ELUA="@comment "
.else
LIB_DEPENDS+=			libluajit-5.1.so:lang/luajit
MESON_ARGS+=			-Dlua-interpreter=luajit
PLIST_SUB+=			ELUA=""
.endif

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/gdb
	@for i in `${FIND} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib -type f`; do \
	    if ${FILE} $$i | ${GREP} -q "not stripped"; then ${STRIP_CMD} $$i; fi; \
	done
	# workaround for https://phab.enlightenment.org/T6783 : it leaves an empty directory
	@if [ -d ${STAGEDIR}${PREFIX}/lib/evas/utils -a -z "$$(ls -A ${STAGEDIR}${PREFIX}/lib/evas/utils)" ]; then \
	    ${RMDIR} ${STAGEDIR}${PREFIX}/lib/evas/utils; \
	fi

.include <bsd.port.mk>
