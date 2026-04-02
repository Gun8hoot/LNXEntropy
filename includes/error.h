
#ifndef ERROR_H
# define ERROR_H

// --- ERROR MESSAGES ---
# define MSG_ALLOC "[!] Failed to allocated memory!"
# define MSG_THREAD "[!] Failed to create thread!"
# define MSG_FORK "[!] Failed to create fork!"
# define MSG_ROOT "[!] The program need root privileges!"
# define MSG_OPEN "[!] Failed to open %s!"



// --- ERROR CODES ---
# define EALLOC				0x01
# define EPROCESS			0x02
# define EROOT				0x03
# define EOPEN				0x04
# define EPIPE_FAILED		0x05

#endif
