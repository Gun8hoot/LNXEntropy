
#ifndef ERROR_H
# define ERROR_H

// --- ERROR MESSAGES ---
# define EALLOC "[!] Failed to allocated memory!"
# define ETHREAD "[!] Failed to create thread!"
# define EFORK "[!] Failed to create fork!"
# define EROOT "[!] The program need root privileges!"
# define EOPEN "[!] Failed to open %s!"

// --- ERROR CODES ---
# define EERRNO_ALLOC	0x01
# define EERRNO_PROCESS	0x02
# define EERRNO_ROOT	0x03
# define EERRNO_OPEN	0x04

#endif
