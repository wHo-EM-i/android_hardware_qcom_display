ifeq ($(call my-dir),$(call project-path-for,qcom-display))
display-hals := \
    include\
    sdm/libs/utils\
    sdm/libs/core\
    libdebug

ifneq ($(TARGET_IS_HEADLESS), true)
display-hals += \
    libcopybit \
    liblight \
    libmemtrack \
    hdmi_cec \
    sdm/libs/hwc2 \
    gpu_tonemapper \
    libdrmutils
endif

display-hals += gralloc

include $(call all-named-subdir-makefiles,$(display-hals))
endif
