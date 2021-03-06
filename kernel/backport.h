/*
 * Include wrappers for older kernels as interfaces change
 */

#define SG_SEGMENT_SZ	8192

#ifndef slab_flags_t
typedef unsigned __bitwise slab_flags_t;
#endif

/*
 * Copied kmem_cache_create_usercopy() from scst project
 */
#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 23)
static inline struct kmem_cache *kmem_cache_create_usercopy(const char *name,
			unsigned int size, unsigned int align,
			slab_flags_t flags,
			unsigned int useroffset, unsigned int usersize,
			void (*ctor)(void *))
{
	return kmem_cache_create(name, size, align, flags, ctor, NULL);
}
#elif LINUX_VERSION_CODE < KERNEL_VERSION(4, 16, 0)
static inline struct kmem_cache *kmem_cache_create_usercopy(const char *name,
			unsigned int size, unsigned int align,
			slab_flags_t flags,
			unsigned int useroffset, unsigned int usersize,
			void (*ctor)(void *))
{
	return kmem_cache_create(name, size, align, flags, ctor);
}
#endif


