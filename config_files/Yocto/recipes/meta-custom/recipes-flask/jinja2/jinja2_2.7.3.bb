DESCRIPTION = "A small but fast and easy to use stand-alone template engine written in pure python."
HOMEPAGE = "https://pypi.python.org/pypi/Jinja2/2.7.3"
SECTION = "devel/python"
LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://LICENSE;md5=20c831f91dd3bd486020f672ba2be386"

SRCNAME = "Jinja2"

SRC_URI = "https://pypi.python.org/packages/source/J/Jinja2/Jinja2-2.7.3.tar.gz"
SRC_URI[md5sum] = "b9dffd2f3b43d673802fe857c8445b1a"
SRC_URI[sha256sum] = "2e24ac5d004db5714976a04ac0e80c6df6e47e98c354cb2c0d82f8879d4f8fdb"

S = "${WORKDIR}/${SRCNAME}-${PV}"

inherit setuptools
