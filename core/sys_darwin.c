#include <sys/sysctl.h>

#include "sys.h"

int sys_ncpu(void) {
  int mib[2], ncpu, n;
  size_t len;
  
  mib[0] = CTL_HW;
  mib[1] = HW_NCPU;
  len = sizeof ncpu;

  n = sysctl(mib, 2, &ncpu, &len, 0, 0);
  return n < 0? n : ncpu;
}
