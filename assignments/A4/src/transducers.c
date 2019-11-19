#include "transducers.h"
#include <bool.h>

struct stream {
  FILE *sptr;
  bool read_flag; /* replace with implementation. */
};

void transducers_free_stream(stream *s) {
  s=s; /* unused */
}



int transducers_link_source(stream **out,
                            transducers_source s, const void *arg) {

  // opret pipe ...
  // write_end = ..
  // read_end = ..

  if (fork() == 0) {
    fclose(read_end);

    s(arg, write_end); // generer bytes og spyt ud i out-strøm

    fclose(write_end);
    exit(0);
  }
  fclose(write_end);

  struct *new_stream = // malloc ...
  assert(new_stream != NULL);

  new_stream->sptr = read_end;
  new_stream->flag = true;

  *out = new_stream;

  return 0;
}

int transducers_link_sink(transducers_sink s, void *arg,
                          stream *in) {
  s=s; /* unused */
  arg=arg; /* unused */
  in=in; /* unused */
  return 1;
}

int transducers_link_1(stream **out,
                       transducers_1 t, const void *arg,
                       stream* in) {
  out=out; /* unused */
  t=t; /* unused */
  arg=arg; /* unused */
  in=in; /* unused */
  return 1;
}

int transducers_link_2(stream **out,
                       transducers_2 t, const void *arg,
                       stream* in1, stream* in2) {
  out=out; /* unused */
  t=t; /* unused */
  arg=arg; /* unused */
  in1=in1; /* unused */
  in2=in2; /* unused */
  return 1;
}

int transducers_dup(stream **out1, stream **out2,
                    stream *in) {
  out1=out1; /* unused */
  out2=out2; /* unused */
  in=in; /* unused */
  return 1;
}
