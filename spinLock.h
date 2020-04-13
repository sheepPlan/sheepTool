#ifndef SPTOOL_SPINLOCK_H
#define SPTOOL_SPINLOCK_H


struct SPSpinLock{
	int lock;
};

static inline void spinLockInit(struct SPSpinLock *lock) {
	lock->lock = 0;
}

static inline void spinLockLock(struct SPSpinLock *lock) {
	while (__sync_lock_test_and_set(&lock->lock,  1)) {}
}

static inline void spinLockUnlock(struct SPSpinLock *lock) {
	__sync_lock_release(&lock->lock);
}

static inline void spinLockDestory(struct SPSpinLock *lock) {
	(void) lock;
}

#endif
