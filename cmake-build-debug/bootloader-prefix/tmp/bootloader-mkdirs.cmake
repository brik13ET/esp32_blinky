# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/ESP/framework/components/bootloader/subproject"
  "D:/Git/esp/scan/cmake-build-debug/bootloader"
  "D:/Git/esp/scan/cmake-build-debug/bootloader-prefix"
  "D:/Git/esp/scan/cmake-build-debug/bootloader-prefix/tmp"
  "D:/Git/esp/scan/cmake-build-debug/bootloader-prefix/src/bootloader-stamp"
  "D:/Git/esp/scan/cmake-build-debug/bootloader-prefix/src"
  "D:/Git/esp/scan/cmake-build-debug/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Git/esp/scan/cmake-build-debug/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Git/esp/scan/cmake-build-debug/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
