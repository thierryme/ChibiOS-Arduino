
#include "ch.h"

KHooks hooksStruct;

void chHooksInit()
{
   hooksStruct.threadInitHook    = NULL;
   hooksStruct.threadExitHook    = NULL;
   hooksStruct.contextSwitchHook = NULL;
   hooksStruct.idleEnterHook     = NULL;
   hooksStruct.idleLeaveHook     = NULL;
   hooksStruct.idleLoopHook      = NULL;
   hooksStruct.systemTickHook    = NULL;
   hooksStruct.systemHaltHook    = NULL;
}

void chHooksSetThreadInitHook(void (* f)(thread_t *))
{
   hooksStruct.threadInitHook = f;
}
void chHooksSetThreadExitHook(void (* f)(thread_t *))
{
   hooksStruct.threadExitHook = f;
}
void chHooksSetContextSwitchHook( void (* f)(thread_t *, thread_t *))
{
   hooksStruct.contextSwitchHook = f;
}
void chHooksSetIdleEnterHook(void (* f)())
{
   hooksStruct.idleEnterHook = f;
}
void chHooksSetIdleLeaveHook(void (* f)())
{
   hooksStruct.idleLeaveHook = f;
}
void chHooksSetIdleLoopHook(void (* f)())
{
   hooksStruct.idleLoopHook = f;
}
void chHooksSetSystemTickHook(void (* f)())
{
   hooksStruct.systemTickHook = f;
}
void chHooksSetSystemHaltHook(void (* f)(const char *))
{
   hooksStruct.systemHaltHook = f;
}


void chThreadInitHook(thread_t * tp)
{
   if(hooksStruct.threadInitHook)
      hooksStruct.threadInitHook(tp);
}
void chThreadExitHook(thread_t * tp)
{
   if(hooksStruct.threadExitHook)
      hooksStruct.threadExitHook(tp);
}
void chContextSwitchHook(thread_t * ntp, thread_t * otp)
{
   if(hooksStruct.contextSwitchHook)
      hooksStruct.contextSwitchHook(ntp, otp);
}
void chIdleEnterHook()
{
   if(hooksStruct.idleEnterHook)
      hooksStruct.idleEnterHook();
}
void chIdleLeaveHook()
{
   if(hooksStruct.idleLeaveHook)
      hooksStruct.idleLeaveHook();
}
void chIdleLoopHook()
{
   if(hooksStruct.idleLoopHook)
      hooksStruct.idleLoopHook();
}
void chSystemTickHook()
{
   if(hooksStruct.systemTickHook)
      hooksStruct.systemTickHook();
}
void chSystemHaltHook(const char * reason)
{
   if(hooksStruct.systemHaltHook)
      hooksStruct.systemHaltHook(reason);
}