DESCRIPTION = "Random assortment of WSGI servers"
HOMEPAGE = "https://https://pypi.python.org/pypi/flup/1.0.2"
LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://PKG-INFO;md5=6d27df765893654fc6b092c83fb372d7"

PR = "r0"
SRCNAME = "flup"
PV = "1.0.2"

SRC_URI = "https://pypi.python.org/packages/source/f/flup/flup-1.0.2.tar.gz"
SRC_URI[md5sum] = "24dad7edc5ada31dddd49456ee8d5254"
SRC_URI[sha256sum] = "4bad317a5fc1ce3d4fe5e9b6d846ec38a8023e16876785d4f88102f2c8097dd9"


S = "${WORKDIR}/${SRCNAME}-${PV}"

inherit setuptools

CLEANBROKEN = "1"

