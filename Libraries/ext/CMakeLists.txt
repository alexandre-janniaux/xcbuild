#
# Copyright (c) 2015-present, Facebook, Inc.
# All rights reserved.
#
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.
#

add_library(ext
            Sources/optional.cpp
            )

target_link_libraries(ext PUBLIC)
target_include_directories(ext PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Headers")
install(TARGETS ext DESTINATION usr/lib)

