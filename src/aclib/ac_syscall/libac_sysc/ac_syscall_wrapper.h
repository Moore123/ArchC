#ifndef _AC_SYSCALL_WRAPPER_H_
#define _AC_SYSCALL_WRAPPER_H_

#include <errno.h>



#define __syscall_return(type, res) \
do { \
  if ((int)(res) == -1) errno = ac_syscall_geterrno(); \
  return (type) (res); \
} while (0)


#define _syscall0(type,name) \
type name(void) \
{ \
long __res; \
__res = ac_syscall_wrapper(__NR_##name); \
__syscall_return(type,__res); \
}

#define _syscall1(type,name,type1,arg1) \
type name(type1 arg1) \
{ \
long __res; \
__res = ac_syscall_wrapper(__NR_##name,arg1); \
__syscall_return(type,__res); \
}

#define _syscall2(type,name,type1,arg1,type2,arg2) \
type name(type1 arg1, type2 arg2) \
{ \
long __res; \
__res = ac_syscall_wrapper(__NR_##name,arg1,arg2); \
__syscall_return(type,__res); \
}

#define _syscall3(type,name,type1,arg1,type2,arg2,type3,arg3) \
type name(type1 arg1, type2 arg2, type3 arg3) \
{ \
long __res; \
__res = ac_syscall_wrapper(__NR_##name,arg1,arg2,arg3); \
__syscall_return(type,__res); \
}

#define _syscall4(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4) \
type name(type1 arg1, type2 arg2, type3 arg3, type4 arg4) \
{ \
long __res; \
__res = ac_syscall_wrapper(__NR_##name,arg1,arg2,arg3,arg4); \
__syscall_return(type,__res); \
}

#define _syscall5(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4,type5,arg5) \
type name(type1 arg1, type2 arg2, type3 arg3, type4 arg4, type5 arg5) \
{ \
long __res; \
__res = ac_syscall_wrapper(__NR_##name,arg1,arg2,arg3,arg4,arg5); \
__syscall_return(type,__res); \
}

#define _syscall6(type,name,type1,arg1,type2,arg2,type3,arg3,type4,arg4,type5,arg5,type6,arg6) \
type name(type1 arg1, type2 arg2, type3 arg3, type4 arg4, type5 arg5, type6 arg6) \
{ \
long __res; \
__res = ac_syscall_wrapper(__NR_##name,arg1,arg2,arg3,arg4,arg5,arg6); \
__syscall_return(type,__res); \
}


#endif /* _AC_SYSCALL_WRAPPER_H_ */
