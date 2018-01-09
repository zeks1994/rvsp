#include <packet.h>

struct rsvp_packet * rsvp_packet_new (size_t size)
{
struct rsvp_packet *new
new = malloc(sizeof(struct rsvp_packet));
return new;
}

void rsvp_packet_free(struct rsvp_packet *p)
{

}



#kreiranje fifo bafera
struct rsvp_fifo * rsvp_fifo_new()
{
 struct rsvp_fifo *new;
 new = malloc(sizeof(struct rsvp_fifo));
 return new; 
}


#stigao je novi rsvp paket, stavlja se na kraj 
void rsvp_fifo_push (struct rsvp_fifo *fifo, struct rsvp_packet *p)
{
if (fifo->tail)
  fifo->tail->next = p;
else
  fifo->head = p;
  fifo->tail = p;

fifo->count++;
}

#prosledili smo prvi paket iz bafera
struct rsvp_paket * rsvp_fifo_pop (struct rsvp_fifo *fifo)
{
struct rsvp_paket *p;
p = fifo->head;
if (p)
{
 fifo->head = p->next;
  if (fifo->head == NULL) fifo->tail = NULL;  #slucaj kada nema vise paketa
 fifo->count--;
}
return p;
}

