# Copyright (c) Facebook, Inc. and its affiliates.
#
# Licensed under the Apache License Version 2.0 with LLVM Exceptions
# (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
#
#     https://llvm.org/LICENSE.txt
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

find_path(LIBURING_INCLUDE_DIR NAMES liburing/io_uring.h linux/io_uring.h)
mark_as_advanced(LIBURING_INCLUDE_DIR)

find_library(LIBURING_LIBRARY NAMES uring)
mark_as_advanced(LIBURING_LIBRARY)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(
        LibUring
        REQUIRED_VARS LIBURING_INCLUDE_DIR LIBURING_LIBRARY)

if(NOT TARGET LibUring::LibUring)
    add_library(LibUring::LibUring UNKNOWN IMPORTED)
    set_target_properties(LibUring::LibUring PROPERTIES
                          INTERFACE_INCLUDE_DIRECTORIES "${LIBURING_INCLUDE_DIR}"
                          IMPORTED_LINK_INTERFACE_LANGUAGES "C"
                          IMPORTED_LOCATION "${LIBURING_LIBRARY}")
endif()
