FILESEXTRAPATHS_prepend := "${THISDIR}/${BP}:"

RDEPENDS_${PN} += " \
		lighttpd-module-fastcgi \
		lighttpd-module-alias \
		lighttpd-module-rewrite \
"
