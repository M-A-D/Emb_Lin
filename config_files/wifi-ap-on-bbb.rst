

Installation der nötigen Softwarekomponenten
--------------------------------------------

.. code:: bash
    
    # 
    sudo apt-get install isc-dhcp-server
    # 
    sudo apt-get install hostapd
    # 
    sudo apt-get install
    #
    sudo apt-get install dnsmasq


Hinzufügen eines eigenen Interfaces für wlan0
---------------------------------------------

.. code:: bash

    root@arm vi /etc/network/interfaces
    
    # Hinzufügen der folgenden Zeilen:
    # Wifi-Interface wlan0
    auto wlan0
        iface wlan0 inet dhcp
        address 192.168.3.1
        network 192.168.3.0
        netmask 255.255.255.0
        broadcast 192.168.3.255


Das W-Lan Device finden und identifizieren
------------------------------------------

.. code:: bash

    root@arm:~# lsusb
    # sollte eine ähnliche Ausgabe erzeugen
    Bus 001 Device 002: ID 0846:9030 NetGear, Inc. WNA1100 Wireless-N 150 [Atheros AR9271] # <- WIFI-Device
    Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub


Da das Device erkannt wurde und das Interface eingerichtet ist kann nun mittels des folgenden Befehls das Modul aktiviert werden, dies ist nicht bei allen W-lan Sticks nötig. Je einfacher (und günstiger) der Stick ist desto wahrscheinlicher ist es, das es keine Möglichkeit gibt den angeschlossenen Stick zu deaktivieren.

.. code:: bash

    root@arm:~# ip link set wlan0 up


Den Netzwerkservice neu starten
-------------------------------

.. code:: bash

    root@arm /etc/init.d/networking restart


Chipset und Treiber finden
--------------------------

.. code:: bash

    root@arm:~# dmesg | grep AR9271
    [   19.484197] ieee80211 phy0: Atheros AR9271 Rev:1


.. code:: bash

    root@arm iw list
    
    # sollte eine ähnliche Ausgabe wie die folgende erzeugen:
    
    Wiphy phy0
	max # scan SSIDs: 4
	max scan IEs length: 2257 bytes
	Retry short limit: 7
	Retry long limit: 4
	Coverage class: 0 (up to 0m)
	Device supports RSN-IBSS.
	Supported Ciphers:
		* WEP40 (00-0f-ac:1)
		* WEP104 (00-0f-ac:5)
		* TKIP (00-0f-ac:2)
		* CCMP (00-0f-ac:4)
		* CMAC (00-0f-ac:6)
	Available Antennas: TX 0x1 RX 0x1
	Configured Antennas: TX 0x1 RX 0x1
	Supported interface modes:
		 * IBSS
		 * managed
		 * AP
		 * AP/VLAN
		 * monitor
		 * mesh point
		 * P2P-client
		 * P2P-GO
	Band 1:
		Capabilities: 0x116e
			HT20/HT40
			SM Power Save disabled
			RX HT20 SGI
			RX HT40 SGI
			RX STBC 1-stream
			Max AMSDU length: 3839 bytes
			DSSS/CCK HT40
		Maximum RX AMPDU length 65535 bytes (exponent: 0x003)
		Minimum RX AMPDU time spacing: 8 usec (0x06)
		HT TX/RX MCS rate indexes supported: 0-7
		Bitrates (non-HT):
			* 1.0 Mbps
			* 2.0 Mbps (short preamble supported)
			* 5.5 Mbps (short preamble supported)
			* 11.0 Mbps (short preamble supported)
			* 6.0 Mbps
			* 9.0 Mbps
			* 12.0 Mbps
			* 18.0 Mbps
			* 24.0 Mbps
			* 36.0 Mbps
			* 48.0 Mbps
			* 54.0 Mbps
		Frequencies:
			* 2412 MHz [1] (20.0 dBm)
			* 2417 MHz [2] (20.0 dBm)
			* 2422 MHz [3] (20.0 dBm)
			* 2427 MHz [4] (20.0 dBm)
			* 2432 MHz [5] (20.0 dBm)
			* 2437 MHz [6] (20.0 dBm)
			* 2442 MHz [7] (20.0 dBm)
			* 2447 MHz [8] (20.0 dBm)
			* 2452 MHz [9] (20.0 dBm)
			* 2457 MHz [10] (20.0 dBm)
			* 2462 MHz [11] (20.0 dBm)
			* 2467 MHz [12] (20.0 dBm) (no IR)
			* 2472 MHz [13] (20.0 dBm) (no IR)
			* 2484 MHz [14] (20.0 dBm) (no IR)
	Supported commands:
		 * new_interface
		 * set_interface
		 * new_key
		 * start_ap
		 * new_station
		 * new_mpath
		 * set_mesh_config
		 * set_bss
		 * authenticate
		 * associate
		 * deauthenticate
		 * disassociate
		 * join_ibss
		 * join_mesh
		 * remain_on_channel
		 * set_tx_bitrate_mask
		 * frame
		 * frame_wait_cancel
		 * set_wiphy_netns
		 * set_channel
		 * set_wds_peer
		 * probe_client
		 * set_noack_map
		 * register_beacons
		 * start_p2p_device
		 * set_mcast_rate
		 * Unknown command (104)
		 * connect
		 * disconnect
	Supported TX frame types:
		 * IBSS: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
		 * managed: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
		 * AP: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
		 * AP/VLAN: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
		 * mesh point: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
		 * P2P-client: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
		 * P2P-GO: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
		 * P2P-device: 0x00 0x10 0x20 0x30 0x40 0x50 0x60 0x70 0x80 0x90 0xa0 0xb0 0xc0 0xd0 0xe0 0xf0
	Supported RX frame types:
		 * IBSS: 0x40 0xb0 0xc0 0xd0
		 * managed: 0x40 0xd0
		 * AP: 0x00 0x20 0x40 0xa0 0xb0 0xc0 0xd0
		 * AP/VLAN: 0x00 0x20 0x40 0xa0 0xb0 0xc0 0xd0
		 * mesh point: 0xb0 0xc0 0xd0
		 * P2P-client: 0x40 0xd0
		 * P2P-GO: 0x00 0x20 0x40 0xa0 0xb0 0xc0 0xd0
		 * P2P-device: 0x40 0xd0
		 
	# [!] Accesspoint (AP) Modus verfügbar
	
	software interface modes (can always be added):
		 * AP/VLAN
		 * monitor
	valid interface combinations:
		 * #{ managed, P2P-client } <= 2, #{ AP, mesh point, P2P-GO } <= 2,
		   total <= 2, #channels <= 1
	HT Capability overrides:
		 * MCS: ff ff ff ff ff ff ff ff ff ff
		 * maximum A-MSDU length
		 * supported channel width
		 * short GI for 40 MHz
		 * max A-MPDU length exponent
		 * min MPDU start spacing
	Device supports TX status socket option.
	Device supports HT-IBSS.
	Device supports SAE with AUTHENTICATE command
	Device supports low priority scan.
	Device supports scan flush.
	Device supports AP scan.
	Device supports per-vif TX power setting
	Driver supports a userspace MPM


Informationen über aktuell geladene Kernelmodule
------------------------------------------------

.. code:: bash

    root@arm:~# lsmod 
    
    # sollte eine ähnliche Ausgabe wie die Folgende erzeugen:
    
    Module                  Size  Used by
    arc4                    1586  2 
    8021q                  19046  0 
    garp                    4872  1 8021q
    stp                     1316  1 garp
    mrp                     6444  1 8021q
    llc                     3179  2 stp,garp
    
    # [!] hier folgen die Treiber für unser W-lan Modul
    
    ath9k_htc              53619  0 
    ath9k_common            1644  1 ath9k_htc
    ath9k_hw              380797  2 ath9k_common,ath9k_htc
    ath                    17798  3 ath9k_common,ath9k_htc,ath9k_hw
    mac80211              442829  1 ath9k_htc
    cfg80211              381814  3 ath,mac80211,ath9k_htc
    
    bnep                   11802  2 
    pruss_remoteproc       12796  0 
    c_can_platform          5951  0 
    c_can                   9427  1 c_can_platform
    can_dev                 7532  1 c_can
    usb_f_ecm               7909  1 
    g_ether                 1802  0 
    usb_f_rndis            17823  2 g_ether
    u_ether                 9444  3 usb_f_ecm,usb_f_rndis,g_ether
    libcomposite           38891  3 usb_f_ecm,usb_f_rndis,g_ether
    bluetooth             315943  7 bnep
    6lowpan_iphc           10090  1 bluetooth
    rfkill                 14657  3 cfg80211,bluetooth
    uio_pdrv_genirq         2824  0 
    uio                     7008  1 uio_pdrv_genirq


Informationen über das Kernelmodul ath9k_htc
--------------------------------------------

.. code:: bash

    root@arm:~# modinfo ath9k_htc
    
    # sollte eine ähnliche Ausgabe erzeugen
    
    filename:       /lib/modules/3.14.43-ti-r67/kernel/drivers/net/wireless/ath/ath9k/ath9k_htc.ko
    firmware:       htc_9271.fw
    firmware:       htc_7010.fw
    description:    Atheros driver 802.11n HTC based wireless devices
    license:        Dual BSD/GPL
    author:         Atheros Communications
    alias:          usb:v0CF3p20FFd*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v04DAp3904d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v0411p017Fd*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v083ApA704d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v0846p9018d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v0CF3p7010d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v1668p1200d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v0CF3p7015d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v057Cp8403d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v0CF3pB002d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v0CF3pB003d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v040Dp3801d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v04CAp4605d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v13D3p3350d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v13D3p3349d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v13D3p3348d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v13D3p3346d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v13D3p3328d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v13D3p3327d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v07D1p3A10d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v0846p9030d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v0CF3p1006d*dc*dsc*dp*ic*isc*ip*in*
    alias:          usb:v0CF3p9271d*dc*dsc*dp*ic*isc*ip*in*
    depends:        ath9k_hw,ath9k_common,mac80211,ath,cfg80211
    intree:         Y
    vermagic:       3.14.43-ti-r67 SMP preempt mod_unload modversions ARMv7 p2v8 
    parm:           debug:Debugging mask (uint)
    parm:           nohwcrypt:Disable hardware encryption (int)
    parm:           btcoex_enable:Enable wifi-BT coexistence (int)
    parm:           ps_enable:Enable WLAN PowerSave (int)




.. [ATWK] Device Wiki - Atheros AR9271
    https://wikidevi.com/wiki/Atheros_AR9271


