LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := opencrypto_static
LOCAL_SRC_FILES := ../prebuild/$(TARGET_ARCH_ABI)/libcrypto1.a
#LOCAL_EXPORT_C_INCLUDES := ../prebuild/$(TARGET_ARCH_ABI)/include/openssl
include $(PREBUILT_STATIC_LIBRARY)


################BOOST#####################

#include $(CLEAR_VARS)
#LOCAL_MODULE := libboost_datetime
#LOCAL_SRC_FILES := ../prebuild/$(TARGET_ARCH_ABI)/libnew/libboost_date_time.a
#include $(PREBUILT_STATIC_LIBRARY)

#include $(CLEAR_VARS)
#LOCAL_MODULE := libboost_exception
#LOCAL_SRC_FILES := ../prebuild/$(TARGET_ARCH_ABI)/libnew/libboost_exception.a
#include $(PREBUILT_STATIC_LIBRARY)

#include $(CLEAR_VARS)
#LOCAL_MODULE := libboost_system
#LOCAL_SRC_FILES := ../prebuild/$(TARGET_ARCH_ABI)/libnew/libboost_system.a
#include $(PREBUILT_STATIC_LIBRARY)

##########################################

include $(CLEAR_VARS)
LOCAL_MODULE := libboost_system
LOCAL_SRC_FILES := ../prebuild/$(TARGET_ARCH_ABI)/lib1/libboost_system.a
include $(PREBUILT_STATIC_LIBRARY)
###########################



# static library info
include $(CLEAR_VARS)
LOCAL_MODULE := apayib
LOCAL_SRC_FILES := ../prebuild/$(TARGET_ARCH_ABI)/libapayi.a
LOCAL_EXPORT_C_INCLUDES := ../prebuild/$(TARGET_ARCH_ABI)/include
LOCAL_STATIC_LIBRARIES := opencrypto_static libboost_system #libboost_datetime libboost_exception
 #libboost_wserialization libboost_wave libboost_thread libboost_system libboost_signals libboost_serialization libboost_regex libboost_random libboost_program_options libboost_prg_exec_monitor libboost_math_tr1l libboost_math_tr1f libboost_math_tr1 libboost_math_c99l libboost_math_c99f LOCAL_STATIC_LIBRARIES := opencrypto_static libboost_wserialization libboost_wave libboost_thread libboost_system libboost_signals libboost_serialization libboost_regex libboost_random libboost_program_options libboost_prg_exec_monitor libboost_math_tr1l libboost_math_tr1f libboost_math_tr1 libboost_math_c99l libboost_math_c99f libboost_atomic libboost_chrono libboost_context libboost_date_time libboost_exception libboost_filesystem libboost_graph libboost_iostreams libboost_math_c99

include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := apayi-user
LOCAL_SRC_FILES := apayi-user.cpp
LOCAL_STATIC_LIBRARIES := apayib
include $(BUILD_SHARED_LIBRARY)
