#include <stdio.h>
#include <inttypes.h>

struct commheader {
int vers;
char flags;
uint8_t type;
uint16_t checksum;
uint8_t ttl;
uint16_t len; 
};

struct session {   #objekat koji se nalazi u svakom rsvp paketu 
uint32_t dstipv4;
int protid;
char flag;
int dstport;
};

struct rsvp_hop {
uint32_t phop;
uint32_t nhop;
int lih;
};

struct style {
uint24_t opt;
};

#ne znam kako zbog QoS
struct flowspec{

};

struct error {
uint32_t erripv4;  #ipv4 adresa noda koji je detektovao gresku
char flag;
uint8_t errcode;
uint16_t errval;
};

struct scope {    #lista ipv4 adresa, ipv4 adresa kao val
uint32_t ipv4;
struct scope *next;
};

struct rsvp_packet {
struct commheader header;
struct session sess;
struct rsvp_hop rhop;
struct error err;
struct scope sc;
};

struct rsvp_fifo{         
unsigned long count;      #broj paketa u baferu
struct rsvp_packet *head;
struct rsvp_packet *tail;
};

