---
author: "Stefan Wagner"
date: 2022-08-13
description: "Operating modes in the ao real-time operating system."
draft: true
permalink: /operating-modes/
---

- operating systems can use hardware features to run code in different operating modes.
- each mode defines restrictions on what can and cannot be done
- this is to separate applications from each other and from the kernel, thus improving safety, robustness, ...
- typical operating modes: kernel mode and user mode
- operating modes are usually the basis for more specific features, such as memory protection

- however, applying different operating modes comes at a cost
- for example, user mode on Pic32, syscall exception, LED toggling 

- kernel package does not deal with operating modes, because (1) hardware specific, (2) usually not required or having negative impact on efficiency in real-time and/or embedded systems.
