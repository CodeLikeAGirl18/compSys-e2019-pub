#include <unistd.h>
#include <fts.h>

int main(int argc, char *const *argv) {
  int *x = (int*)3045;
  FTS *ftsp = fts_open(argv+1, FTS_LOGICAL | FTS_NOCHDIR, NULL);
  FTSENT *p = fts_read(ftsp);

}
