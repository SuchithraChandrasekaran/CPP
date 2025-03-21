# Six Stages of Linux Boot Process

## 1️⃣ BIOS (Basic Input/Output System)
- Performs POST (Power-On Self-Test) to check hardware integrity.
- Searches for and loads the Bootloader from the Master Boot Record (MBR).

## 2️⃣ MBR (Master Boot Record)
- Occupies the first 512 bytes of the bootable disk.
- Contains the bootloader and partition table.
- Loads the bootloader, such as GRUB or LILO.

## 3️⃣ Bootloader (GRUB, LILO, etc.)
- Provides a menu for OS selection if multiple operating systems are installed.
- Loads the Linux kernel into memory along with the initial RAM filesystem (initramfs).

## 4️⃣ Kernel Initialization
- Initializes hardware and loads essential device drivers.
- Mounts the root filesystem using initramfs.
- Starts the first process: `init` or `systemd`.

## 5️⃣ Init/Systemd Process
- For `init`, reads `/etc/inittab` to determine initialization scripts.
- For `systemd`, executes systemd units to initialize services and daemons.

## 6️⃣ Runlevel/Target Execution
- The system reaches a usable state.
- Activates the default runlevel (for init) or systemd target (e.g., multi-user.target).

---------------
To Remember easily...

1- BIOS → Your alarm clock wakes you up

2- MBR → You check the to-do list (where to start)

3- Bootloader → You decide what to wear (which OS to load)

4- Kernel → You get out of bed and start functioning

5- Init/Systemd → You get ready for work (load services)

6- Runlevel/Target → You are fully prepared and working
