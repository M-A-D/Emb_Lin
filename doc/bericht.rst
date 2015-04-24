.. include:: etc/kopf.rst


Beschreibung der Hardware
=========================

Für das Projekt wird das Beaglebone Black verwendet. Gründe hierfür sind der günstige Preis, die gute Verarbeitung und die hohe Leistung bei relativ geringem Energiebedarf.

Zunächst werden wir uns einmal mit der Hard- und Software im Orginalzustand wittmen. Verbindet man ein neues Beaglebone Black via USB mit dem Host-/Entwicklungsrechner so wird eine weitere Netzwerkverbindung geöffnet. Über diese kann man via ssh eine Verbindung zum Target starten.

.. code:: bash
    
    ssh debian@192.168.7.2
    # pwd: temppwd

.. figure:: img/ssh-BBB.png
   :align: center

Es befindet sich bereits eine angepasste Debian Version Linux beaglebone 3.8.13-bone47 auf dem 4 GB großen eMMC Speicher. Es wird per default von der eMMC gebootet und unter Verwendung von Maus, Tastatur und Display könnte man das BBB wie einen  rechenpower armen PC verwenden.


.. cat /proc/cpuinfo
.. cat /proc/meminfo
.. cat /proc/version
.. cat /lib/libc.so

.. bootloader
.. printenv
.. 

.. hush.c - shell


Verbindung
----------

.. code:: bash
    
    debian@beaglebone:~# ifconfig
    debian@beaglebone:~# dhclient eth0

.. figure:: img/ssh-ifconfig-BBB.png
   :align: center


Blockschaltplan Beaglebone Black
--------------------------------


.. figure:: img/BBB-Blockschaltplan.png
   :align: center


Komponenten
-----------

.. figure:: img/BBB-components.png
   :align: center

+-----------------+-------------------------------------+
| Komponenten     | Model / Ausführung                  |
+=================+=====================================+
| CPU             | Sitara AM3358BZCZ100 ARM® Cortex-A8 |
|                 | 1GHz  dual-core mit 2000 MIPS       |
+-----------------+-------------------------------------+
| RAM             | 512 MB DDR3L @ 800 MHz              |
+-----------------+-------------------------------------+
| ROM             | 4 GB eMMC                           |
+-----------------+-------------------------------------+
| IPU             | 4 x ARM® Cortex-M4                  |
+-----------------+-------------------------------------+
| GPU             | - PowerVR SGX544 dual core (3D)     |
|                 | - Vivante GC320 core       (2D)     |
+-----------------+-------------------------------------+
| Power Source    | - mini USB DC Jack                  |
|                 | - 5 V DC Jack                       |
|                 | - TPS65217C PMIC                    |
|                 | - LDO                               |
+-----------------+-------------------------------------+
| User Input      | - Reset Button                      |
|                 | - Boot Button                       |
|                 | - Power Button                      |
+-----------------+-------------------------------------+
| Connectors      | - RJ-45 Ethernet 10 / 100           |
|                 | - USB-A (2.0), mini USB             |
|                 | - mini HDMI (audio / video)         |
|                 | - microSD (3,3V)                    |
|                 | - VDD_ADC (1,8V)                    |
|                 | - GPIO    (3,3V)                    |
|                 | - SPI                               |
|                 | - I2C                               |
|                 | - UART                              |
|                 | - JTAG (20 pin Onboard Header)      |
|                 | - MMC1, MMC2                        |
|                 | - 4 Timer                           |
|                 | - CAN                               |
|                 | - XDMA Interrupt                    |
|                 | - LCD                               |
|                 | - Expansion Board ID                |
+-----------------+-------------------------------------+
| PCB             | - 3,4" x 2,1"                       |
|                 | - 6 Layer                           |
|                 | - 39,68 g                           |
+-----------------+-------------------------------------+

[BBB-BSP]_



Bau einer eigenen Linuxumgebung mit dem Yoctoproject
====================================================

.. sudo apt-get install chrpath gawk diffstat texinfo g++

Zu Begin soll eine neue angepasste Linuxumgebung auf dem Beagelbone Black aufgesetzt werden. Hierzu bedienen wir uns des Yoctoproject. [BBB-YOCTO]_

	* **Herunterladen der Buildumgebung vom Github des Yoctoproject.**

	.. code:: bash
	    
	    git clone git://git.yoctoproject.org/meta-yocto -b dizzy

	* **Den richtigen USB-Port finden**

	.. code:: bash

		dmesg

	.. figure:: img/BBB-dmesg.png
	   :align: center


	* **Auf den Port zugreifen** - Hierfür benötigt man ein [] wie z.B. Minicom außerdem werden spezielle Befugnisse für das Zugreifen auf den Port benötigt hierfür gibt es 2 unterschiedliche herangehensweisen: 

		a) Ändern der Befugnisse um auf den seriellen Port zugreifen zu dürfen

		.. code:: bash

			sudo chmod 0666 dev/<tty of the eth connection to the bbb>
			# for my system
			sudo chmod 0666 dev/ttyACM0

		b) Eigenes Profil zur Gruppe "dialout" hinzufügen um auf den seriellen Port zugreifen zu dürfen

		.. code:: bash

			sudo usermod -a -G dialout <username>


Minicom konfigurieren
---------------------

	.. code:: bash

		# for ubuntu / debian based distributions
		sudo apt-get install minicom

		sudo minicom -s

	* **Einstellungen zum seriellen Anschluss**
	
	.. figure:: img/microcom-setup1.png
	   :align: center
	
	* **Unter A das richtige Device einrichten**

	.. figure:: img/microcom-setup2.png
	   :align: center

	* **Als default Speichern**

	.. figure:: img/microcom-setup3.png
	   :align: center

	* **Minicom beenden und neu starten**

	.. figure:: img/microcom-setup4.png
	   :align: center


Vorbereiten der microSD Karte
-----------------------------

		.. code:: bash

			sudo fdisk -lu <device_name>
			# for my system
			sudo fdisk -lu mmcblk0

		.. figure:: img/fdisk-list-volumes.png
		   :align: center

		- /dev/mmcblk0p1 * 63 144584 72261 c Win95 FAT32 (LBA) 
		
		- /dev/mmcblk0p2 144585 465884 160650 83 Linux	
		
		- mkfs.vfat -F 16 -n "boot" /dev/mmcblk0p1

		- mke2fs -j -L "root" /dev/mmcblk0p2

		.. figure:: img/mkfs-2.png
		   :align: center

	* **Yocto Build Download**
		
		.. code:: bash

			wget http://downloads.yoctoproject.org/releases/yocto/yocto-1.7/machines/beaglebone/beaglebone-dizzy-12.0.0.tar.bz2

	* **Build the Yocto core and bootloader**
		
		.. code:: bash

			source oe-init-build-env build

		.. figure:: img/Yocto-build1.png
		   :align: center

		.. code:: bash

			Remove the '#' from the 
			#MACHINE ?= "beaglebone"






Literatur und sonstige Quellen
==============================

.. [BBB-BSP] Beaglebone Black Blockschaltpläne
	http://linuxgizmos.com/beagleboard-x15-features-dual-core-cortex-a15-sitara/

.. [ELIN-BBB-OS] Beaglebone Black Operating Systems
	http://elinux.org/BeagleBone_Operating_Systems

.. [ELIN-BBB-Debian] Beaglebone Black Debian
	http://elinux.org/BeagleBoardDebian

.. [BBB-YOCTO] Yocto Project Beaglebone Black
	https://www.yoctoproject.org/downloads/bsps/daisy16/beaglebone

.. vim: et sw=4 ts=4
