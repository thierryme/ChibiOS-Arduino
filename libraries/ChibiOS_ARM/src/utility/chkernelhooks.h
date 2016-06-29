


#ifndef _KERNEL_HOOKS_H_
#define _KERNEL_HOOKS_H_



typedef struct ch_kernel_hooks_t {

    int (* length)();
    void (* threadInitHook)(thread_t *);
    void (* threadExitHook)(thread_t *);
    void (* contextSwitchHook)(thread_t *, thread_t *);
    void (* idleEnterHook)();
    void (* idleLeaveHook)();
    void (* idleLoopHook)();
    void (* systemTickHook)();
    void (* systemHaltHook)(const char *);
} KHooks;

#ifdef __cplusplus
extern "C" {
#endif
   void chHooksInit();

   void chHooksSetThreadInitHook(void (* threadInitHook)(thread_t *));
   void chHooksSetThreadExitHook(void (* threadExitHook)(thread_t *));
   void chHooksSetContextSwitchHook( void (* contextSwitchHook)(thread_t *, thread_t *));
   void chHooksSetIdleEnterHook(void (* idleEnterHook)());
   void chHooksSetIdleLeaveHook(void (* idleLeaveHook)());
   void chHooksSetIdleLoopHook(void (* idleLoopHook)());
   void chHooksSetSystemTickHook(void (* systemTickHook)());
   void chHooksSetSystemHaltHook(void (* systemHaltHook)(const char *));

   void chThreadInitHook(thread_t * tp);
   void chThreadExitHook(thread_t * tp);
   void chContextSwitchHook(thread_t * ntp, thread_t * otp);
   void chIdleEnterHook();
   void chIdleLeaveHook();
   void chIdleLoopHook();
   void chSystemTickHook();
   void chystemHaltHook(const char * reason);
#ifdef __cplusplus
}
#endif

#endif