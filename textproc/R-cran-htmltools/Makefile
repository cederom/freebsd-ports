# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	htmltools
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools for HTML generation and output

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-digest>0:security/R-cran-digest \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-rlang>0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
