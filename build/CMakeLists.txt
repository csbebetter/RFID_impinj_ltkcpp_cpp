
cmake_minimum_required(VERSION 3.9)
project(example_test1)

set (EXECUTABLE_OUTPUT_PATH ../bin)

aux_source_directory (../src SRC_LIST)

include_directories (../ltkcpp/include)

find_library(LIBLTKCPP libltkcpp_x86_64.a ../ltkcpp/lib)
find_library(LIBLTKCPP_IMPINJ libltkcppimpinj_x86_64.a ../ltkcpp/lib)
# it is not recommended to statically link for ssl and crypto libraries
find_library(LIBSSL ssl REQUIRED)
find_library(LIBCRYPTO crypto REQUIRED)
# The ETK does not contain a host static library for xml2.  Add the generic
# name 'xml2' to link against the dynmaic library when compiling for host.
find_library(LIBXML2 NAMES libxml2.a xml2 REQUIRED)
set(LIBS
    ${LIBLTKCPP}
    ${LIBLTKCPP_IMPINJ}
    ${LIBCRYPTO}
    ${LIBSSL}
    ${LIBXML2}
)

add_executable(main ${SRC_LIST})
target_link_libraries(main PRIVATE ${LIBS})
