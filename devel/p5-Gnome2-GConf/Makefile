# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	Gnome2-GConf
PORTVERSION=	1.044
PORTREVISION=	8
CATEGORIES=	devel gnome perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl bindings for the GConf2 configuration engine

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2
RUN_DEPENDS=	p5-Glib>=0:devel/p5-Glib

USES=		gnome perl5
USE_PERL5=	configure
USE_GNOME=	gconf2
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
