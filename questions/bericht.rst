.. include:: etc/kopf.rst


Leseliste für die Klausur
=========================



A Typical Embedded System
=========================

Wie bootet ein Embedded Linux Rechner?
--------------------------------------

.. figure:: img/bootloader.jpg
  :align: center



[ATES]_


Welche Aufgaben hat der Bootloader?
-----------------------------------


[ATES]_


Welche besonderen Filesysteme gibt es für Embedded Linux?
---------------------------------------------------------


[ATES]_


Welche Unterschiede gibt es beim Kernel im Vergleich zum PC?
------------------------------------------------------------


[ATES]_


Welche Bedeutung hat die C Bibliothek?
--------------------------------------


[ATES]_


Was ist die “Busybox”?
----------------------


[ATES]_


Wie funktioniert Cross-Kompilierung?
------------------------------------


[ATES]_


Welche Distribution für Embedded Linux werden erwähnt?
------------------------------------------------------


[ATES]_


Ist der Apache Webserver eine gute Wahl? Welche anderen Webserver gibt es noch?
-------------------------------------------------------------------------------


[ATES]_


Welche Werkzeuge gibt es zur Programmierung grafischer Oberflächen?
-------------------------------------------------------------------


[ATES]_


Fazit: Was ist der Unterschied zwischen Embedded Linux und “gewöhnlichem” Linux?
--------------------------------------------------------------------------------


[ATES]_


Tips for planning an embedded Linux project
===========================================

[TPEL]_

Welche Anforderungen sprechen für Linux? (5 Stück)
--------------------------------------------------

[TPEL]_


Wie “bezahlt” man die Vorteile von Linux?
-----------------------------------------

[TPEL]_


Aus welchen Einzelteilen besteht Embedded Linux? (6 Stück)
----------------------------------------------------------

[TPEL]_


Welche Fähigkeiten braucht man, um einen Rechner mit Embedded Linux auszustatten und zu programmieren?
------------------------------------------------------------------------------------------------------

[TPEL]_


Welche Kosten sind zu erwarten?
-------------------------------

[TPEL]_


Welche Risiken gibt es?
-----------------------

[TPEL]_


Was umfasst der Lebenszyklus des Produktes?
-------------------------------------------

[TPEL]_


Speichertechnologien und Filesystems
====================================


Wie funktioniert Flash Speicher?
--------------------------------

[STFS]_


Welche grundsätzlichen Bausteintypen gibt es?
---------------------------------------------

[STFS]_


Was verstehen Sie unter dem Kürzel “MTD”?
-----------------------------------------

[STFS]_


Was ist CRAMFS?
---------------

[STFS]_


Was ist SQUASHFS?
-----------------

[STFS]_


Was ist JFFS2?
--------------

[STFS]_


Was ist YAFFS?
--------------

[STFS]_



Anatomy of Flash Filesystems
============================


Was ist das Virtual File System VFS?
------------------------------------


[AFFS]_



Was sind “bad blocks” und “wear leveling”?
------------------------------------------


[AFFS]_


Was kann man über die Mount-Zeit von verschiedenen Flash Filesystemen sagen?
----------------------------------------------------------------------------


[AFFS]_


Embedded Linux Primer (Bootloader)
==================================


Wozu braucht man einen Bootloader?
----------------------------------


[ELPB]_


Wieso kann der first level bootloader im Mikrocontroller im Allgemeinen nicht den allgemeinen Bootvorgang des Linux Kernels einleiten?
--------------------------------------------------------------------------------------------------------------------------------------

[ELPB]_


Wie gross sind typische Bootloader wie z.B. U-Boot und Apex?
------------------------------------------------------------

[ELPB]_


Welchen Funktionsumfang hat der U-Boot Bootloader?
--------------------------------------------------

[ELPB]_


Fast Startup Linux
==================


Welche Möglichkeiten gibt es, die Bootzeit zu reduzieren?
---------------------------------------------------------

[FSTL]_


Linux Kernel Module
===================


Kann man in einem Kernelmodul auf die C Bibliothek zugreifen?
-------------------------------------------------------------


[LKMS]_


Beschreiben Sie, wie man ein einfaches Kernelmodul nativ als auch cross-kompiliert.
-----------------------------------------------------------------------------------


[LKMS]_


Wie lädt man ein Kernelmodul in den Kernel?
-------------------------------------------


[LKMS]_


Was sind Gerätenummern?
-----------------------


[LKMS]_


Wie legt man Gerätedateien an?
------------------------------


[LKMS]_


Was sind zeichenorientierte Treiber (character driver)?
-------------------------------------------------------

[LKMS]_


Standard UNIX wird echtzeitfähig
================================


Nennen Sie Anwendungsgebiete, die es notwendig machen, dem Linux Kern Echtzeit-Fähigkeit zu geben.
--------------------------------------------------------------------------------------------------

[SURT]_


Beschreiben Sie die wichtigsten Komponenten des Realtime-Preempt Patches.
-------------------------------------------------------------------------

[SURT]_


Welche Funktion hat die Organisation OSADL?
-------------------------------------------

[SURT]_


Wie kann man das Scheduling von Prozessen im Anwendungsprogramm setzen?
-----------------------------------------------------------------------


[SURT]_


Linuxtronix, Echtzeit - prinzipielle Ansätze
============================================


Welche prinzipiellen Lösungsansätze gibt es, um Linux mit Echtzeit-Eigenschaften auszustatten?
----------------------------------------------------------------------------------------------


[LTRT]_


Wie heissen die seit Jahren etablierten praktischen Implementierungen der prinzipiellen Lösungsansätze?
-------------------------------------------------------------------------------------------------------

[LTRT]_


Welchen Vorteil hat der “Preempt-RT” Ansatz, auch wenn er nicht für “harte” Echtzeit geeignet ist.
--------------------------------------------------------------------------------------------------

[LTRT]_


Echtzeitsysteme mit Linux
=========================


Was versteht man unter “Interrupt Latenzzeiten”?
------------------------------------------------


[GRTL]_


Wie werden im Kernel kritische Abschnitte geschützt?
----------------------------------------------------


[GRTL]_


Linux Debugging
=============== 


Beschreiben Sie kurz den Zweck von Strace, LTTng und Systemtap.
---------------------------------------------------------------


[TSLD]_


Embedded Debugging
==================

[EMDB]_ 




Freie / offene Software
=======================

Freie_Software_

.. figure:: img/800px-Konzept-karte_der_Freien_Software.svg.png
   :align: center

[WIKI]_

+--------------------------------------------------------------------------------+-----+------+------+-----+-----+-----+
| Kriterium                                                                      | GPL | LGPL | AGPL | BSD | MPL | CC  |
+================================================================================+=====+======+======+=====+=====+=====+
| kann für jeden Zweck verwendet werden                                          |  X  |  X   |  X   |     |     |     |
+--------------------------------------------------------------------------------+-----+------+------+-----+-----+-----+
| kann den eigenen Bedürfnissen angepasst werden                                 |  X  |  X   |  X   |  X  |     |     |
+--------------------------------------------------------------------------------+-----+------+------+-----+-----+-----+
| kann mit Freunden und Nachbarn geteilt werden                                  |  X  |  X   |  X   |  X  |     |     |
+--------------------------------------------------------------------------------+-----+------+------+-----+-----+-----+
| eigene Änderungen dürfen verbreitet werden                                     |  X  |  X   |  X   |  X  |     |     |
+--------------------------------------------------------------------------------+-----+------+------+-----+-----+-----+
| auf Freier Software basierende Programme müssen freie Software bleiben         |  X  |      |      |     |     |     |
+--------------------------------------------------------------------------------+-----+------+------+-----+-----+-----+
| Aufzählung aller Copyright besitzer der vorhergehenden Sources                 |     |      |  X   |  X  |     |     |
+--------------------------------------------------------------------------------+-----+------+------+-----+-----+-----+
| Änderungen müssen dem Urheber der Software angezeigt und übermittelt werden    |     |      |  X   |     |     |     |
+--------------------------------------------------------------------------------+-----+------+------+-----+-----+-----+


Erläutern Sie das Prinzip des Copyleft.
---------------------------------------

Das Copyleft-Prinzip besagt, dass Software, die auf unter der GNU General Public License (GPL_) veröffentlichten Software basiert nur mit den gleichen Freiheiten veröffentlicht werden darf. Dies stellt sicher, das freie Software für alle zugänglich und frei bleibt.


Welche vier Freiheiten gewährt die GPL?
---------------------------------------

Niemand sollte von der Software, die er verwendet eingeschränkt werden. Es gibt vier Freiheiten, die jeder Benutzer haben sollte.

    * die Freiheit die Software für jeden Zweck zu verwenden
    * die Freiheit die Software an die eigenen Bedürfnisse anzupassen
    * die Freiheit die Software mit Freunden und Nachbarn zu teilen
    * die Freiheit die eigenen Änderungen zu teilen

Erfüllt ein Programm diese Kriterien kann es als freie Software bezeichnet werden.


Wie unterscheidet sich die LGPL von der GPL?
--------------------------------------------

Die Lesser GNU Public License (LGPL_) unterscheidet sich von der GNU Public License (GPL_) in der Copyleft Regelung während bei der GPL alle von der Software abgeleiteten Programme ebenfalls unter der selben Lizenz veröffentlicht werden müssen kann aus unter der LGPL veröffentlichten Quellen auch proprietäre Software geschrieben werden.


Wie unterscheidet sich die BSD Lizenz von der GPL?
--------------------------------------------------

Die BSD_Licence_ verlangt, dass nach einer Änderung der Urheber entsprechende des Musters "Copyright (c) <YEAR>, <OWNER>" auch in der geänderten Version bekannt gegeben wird.


Was sind Duale Lizenzen? Nennen Sie ein Beispiel.
-------------------------------------------------

Mehrfach_Lizenzen_ erlauben es 

Beispiele: Qt, MySQL, Asterisk, Sendmail und Perl

Vorteile
++++++++

Mit diesem Lizenzierungsprinzip können Unternehmen eigene Anwendungen entwickeln, ohne diese selbst wieder der Open-Source-Lizenz unterwerfen zu müssen. So ist es einerseits möglich, das Open-Source-Modell zur Entwicklung und Distribution von Software zu fördern, und andererseits ein professionelles Geschäftsmodell zu etablieren, bei dem Softwarelizenzen ohne Einschränkungen verkauft werden können. Für eine Mehrfachlizenzierung spricht des Weiteren die Möglichkeit, die Software mit proprietären Erweiterungen zu versehen.

Käufer einer mehrfach lizenzierten Software sind darüber hinaus nicht an die teils sehr restriktiven Vorgaben zur Weitergabe von Software unter einer freien Lizenz gebunden. Die Entwicklung freier Software wird gefördert, ohne auf Spenden angewiesen zu sein.

Nachteile
+++++++++

Gegen eine Mehrfachlizenzierung spricht, dass das lizenzierende Unternehmen die Arbeit der Open-Source-Entwickler ausnutzen könnte. Darüber hinaus könnte das entwickelnde Unternehmen es sich vorbehalten, irgendwann die Weiterentwicklung der offenen Version zu stoppen.

Umstritten und selten erwähnt ist jedoch die Tatsache, dass bei einigen Open-Source-Lizenzen die Kontrolle über die Entwicklung der Software leicht an die Community oder an finanziell überlegene Unternehmen gehen kann. Ein Entwicklungsstopp einer unter GPL lizenzierten Software besagt noch lange nicht, dass die Software nicht mehr weiterentwickelt wird. Die GPL räumt jedem Nutzer das Recht ein, die Software beliebig zu modifizieren, also auch weiterzuentwickeln.

Heftig umstritten ist, ob der Initiator eines Open-Source-Projektes, welcher seine Software unter einer dualen Lizenz auf den Markt bringt, die Weiterentwicklungen der Community in sein Produkt einfließen lassen kann, um diese unter einer anderen Lizenz als der GPL zu vertreiben.

Kleine Unternehmen laufen generell Gefahr, ihre Open-Source-Softwareprojekte an große Unternehmen zu „verlieren“.


Darf man Programme im Linux Userspace unter einer proprietären Lizenz vertreiben?
---------------------------------------------------------------------------------


Darf man mit dem freien GNU C Compiler kommerzielle geschlossene Programme schreiben?
-------------------------------------------------------------------------------------


Was halten Sie von geschlossenen Kernelmodulen?
-----------------------------------------------



Linux auf eingebetteten Systemen
================================

Suchen Sie Geräte, die unter Linux laufen. Sie haben sicher schon selber welche entdeckt. Sie können sich aber auch von folgenden Seiten inspirieren lassen:  

linuxgizmos_
elinux_
linuxfordevices_



Was erwartet Sie hinsichtlich der Lizenzen, wenn Sie Linux wählen?
------------------------------------------------------------------

[TBP]_


Warum Linux? (6 Gründe)
-----------------------


Was bedeutet “GPL”?
-------------------


Was ist “Open Source”?
----------------------


Was verstehen Sie unter “Linux Standard Base”?
----------------------------------------------

[TBP]_


Was zeichnet Embedded Systems aus?
----------------------------------


Vergleichen Sie BIOS und Bootloader.
------------------------------------


Aus welchen wesentlichen Funktionsblöcken bestehen Embedded Systems?
--------------------------------------------------------------------


Aus welcher Hardware besteht die Entwicklungsumgebung?
------------------------------------------------------


Wie startet Embedded Linux? (von U-Boot bis init Prozess)
---------------------------------------------------------


Welche Arten von Flash Speicher gibt es?
----------------------------------------


In welche Regionen ist der Flash Speicher bei Linux in der Regel aufgeteilt?
----------------------------------------------------------------------------


Wie sieht grob die memory map des gesamten Rechners aus?
--------------------------------------------------------


Beschreiben Sie den Ausführungskontext mit Applikation, C Bibliothek, Kernel und Gerätetreibern. Was läuft im Kernel-Kontext, was im User-Kontext?

        

Was macht die MMU und wo ist sie eingebaut?
-------------------------------------------


Wie nennt man die nicht-native Kompilierung auch?
-------------------------------------------------

"Cross-Kompilierung" - Das kompilieren von nativer Software auf einem Hostrechner für ein spezifisches Target mit Hilfe von Cross-Kompilierungs Toolchain und im Terminal gesetzten Variablen wie z.B. "$ARCH", "$CC", etc.


Was ist native Kompilierung? Ab welcher Rechenleistung macht sie Sinn?
----------------------------------------------------------------------


Was ist eine Embedded Linux Distribution?
-----------------------------------------


Aus wie vielen Paketen besteht eine Distribution ungefähr?
----------------------------------------------------------

.. Beantworten Sie folgende Fragen:


Welche anderen CPUs unterstützt Linux neben dem x86?
----------------------------------------------------


Was ist ein monolithischer Kern?
--------------------------------


Warum lässt sich Linux einfach auf fast beliebige Prozessoren portieren?
------------------------------------------------------------------------


Wie unterscheiden sich die Befehlssätze der Prozessorfamilien?
--------------------------------------------------------------


Virtual Memory Management
-------------------------

.. Damit die Linux Speicherverwaltung (virtual memory) funktioniert, muss der Mikrocontroller eine bestimmte Hardware-Komponente haben. Wie heisst diese?



Wie heisst die Linux Variante, die ohne diese Hardware-Komponente auskommt?
---------------------------------------------------------------------------


Was ist ein “System on Chip” (SoC)?
-----------------------------------


Wie sieht die Schichtung der Software eines Embedded Linux Systems in etwa aus?
-------------------------------------------------------------------------------



Welches Dateisystem wird bei Flash Speicher häufig verwendet?
-------------------------------------------------------------



Welche Sprachen werden zur Programmierung verwendet?
----------------------------------------------------



Welche Bootloader werden bei Embedded Linux verwendet? Ist grub auch eine Option?
---------------------------------------------------------------------------------



Der Entwicklungsrechner
=======================


Installieren Sie Linux auf Ihrem Hostrechner, entweder in einer eigenen Partition oder in einer virtuelle Maschine wie z.B. VirtualBox_.




Sehen Sie sich auf Ihrem GNU/Linux Desktop PC oder Laptop den Kernel und das Root Filesystem an. Wie viel Platz beanspruchen die einzelnen Teile?




Für welche Aufgaben wird der Hostrechner (Entwicklungsrechner) verwendet?
-------------------------------------------------------------------------



Im Skript steht eine Liste von Werkzeugen für den Entwicklungsrechner. Was macht jedes einzelne dieser Werkzeuge?.




Lernen Sie die Bedienung Ihres Linux Rechners ausschliesslich über die Kommandozeile.
-------------------------------------------------------------------------------------



Installieren Sie einen Teminal Multiplexer, z.B. screen_ oder tmux_. Auch auf dem Zielrechner ist so ein Werkzeug sehr praktisch.





Welche Terminalprogramme gibt es unter Linux, um auf die Konsole über die serielle Schnittstelle zu gehen? Wie lauten die üblichen Einstellungen?




Wie kann man Daten im Terminalprogramm mit dem Protokoll X/Y/Z-Modem übertragen? Warum sollten nur kleinere Dateien bis zu ein paar 100 KByte übertragen werden?




Wie arbeitet man mit folgenden Programmen: ssh, scp, ftp (ncftp)?
-----------------------------------------------------------------

ssh
+++

Ssh bietet die Möglichkeit sich auf entfernten Geräten anzumelden hierfür benötigt man eine Netzwerkverbindung (IP-Adresse), einen laufenden ssh-server / service und eingerichtete "rsa-Fingerprints". Sind diese richtig eingerichtet kann man sich über das einfache Muster:

.. code:: bash

    ssh <USER>@<IP-Adress>
    # alternativ
    ssh <USER>@<Netzwerkname>

scp
+++



ftp
+++



ncftp
+++++




Wie ändert man die Netzwerkeinstellungen für die Schnittstellen eth0 und eth1 mit den Werkzeugen ifconfig, route, ethtool und iptables.




Wie richtet man auf dem Host eine zweite Ethernet-Schnittstelle ein, um ein Netzwerkkabel mit dem Target zu verbinden? Wie lauten die Einstellungen auf dem Target und auf dem Host?




Installieren Sie den Quelltext des Linux Kernels auf dem Hostrechner und kompilieren Sie ihn.
---------------------------------------------------------------------------------------------



Installieren Sie auf Ihrem Entwicklungsrechner eine Toolchain für die ARMv5 Architektur (ELDK oder Debian).
-----------------------------------------------------------------------------------------------------------



Wie richtet man auf dem Host einen NFS Server ein?
--------------------------------------------------



Wie richtet man auf dem Host einen TFTP Server ein?
---------------------------------------------------








Literatur und sonstige Quellen
==============================


.. [AELS] Architekturen eingebetteter Linux Systeme, Rene Rebe, 2008

    http://elk.informatik.fh-augsburg.de/cdrom-elinux/Lesen/rebe-linux-ueberall.pdf


.. [ATES] Johan Thelin, Introduction: A Typical Embedded System, 12/2009

    http://www.linuxjournal.com/article/10565

    http://elk.informatik.fh-augsburg.de/pub/rtlabor/elinux/intro/thelin/


.. [AFFS] M. Tim Jones, Anatomy of Flash Filesystems, 2008

    http://elk.informatik.fh-augsburg.de/pub/rtlabor/elinux/speicher/l-flash-filesystems-pdf.pdf


.. [BSD2] Berkley Software Distribution

.. _BSD_Licence: http://opensource.org/licenses/BSD-2-Clause


.. [ELPB] Hallinan, Kap. 7 (Bootloader)

    http://elk.informatik.fh-augsburg.de/pub/rtlabor/elinux/boot/hallinan_embedded_linux_primer_chap_7_bootloaders.pdf


.. [EMDB] Anselm Busse, Jan Richling, Embedded Debugging. Linux Magazin, 9/2013.

    http://elk.informatik.fh-augsburg.de/pub/rtlabor/elinux/debug/lm-9-2013-debug/


.. [FSTL] Fast Startup Linux

    http://elk.informatik.fh-augsburg.de/pub/rtlabor/elinux/boot/637_Fast_Startup_Linux.pdf


.. [GRTL] Eva-Katharina Kunst, Jürgen Quade, Grundlagen: Echtzeitsysteme mit Linux, 2008

    http://www.linux-magazin.de/Ausgaben/2008/06/Gerade-echtzeitig


.. [GNU] GNU Software Foundation

.. _GPL: http://www.gnu.org/licenses/quick-guide-gplv3.html

.. _LGPL: http://www.gnu.org/licenses/why-not-lgpl.html

.. _AGPL: http://www.gnu.org/licenses/why-affero-gpl.html


.. [LKMS] Boguslaw Sylla, Patrick Schorn, Linux Kernel Module.

    http://elk.informatik.fh-augsburg.de/pub/rtlabor/elinux/kernel/linuxkernel.pdf


.. [LTRT] Linuxtronix, Echtzeit - prinzipielle Ansätze

    http://elk.informatik.fh-augsburg.de/pub/rtlabor/elinux/rt/WP_2011_Linux_+_Echtzeit_prinzipielle_Ansaetze_V1_0.pdf


.. [STFS] Plattner/Schnepp Speichertechnologien und Filesystems

    http://elk.informatik.fh-augsburg.de/pub/rtlabor/elinux/speicher/speichertechnologie.pdf


.. [SURT] Emde, Gleixner, Standard UNIX wird echtzeitfaehig, 2007

    http://elk.informatik.fh-augsburg.de/pub/rtlabor/elinux/rt/elektronik-2007-03.pdf


.. [TBP] The Big Picture, Hallinan

    http://proquest.tech.safaribooksonline.de/book/operating-systems-and-server-administration/embedded-linux/9780137061129


.. [TPEL] Tipps for planning an embedded Linux project, Cliff Brake, 2006

    http://elk.informatik.fh-augsburg.de/cdrom-elinux/planning-tips.txt


.. [TSLD] Tim Schürmann, Linux Debugging, Linux Magazin 1/2013

    http://elk.informatik.fh-augsburg.de/pub/rtlabor/elinux/debug/lm-1-2013-debug/


.. [WIKI] Wikipedia the free Encyclopedia

.. _Freie_Software: http://de.wikipedia.org/wiki/Freie_Software

.. _BSD: http://de.wikipedia.org/wiki/Berkeley_Software_Distribution

.. _Mehrfach_Lizenzen: http://de.wikipedia.org/wiki/Mehrfachlizenzierung


.. _linuxgizmos: http://linuxgizmos.com

.. _elinux: http://elinux.org

.. _linuxfordevices: http://www.linuxfordevices.com

.. _VirtualBox: https://www.virtualbox.org

.. _screen: http://www.gnu.org/software/screen

..  _tmux: http://sourceforge.net/projects/tmux

.. vim: et sw=4 ts=4
