  unsigned int size;
  unsigned int offset;
  unsigned int offset_metadata;
  uint64_t base;
  uint64_t base_metadata;
  uint64_t gpuaddr;
#ifndef GRALLOC_HANDLE_HAS_NO_RESERVED_SIZE
  unsigned int reserved_size;
#endif
#ifndef GRALLOC_HANDLE_HAS_NO_CUSTOM_CONTENT_MD_RESERVED_SIZE
  unsigned int custom_content_md_reserved_size;
#endif
  unsigned int layer_count;
  uint64_t id;
  uint64_t usage;
#ifdef __cplusplus
  static const int kNumFds = 2;
  static const int kMagic = 'gmsm';
#ifndef GRALLOC_HANDLE_HAS_NO_UBWCP
  unsigned int linear_size;
  int ubwcp_format;
#endif

  static inline int NumInts() {
    return ((sizeof(private_handle_t) - sizeof(native_handle_t)) / sizeof(int)) - kNumFds;
  }

  private_handle_t(int fd, int meta_fd, int flags, int width, int height, int uw, int uh,
                   int format, int buf_type, unsigned int size, uint64_t usage = 0)
      : fd(fd),
        fd_metadata(meta_fd),
        magic(kMagic),
        flags(flags),
        width(width),
        height(height),
        unaligned_width(uw),
        unaligned_height(uh),
        format(format),
        buffer_type(buf_type),
        size(size),
        offset(0),
        offset_metadata(0),
        base(0),
        base_metadata(0)
#ifndef GRALLOC_HANDLE_HAS_NO_RESERVED_SIZE
        ,reserved_size(0)
#endif
#ifndef GRALLOC_HANDLE_HAS_NO_UBWCP
        ,linear_size(0),
        ubwcp_format(format)
#endif
#ifndef GRALLOC_HANDLE_HAS_NO_CUSTOM_CONTENT_MD_RESERVED_SIZE
        ,custom_content_md_reserved_size(0)
#endif
        ,gpuaddr(0),
        layer_count(1),
        id(0),
        usage(usage)
{
    version = static_cast<int>(sizeof(native_handle));
    numInts = NumInts();
    numFds = kNumFds;
  }
#endif
